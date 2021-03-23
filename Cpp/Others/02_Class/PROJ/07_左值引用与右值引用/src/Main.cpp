#include <iostream>

void lvalueRef()
{
	// 左值：既能出现在等号左边、也能出现在等号右边的变量（表达式）
	// intValue1 为左值
	int intValue1 = 10;

	// 左值引用：通过&获得左值引用，左值引用只能绑定左值。
	// 将左值intValue1绑定到intValue2和intValue3
	int& intValue2 = intValue1;
	int& intValue3 = intValue2;

	intValue2 = 100;
	std::cout << intValue1 << std::endl;//100
	std::cout << intValue2 << std::endl;//100
	std::cout << intValue3 << std::endl;//100

	//int& intValue4 = 10;//错误
	// const的左值引用可以绑定右值，常量引用不能修改绑定对象的值。
	const int& intValue5 = 10;//正确
}

void rvalueRef()
{
	// 右值引用：通过&&获取右值引用，只能绑定右值。
	// 右值引用可以减少右值作为参数传递时的复制开销
	int intValue = 10;
	int&& intValue2 = 10;//正确
	//int&& intValue3 = intValue;//错误
}

int main()
{
	lvalueRef();
	rvalueRef();

	return 0;
}

/*
================================================================================
==>左值引用与右值引用
--------------------------------------------------------------------------------
左值引用：通过&获得左值引用，左值引用只能绑定左值，但const修饰的左值引用（常量引用）可以绑定右值。
右值引用：通过&&获取右值引用，只能绑定右值。（可以减少右值作为参数传递时的复制开销）。
================================================================================
*/