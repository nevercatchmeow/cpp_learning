/**
 * @file MainTest.cpp
 * @author Kevin MRZ (5445029@gmail.com)
 * @brief Test for stack
 * @version 0.1
 * @date 2021-03-07
 *
 * @copyright Copyright (c) 2021
 *
 */

 //  Compile: g++ -o MainTest MainTest.cpp Stack.hpp ../SLList/SLList.hpp -w -std=c++11
#include <iostream>

#include "Stack.hpp"

void test()
{
	Stack<int>* stack = new Stack<int>();

	// Test: print()
	stack->print();

	// Test: isEmpty()
	std::cout << "Stack[" << stack->size() << "]: Is empty ? ";
	if (stack->isEmpty())
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "No!" << std::endl;

	// Test: push()
	int i = 5;
	while (i > 0)
	{
		stack->push(i);
		stack->print();
		i--;
	}
	// Test: pop()
	stack->pop();
	stack->print();
	// Test: top()
	std::cout << "Stack[" << stack->size() << "]: The top element is ? ";
	std::cout << stack->top() << std::endl;


	// Test: isEmpty()
	std::cout << "Stack[" << stack->size() << "]: Is empty ? ";
	if (stack->isEmpty())
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "No!" << std::endl;

	// Test: clear()
	stack->clear();
	stack->print();
}

int main()
{
	test();

#ifdef _WIN32
	system("pause");
#endif
	return 0;
}