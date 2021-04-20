/**
 * @file MainTest.cpp
 * @author Kevin MRZ (5445029@gmail.com)
 * @brief Test for deque
 * @version 0.1
 * @date 2021-03-07
 *
 * @copyright Copyright (c) 2021
 *
 */

 //  Compile: g++ -o MainTest MainTest.cpp Deque.hpp ../DLList/DLList.hpp -w -std=c++11
#include <iostream>

#include "Deque.hpp"

void test()
{
	Deque<int>* deque = new Deque<int>();

	// Test: print()
	deque->print();

	// Test: isEmpty()
	std::cout << "Deque[" << deque->size() << "]: Is empty ? ";
	if (deque->isEmpty())
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "No!" << std::endl;

	// Test: enqueue_back()
	int i = 3;
	while (i > 0)
	{
		deque->enqueue_back(i);
		deque->print();
		i--;
	}

	// Test: enqueue_front()
	int j = 4;
	while (j < 7)
	{
		deque->enqueue_front(j);
		deque->print();
		j++;
	}

	// Test: dequeue_back()
	deque->dequeue_back();
	deque->print();

	// Test: dequeue_front()
	deque->dequeue_front();
	deque->print();

	// Test: front()
	std::cout << "Deque[" << deque->size() << "]: The front element is ? ";
	std::cout << deque->front() << std::endl;

	// Test: back()
	std::cout << "Deque[" << deque->size() << "]: The back element is ? ";
	std::cout << deque->back() << std::endl;

	// Test: isEmpty()
	std::cout << "Deque[" << deque->size() << "]: Is empty ? ";
	if (deque->isEmpty())
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "No!" << std::endl;

	// Test: clear()
	deque->clear();
	deque->print();
}

int main()
{
	test();

#ifdef _WIN32
	system("pause");
#endif
	return 0;
}