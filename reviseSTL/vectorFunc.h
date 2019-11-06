#pragma once
#include <iostream>
#include <vector>

#define INITIAL_SIZE 5

//rend                       end
//↓    iterator              ↓
//  dwwwwwwwaaaaaaaaaddddddddd
// ↑                        ↑                  	
//begin                    rbegin

// output all elements in vector
template<typename T>
bool showVector(std::vector<T> list, int flag = 1)
{
	// auto for self-adaptive type
	// method 1
	switch ( flag )
	{

	case 1:
		// method 1
		for ( auto lIter = list.begin (); lIter != list.end (); ++lIter )
			std::cout << *lIter << "  ";
		std::cout << std::endl;
		break;
	case 2:
		// method 2
		for ( int i = 0; i < list.size(); i++ )
			std::cout << list.at (i) << " ";
		std::cout << std::endl;
		break;
	case 3:
		// method 3
		// element's data type is T. in this issue,it's double,not iterator or pointer. 
		for ( auto element : list )
			std::cout << element << " ";
		std::cout << std::endl;
		break;
	default:
		break;
	}

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
		tempIndex = std::find (++tempIndex, list.end(), 9.0);

		if ( tempIndex == list.end() )
			break;
		else
			tempIndex = list.erase (tempIndex - 1);
	}
	showVector (list);

	return true;
}


bool testVector ()
{
	// Initial doubleList with 9,9,9 ... 9.  
	std::vector<double> doubleList (INITIAL_SIZE, 9);
	std::vector<std::string> stringList{ "bei","jing","welcome","to","you" };

	// visit & change element in vector
	// .at() will check the validity of index to avoid out of range,while [] will not do it. 
	doubleList[1] = 3.14;
	doubleList.at (2) = 3.33;

	// add element into vector 
	// vector.size() will be 11 and vector.capcity will over 11,which is dependent by compiler. in VS2019, it's 15.  
	// emplace_back() is more effective than push_back() for no move
	doubleList.push_back (1);
	doubleList.emplace_back (5.14);

	// .size() return size_t type, or u can choose auto 
	size_t num1 = doubleList.size ();
	auto num2 = doubleList.size ();
	std::cout << num1 << std::endl;
	std::cout << doubleList.capacity () << std::endl;

	// reserve only change the capacity
	doubleList.reserve (11);
	std::cout << doubleList.size () << std::endl;
	std::cout << doubleList.capacity () << std::endl;

	// resize change the size and capacity.
	doubleList.resize (5);
	std::cout << doubleList.size () << std::endl;
	std::cout << doubleList.capacity () << std::endl;


	std::vector<double> verVector;
	reverseVector (doubleList, verVector);
	// insert sth behind the second element.
	insertVector (verVector, 2);
	delElement (verVector);

	return true;
}