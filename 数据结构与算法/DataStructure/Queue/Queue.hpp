/**
 * @file Queue.hpp
 * @author Kevin MRZ (5445029@gmail.com)
 * @brief Queue powered by SLList
 * @version 0.1
 * @date 2021-03-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

#include "../SLList/SLList.hpp"

template <class T>
class Queue
{
public:
	Queue() : _pSLList(new SLList<T>()) {}
	~Queue() {}

	bool isEmpty() const { return _pSLList->isEmpty(); }
	void clear() { _pSLList->clear(); }
	int size() { return _pSLList->size(); }

	T front() { return _pSLList->get_back(); }
	void enqueue(const T& data) { _pSLList->push_front(data); }
	T dequeue() { return _pSLList->pop_back(); }

	void print();

private:
	SLList<T>* _pSLList;
};

template<class T>
inline void Queue<T>::print()
{
	std::cout << "Queue[" << _pSLList->size() << "]: back → ";
	for (int i = 0; i < _pSLList->size(); i++)
	{
		std::cout << _pSLList->get_from(i) << " → ";
	}
	std::cout << "front" << std::endl;
}

#endif // QUEUE_HPP