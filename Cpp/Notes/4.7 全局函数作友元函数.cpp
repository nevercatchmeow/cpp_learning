#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

/*
--------------------------------------------------
全局函数作友元函数：
	1.关键字friend，在类内声明（任意位置）。
	2.友元函数可以访问类的私有成员。
--------------------------------------------------
*/

class Building
{
	//在类内声明，可以访问类的私有成员。
	friend void goodGay(Building * buliding);
public:
	Building()
	{
		this->m_SittingRoom = "客厅";
		this->m_BedRoom = "卧室";
	}

public:
	string m_SittingRoom; //客厅
private:
	string m_BedRoom; //卧室
};

//全局函数
void goodGay(Building * buliding)
{
	cout << "友元函数正在访问：" << buliding->m_SittingRoom << endl;
	cout << "友元函数正在访问：" << buliding->m_BedRoom << endl;
}

void test_friendGlobalFunc()
{
	Building buliding;
	goodGay(&buliding);
}

int main() {
	test_friendGlobalFunc();

	system("pause");
	return EXIT_SUCCESS;
}