#include <iostream>
#include "linklist.h"
#include "linklist.cpp"

using namespace std;
int main()
{
	char flag;
	cout << "\t\tѡ����" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "1.��������c\t2.�����㣺i\t3.ɾ����㣺d\t4.�˳���q" << endl;
	cout << "�����ַ���";
	Linklist<int> list = Linklist<int>();
	while( cin >> flag )
	{ 
	if (  flag == 'q' )
			break;
	else if (flag == 'c')
	{
		if (list.creatList(3))
		{
			cout << "creat linklist success" << endl;
			if (!list.showList())
				cout << "error in show linklist" << endl;
		}
	}
	else if(flag == 'i')
	{
		if (list.insert())
		{
			cout << "insert node success" << endl;
			if (!list.showList())
				cout << "error in show linklist" << endl;
		}
	}

	else if (flag == 'd')
	{
		if (list.deleteNode())
		{
			cout << "delete node success" << endl;
			if (!list.showList())
				cout << "error in show linklist" << endl;
		}

	}
	else
	{
		cout << "����������" << endl;

	}

	cout << "�����ַ���";
	
	}
}
