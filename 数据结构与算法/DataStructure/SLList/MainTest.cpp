/**
 * @file MainTest.cpp
 * @author Kevin MRZ (5445029@gmail.com)
 * @brief Test for singly linked list
 * @version 0.1
 * @date 2021-03-07
 *
 * @copyright Copyright (c) 2021
 *
 */

 //  Compile: g++ -o MainTest MainTest.cpp SLList.hpp -w -std=c++11
#include <iostream>

#include "SLList.hpp"

void test()
{
	SLList<int>* sllist = new SLList<int>();

	// Test: print()
	sllist->print();

	// Test: isEmpty()
	std::cout << "SLList[" << sllist->size() << "]: Is empty ? ";
	if (sllist->isEmpty())
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "No!" << std::endl;

	// Test: insert_after()
	int i = 5;
	while (i > 0)
	{
		sllist->insert_after(0, i--);
		sllist->print();
	}
	// Test: push_front()
	sllist->push_front(0);
	sllist->print();
	// Test: push_back()
	sllist->push_back(6);
	sllist->print();

	// Test: delete_from()
	sllist->delete_from(6);
	sllist->print();
	// Test: pop_front()
	sllist->pop_front();
	sllist->print();
	// Test: pop_back()
	sllist->pop_back();
	sllist->print();

	// Test: delete_elem()
	sllist->push_back(3);
	sllist->print();
	sllist->delete_elem(3);
	sllist->print();

	// Test: set_elem()
	sllist->set_elem(2, 3);
	sllist->print();

	// Test: get_from()
	std::cout << "SLList[" << sllist->size() << "]: The element with index 1 is ? ";
	std::cout << sllist->get_from(1) << std::endl;
	// Test: get_front()
	std::cout << "SLList[" << sllist->size() << "]: The first element / with index 0 is ? ";
	std::cout << sllist->get_front() << std::endl;
	// Test: get_back()
	std::cout << "SLList[" << sllist->size() << "]: The last element / with index " << sllist->size() - 1 << " is ? ";
	std::cout << sllist->get_back() << std::endl;

	// Test: isEmpty()
	std::cout << "SLList[" << sllist->size() << "]: Is empty ? ";
	if (sllist->isEmpty())
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "No!" << std::endl;

	// Test: isContains()
	std::cout << "SLList[" << sllist->size() << "]: Is Contains 2 ? ";
	if (sllist->isContains(2))
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "No!" << std::endl;

	std::cout << "SLList[" << sllist->size() << "]: Is Contains 10 ? ";
	if (sllist->isContains(10))
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "No!" << std::endl;

	// Test: reverse()
	sllist->print();
	sllist->reverse();
	sllist->print();

	// Test: clear()
	sllist->clear();
	sllist->print();
}

int main()
{
	test();

#ifdef _WIN32
	system("pause");
#endif
	return 0;
}