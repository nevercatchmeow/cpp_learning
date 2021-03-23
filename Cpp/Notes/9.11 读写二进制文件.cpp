#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
 //文件流
#include <fstream>

class Hero{
public:
	Hero(){}
	Hero(char* name,int age)
	{
		strcpy(this->mName, name);
		this->mAge = age;
	}
	char mName[64];
	int mAge;
};

void test()
{
	char* fileName = "Hero.bin";
	//二进制模式读写文件
	//创建文件对象输出流
	ofstream osm(fileName, ios::out | ios::binary);

	Hero p1("Teemo",7);
	Hero p2("ZOE", 9999);

	//Hero对象写入文件
	osm.write((const char*)&p1,sizeof(Hero));
	osm.write((const char*)&p2, sizeof(Hero));

	//关闭文件输出流
	osm.close();

	//从文件中读取对象数组
	ifstream ism(fileName, ios::in | ios::binary);
	if (!ism){
		cout << "打开失败!" << endl;
	}
	
	Hero p3;
	Hero p4;

	ism.read((char*)&p3, sizeof(Hero));
	ism.read((char*)&p4, sizeof(Hero));

	cout << "Name:" << p3.mName << " Age:" << p3.mAge << endl;
	cout << "Name:" << p4.mName << " Age:" << p4.mAge << endl;

	//关闭文件输入流
	ism.close();
}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}
