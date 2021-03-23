#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>

class Log
{
public:
	Log(int id, const std::string& filename);
	~Log();
	void logInfo(const std::string& info);

private:
	int m_id;
	std::fstream m_f;
};