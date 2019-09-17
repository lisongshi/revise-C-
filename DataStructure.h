#pragma once
namespace DataStructure
{

	//Node
	template<typename T>
	struct Node
	{
		T element;
		Node<T>* next;
	};

	//Linklist
	template<typename T>
	class Linklist
	{
	private:
		Node<T>* head;
	public:
		Linklist();
		~Linklist();
		bool creatList();
		bool showList();
		bool count();
		bool insert();
		bool deleteNode();
		bool showFunc();
	};

	//Stack
	template<typename T>
	class Stack
	{
	private:
		T* top;
		int size;
	public:
		Stack();
		~Stack();
		bool pushElem();
		bool popStack();
		bool showStack();
		int count();
		bool showFunc();
		
		
	};


}

