#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
--------------------------------------------------
虚析构：
	子类有成员指向堆区，delete时调用子类析构（利用虚析构技术）
	virtual ~Animal()
	{
		cout << "Animal的析构函数调用" << endl;
	}

纯虚析构函数：
	1.包含纯虚析构函数的类属于抽象类，无法实例化。
	2.声明：virtual ~Animal() = 0;
	3.实现：Animal::~Animal(){//do something}
--------------------------------------------------
*/

class Animal
{
public:
	Animal()
	{
		cout << "Animal的构造函数调用" << endl;
	}
	virtual void speak()
	{
		cout << "动物嗷嗷叫" << endl;
	}
	virtual ~Animal() = 0;
};

Animal::~Animal()
{
	cout << "Animal的纯虚析构函数调用" << endl;
}

class Cat :public Animal
{
public:
	Cat(char * name)
	{
		cout << "Cat的构造函数调用" << endl;
		this->m_Name = new char[strlen(name) + 1];
		strcpy(this->m_Name, name);
	}

	virtual void speak()
	{
		cout << this->m_Name <<" 小猫喵喵叫" << endl;
	}

	~Cat()
	{
		if (this->m_Name)
		{
			cout << "Cat的析构函数调用" << endl;
			delete[] this->m_Name;
			this->m_Name = NULL;
		}
	}
	char * m_Name;
};

void test()
{
	Animal * animal = new Cat("Tom");
	animal->speak();

	delete animal;
}

int main(){
	test();

	system("pause");
	return EXIT_SUCCESS;
}
