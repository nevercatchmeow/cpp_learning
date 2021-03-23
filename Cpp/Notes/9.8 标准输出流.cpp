#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
#include <iomanip> //控制符格式化输出  头文件

/*
--------------------------------------------------
标准输出流：

格式化输出：
	1、通过 流成员函数 格式化输出
	2、使用控制符 格式化输出
--------------------------------------------------
*/

/*
cout.put() //向缓冲区写字符
cout.write() //从buffer中写num个字节到当前输出流中。
*/
void test01()
{
	//cout.put('h').put('e');
	char buf[] = "hello world";
	cout.write(buf, strlen(buf));
	cout << "hello world" << endl;
}

//1、通过 流成员函数 格式化输出
void test02()
{
	int number = 99;
	cout.width(20); //指定宽度为20
	cout.fill('*'); //填充
	cout.setf(ios::left);  //左对齐
	cout.unsetf(ios::dec); //卸载十进制
	cout.setf(ios::hex);  //安装十六进制
	cout.setf(ios::showbase);  //显示基数
	cout.unsetf(ios::hex);  //卸载十六进制
	cout.setf(ios::oct);   //安装八进制
	cout << number << endl;
}

//2、使用控制符 格式化输出
void test03()
{
	int number = 99;
	cout << setw(20)     //设置宽度
		<< setfill('~')  //设置填充
		<< setiosflags(ios::showbase)  //显示基数
		<< setiosflags(ios::left)  //设置左对齐
		<< hex   //显示十六进制
		<< number
		<< endl;
}

int main(){

	//test01();
	//test02();
	test03();

	system("pause");
	return EXIT_SUCCESS;
}
