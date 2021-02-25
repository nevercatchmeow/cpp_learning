#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#include <iostream>

using namespace std;

const int initialLen = 8; // 初始容量

class Array
{
private:
	int *m_data;	//数组数据
	int m_size;		//数组大小
	int m_capacity; //数组容量

public:
	Array();
	Array(int len);

	void reserve(int len);		//动态容量

	void insert(int index, int num); //添加元素
	void insertToFirst(int num);		//添加至头部
	void insertToLast(int num);		//添加至尾部

	int erase(int index);		//移除元素
	int eraseFromFirst();		//移除首元素
	int eraseFromLast();		//移除尾元素
	void eraseElement(int num);	//移除指定数据

	void set(int index, int num);	//设置数据
	int get(int index);			//获取数据
	int indexOf(int num);			//获取数据索引
	bool isContains(int num);		//是否包含指定数据

	int capacity();
	int size();
	bool isEmpty();
	void print();
};

#endif // DYNAMIC_ARRAY