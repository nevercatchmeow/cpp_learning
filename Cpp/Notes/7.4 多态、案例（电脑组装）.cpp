#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
--------------------------------------------------
电脑组装：
	虚基类：
		1.CPU
		2.VideoCard
		3.Memory
	派生类：
		1.Intel派生类
		2.Lenovo派生类
	Computer类：
		
--------------------------------------------------
*/

//基类
class CPU
{
public:
	virtual void calculate() = 0;
};

class VideoCard
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

class Computer
{
public:
	Computer(CPU * cpu, VideoCard * vc, Memory * mem)
	{
		this->m_cpu = cpu;
		this->m_vc = vc;
		this->m_mem = mem;
	}

	void dowork()
	{
		this->m_cpu->calculate();
		this->m_vc->display();
		this->m_mem->storage();
	}

	~Computer()
	{
		if (this->m_cpu)
		{
			delete this->m_cpu;
			this->m_cpu = NULL;
		}

		if (this->m_vc)
		{
			delete this->m_vc;
			this->m_vc = NULL;
		}

		if (this->m_mem)
		{
			delete this->m_mem;
			this->m_mem = NULL;
		}
	}

private:
	CPU * m_cpu;
	VideoCard * m_vc;
	Memory * m_mem;
};

//Intel派生类
class intelCPU :public CPU
{
	void calculate()
	{
		cout << "英特尔CPU开始工作..." << endl;
	}
};

class intelVideoCard :public VideoCard
{
	void display()
	{
		cout << "英特尔显卡开始工作..." << endl;
	}
};

class intelMemory :public Memory
{
	void storage()
	{
		cout << "英特尔内存开始工作..." << endl;
	}
};

//Lenovo派生类
class lenovoCPU :public CPU
{
	void calculate()
	{
		cout << "联想CPU开始工作..." << endl;
	}
};

class lenovoVideoCard :public VideoCard
{
	void display()
	{
		cout << "联想显卡开始工作..." << endl;
	}
};

class lenovoMemory :public Memory
{
	void storage()
	{
		cout << "联想内存开始工作..." << endl;
	}
};

void test()
{
	cout << "第一台电脑组成：" << endl;
	CPU * intelCpu = new intelCPU;
	VideoCard * lenovoVC = new lenovoVideoCard;
	Memory * lenovoMem = new lenovoMemory;

	Computer c1(intelCpu, lenovoVC, lenovoMem);
	c1.dowork();

	cout << "第二台电脑组成：" << endl;
	CPU * intelCpu2 = new lenovoCPU;
	VideoCard * lenovoVC2 = new intelVideoCard;
	Memory * lenovoMem2 = new intelMemory;

	Computer c2(intelCpu2, lenovoVC2, lenovoMem2);
	c2.dowork();
}

int main() {
	test();

	system("pause");
	return EXIT_SUCCESS;
}
