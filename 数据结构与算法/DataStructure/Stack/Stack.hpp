/**
 * @file Stack.hpp
 * @author Kevin MRZ (5445029@gmail.com)
 * @brief Stack powered by SLList
 * @version 0.1
 * @date 2021-03-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

#include "../SLList/SLList.hpp"

template <class T>
class Stack
{
public:
	Stack() : _pSLList(new SLList<T>()) {}
	~Stack() {}

	bool isEmpty() const { return _pSLList->isEmpty(); }
	void clear() { _pSLList->clear(); }
	int size() { return _pSLList->size(); }

	T top() { return _pSLList->get_back(); }
	void push(const T& data) { _pSLList->push_back(data); }
	T pop() { return _pSLList->pop_back(); }

	void print();

private:
	SLList<T>* _pSLList;
};

template<class T>
inline void Stack<T>::print()
{
	std::cout << "Stack[" << _pSLList->size() << "]: bottom → ";
	for (int i = 0; i < _pSLList->size(); i++)
	{
		std::cout << _pSLList->get_from(i) << " → ";
	}
	std::cout << "top" << std::endl;
}

#endif // STACK_HPP