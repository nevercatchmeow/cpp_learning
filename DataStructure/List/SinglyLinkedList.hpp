#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <iostream>

template <class T>
class ChainNode
{
private:
    T _data;
    ChainNode<T> *_link;

public:
    friend Chain<T>;
};

template <class T>
class Chain
{
private:
    ChainNode<T> *_first;

public:
    Chain() : _first(nullptr) {}
    ~Chain();

    bool IsEmpty() const { return _first == nullptr; }
    int Length() const;
    bool Find(int index, T &data) const;
    int Search(const T &data) const;
    Chain<T> &Delete(int index, T &data);
    Chain<T> &Insert(int index, const T &data);
    void Output(ostream &out) const;
};

#endif