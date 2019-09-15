#include <iostream>
#include "linklist.h"

template<typename T>
Linklist<T>::Linklist()
{
	head = new Node<T>;
	head->element = 0;
	head->next = NULL;
}

template<typename T>
Linklist<T>::~Linklist()
{
	Node<T>* ptem = head;
	std::cout << "\n delete linklist" << std::endl;
	while (head) 
	{
		ptem = head;
		head = head->next;
		delete ptem;
	}
	delete head;
	
}

template<typename T>
bool Linklist<T>::creatList(int n)
{
	Node<T>* ptem;
	ptem = head;
	for (int i = 0; i < n; i++)
	{
		std::cout << "输入要添加的值" << std::endl;
		Node<T>* pnew = new Node<T>;
		std::cin >> pnew->element;
		ptem->next = pnew;
		ptem = pnew;
	}
	ptem->next = NULL;
	return true;

}

template<typename T>
bool Linklist<T>::showList()
{
	Node<T>* flag = head->next;
	while( flag )
	{
		std::cout << flag->element << "->";
		flag = flag->next;

	}
	std::cout << "NULL" << std::endl;
	return true;
}


template<typename T>
bool Linklist<T>::count()
{
	int num = 0;
	Node<T>* ptem = head;
	while (ptem)
	{
		num += 1;
		ptem = ptem->next;
	}
	std::cout << "the number of cells is:" << num << std::endl;
	return true;

}

template<typename T>
bool Linklist<T>::insert()
{
	std::cout << "输入插入的位置" << std::endl;
	int index;
	std::cin >> index;
	Node<T>* pre_node = head;
	for (int i = 0; i < index - 1; i++)
	{
		pre_node = pre_node->next;
	}
	Node<T>* next_node = pre_node->next;
	Node<T>* ptem = new Node<T>;
	std::cout << "输入要插入的值" << std::endl;
	std::cin >> ptem->element;
	pre_node->next = ptem;
	ptem->next = next_node;
	return true;

}

template<typename T>
bool Linklist<T>::deleteNode()
{
	std::cout << "输入要删除的元素序号" << std::endl;
	int index;
	std::cin >> index;
	Node<T>* pre_node = head;
	for (int i = 0; i < index - 1; i++)
	{
		pre_node = pre_node->next;
	}
	Node<T>* del_node = pre_node->next;
	pre_node->next = del_node->next;
	delete del_node;
	return true;
}


