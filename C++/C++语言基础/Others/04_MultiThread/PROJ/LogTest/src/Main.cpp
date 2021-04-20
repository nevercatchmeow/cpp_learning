#include <iostream>

#include "Log.h"

static Log myLog(1, "log.log"); // static置于函数体外，实际写入内容：hello hakuno

void test1()
{
	// 获取文件指针头，写向文件的内容实际在缓存中，尚未真正写入到文件。
	//static Log myLog(1, "log.log"); // static 对象在main结束后再析构（先构造的最后析构）。
	myLog.logInfo("hello ");
}

void test2()
{
	// 获取文件指针头（与test1获取的文件指针头相同），导致hello被hakuno覆盖。
	//static Log myLog(2, "log.log");
	myLog.logInfo("hakuno ");
}

int main()
{
	test1();
	test2();
	// Choose answer：
	//		hello			局部myLog	
	//		hakuno			局部myLog + flush
	//		hello hakuno	全局myLog + flush
	//		hakuno hello	无此情况。
	std::cout << "\nBye Main " << std::endl;
}