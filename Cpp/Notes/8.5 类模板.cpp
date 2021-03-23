#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

/*
--------------------------------------------------
类模板：
1.类模板中指定默认参数。
2.类模板中无法使用自动类型推导，需手动指定。

--------------------------------------------------
*/

//类模板中指定默认参数：（指定m_Age默认参数类型为int）
template<class NAMETYPE, class AGETYPE = int>
class Hero
{
public:
	Hero(NAMETYPE name, AGETYPE age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void show()
	{
		cout << "Name:" << this->m_Name << " , Age:" << this->m_Age << endl;
	}

	NAMETYPE m_Name;
	AGETYPE m_Age;
};

void test()
{
	Hero<string > h("Teemo", 7 );

	h.show();
}

int main()
{
	test();

	system("pause");
	return 0;
}