#include <iostream>
#include <vector>
#include <assert.h>

class Principle {
public:
	// 无参构造
	Principle() : m_value(new int(10)) {}
	
	// 拷贝构造
	Principle(const Principle& rhs) : m_value(new int(*(rhs.m_value))) {}
	
	// 拷贝构造（传入左值，返回右值）
	Principle(Principle&& rhs);

	// 赋值运算符重载
	Principle& operator = (const Principle& rhs) 
	{
		*m_value = *(rhs.m_value);
		return *this;
	}
	// 赋值运算符重载（参数为左值）
	Principle& operator = (Principle&& rhs)
	{
		// 加入以下判断以应对：e = std::move(e);
		if (&rhs == this)
		{
			return *this;
		}
		delete m_value;
		m_value = rhs.m_value;
		rhs.m_value = nullptr;
		return *this;
	}

	// 析构函数
	~Principle() { delete m_value; };

	void print() const
	{
		assert(m_value);	// 若 m_value 存在，则打印。
		std::cout << *m_value << std::endl;
	}

private:
	int* m_value;
};

// 拷贝构造（（传入左值，返回右值））
Principle::Principle(Principle&& rhs)
{
	m_value = rhs.m_value;
	rhs.m_value = nullptr;
}

// 传入左值，输入右值
void print(const int& a)
{
	
	std::cout << a << std::endl;
}

int main()
{
	int abc = 10;
	// 传入左值，输出右值
	print(abc);		// 10
	print(10);		// 10

	std::vector<int> a;
	for (int i = 0; i < 10; i++)
	{
		a.push_back(i);
	}

	Principle b, e;
	auto& c = b;

	// 传入左值，返回右值（抽取资源）。
	// 此处实际调用了	Principle(Principle&& rhs);
	Principle d = std::move(b);

	// 建议执行move后不再使用。
	// b.print(); // 若 print函数 无 assert(m_value); 运行程序将 core dumped ，因 b 的资源已不存在。
	// 如果不重写 Principle(Principle&& rhs);  b.print(); 就可执行成功。
	
	e = std::move(e);
}

/*
================================================================================
==>类的五大原则
--------------------------------------------------------------------------------
自主创建的资源需要自定义以下函数进行管理：
	1.构造函数。
	2.析构函数。
	3.赋值运算符重载。
	4.拷贝构造（参数为左值，返回右值）
	5.赋值运算符重载（参数为左值，返回右值）
================================================================================
*/