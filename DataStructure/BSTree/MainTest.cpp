/**
 * @file MainTest.cpp
 * @author Kevin MRZ (5445029@gmail.com)
 * @brief Test for BSTree
 * @version 0.1
 * @date 2021-03-07
 *
 * @copyright Copyright (c) 2021
 *
 */

 //  Compile: g++ -o MainTest MainTest.cpp BSTree.hpp -w -std=c++11
#include <iostream>
#include <ctime>

#include "BSTree.hpp"

void test()
{
	BSTree<int>* bstree = new BSTree<int>();

	// Test: isEmpty()
	std::cout << "BSTree[" << bstree->size() << "]: Is empty ? ";


	if (bstree->isEmpty())
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "No!" << std::endl;

	srand((unsigned)time(NULL));
	for (int i = 0; i < 5; i++)
	{
		bstree->add(rand() % 30);
	}

	bstree->preOrder();
	bstree->inOrder();
	bstree->postOrder();
}

int main()
{
	test();

#ifdef _WIN32
	system("pause");
#endif
	return 0;
}