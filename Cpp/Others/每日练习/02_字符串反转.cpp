#include <iostream>
#include <string>
#include <algorithm>

//反转字符串：三种方法。

//string对象与C风格字符串的转换。
void stringToCString()
{
	char cstr[] = "hello_world";
	std::string str = "hello world";
	strcpy_s(cstr, str.c_str());
	std::cout << cstr << std::endl;
}

//C风格字符串
void reverseString()
{
	char c_str[] = "[ abc 123 456 ]";
	int i = 0;
	int j = strlen(c_str) - 1;
	char s_tmp = NULL;
	while (i < j)
	{
		s_tmp = c_str[i];
		c_str[i++] = c_str[j];
		c_str[j--] = s_tmp;
	}
	std::cout << c_str << std::endl;
}

//C风格字符串，使用函数_strrev();
void reverseString1()
{
	char c_str[] = "[ abc 123 456 ]";
	_strrev(c_str);
	std::cout << c_str << std::endl;
}

//string对象，使用algorithm库函数reverse();
void reverseString2()
{
	std::string str = "[ abc 123 456 ]";
	std::reverse(str.begin(), str.end());
	std::cout << str << std::endl;
}

int main()
{
	reverseString();
	//reverseString1();
	//reverseString2();

	return 0;
}