/*
	可调用对象包装器、绑定器：
		可调用对象：
			1.函数指针
			2.具有operator()成员函数的类对象（仿函数）
			3.可转换为函数指针的类对象
			4.类成员指针或类成员函数指针
		可调用对象包装器：
			#include <functional>
			std::function<可调用对象返回值类型(参数1, 参数2)> f = 可调用对象; 
		可调用对象绑定器：
			作用：
				1.将可调用对象与其参数绑定成一个仿函数。
				2.将多元（参数个数n，n>1）可调用对象转换为一元或n-1元可调用对象（只绑定部分参数）
			使用：
				1.绑定非类成员函数/变量
					auto f = std::bind(可调用对象地址，绑定的参数/占位符)
				2.绑定类成员函数/变量
					auto f = std::bind(可调用对象地址，类实例对象地址，绑定的参数/占位符)
	
	Compile: g++ main.cpp -o main -std=c++11
*/

#include <iostream>
#include <string>
#include <functional>

/***********************************************/
/*					可调用对象				   */
/***********************************************/
// 1.函数指针
using func_ptr = void(*)(int, std::string);

class Test
{
public:
	// 2.仿函数
	void operator() (std::string msg)
	{
		std::cout << "仿函数： " << msg << std::endl;
	}

	// 3.类对象转换为函数指针
	operator func_ptr()
	{
		return world;	// world函数被调用。
		// return hello; // Error: 当类对象不存在时，hello()亦不存在。
	}

	void hello(int a, std::string s)
	{
		std::cout << "number: " << a << ", name: " << s << std::endl;
	}

	static void world(int a, std::string s)
	{
		std::cout << "number: " << a << ", name: " << s << std::endl;
	}

	void output(int n1, int n2)
	{
		std::cout << "number1: " << n1 << ", number2: " << n2 << std::endl;
	}

	Test() : m_id(0) {};
	~Test() {};

	int m_id;
};

void callableObj()
{
	Test t1;
	t1("Hello CPP");

	Test t2;
	t2(23, "Kevin");

	// 4.类的函数指针
	func_ptr f1 = Test::world;
	using fptr = void(Test::*)(int, std::string);
	fptr f2 = &Test::hello;

	// 4.类的成员指针（变量）
	using ptr = int Test::*;
	ptr p1 = &Test::m_id;

	Test t3;
	(t3.*f2)(20, "Have a nice day!");
	t3.*p1 = 100;
	std::cout << "m_id: " << t3.*p1 << std::endl;
}

/***********************************************/
/*				可调用对象包装器				   */
/***********************************************/
// 普通函数
void print(int num, std::string name)
{
	std::cout << "number: " << num << " , name: " << name << std::endl;
}

class A
{
public:
	A(const std::function<void(int, std::string)>& f) : callBack(f) { }

	void notify(int id, std::string name)
	{
		callBack(id, name);	// 调用通过构造函数获得的函数指针
	}

private:
	std::function<void(int, std::string)> callBack;
};

void callableObjWrapper()
{
	// 直接打包可调用对象
	// 1.包装普通函数
	std::function<void(int, std::string)> f1 = print;
	// 2.包装类的静态函数
	std::function<void(int, std::string)> f2 = Test::world;
	// 3.包装仿函数
	Test ta;
	std::function<void(std::string)> f3 = ta;
	// 4.包装转换为函数指针的对象
	Test tb;
	std::function<void(int, std::string)> f4 = tb;

	f1(1, "a");
	f2(2, "b");
	f3("c");
	f4(4, "d");

	// 通过类的构造函数打包可调用对象
	// 1.包装普通函数
	A a1(print);
	a1.notify(7, "Teemo");
	// 2.包装类的静态函数
	A a2(Test::world);
	a2.notify(8, "EZ");
	// 3.包装仿函数：参数列表不匹配
	// 4.包装转换为函数指针的对象
	A a3(tb);
	a3.notify(27, "YaSuo");
}

/***********************************************/
/*				可调用对象绑定器				   */
/***********************************************/
void output(int x, int y)
{
	std::cout << x << " " << y << std::endl;
}

void testFunc(int x, int y, const std::function<void(int x, int y)>& f)
{
	if (x % 2 == 0)
	{
		f(x, y);
	}
}

void output_add(int x, int y)
{
	std::cout << "x: " << x << ", y: " << y
		<< ", x+y: " << x + y << std::endl;
}

void callableObjBinder()
{
	// std::placeholders::_x为参数占位符
	std::bind(output, 1, 2);
	std::bind(output, std::placeholders::_1, 2)(10);
	std::bind(output, 2, std::placeholders::_1)(10);

#if 0
	// Error：无第二个实参，std::placeholders::_2非法
	std::bind(output, 2, std::placeholders::_2)(10);
#else
	// 注：第一个参数已绑定为2，实参列表第一个参数无效。
	std::bind(output, 2, std::placeholders::_2)(10, 20);
#endif // 0
	std::bind(output, std::placeholders::_1, std::placeholders::_2)(10, 20);
	std::bind(output, std::placeholders::_2, std::placeholders::_1)(10, 20);

	for (int i = 0; i < 10; i++)
	{
		auto f1 = std::bind(output_add, i + 100, i + 200);
		testFunc(i, i, f1);

		auto f2 = std::bind(output_add, std::placeholders::_1, std::placeholders::_2);
		testFunc(i, i, f2);
	}

	// 绑定成员函数
	Test t;
	auto f3 = std::bind(&Test::output, &t, 520, std::placeholders::_1);
	std::function<void(int, int)> f33 = std::bind(&Test::output, &t, 520, std::placeholders::_1);
	f3(1214);

	// 绑定成员变量（省略参数）
	auto f4 = std::bind(&Test::m_id, &t);
	std::function<int&(void)> f44 = std::bind(&Test::m_id, &t);
	std::cout << f4() << std::endl;
	f4() = 777;
	std::cout << f4() << std::endl;
}

void cpp_11()
{
	// 可调用对象
	callableObj();
	// 可调用对象包装器
	callableObjWrapper();
	// 可调用对象绑定器
	callableObjBinder();
}

int main()
{
	cpp_11();

	return 0;
}