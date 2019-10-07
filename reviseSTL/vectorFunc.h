#pragma once
#include <iostream>
#include <vector>


// output all elements in vector
template<typename T>
bool showVector(std::vector<T> list)
{
	
	// auto for self-adaptive type
	for (auto lIter = list.begin(); lIter != list.end(); ++lIter)
		std::cout << *lIter << " ";
	std::cout<< std::endl;
	return true;

}