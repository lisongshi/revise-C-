#include <iostream>
#include <vector>
#include <string>

#include "vectorFunc.h"

#define INITIAL_NUM 10

template<typename T>
bool showVector(std::vector<T> list);


int main()
{
	// Initial doubleList with 0,0,0 ... 0.  
	std::vector<double> doubleList(INITIAL_NUM, 0);
	std::vector<std::string> stringList {"bei","jing","welcome","to","you"};
	
	// visit & change element in vector
	doubleList[1] = 3.14;
	doubleList.at(2) = 3.33;


	// add element into vector 
	// vector.size() will be 11 and vector.capcity will over 11,which is dependent by compiler. in VS2019, it's 15.  
	doubleList.push_back(1);

	showVector(doubleList);


	return 0;
}



