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
	auto Iter = list.insert (list.begin () + index, temp.begin (), temp.end ());
	showVector (list);
	return true;
}