#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
--------------------------------------------------
虚继承内部工作原理：通过虚基类指针和虚基类表实现，
	一、虚继承的子类包含：
		1. 虚基类指针（占用一个指针的存储空间，4字节）。
		2. 虚基类表（不占用类对象的存储空间）。
	二、虚基类依旧会在子类里面存在拷贝，最多仅一份
	三、当虚继承的子类被当做父类继承时，虚基类指针也会被继承。

普通继承需要维持来自虚基类的两份同样的拷贝，浪费空间。

虚基类表指针（vbptr）指向虚基类表，其中记录虚基类与本类的偏移地址；
虚继承通过偏移地址，寻找虚基类成员。节省了存储空间。
--------------------------------------------------
*/
  
// 基类A  
#include<iostream>  
using namespace std;  
  
class A  //大小为4  
{  
public:  
	int a;  
};  
class B :virtual public A  //大小为12，变量a,b共8字节，虚基类表指针4  
{  
public:  
	int b;  
};  
class C :virtual public A //与B一样12  
{  
public:  
	int c;  
};  
class D :public B, public C //24,变量a,b,c,d共16，B的虚基类指针4，C的虚基类指针4  
{  
public:  
	int d;  
};  
  
int main()  
{  
	A a;  
	B b;  
	C c;  
	D d;  
	cout << sizeof(a) << endl;  
	cout << sizeof(b) << endl;  
	cout << sizeof(c) << endl;  
	cout << sizeof(d) << endl;  
	
	system("pause");  
	return 0;  
}  
