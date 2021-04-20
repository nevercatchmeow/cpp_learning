#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

static void autoValue();
static void autoPointer();
static void newVersionFor();
static void newVersionConstruct();
static void defaultInitValue();

int main()
{
	autoValue();
	autoPointer();
	newVersionFor();
	newVersionConstruct();
	defaultInitValue();

	return 0;
}

static void autoValue()
{
	// int age; // 重定义
	auto age = 10;
	auto name = std::string("Hakuno");
	auto height = 160.0f;
	auto weight = 72.0;
	std::cout << "age is type " << typeid(age).name() << std::endl;
	std::cout << "name is type " << typeid(name).name() << std::endl;
	std::cout << "height is type " << typeid(height).name() << std::endl;
	std::cout << "weight is type " << typeid(weight).name() << std::endl;
}

static void autoPointer()
{
	auto age = new int(10);
	auto name = "Hakuno"; // const char*
	auto height = new float(160.0f);
	auto weight = new double(72.0);
	std::cout << "age is type " << typeid(age).name() << std::endl;
	std::cout << "name is type " << typeid(name).name() << std::endl;
	std::cout << "height is type " << typeid(height).name() << std::endl;
	std::cout << "weight is type " << typeid(weight).name() << std::endl;
}

static void newVersionFor()
{
	int ids[] = { 1, 2, 3, 4, 5, 6 };

	std::cout << "old version for : ";
	for (int i = 0; i < sizeof(ids) / sizeof(int); i++)
	{
		std::cout << ids[i] << " ";

	}
	std::cout << std::endl;

	std::cout << "new version for : ";
	for (auto& v : ids)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	// 迭代器
	std::vector<int> group;
	for (int i = 0; i < 6; i++)
	{
		group.push_back(i);
	}
	for (std::vector<int>::const_iterator iter = group.begin();
		iter != group.end(); ++iter)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	for (size_t i = 0; i < group.size(); i++)
	{
		std::cout << group[i] << " ";
	}
	std::cout << std::endl;

}

static void newVersionConstruct()
{
	int avector[] = { 1, 2, 3 };
	std::vector<int> bv = { 1, 2, 3 };  // 新版构造器
}

class Object
{
public:
	Object() {} // 默认初始化。
	int getAge() const { return age; }
	std::string getName() const { return name; }

private:
	int age = 0;
	std::string name = "Hakuno";
};


static void defaultInitValue()
{
	Object a; 
	std::cout << a.getAge() << std::endl;
	std::cout << a.getName() << std::endl;
}