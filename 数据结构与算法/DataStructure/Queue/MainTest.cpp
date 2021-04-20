/**
 * @file MainTest.cpp
 * @author Kevin MRZ (5445029@gmail.com)
 * @brief Test for queue
 * @version 0.1
 * @date 2021-03-07
 *
 * @copyright Copyright (c) 2021
 *
 */

 //  Compile: g++ -o MainTest MainTest.cpp Queue.hpp ../SLList/SLList.hpp -w -std=c++11
#include <iostream>

#include "Queue.hpp"

void test()
{
	Queue<int>* queue = new Queue<int>();

	// Test: print()
	queue->print();

	// Test: isEmpty()
	std::cout << "Queue[" << queue->size() << "]: Is empty ? ";
	if (queue->isEmpty())
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "No!" << std::endl;

	// Test: enqueue()
	int i = 5;
	while (i > 0)
	{
		queue->enqueue(i);
		queue->print();
		i--;
	}
	// Test: dequeue()
	queue->dequeue();
	queue->print();
	// Test: front()
	std::cout << "Queue[" << queue->size() << "]: The front element is ? ";
	std::cout << queue->front() << std::endl;


	// Test: isEmpty()
	std::cout << "Queue[" << queue->size() << "]: Is empty ? ";
	if (queue->isEmpty())
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "No!" << std::endl;

	// Test: clear()
	queue->clear();
	queue->print();
}

int main()
{
	test();

#ifdef _WIN32
	system("pause");
#endif
	return 0;
}