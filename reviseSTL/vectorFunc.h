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

	// insert in specific position
	list.insert (list.begin () + index, temp.begin (), temp.end ());
	//  <=> list.insert (std::begin (list) + index, std::begin(temp), std::end(temp));
	showVector (list);


	// find all 9 and insert 8 front them
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

	while ( true )
	{
		tmpIter = std::find (tmpIter, list.end(), 9.0);
		if ( tmpIter == list.end () )
			break;
		tmpIter = list.insert (tmpIter, 8) + 2;
	}
	showVector (list);

	// find all 9 and insert 10 behind them

	auto tmpIter2 = list.begin ();
	while ( true )
	{
		tmpIter2 = std::find (tmpIter2, list.end (), 9.0);
		if ( tmpIter2 == list.end() )  
			break;
		else 
			tmpIter2 = list.insert (tmpIter2 + 1, 10);
		
	}
	showVector (list);
	
	return true;
} 

template<typename T>
bool delElement (std::vector<T>& list)
{

	// delete the last element in vector
	//list.pop_back ();
	list.erase (list.end () - 1);
	showVector (list);

	// delete the specific element in vector if dont care sequence
	size_t index = 3;
	std::swap ( *(std::begin (list) + index), *(std::end(list) - 1) );
	list.pop_back ();
	showVector (list);

	// delete the specific element 
	index = 1;
	list.erase (list.begin () + index);
	showVector (list);

	// delete some sequence elements from a to b , [a,b).
	list.erase (list.begin (), list.begin () + 1);
	showVector (list);

	// delete all elements if it front 9.
	

	

	auto tempIndex = list.begin ();
	while ( true ) 
	{
		tempIndex = std::find (tempIndex, list.end(), 9.0);

		if ( tempIndex == list.end() )
			break;
		else if ( tempIndex == list.begin() )
		{
			tempIndex = list.begin() + 1;
			continue;
		}
		else 
			tempIndex = list.erase (tempIndex - 1);

	}
	showVector (list);

	

	return true;
}