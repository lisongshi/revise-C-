#include <iostream>
#include <vector>
#include <string>

#include "vectorFunc.h"

#define INITIAL_SIZE 5

template<typename T>
bool showVector(std::vector<T> list);
template<typename T>
bool reverseVector (std::vector<T> oldList, std::vector<T>& verVector);
template<typename T>
bool insertVector (std::vector<T>& list, int index);

int main()
{
	// Initial doubleList with 9,9,9 ... 9.  
	std::vector<double> doubleList(INITIAL_SIZE, 9);
	std::vector<std::string> stringList {"bei","jing","welcome","to","you"};
	
	// visit & change element in vector
	// .at() will check the validity of index to avoid out of range,while [] will not do it. 
	doubleList[1] = 3.14;
	doubleList.at(2) = 3.33;

	
	// add element into vector 
	// vector.size() will be 11 and vector.capcity will over 11,which is dependent by compiler. in VS2019, it's 15.  
	// emplace_back() is more effective than push_back() for no move
	doubleList.push_back(1);
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

	// traversal the vector
	// 1.
	for ( size_t i = 0; i < doubleList.size (); i++ )
	{
		std::cout << doubleList.at (i) << "  ";
	}
	std::cout << std::endl;
	// 2.
	for ( auto element : doubleList )
	{
		std::cout << element << "  ";
	}
	std::cout << std::endl;
	// 3.
	for ( auto Iterator = doubleList.begin (); Iterator != doubleList.end (); Iterator++ )
	{
		std::cout << *Iterator << "  ";
	}
	std::cout << std::endl;

	
	std::vector<double> verVector;
	reverseVector (doubleList, verVector);
	// insert sth behind the second element.
	insertVector (verVector, 2);


	return 0;
}



