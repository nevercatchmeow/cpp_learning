#pragma once

#include <iostream>
#include <set>
#include <string>
#include <algorithm>

/*
================================================================================
==>set：（二叉树结构）。
--------------------------------------------------------------------------------
插入元素自动排序（从小到大），且唯一。
增删查复杂度：O(logn)。
元素必须支持严格的若顺序。
（1） x < y == true , y < x == false 
（2） x < y == true , y < z == true , x < z == true 
（3） x < x == false 
（4） a == b , b == c , c == a
不能改变元素的值。

辅助类：

================================================================================
*/

class Player;
struct CompareAge;
struct CompareName;
void compareTest();

static void setTest()
{
	using Group = std::set<float>;

	Group a;
	Group b = a;
	Group c(a);
	Group d(c.begin(), c.end());
	Group e({ 1.0f, 2.0f, 3.0f });
	Group f = { 1.0f, 2.0f, 3.0f };		// 列表初始化

	d.empty();
	d.size();
	d.max_size();

	auto keycomp = c.key_comp();
	auto valuecomp = c.value_comp();

	b = e;

	b.swap(a);
	std::swap(a, b);

	// 迭代器
	a.begin();							// 迭代器
	a.end();
	a.cbegin();							// 常量迭代器：不能修改指向的元素值
	a.cend();
	a.rbegin();							// 反向迭代器
	a.rend();
	a.crbegin();						// 常量反向迭代器
	a.crend();

	auto iterBegin = a.begin();

	// 算法
	auto num = a.count(1.0f); // 统计集合中某个元素的个数。
	auto findIter = a.find(1.0f);	// 查找元素中某个元素的位置，返回迭代器。

	if (findIter == a.end())
	{
		// 未找到
	}
	else
	{
		*findIter;
	}

	auto lower = a.lower_bound(1.0f); // 返回第一个不小于该元素的迭代器，不存在则返回end()
	if (lower != a.end())
	{
		if (*lower == 1.0f)
		{
			// has 1.0f
		}
	}
	auto high = a.upper_bound(1.0f); // 返回第一个大于该元素的迭代器，不存在则返回end()
	auto range = a.equal_range(1.0f); // 二分查找，return pair

	auto eraseIter = b.erase(b.begin());
	eraseIter = b.erase(b.begin(), b.end());

	auto state = b.insert(100.0f); // return pair
	b.insert(e.begin(), e.end());	// return void
	b.emplace(10.0f); // 直接构造，避免两次构造（初始构造+拷贝构造）

	b.emplace_hint(b.end(), 50.0f); // 传入键值对

	for (auto v : b)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	compareTest();
}

/*
================================================================================
定义set元素排序规则：
================================================================================
*/

class Player
{
public:
	Player(int age, std::string name) : m_age(age), m_name(name) { std::move(age); }
	~Player() {}
	const int& getAge() const { return m_age; }
	const std::string& getName() const { return m_name; }
	void print() const { std::cout << m_age << " : " << m_name << std::endl; }
	void changeAge(int newAge) { m_age = newAge; }
	bool operator == (Player const& rhs) const
	{
		return m_age == rhs.m_age && m_name == rhs.m_name;
	}

private:
	int m_age;
	std::string m_name;
};

struct CompareAge
{
	template<typename T>
	bool operator() (const T& t1, const T& t2) const
	{
		return t1.getAge() < t2.getAge();
	}
};

struct CompareName
{
	template<typename T>
	bool operator() (const T& t1, const T& t2) const
	{
		return t1.getName() < t2.getName();
	}
};

void compareTest()
{
	Player a(35, "Yasuo");
	Player b(7, "Teemo");
	Player c(19, "Lux");

	std::cout << "Order by Age:\n";
	using Group1 = std::set<Player, CompareAge>;
	Group1 g1;
	g1.insert(a);
	g1.insert(b);
	g1.insert(c);

	for(auto& v : g1)
	{
		v.print();
	}

	auto ageIter = g1.begin();
	//(*ageIter).changeAge(30);

	std::cout << "Order by Name:\n";
	using Group2 = std::set<Player, CompareName>;
	Group2 g2;
	g2.insert(a);
	g2.insert(b);
	g2.insert(c);

	for (auto& v : g2)
	{
		v.print();
	}

	Player aa(19, "Lux");
	// set自身提供find查找规则：构造时传入规则（如CompareName）
	auto iter = g2.find(aa);
	if (iter == g2.end())
	{
		std::cout << "未找到" << std::endl;
	}
	else
	{
		std::cout << "已找到" << std::endl;
	}

	// 算法库的查找规则：根据重载==运算符。
	iter = std::find(g2.begin(), g2.end(), aa);

}