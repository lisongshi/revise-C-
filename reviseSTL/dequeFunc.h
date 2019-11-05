#pragma once
#include <iostream>
#include <deque>
#include <algorithm>

// deque Double Ended Queue 双端队列.
// 具有队列和栈的特点，数据从双端队列两端 A and B添加或弹出.
// 若令A端只能插入，B端只能弹出，则为一个标准队列
// 若令A端不能插入与弹出， B端可插入可弹出，则为一个标准栈

#define DEQUE_SIZE 5

template<typename T>
bool showDeque (const std::deque<T> deque_, int flag_ = 1)
{
	if ( flag_ == 1 ) 
	{
		for ( auto element : deque_ )
			std::cout << element << " ";
		std::cout << std::endl;
	}
	else if ( flag_ == 2 )
	{
		// reverse travel 
		for ( auto Iter = deque_.rbegin (); Iter != deque_.rend (); Iter++ )
			std::cout << *Iter << " ";
		std::cout << std::endl;
	}
	else 
	{
		for ( size_t i = 0; i < deque_.size (); i++ )
			std::cout << deque_.at (i) << " ";
		std::cout << std::endl;
	}
	return true;
}

template<typename T>
bool addElement (std::deque<T>& deque_)
{
	// show the element in front and back.
	std::cout << deque_.back () << std::endl;
	std::cout << deque_.front () << std::endl;
	deque_.push_back (11.0);
	deque_.push_front (-5.0);
	showDeque (deque_);
	return true;
}

template<typename T>
bool insertElement (std::deque<T>& deque_)
{
	std::deque<T> tmpDeque{ 9.2, 6.7, 14.2 };
	// position, begin, end . type : iterator
	deque_.insert (deque_.begin () + 2, tmpDeque.begin(), tmpDeque.end () - 1);
	showDeque (deque_);
	return true;
}

bool cmp (double a, double b)
{
	return a > b;
} 

template<typename T>
bool sortDeque (std::deque<T>& deque_)
{
	// 加入cmp从大到小排序，默认从小到大. 需要algorithm.h
	sort (deque_.begin(), deque_.end(), cmp);
	showDeque (deque_);
	return true;
}


bool testDeque ()
{
	// initialize a deque
	std::deque<double> doubleDeque(DEQUE_SIZE, 1.5);
	std::deque<std::string> stringDeque{ "hello", "world","!" };
	//showDeque (stringDeque);
	addElement (doubleDeque);
	insertElement (doubleDeque);
	sortDeque (doubleDeque);
	return true;
}