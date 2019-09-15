#pragma once

template<typename T>
struct Node
{
	T element;
	Node<T>* next;
};

template<typename T>
class Linklist
{
private:
	Node<T>* head;
public:
	Linklist();
	~Linklist();
	bool creatList(int n);
	bool showList();
	bool count();
	bool insert();
	bool deleteNode();

};
