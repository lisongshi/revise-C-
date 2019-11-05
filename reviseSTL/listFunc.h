#pragma once
#include <iostream>
#include <list>
//#include <algorithm>

#define LIST_SIZE 5

template<typename T>
bool showList (const std::list<T> list_, int flag_ = 1)
{
	// .at(index) is unavailable for list
	if ( flag_ == 1 ) 
	{
	for ( auto element : list_ )
		std::cout << element << " ";
	std::cout << std::endl;
	}
	else
	{
	for ( auto Iter = list_.begin (); Iter != list_.end (); Iter++ )
		std::cout << *Iter << " ";
	std::cout << std::endl;
	}
	return true;
}

template<typename T>
bool insertNode (std::list<T> & list_)
{
	std::cout << *list_.begin() << std::endl;
	// insert node at two end
	list_.push_back (0.9);
	list_.push_front (10.1);
	showList (list_);

	// Iterator 辅助函数,list中迭代器可++,--. 但无法 + - 整型
	// 利用advance 移动Iterator
	int index = 1;
	auto tmpIter = list_.begin ();
	std::advance (tmpIter, index);
	list_.insert (tmpIter, 11.4);

	index = -2;
	auto tmpIter2 = list_.end ();
	std::advance (tmpIter2, index);
	list_.insert (tmpIter2, -7.7);
	showList (list_);

	std::swap ( *list_.begin(), *(--list_.end ()) );
	showList (list_);

	std::list<T> tmpList{ 5.2, 6.3 };
	list_.insert (++list_.begin(), tmpList.begin (), tmpList.end ());
	showList (list_);
	return true;
}

bool testList ()
{
	double tmpArray[LIST_SIZE] = { 3.1, 1.2, 4.2, -0.5, 7.5 };
	std::list<double> doubleList (tmpArray, tmpArray + 5);
	insertNode (doubleList);
	return true;
}