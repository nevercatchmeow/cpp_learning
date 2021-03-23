/*
--------------------------------------------------
C语言使用static关键字使名字只在本编译单元内可见。
C++引入命名空间（namespace）。
--------------------------------------------------
*/

/*
--------------------------------------------------
创建命名空间（只能在全局范围内定义）
	1.命名空间可嵌套命名空间。
	2.添加新成员。
	3.无名命名空间只在当前文件内有效（相当于加static）。
	4.命名空间可取别名。
	4.命名空间可嵌套。
--------------------------------------------------
*/
namespace A{int a = 10;}
void test(){cout << "A::a : " << A::a << endl;}

//命名空间可嵌套命名空间
namespace A{
	int a = 10;
	namespace B{
         int a = 20;
	}
}

namespace veryLongName{
	int a = 10;
	void func(){ cout << "hello namespace" << endl; }
}

/*
--------------------------------------------------
命名空间使用：
	1. 通过命名空间域运算符。
	2. using声明
--------------------------------------------------
*/

cout << A::paramA << endl;//命名空间域运算符
A::funcA();
using A::paramA;//using声明
using A::funcA;
cout << paramA << endl;


/*
如果命名空间包含一组用相同名字重载的函数,
using声明就声明了这个重载函数的所有集合。
*/
namespace A{
	void func(){}
	void func(int x){}
	int  func(int x,int y){}
}
void test(){
	using A::func;
	func();
	func(10);
	func(10, 20);
}


//使整个命名空间标识符可用。
using namespace A;//增加命名冲突可能性