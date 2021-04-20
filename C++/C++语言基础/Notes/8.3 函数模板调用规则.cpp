#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
--------------------------------------------------
	实现泛型，提高编码效率，增强复用性。

【函数模板与普通函数】
区别：
	函数模板：自动类型推导，故无法发生隐式类型转换。
	普通函数：可以隐式类型转换。
	
【调用规则】：
	1.函数模板通过具体参数类型产生不同的函数。
	2.函数模板与普通函数同时可用时，优先普通函数。
	3.强制调用函数模板：空模板参数列表，如func<>(a, b);
	4.函数模板可以发生重载：func(a, b)与func(a, b, 10)
	5.普通函数参数类型不符时，优先函数模板。
	
--------------------------------------------------
*/

#include<iostream>
using namespace std;

int myAdd(int a, int b) {
	cout << "调用普通函数" << endl;
	return a + b;
}
template<class T>
T myAdd(T a, T b) {
	cout << "调用函数模板" << endl;
	return a + b;
}
template<class T>
T myAdd(T a, T b, T c) {
	cout << "调用重载函数模板" << endl;
	return a + b;
}
void test() {
	int a = 10;
	int b = 20;
	//1、调用普通函数
	cout << myAdd(a, b) << endl;
	//2、调用函数模板
	cout << myAdd<>(a, b) << endl;
	//3、调用重载函数模板
	cout << myAdd(a, b, 100) << endl;
	//4、调用函数模板
	cout << myAdd('a', 'b') << endl;
}

int main() 
{
	test();
	system("pause");
	return 0;
}
