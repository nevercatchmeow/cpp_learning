#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
--------------------------------------------------
模板（函数模板、类模板）：
	1.将函数或类要处理的数据类型参数化（参数多态性），类属。
	2.逻辑结构相同，数据元素类型不同的对象的通用行为。
		
模板特点:
	1.自动推导参数数据类型，或可显式指定。
	2.template<typename T>或template<class T>同等效力。
--------------------------------------------------
*/

//template<typename T>
template<class T>
void MySwap(T& a,T& b){
	T temp = a;
	a = b;
	b = temp;
}

void test(){
	
	int a = 10;
	int b = 20;
	cout << "a:" << a << " b:" << b << endl;
	MySwap(a,b);
	cout << "a:" << a << " b:" << b << endl;

	cout << "--------------------" << endl;

	char c1 = 'a';
	char c2 = 'b';
	cout << "c1:" << c1 << " c2:" << c2 << endl;
	MySwap<char>(c1, c2);
	cout << "c1:" << c1 << " c2:" << c2 << endl;
}


int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}
