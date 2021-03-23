#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

 //文件流
#include <fstream>

/*
--------------------------------------------------
文件读写：
　　ios::app：　　　以追加的方式打开文件
　　ios::ate：　　　文件打开后定位到文件尾，ios:app就包含有此属性
　　ios::binary：　以二进制方式打开文件，缺省的方式是文本方式。两种方式的区别见前文
　　ios::in：　　　 文件以输入方式打开(文件数据输入到内存)
　　ios::out：　　　文件以输出方式打开(内存数据输出到文件)
　　ios::nocreate： 不建立文件，所以文件不存在时打开失败
　　ios::noreplace：不覆盖文件，所以打开文件时如果文件存在失败
　　ios::trunc：　　如果文件存在，把文件长度设为0

文件定位：
　　ios::beg：　　文件开头
　　ios::cur：　　文件当前位置
　　ios::end：　　文件结尾
--------------------------------------------------
*/

void test01()
{
	//写文件  o --  输出    
	ofstream  ofs("./test.txt", ios::out | ios::trunc);

	//ofs.open("./test.txt", ios::out | ios::trunc);  设置打开方式 以及路径

	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	ofs << "姓名：Yasuo" << endl;
	ofs << "年龄：27" << endl;
	ofs << "性别：男" << endl;

	//关闭文件
	ofs.close();

}

void test02()
{
	//读文件   i  -- 输入
	ifstream  ifs;
	ifs.open("./test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//第一种方式
	//char buf[1024] = { 0 };

	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}


	//第二种方式
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf,sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	//第三种方式
	//string buf;
	//while ( getline(ifs,buf) )
	//{
	//	cout << buf << endl;
	//}


	//第四种方式
	char  c;
	while ( (c = ifs.get()) != EOF )
	{
		cout << c;
	}

	ifs.close();
}

int main(){

	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}