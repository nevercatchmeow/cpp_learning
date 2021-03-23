#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
--------------------------------------------------
空指针访问成员函数：
	1.如果成员函数中没有用到this指针，可以用空指针调用成员函数
	2.如果成员函数中用到了this，那么这个this需要加判断，防止代码down掉

--------------------------------------------------
*/

class Person
{
public:
	void showClass()
	{
		cout << "class Name is Person" << endl;
	}

	void showAge()
	{
		//如果不对this判断将产生错误（写入访问权限冲突）。
		if (this == NULL)
		{
			return;
		}
		m_Age = 0;
		cout << "age = " << this->m_Age << endl;
	}
	int m_Age;
};

void test_nullptr()
{
	Person * p = NULL;
	p->showClass();//调用成功。
	p->showAge();//调用失败（无打印内容）。
}

int main(){
	test_nullptr();

	system("pause");
	return EXIT_SUCCESS;
}