#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
--------------------------------------------------
多态分类：
	1. 静态联编（编译时多态）：运算符重载、函数重载
	2. 动态联编（运行时多态）：派生类、虚函数

	区别：函数地址的绑定时机。

动态多态产生条件：
	1. 继承关系
	2. 父类中有虚函数，子类重写父类中的虚函数
	3. 父类的指针或引用指向子类的对象
		//Animal & animal = cat;

重写：函数返回值、函数名、形参列表都相同。

多态原理：
	1. 当父类写了虚函数后，类内部结构发生改变，多出vfptr
	2. vfptr（虚函数表指针）：指向vftable（虚函数表）
	3. 虚函数表内部记录虚函数的入口地址
	4. 当父类指针或引用指向子类对象，发生多态，调用时从虚函数中找函数入口地址
	5. 利用指针的偏移调用函数 
		((void(*)()) (*(int *)*(int *)animal)) ();
		typedef void( __stdcall *FUNPOINT)(int);
		(FUNPOINT (*((int*)*(int*)animal + 1)))(10);
--------------------------------------------------
*/

class Animal
{
public:
	//虚函数
	virtual void speak()
	{
		cout << "动物叫" << endl;
	}

	virtual void eat(int a)
	{
		cout << "动物吃" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "小猫喵喵叫" << endl;
	}

	void eat(int a)
	{
		cout << "小猫吃猫粮" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "小狗吃狗粮" << endl;
	}
};


//对于有父子关系的两个类，指针或者引用可以直接转换
void doSpeak(Animal& animal) //Animal & animal = cat;
{
	animal.speak();
}

void test_Polymorphism1()
{
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);

	Animal animal;
	doSpeak(animal);

}

void test_Polymorphism2()
{
	//cout << "sizeof  Animal = " << sizeof (Animal) << endl;

	Animal* animal = new Cat;
	//animal->speak();
	// *(int *)animal 解引用到虚函数表中
	// *(int *)*(int *)animal 解引用到函数speak地址

	//调用猫喵喵叫
	((void(*)()) (*(int*)*(int*)animal)) ();


	//C/C++默认调用惯例  __cdecl
	//用下列调用时候 真实调用惯例  是 __stdcall
	//调用猫吃猫粮
	typedef void(__stdcall* FUNPOINT)(int);

	(FUNPOINT(*((int*)*(int*)animal + 1)))(10);
}


int main() {
	test_Polymorphism1();
	//test_Polymorphism2();

	system("pause");
	return EXIT_SUCCESS;
}