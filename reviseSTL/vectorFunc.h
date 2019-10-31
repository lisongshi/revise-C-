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

	��ȡ����д�������ڳ��ȸı䣬vector ���ܻ����·����ڴ棬�Ӷ��ᵼ��if�ж��еĵ�����end()ʧЧ��
	Ҫ�������1.Ҫôһ��ʼ��vector�����㹻����ڴ�ռ䣬2.Ҫô��ѭ�� �ڲ��� �޸��Ѿ�ʧЧ�ĵ�������
	ͬʱӦ��ע�⵱���ȸı�ʱ����ʹ��++ -- ��д��������ͬ�ϡ�
	���⣬find insert���صĶ����ҵ���ֵ�Լ�����ĵ�ǰֵλ�á�
	���� 8 ���� 9 ��ǰ����˵�����ָ�� 8 Ҫ������ǰ�� 9 �� ��������Ҫ + 2��
	
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