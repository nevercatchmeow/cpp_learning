/**
 * @file SLList.hpp
 * @author Kevin MRZ (5445029@gmail.com)
 * @brief Singly linked list
 * @version 0.1
 * @date 2021-03-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <iostream>

template <class T>
class Node {
public:
	Node(T data = NULL, Node* next = nullptr) : _data(data), _next(next) {}
	~Node() { _next = nullptr; }
public:
	T _data;
	Node<T>* _next;
};

template<class T>
class SLList
{
	using NODE = Node<T>;
	using PNODE = Node<T>*;
public:
	SLList() :_head(new Node<T>()), _length(0) {}
	~SLList();

	void insert_after(int index, const T& data);
	void push_front(const T& data);
	void push_back(const T& data);

	T delete_from(int index);
	T pop_front();
	T pop_back();

	T get_from(int index);
	T get_front();
	T get_back();

	void delete_elem(const T& data);
	void set_elem(int index, const T& data);

	int size();
	bool isEmpty();
	bool isContains(const T& data);

	void clear();
	void print();
	void reverse();


private:
	Node<T>* _head;
	int _length;
};

template<class T>
inline SLList<T>::~SLList()
{
	clear();
}

template<class T>
inline void SLList<T>::insert_after(int index, const T& data)
{
	if (index < 0 || index > _length)
	{
		std::cerr << "Insert failed: Out Of Bounds!" << std::endl;
		return;
	}
	PNODE pCurrent = _head;
	for (int i = 0; i < index; i++, pCurrent = pCurrent->_next);
	pCurrent->_next = new NODE(data, pCurrent->_next);
	_length++;
}

template<class T>
inline void SLList<T>::push_front(const T& data)
{
	insert_after(0, data);
}

template<class T>
inline void SLList<T>::push_back(const T& data)
{
	insert_after(_length, data);
}

template<class T>
inline T SLList<T>::delete_from(int index)
{
	if (index < 0 || index > _length - 1)
	{
		std::cerr << "Insert failed: Out Of Bounds!" << std::endl;
		return NULL;
	}

	PNODE pCurrent = _head;
	for (int i = 0; i < index; i++, pCurrent = pCurrent->_next);
	PNODE pNext = pCurrent->_next;
	T data = pNext->_data;
	pCurrent->_next = pNext->_next;
	delete pNext;
	_length--;

	return data;
}

template<class T>
inline T SLList<T>::pop_front()
{
	return delete_from(0);
}

template<class T>
inline T SLList<T>::pop_back()
{
	return delete_from(_length - 1);
}

template<class T>
inline void SLList<T>::delete_elem(const T& data)
{
	if (!_head || !_head->_next) { return; }

	PNODE pCurrent = _head;
	PNODE pNext = _head->_next;
	while (pNext)
	{
		if (pNext->_data == data)
		{
			pCurrent->_next = pNext->_next;
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

template<class T>
inline T SLList<T>::get_from(int index)
{
	if (index < 0 || index > _length - 1)
	{
		std::cerr << "Insert failed: Out Of Bounds!" << std::endl;
		return NULL;
	}

	PNODE pCurrent = _head->_next;
	for (int i = 0; i < index; i++, pCurrent = pCurrent->_next);
	return pCurrent->_data;
}

template<class T>
inline T SLList<T>::get_front()
{
	return get_from(0);
}

template<class T>
inline T SLList<T>::get_back()
{
	return get_from(_length - 1);
}

template<class T>
inline void SLList<T>::set_elem(int index, const T& data)
{
	if (index < 0 || index > _length - 1)
	{
		std::cerr << "Insert failed: Out Of Bounds!" << std::endl;
		return;
	}
	PNODE pCurrent = _head->_next;
	for (int i = 0; i < index; i++, pCurrent = pCurrent->_next);
	pCurrent->_data = data;
}

template<class T>
inline int SLList<T>::size()
{
	return _length;
}

template<class T>
inline bool SLList<T>::isEmpty()
{
	return _length == 0;
}

template<class T>
inline bool SLList<T>::isContains(const T& data)
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

template<class T>
inline void SLList<T>::clear()
{
	while (_head->_next)
	{
		pop_front();
	}
}

template<class T>
inline void SLList<T>::print()
{
	std::cout << "SLList[" << size() << "]: head → ";
	PNODE pCurrent = _head->_next;
	while (pCurrent)
	{
		std::cout << pCurrent->_data << " → ";
		pCurrent = pCurrent->_next;
	}
	std::cout << "null" << std::endl;
}

template<class T>
inline void SLList<T>::reverse()
{
	if (!_head || !_head->_next) { return; }
	PNODE pCurrent = _head->_next;
	PNODE pNext = _head->_next;
	_head->_next = nullptr;

	while (pCurrent)
	{
		pNext = pCurrent->_next;
		pCurrent->_next = _head->_next;
		_head->_next = pCurrent;
		pCurrent = pNext;
	}
}

#endif
