/**
 * @file MainTest.cpp
 * @author Kevin MRZ (5445029@gmail.com)
 * @brief Test for dynamic array
 * @version 0.1
 * @date 2021-03-07
 *
 * @copyright Copyright (c) 2021
 *
 */

 //  Compile: g++ -o MainTest MainTest.cpp DynamicArray.hpp -w -std=c++11
#include <iostream>

#include "DynamicArray.hpp"

void test()
{
	DynamicArray<int>* array = new DynamicArray<int>();
	// DynamicArray<int>* array = new DynamicArray<int>(16);

	// Test: print()
	array->print();

	// Test: isEmpty(), size(), array->capacity()
	std::cout << "DynamicArray[" << array->size() << "/" << array->capacity() << "]: Is empty ? ";
	if (array->isEmpty())
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "No!" << std::endl;

	// Test: insert_first()
	for (int i = 7; i > 0; i--)
	{
		array->insert_first(i);
		array->print();
	}	

	// Test: insert_to()
	array->insert_to(7, 8);
	array->print();
	
	// Test: insert_last()
	for (int i = 9; i < 16; i++)
	{
		array->insert_last(i);
		array->print();
	}
	array->insert_last(12);
	array->print();

	// Test: delete_from()
	array->delete_from(7);
	array->print();

	// Test: delete_elem()
	array->delete_elem(12);
	array->print();

	// Test: delete_first(), delete_last()
	for (int i = 0; i < 5; i++)
	{
		array->delete_first();
		array->delete_last();
		array->print();
	}

	// Test: get_first(), get_last(), get()
	std::cout << "DynamicArray[" << array->size() << "/" << array->capacity() << "]: The first element is ? " << array->get_first() << std::endl;
	std::cout << "DynamicArray[" << array->size() << "/" << array->capacity() << "]: The last element is ? " << array->get_last() << std::endl;
	std::cout << "DynamicArray[" << array->size() << "/" << array->capacity() << "]: The element with index 1 is ? " << array->get(1) << std::endl;

	// Test: isEmpty(), size(), array->capacity()
	std::cout << "DynamicArray[" << array->size() << "/" << array->capacity() << "]: Is empty ? ";
	if (array->isEmpty())
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "No!" << std::endl;

	// Test: clear()
	array->clear();
	array->print();
}

int main()
{
	test();

#ifdef _WIN32
	system("pause");
#endif
	return 0;
}