/**
 * @file Deque.hpp
 * @author Kevin MRZ (5445029@gmail.com)
 * @brief BSTree
 * @version 0.1
 * @date 2021-03-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef BSTREE_HPP
#define BSTREE_HPP

#include <iostream>

template <class T>
class BSTNode
{
public:
	BSTNode(T data, BSTNode<T> *left = nullptr, BSTNode<T> *right = nullptr) : _data(data), _left(left), _right(right) {}

public:
	T _data;
	BSTNode<T>* _left;
	BSTNode<T>* _right;
};

template <class T>
class BSTree
{
private:
	BSTNode<T>* _root;
	int _size;

	BSTNode<T>* add(BSTNode<T>* node, T data);
	BSTNode<T>* remove(BSTNode<T>* node, T data);
	bool isContains(BSTNode<T>* node, T data);
	void preOrder(BSTNode<T>* node);
	void inOrder(BSTNode<T>* node);
	void postOrder(BSTNode<T>* node);

public:
	BSTree() : _root(nullptr), _size(0) {}
	~BSTree() {}

	void add(T data);
	void remove(T data);
	bool isContains(T data);
	void preOrder();
	void inOrder();
	void postOrder();

	bool isEmpty() { return _root == nullptr; }
	int size() { return _size; }
};

template<class T>
inline BSTNode<T>* BSTree<T>::add(BSTNode<T>* node, T data)
{
	if (node == nullptr)
	{
		_size++;
		return new BSTNode<T>(data);
	}
	else if (data < node->_data)
	{
		node->_left = add(node->_left, data);
	}
	else if (data > node->_data)
	{
		node->_right = add(node->_right, data);
	}
	return node;
}

template<class T>
inline BSTNode<T>* BSTree<T>::remove(BSTNode<T>* node, T data)
{
	if (node == nullptr)
	{
		return node;
	}
	if (data < node->_data)
	{
		node->_left = remove(node->_left, data);
	}
	else if (data > node->_data)
	{
		node->_right = remove(node->_right, data);
	}
	else if (data == node->_data)
	{
		if (node->_left == nullptr)
		{
			BSTNode<T>* rightNode = node->_right;
			delete node;
			_size--;
			return rightNode;
		}
		else if (node->_right == nullptr)
		{
			BSTNode<T>* leftNode = node->_left;
			delete node;
			_size--;
			return leftNode;
		}
		else
		{
			BSTNode<T>* minNode = node->_right;
			for (; minNode->_left; minNode = minNode->_left);
			node->_data = minNode->_data;
			node->_right = remove(node->_right, minNode->_data);
			return node;
		}
	}
	return node;
}

template<class T>
inline bool BSTree<T>::isContains(BSTNode<T>* node, T data)
{
	if (node == nullptr)
	{
		return false;
	}
	if (data == node->_data)
	{
		return true;
	}
	else if (data < node->_data)
	{
		return isContains(node->_left, data);
	}
	else
	{
		return isContains(node->_right, data);
	}
}

template<class T>
inline void BSTree<T>::preOrder(BSTNode<T>* node)
{
	if (node == nullptr)
	{
		return;
	}
	std::cout << node->_data << " ";
	preOrder(node->_left);
	preOrder(node->_right);
}

template<class T>
inline void BSTree<T>::inOrder(BSTNode<T>* node)
{
	if (node == nullptr)
	{
		return;
	}
	inOrder(node->_left);
	std::cout << node->_data << " ";
	inOrder(node->_right);
}

template<class T>
inline void BSTree<T>::postOrder(BSTNode<T>* node)
{
	if (node == nullptr)
	{
		return;
	}
	postOrder(node->_left);
	postOrder(node->_right);
	std::cout << node->_data << " ";
}

template<class T>
inline void BSTree<T>::add(T data)
{
	_root = add(_root, data);
}

template<class T>
inline void BSTree<T>::remove(T data)
{
	_root = remove(_root, data);
}

template<class T>
inline bool BSTree<T>::isContains(T data)
{
	return isContains(_root, data);
}

template<class T>
inline void BSTree<T>::preOrder()
{
	std::cout << "BSTree[" << this->size() << "]:  preOrder → ";
	preOrder(_root);
	std::cout << std::endl;
}

template<class T>
inline void BSTree<T>::inOrder()
{
	std::cout << "BSTree[" << this->size() << "]:  inOrder → ";
	inOrder(_root);
	std::cout << std::endl;
}

template<class T>
inline void BSTree<T>::postOrder()
{
	std::cout << "BSTree[" << this->size() << "]:  postOrder → ";
	postOrder(_root);
	std::cout << std::endl;
}



#endif // BSTREE_HPP