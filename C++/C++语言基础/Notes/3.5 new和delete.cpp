#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <malloc.h>

using namespace std;

/*
--------------------------------------------------
【malloc】
--------------------------------------------------
*/
class Person1
{
public:
	int mAge;
	char * pName;

	Person1()
	{
		mAge = 20;

		pName = (char*)malloc(strlen("Jonah") + 1);
		if (pName != NULL)
		{
			strcpy(pName, "Jonah");
			cout << "malloc" << endl;
		}
		else
		{
			cout << "申请内存失败！"
		}
	}
};

void test_malloc()
{
	//分配内存
	Person1* person = (Person1*)malloc(sizeof(Person1));
	if (person == NULL) {}
	else {}
}

/*
--------------------------------------------------
【malloc缺陷】
1.程序员必须确定对象长度。
2.malloc返回void*，C++中不允许将void*赋值给其他类型指针，必须强转。
3.malloc可能申请内存失败，需要通过返回值判断是否申请成功。
4.用户在使用对象前必须对其初始化，构造函数不能显式调用初始化（用户可能忘记调用初始化函数）。
--------------------------------------------------
*/


/*
--------------------------------------------------
【new/delete】
--------------------------------------------------
*/
class Person2
{
public:
	int m_Age;

	Person2()
	{
		cout << "new无参构造函数" << endl;
	}

	Person2(int age)
	{
		cout << "new有参构造" << endl;
		m_Age = age;
	}

	~Person2()
	{
		cout << "new析构函数" << endl;
	}
};

void test_new1()//手动申请，手动释放
{
	Person2 *p = new Person2;
	delete p;
	//1个无参构造。
}

/*
--------------------------------------------------
new和malloc区别：
1.malloc和free属于库函数；new和delete属于运算符。
2.malloc不会调用构造函数；new会调用构造函数。
3.malloc返回void*，C++下要强制转换；new返回创建的对象的指针。
--------------------------------------------------
*/

/*
--------------------------------------------------
注意：
不要用void*接受new出的对象。
原因：无法释放（编译器不知道目标类型，无法调用析构）。
--------------------------------------------------
*/

/*
--------------------------------------------------
利用new开辟数组：
int *pInt = new int[10];
double *pD = new double[10];
--------------------------------------------------
*/

void test_new2()
{
	Person2 *p = new Person2[10];//堆区开辟数组，一定会调用默认构造函数（确保默认构造函数可用）
	delete[] p;// 释放数组必须加[]：确保释放掉所有，而非第一个
	//10个无参构造。

	Person2 pArray[10] = { Person2(10), Person2(20), Person2(30) };//栈上开辟数组，可以没有默认构造函数
	//3个有参构造，7个无参构造。
}


int main()
{
	test_malloc();
	test_new1();
	test_new2();

	system("pause");
	return 0;
}