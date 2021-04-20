#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

/*
--------------------------------------------------
类作友元函数：
	
A类作B类的友元类：
	1.B类中声明A类：friend class GoodGay;
	2.A类中成员变量(指向B类的指针)：Building * m_building;
	3.A类中绑定指针(通过构造函数)：
		GoodGay();
		{
			this->m_building =  new Building;
		}
	4.A类实现对B类成员的访问（通过成员函数）：
		this->m_building->m_SittingRoom //B类公有成员。
		this->m_building->m_BedRoom //B类私有成员。
		
注：类成员函数的实现放在所有类的下面。
--------------------------------------------------
*/


class Building;

class GoodGay
{
public:
	Building * m_building;
	GoodGay();
	void visit();
};

class Building
{
	//使goodGay类作为 Building的友元类，可以访问私有成员
	friend class GoodGay;//友元类声明。
public:
	Building();
	string m_SittingRoom;
private:
	string m_BedRoom;
};

Building::Building()
{
	this->m_SittingRoom = "客厅";
	this->m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
	this->m_building = new Building;
}

void GoodGay::visit()
{
	cout << "友元类正在访问： " << this->m_building->m_SittingRoom << endl;
	cout << "友元类正在访问： " << this->m_building->m_BedRoom << endl;
}

void test_friendClass()
{
	GoodGay gg;
	gg.visit();
}

int main()
{
	test_friendClass();

	system("pause");
	return EXIT_SUCCESS;
}