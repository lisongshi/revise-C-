#include <iostream>
#include "linklist.h"
#include "linklist.cpp"

using namespace std;
int main()
{
	char flag;
	cout << "\t\t\t\t选择功能" << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "1.创建链表：c\t2.插入结点：i\t3.删除结点：d\t4.统计结点个数：n\t4.删除并退出：q" << endl;
	cout << "输入字符：";
	Linklist<int> list = Linklist<int>();
	while( cin >> flag )
	{ 
		if (flag == 'q')
			break;
		else if (flag == 'c')
		{
			if (list.creatList(3))
				cout << "creat linklist success" << endl;
		}
		else if (flag == 'i')
		{
			if (list.insert())
				cout << "insert node success" << endl;
		}

		else if (flag == 'd')
		{
			if (list.deleteNode())
				cout << "delete node success" << endl;
		}
		else if (flag == 'n')
			list.count();
		else
		{
			cout << "请重新输入有效字符" << endl;

		}

	cout << "输入字符：";
	
	}
}
