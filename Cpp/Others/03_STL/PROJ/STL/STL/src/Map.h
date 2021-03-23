#pragma once

#include <iostream>
#include <map>
#include <string>
#include <algorithm>

/*
================================================================================
==>map：（二叉树型结构）。
--------------------------------------------------------------------------------


================================================================================
*/

// 查找模板函数
template <class Map>
typename Map::mapped_type get_default
(const Map& map, const typename Map::key_type& key, const typename Map::mapped_type& dflt = typename Map::mapped_type())
{
	auto pos = map.find(key);
	return (pos != map.end() ? pos->second : dflt);
}


static void mapTest()
{
	using Group = std::map<int, std::string>;

	Group a;
	Group b = a;
	Group c(a);
	Group d(c.begin(), c.end());
	Group e({ { 1, "a" }, { 2, "b" }, { 3, "c" } });

	d.empty();
	d.size();
	d.max_size();

	auto keycomp = c.key_comp();
	auto valuecomp = c.value_comp();

	b = e;

	b.swap(a);
	std::swap(a, b);

	a.begin();
	a.end();
	a.cbegin();
	a.cend();
	a.rbegin();
	a.rend();
	a.crbegin();
	a.crend();
	auto iterBegin = a.begin();

	// 算法
	auto num = a.count(1);
	auto findIter = a.find(1);
	if (findIter == a.end())
	{
		//not found
	}
	else
	{
		// map的迭代器解引用 为 const pair
		const std::pair<int, std::string>& obj = *findIter;
	}

	auto lower = a.lower_bound(1);
	auto high = a.upper_bound(1);
	auto range = a.equal_range(1); // return std::make_pair(a.lower_bound(1), a.upper_bound(1));
	
	auto eraseIter = b.erase(b.begin());
	eraseIter = b.erase(b.begin(), b.end());

	auto state = b.insert(std::make_pair(100, "Good")); // return pair<Iter, bool>
	b.insert(c.begin(), c.end());

	b.emplace(std::make_pair(10, "has it"));
	b.emplace(11, std::string("again")); // b.emplace(std::pair<const int , std::string>(11, std::string("again"));
	b.emplace(12, "third"); // b.emplace(std::pair<const int , std::string>(11, "again");
	b.emplace_hint(b.end(), 13, "hhh");

	auto& info = b[10]; // 需要提供默认构造。
	
	try
	{
		auto& findInfo = b.at(10); // const
	}
	catch (const std::exception&)
	{
		// ...
	}

	findIter = b.find(10);
	if (findIter != std::end(b))
	{
		auto& v = (*findIter).second;
	}
	else
	{

	}

	auto INFO = get_default(b, 10);
	if (INFO.empty())
	{

	}
	else
	{

	}
}
