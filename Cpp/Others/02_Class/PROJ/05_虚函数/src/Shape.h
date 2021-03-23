#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

using namespace std;

class Shape
{
public:
	Shape();
	virtual ~Shape(); // virtual被继承到子类析构函数。
	virtual double calcArea(); // virtual被继承到子类calcArea()函数。
};

#endif

