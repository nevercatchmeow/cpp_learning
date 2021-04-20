/**
 * @file Deque.hpp
 * @author Kevin MRZ (5445029@gmail.com)
 * @brief Deque powered by DLList
 * @version 0.1
 * @date 2021-03-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <iostream>

#include "../DLList/DLList.hpp"

template <class T>
class Deque
{
public:
	Deque() : _pDLList(new DLList<T>()) {}
	~Deque() {}

	bool isEmpty() const { return _pDLList->isEmpty(); }
	void clear() { _pDLList->clear(); }
	int size() { return _pDLList->size(); }

	T front() { return _pDLList->get_back(); }
	T back() { return _pDLList->get_front(); }
	void enqueue_front(const T& data) { _pDLList->push_back(data); }
	void enqueue_back(const T& data) { _pDLList->push_front(data); }
	T dequeue_front() { return _pDLList->pop_back(); }
	T dequeue_back() { return _pDLList->pop_front(); }

	void print();

private:
	DLList<T>* _pDLList;
};

template<class T>
inline void Deque<T>::print()
{
	std::cout << "Deque[" << _pDLList->size() << "]: back ↔ ";
	for (int i = 0; i < _pDLList->size(); i++)
	{
		std::cout << _pDLList->get_from(i) << " ↔ ";
	}
	std::cout << "front" << std::endl;
}

#endif // DEQUE_HPP