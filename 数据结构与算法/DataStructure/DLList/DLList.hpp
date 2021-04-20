/**
 * @file DLList.hpp
 * @author Kevin MRZ (5445029@gmail.com)
 * @brief Doubly linked list
 * @version 0.1
 * @date 2021-03-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP
 
#include <iostream>

template <class T>
class Node
{
public:
	Node(T data = NULL, Node *next = nullptr, Node *prev = nullptr) : _data(data), _next(next), _prev(prev) {}
	~Node() { _next = _prev = nullptr; }

public:
	T _data;
	Node<T> *_next;
	Node<T> *_prev;
};

template <class T>
class DLList
{
	using NODE = Node<T>;
	using PNODE = Node<T> *;

public:
	DLList();
	~DLList();

	void insert_after(int index, const T &data);
	void push_front(const T &data);
	void push_back(const T &data);

	T delete_from(int index);
	T pop_front();
	T pop_back();

	T get_from(int index);
	T get_front();
	T get_back();

	void delete_elem(const T &data);
	void set_elem(int index, const T &data);

	int size();
	bool isEmpty();
	bool isContains(const T &data);

	void clear();
	void print();
	void reverse();

private:
	Node<T> *_head;
	Node<T> *_tail;
	int _length;
};

template <class T>
inline DLList<T>::DLList() : _head(new Node<T>()),
							 _tail(new Node<T>()), _length(0)
{
	_head->_next = _tail;
	_head->_prev = nullptr;
	_tail->_next = nullptr;
	_tail->_prev = _head;
}

template <class T>
inline DLList<T>::~DLList()
{
	clear();
	delete _head;
	delete _tail;
}

template <class T>
inline void DLList<T>::insert_after(int index, const T &data)
{
	if (index < 0 || index > _length)
	{
		std::cerr << "Insert failed: Out Of Bounds!" << std::endl;
		return;
	}
	PNODE pCurrent = _head;
	for (int i = 0; i < index; i++, pCurrent = pCurrent->_next)
		;

	PNODE pNewNode = new NODE(data, pCurrent->_next, pCurrent);
	pCurrent->_next = pNewNode;

	_length++;
}

template <class T>
inline void DLList<T>::push_front(const T &data)
{
	insert_after(0, data);
}

template <class T>
inline void DLList<T>::push_back(const T &data)
{
	insert_after(_length, data);
}

template <class T>
inline T DLList<T>::delete_from(int index)
{
	if (index < 0 || index > _length - 1)
	{
		std::cerr << "Insert failed: Out Of Bounds!" << std::endl;
		return NULL;
	}

	PNODE pCurrent = _head;
	for (int i = 0; i < index; i++, pCurrent = pCurrent->_next)
		;
	PNODE pNext = pCurrent->_next;
	T data = pNext->_data;
	pCurrent->_next = pNext->_next;
	pNext->_next->_prev = pCurrent;
	delete pNext;
	_length--;

	return data;
}

template <class T>
inline T DLList<T>::pop_front()
{
	return delete_from(0);
}

template <class T>
inline T DLList<T>::pop_back()
{
	return delete_from(_length - 1);
}

template <class T>
inline void DLList<T>::delete_elem(const T &data)
{
	if (!_head || !_head->_next)
	{
		return;
	}

	PNODE pCurrent = _head;
	PNODE pNext = _head->_next;
	while (pNext)
	{
		if (pNext->_data == data)
		{
			pCurrent->_next = pNext->_next;
			pNext->_next->_prev = pCurrent;
			delete pNext;
			pNext = pCurrent->_next;
			_length--;
		}
		else
		{
			pCurrent = pNext;
			pNext = pNext->_next;
		}
	}
}

template <class T>
inline T DLList<T>::get_from(int index)
{
	if (index < 0 || index > _length - 1)
	{
		std::cerr << "Insert failed: Out Of Bounds!" << std::endl;
		return NULL;
	}

	PNODE pCurrent = _head->_next;
	for (int i = 0; i < index; i++, pCurrent = pCurrent->_next)
		;
	return pCurrent->_data;
}

template <class T>
inline T DLList<T>::get_front()
{
	return _head->_next->_data;
}

template <class T>
inline T DLList<T>::get_back()
{
	return _tail->_prev->_data;
}

template <class T>
inline void DLList<T>::set_elem(int index, const T &data)
{
	if (index < 0 || index > _length - 1)
	{
		std::cerr << "Insert failed: Out Of Bounds!" << std::endl;
		return;
	}
	PNODE pCurrent = _head->_next;
	for (int i = 0; i < index; i++, pCurrent = pCurrent->_next)
		;
	pCurrent->_data = data;
}

template <class T>
inline int DLList<T>::size()
{
	return _length;
}

template <class T>
inline bool DLList<T>::isEmpty()
{
	return _length == 0;
}

template <class T>
inline bool DLList<T>::isContains(const T &data)
{
	PNODE pCurrent = _head->_next;
	while (pCurrent)
	{
		if (pCurrent->_data == data)
		{
			return true;
		}
		pCurrent = pCurrent->_next;
	}
	return false;
}

template <class T>
inline void DLList<T>::clear()
{
	while (_head->_next != _tail)
	{
		pop_front();
	}
}

template <class T>
inline void DLList<T>::print()
{
	std::cout << "DLList[" << size() << "]: head ↔ ";
	PNODE pCurrent = _head->_next;
	while (pCurrent != _tail)
	{
		std::cout << pCurrent->_data << " ↔ ";
		pCurrent = pCurrent->_next;
	}
	std::cout << "tail" << std::endl;
}

template <class T>
inline void DLList<T>::reverse()
{
	if (!_head || !_head->_next)
	{
		return;
	}

	_tail = _head;
	PNODE pTempHead = _head;
	PNODE pPrev = nullptr;
	PNODE pNewNode = nullptr;

	while (pTempHead)
	{
		pNewNode = pTempHead->_next;
		pTempHead->_next = pPrev;
		pPrev = pTempHead;
		pTempHead = pNewNode;
	}
	_head = pPrev;
}

#endif // DOUBLY_LINKED_LIST_HPP
