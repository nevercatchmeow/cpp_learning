#pragma once

#include <iostream>

class Object
{
public:
	Object() { std::cout << "class Object ¹¹Ôì" << std::endl; }
	~Object() { std::cout << "class Object Îö¹¹" << std::endl; }
	int getValue() { return m_Value; }
private:
	int m_Value = 1;
};