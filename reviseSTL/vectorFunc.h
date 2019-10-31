#pragma once
#include <iostream>
#include <vector>


// output all elements in vector
template<typename T>
bool showVector(std::vector<T> list)
{
	
	// auto for self-adaptive type
	for (auto lIter = list.begin(); lIter != list.end(); ++lIter)
		std::cout << *lIter << "  ";
	std::cout<< std::endl;
	return true;

}

// & for reference
template<typename T>
bool reverseVector (std::vector<T> oldList, std::vector<T> & verList)
{
	
	for ( auto Iter = oldList.rbegin (); Iter != oldList.rend (); ++Iter )
	{
		verList.push_back (*Iter);
	}
	showVector (verList);
	return true;

}

template<typename T>
bool insertVector (std::vector<T> & list, int index)
{
	std::vector<T> temp = { 2.5, 6.8, 0.3 };
	list.insert (list.begin () + index, temp.begin (), temp.end ());
	//  <=> list.insert (std::begin (list) + index, std::begin(temp), std::end(temp));
	showVector (list);


	// find all 9 and insert 8 behind them
	/*

	采取如下写法，由于长度改变，vector 可能会重新分配内存，从而会导致if判断中的迭代器end()失效。
	要解决问题1.要么一开始给vector设置足够大的内存空间，2.要么在循环 内部！ 修复已经失效的迭代器。
	同时应当注意当长度改变时不能使用++ -- 等写法，道理同上。
	另外，find insert返回的都是找到的值以及插入的当前值位置。
	由于 8 插入 9 的前面因此迭代器指向 8 要跳过当前的 9 ， 迭代器需要 + 2。
	
	auto tmpIter = list.begin ();
	while ( tmpIter != list.end() )
	{
		tmpIter = std::find (tmpIter, std::end(list), 9.0);
		tmpIter = list.insert (tmpIter, 8) + 2;	
	}
	*/

	auto tmpIter = list.begin ();
	auto endFlag = list.end ();
	while ( tmpIter != endFlag )
	{
		tmpIter = std::find (tmpIter, list.end(), 9.0);
		tmpIter = list.insert (tmpIter, 8) + 2;
		endFlag = list.end ();
	}
	showVector (list);

	// find all 9 and insert 10 after them

	auto tmpIter2 = list.begin ();
	auto endFlag2 = list.end ();
	while ( true )
	{
		tmpIter2 = std::find (tmpIter2, list.end (), 9.0);
		if ( tmpIter2 == endFlag2 )  
			break;
		else 
		{
			tmpIter2 = list.insert (tmpIter2 + 1, 10);
			endFlag2 = std::end (list);
		}
		
	}
	showVector (list);
	

	return true;
} 