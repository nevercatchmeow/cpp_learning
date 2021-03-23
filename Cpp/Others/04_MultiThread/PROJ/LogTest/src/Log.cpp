#include "Log.h"

#include <iostream>
#include <cstdlib>
#include <fstream>

Log::Log(int id, const std::string& filename) : m_id(id)
{
	std::cout << "Creat " << m_id << std::endl;
	m_f.open(filename.c_str(), std::fstream::out);
}

Log::~Log()
{
	std::cout << "Bye " << m_id << std::endl;
	//m_f.close();
}

void Log::logInfo(const std::string& info)
{
	std::cout << info;
	m_f << info;
	m_f.flush();
	// myLog为全局变量：
	// myLog为局部变量：flush立即写入（覆盖hello，最终为hakuno），否则按析构顺序写入(覆盖hakuno，最终为hello)。
}