#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

#include<stdexcept>

/*
--------------------------------------------------
系统标准异常：
	
--------------------------------------------------
*/

class Person{
public:
	Person(int age){
		if (age < 0 || age > 150){
			throw out_of_range("年龄应该在0-150岁之间!");
		}
	}
public:
	int mAge;
};

int main(){

	try{
		Person p(151);
	}
	catch (out_of_range& ex){
		cout << ex.what() << endl;
	}
	
	system("pause");
	return EXIT_SUCCESS;
}
