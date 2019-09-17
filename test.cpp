#include <iostream>
#include "DataStructure.h"
#include "DataStructure.cpp"


using namespace DataStructure;
void showText();

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	char flag1;
	char flag2;
	showText();
	while (cin >> flag1)
	{
		if (flag1 == 'q')

			break;
		else if (flag1 == 'l')
		{
			Linklist<int> list = Linklist<int>();
			list.showFunc();
			while (cin >> flag2)
			{
				if (flag2 == 'q')
					break;


				else if (flag2 == 'c')
					list.creatList();

				else if (flag2 == 'i')
					list.insert();

				else if (flag2 == 'd')
					list.deleteNode();

				else if (flag2 == 'n')
					list.count();
				else
					cout << "please input valid character" << endl;

				cout << "input character£º";
			}
			showText();
		}
		else if (flag1 == 's')
		{
			Stack<int> stack = Stack<int>();
			stack.showFunc();
			while (cin >> flag2)
			{
				if (flag2 == 'q')
					break;

				else if (flag2 == 'p')
					stack.pushElem();

				else if (flag2 == 'o')
					stack.popStack();

				else if (flag2 == 'n')
					cout << stack.count() << endl;

				else
					cout << "please input valid character" << endl;

				cout << "input character£º";
			}

			showText();
		}

		else 
			cout << "please input valid character" << endl;

	}

	return 0;
}

void showText() 
{
	cout << "\t\t\t\tData Structure" << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "1.Linklist£ºl\t2.Stack£ºs\t3.Quit£ºq" << endl;
	cout << "please input character£º";

}