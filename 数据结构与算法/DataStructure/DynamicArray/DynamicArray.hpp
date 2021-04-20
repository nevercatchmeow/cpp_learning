/**
 * @file DynamicArray.hpp
 * @author Kevin MRZ (5445029@gmail.com)
 * @brief DynamicArray
 * @version 0.1
 * @date 2021-03-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <iostream>

template <class T>
class DynamicArray
{
public:
	DynamicArray(int length = 8);
	~DynamicArray();

	bool isEmpty() { return _size == 0; }
	int size() { return _size; }
	int capacity() { return _capacity; }
	void print();

	void insert_to(int index, const T& elem);
	void insert_first(const T& elem){ insert_to(0, elem); }
	void insert_last(const T& elem){ insert_to(_size, elem); }

	T delete_from(int index);
	T delete_first(){ return delete_from(0); }
	T delete_last(){ return delete_from(_size - 1); }

	T get(int index) { return _data[index]; }
	T get_first() { return _data[0]; }
	T get_last() { return _data[_size - 1]; }

	void clear();
	void set(int index, const T& elem);
	int find(const T& elem);
	bool isContains(const T& elem);
	void delete_elem(const T& elem);

private:
	T* _data;
	int _capacity;
	int _size;
	void resize(int newCapacity);
};

template<class T>
inline DynamicArray<T>::DynamicArray(int length)
{
	if (length < 8)
	{
		_capacity = 8;
	}
	_data = new T[_capacity = length];
	_size = 0;
}

template<class T>
inline DynamicArray<T>::~DynamicArray()
{
	delete _data;
	_data = nullptr;
}

template<class T>
inline void DynamicArray<T>::print()
{
	std::cout << "DynamicArray[" << this->size() << "/" << this->capacity() << "]: [";
	for (int i = 0; i < _size; i++)
	{
		std::cout << _data[i];
		if (i != _size - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "]" << std::endl;
}

template<class T>
inline void DynamicArray<T>::resize(int newCapacity)
{
	T* pNewData = new T[newCapacity];
	for (int i = 0; i < _size; i++)
	{
		pNewData[i] = _data[i];
	}
	delete[] _data;
	_data = pNewData;
	_capacity = newCapacity;
}

template<class T>
inline void DynamicArray<T>::insert_to(int index, const T& elem)
{
	if (index < 0 || index > _size)
	{
		std::cerr << "Insert failed: Out Of Bounds!" << std::endl;
		return;
	}
	if (_size >= (_capacity * 0.75))
	{
		resize(_capacity << 1);
	}
	for (int i = _size; i > index; i--)
	{
		_data[i] = _data[i - 1];
	}
	_data[index] = elem;
	_size++;
}

template<class T>
inline T DynamicArray<T>::delete_from(int index)
{
	if (index < 0 || index > _size)
	{
		std::cerr << "Insert failed: Out Of Bounds!" << std::endl;
		return NULL;
	}
	T res = _data[index];
	for (int i = index; i < _size; i++)
	{
		_data[i] = _data[i + 1];
	}
	_size--;
	if (_size < (_capacity >> 2))
	{
		if (_capacity <= 8)
		{
			return res;
		}
		resize(_capacity >> 1);
	}
	return res;
}

template<class T>
inline void DynamicArray<T>::clear()
{
	while (_size)
	{
		delete_last();
	}
}

template<class T>
inline void DynamicArray<T>::set(int index, const T& elem)
{
	if (index < 0 || index > _size)
	{
		std::cerr << "Insert failed: Out Of Bounds!" << std::endl;
		return;
	}
	_data[index] = elem;
}

template<class T>
inline int DynamicArray<T>::find(const T& elem)
{
	for (int i = 0; i < _size; i++)
	{
		if (_data[i] == elem)
		{
			return i;
		}
	}
	return -1;
}

template<class T>
inline bool DynamicArray<T>::isContains(const T& elem)
{
	for (int i = 0; i < _size; i++)
	{
		if (_data[i] == elem)
		{
			return true;
		}
	}
	return false;
}

template<class T>
inline void DynamicArray<T>::delete_elem(const T& elem)
{
	for (int i = 0; i < _size; i++)
	{
		while (_data[i] == elem)
		{
			delete_from(i);
		}
	}
}

#endif // DYNAMIC_ARRAY_HPP