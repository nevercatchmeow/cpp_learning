/**
 * @file MainTest.cpp
 * @author Kevin MRZ (5445029@gmail.com)
 * @brief Test for doubly linked list
 * @version 0.1
 * @date 2021-03-07
 *
 * @copyright Copyright (c) 2021
 *
 */

//  Compile: g++ -o MainTest MainTest.cpp DLList.hpp -w -std=c++11
#include <iostream>

#include "DLList.hpp"

void test()
{
	DLList<int> *dllist = new DLList<int>();

	// Test: print()
	dllist->print();

	// Test: isEmpty()
	std::cout << "DLList[" << dllist->size() << "]: Is empty ? ";
	if (dllist->isEmpty())
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "No!" << std::endl;

	// Test: insert_after()
	int i = 5;
	while (i > 0)
	{
		dllist->insert_after(0, i--);
		dllist->print();
	}
	// Test: push_front()
	dllist->push_front(0);
	dllist->print();
	// Test: push_back()
	dllist->push_back(6);
	dllist->print();

	// Test: delete_from()
	dllist->delete_from(6);
	dllist->print();
	// Test: pop_front()
	dllist->pop_front();
	dllist->print();
	// Test: pop_back()
	dllist->pop_back();
	dllist->print();

	// Test: delete_elem()
	dllist->push_back(3);
	dllist->print();
	dllist->delete_elem(3);
	dllist->print();

	// Test: set_elem()
	dllist->set_elem(2, 3);
	dllist->print();

	// Test: get_from()
	std::cout << "DLList[" << dllist->size() << "]: The element with index 1 is ? ";
	std::cout << dllist->get_from(1) << std::endl;
	// Test: get_front()
	std::cout << "DLList[" << dllist->size() << "]: The first element / with index 0 is ? ";
	std::cout << dllist->get_front() << std::endl;
	// Test: get_back()
	std::cout << "DLList[" << dllist->size() << "]: The last element / with index " << dllist->size() - 1 << " is ? ";
	std::cout << dllist->get_back() << std::endl;

	// Test: isEmpty()
	std::cout << "DLList[" << dllist->size() << "]: Is empty ? ";
	if (dllist->isEmpty())
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "No!" << std::endl;

	// Test: isContains()
	std::cout << "DLList[" << dllist->size() << "]: Is Contains 2 ? ";
	if (dllist->isContains(2))
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "No!" << std::endl;

	std::cout << "DLList[" << dllist->size() << "]: Is Contains 10 ? ";
	if (dllist->isContains(10))
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "No!" << std::endl;

	// Test: reverse()
	dllist->print();
	dllist->reverse();
	dllist->print();

	// Test: clear()
	dllist->clear();
	dllist->print();
}

int main()
{
	test();

#ifdef _WIN32
	system("pause");
#endif
	return 0;
}