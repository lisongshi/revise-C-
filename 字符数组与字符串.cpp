#include <iostream>
using namespace std;

int main () {

	//int list[4] = { 1, 2, 3, 4 };
	//cout << list << '\t' << sizeof (list) << '\t' << *list ;
	//output: 000000A9B796FA78  16  1
	//对于非字符数组，输出数组的地址， list 为首地址。

	//char list[4] ;
	//list[0] = 'a';
	//cout << list;
	//output: a烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫 乱码。 原因在于list未赋初值，最后一位并非是 '\0'
	//而输出时cout遇到\0结束，因此一直搜索后面的内存空间，直至遇到\0才停止。


	//char list[4] = "aaa";
	//list[0] = b;
	//cout << list;
	//output: baa 
	//则不会遇到此问题。因为赋值时将list[3] 确定为'\0' 

	//char list[4] = "aaaa";
	//cout << list;
	//报错：数组越界。因为"aaaa"实际上隐藏了一个'\0'。因此要给list开辟5个char空间才可以。

	//char list[4] = "aaa";
	//list[3] = 'b';
	//cout << list;
	//output: aaab烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫 乱码。原因是将'\0' -> 'b' 字符串不再有正常结束标志

	//char list[4] = "aaa";
	//list[3] = 'b';
	//*(list + 4) = '\0';
	//cout << list;
	//Run-Time Check Failure #2 - Stack around the variable 'list' was corrupted.
	//使用[]赋给字符串大小时，将这四个char总共占有的空间视为list的空间，list + 4造成了越界。


	//char ch = 'a';
	//char * list = &ch;
	//*(list + 1) = 'b';
	//cout << list;
	//output: aaab烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫 乱码。原因是字符串没有正常结束标志。

	//char ch = 'a';
	//char * list = &ch;
	//*(list + 1) = 'b';
	//cout << list;
	//输出结果正常，但是报错 Run-Time Check Failure #2 - Stack around the variable 'ch' was corrupted.
	//原因是 list 指向'a'，他的下一块内存确实也指向'b' 

	//char *list = new char;
	//*list = 'a';
	//*(list + 1) = 'b';
	//cout << list;
	//delete list;
	//output: ab ?  原因 ：*(list + 2) = '？' 没有合适的结束标志。
	//list 本身仅仅指向一个字符，想用list输出字符串并不妥当。

	//char *list = new char[3];
	//list[0] = 'a';
	//list[1] = 'b';
	//list[2] = 'c';
	//cout << list;
	//delete [] list;
	//return 0;
	//output: abc 正常运行。why？猜想是由于指定了大小，编译器从list地址开始输出，输出list开始的三个字符。


}