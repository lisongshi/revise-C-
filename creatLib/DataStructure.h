#pragma once
#include <iostream>


//在编译得到静态库lib的时候
//如果使用了模板template<>，
//则不能将声明放在.h   实现放在.cpp 。
//这样编译得到的.lib和.h无法使用，会报错LNK2019
//如若使用了模板，需要将类的声明和实现需要都放在头文件.h下
//谨记！


namespace DataStructure
{
	using std::cout;
	using std::cin;
	using std::endl;

	//Node def
	template<typename T>
	struct Node
	{
		T element;
		Node<T>* next;
	};

	//Linklist def
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
	 
	//Stack def
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

	//-----------------------------------Linklist func----------------------------------------------

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
		//cout << "\n delete linklist" << endl;
		while (head)
		{
			ptem = head;
			head = head->next;
			delete ptem;
		}
		delete head;

	}

	template<typename T>
	bool Linklist<T>::creatList()
	{
		Node<T>* ptem;
		ptem = head;
		cout << "input how many nodes your want to creat" << endl;
		int num_nodes;
		cin >> num_nodes;
		for (int i = 0; i < num_nodes; i++)
		{
			cout << "the" << i + 1 << "th element:";
			Node<T>* pnew = new Node<T>;
			cin >> pnew->element;
			ptem->next = pnew;
			ptem = pnew;
		}
		ptem->next = NULL;
		showList();
		return true;

	}

	template<typename T>
	bool Linklist<T>::showList()
	{
		Node<T>* flag = head->next;
		while (flag)
		{
			cout << flag->element << "->";
			flag = flag->next;

		}
		cout << "NULL" << endl;
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
		cout << "the number of nodes is:" << num - 1 << endl;
		return true;

	}

	template<typename T>
	bool Linklist<T>::insert()
	{
		cout << "which position ( i th ) you want to insert:";
		int index;
		cin >> index;
		Node<T>* pre_node = head;
		for (int i = 0; i < index - 1; i++)
		{
			pre_node = pre_node->next;
		}
		Node<T>* next_node = pre_node->next;
		Node<T>* ptem = new Node<T>;
		cout << "input the element:";
		cin >> ptem->element;
		pre_node->next = ptem;
		ptem->next = next_node;
		showList();
		return true;

	}

	template<typename T>
	bool Linklist<T>::deleteNode()
	{
		cout << "which node ( i th ) you want to delete" << endl;
		int index;
		cin >> index;
		Node<T>* pre_node = head;
		for (int i = 0; i < index - 1; i++)
		{
			pre_node = pre_node->next;
		}
		Node<T>* del_node = pre_node->next;
		pre_node->next = del_node->next;
		delete del_node;
		showList();
		return true;
	}

	template<typename T>
	bool Linklist<T>::showFunc()
	{
		cout << "\t\t\t\tFunctions" << endl;
		cout << "-----------------------------------------------------------------------------------------" << endl;
		cout << "1.creat linklist：c\t2.insert node：i\t3.delete node：d\t4.count：n\t4.delete & quit：q" << endl;
		cout << "input character：";
		return true;
	}


	//-----------------------------------Stack func----------------------------------------------
	template<typename T>
	Stack<T>::Stack()
	{
		top = new T;
		size = 0;
		cout << "creat stack successfully!" << endl;
	}

	//there are some bugs in ~Stack() about point free!
	template<typename T>
	Stack<T>::~Stack()
	{
		//T* temp = forMeomery;
		//for (int i = 0; i < size; i++)
		//{
		//	temp = forMeomery;
		//	forMeomery++;
		//	delete temp;
		//}
		top = NULL;
		//cout << "delete stack successfully" << endl;
	}


	template<typename T>
	bool Stack<T>::pushElem()
	{
		cout << "please input how many elements your want to push into stack" << endl;
		int numTemp;
		cin >> numTemp;
		size += numTemp;
		for (int i = 0; i < numTemp; i++)
		{
			cout << "input the " << i + 1 << "th element:";
			top++;
			cin >> *top;
		}
		Stack<T>::showStack();
		return true;

	}

	template<typename T>
	bool Stack<T>::popStack()
	{
		cout << "the poped element：" << *top << endl;
		top--;
		size--;
		Stack<T>::showStack();
		return true;
	}



	template<typename T>
	int Stack<T>::count()
	{
		return size;

	}

	template<typename T>
	bool Stack<T>::showStack()
	{
		T* temp = top;
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "----------------------" << endl;
			cout << "\t" << *(temp - i) << endl;
		}
		cout << "----------------------" << endl;
		cout << endl;
		return true;
	}

	template<typename T>
	bool Stack<T>::showFunc()
	{
		cout << "\t\t\t\tFunctions" << endl;
		cout << "-----------------------------------------------------------------------------------------" << endl;
		cout << "1.push：p\t 2.pop：o\t 3.count num：n\t 4.delete&quit：q" << endl;
		cout << "input character：";
		return true;
	}

}
