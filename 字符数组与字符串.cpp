#include <iostream>
using namespace std;

int main () {

	//int list[4] = { 1, 2, 3, 4 };
	//cout << list << '\t' << sizeof (list) << '\t' << *list ;
	//output: 000000A9B796FA78  16  1
	//���ڷ��ַ����飬�������ĵ�ַ�� list Ϊ�׵�ַ��

	//char list[4] ;
	//list[0] = 'a';
	//cout << list;
	//output: a�������������������������������� ���롣 ԭ������listδ����ֵ�����һλ������ '\0'
	//�����ʱcout����\0���������һֱ����������ڴ�ռ䣬ֱ������\0��ֹͣ��


	//char list[4] = "aaa";
	//list[0] = b;
	//cout << list;
	//output: baa 
	//�򲻻����������⡣��Ϊ��ֵʱ��list[3] ȷ��Ϊ'\0' 

	//char list[4] = "aaaa";
	//cout << list;
	//��������Խ�硣��Ϊ"aaaa"ʵ����������һ��'\0'�����Ҫ��list����5��char�ռ�ſ��ԡ�

	//char list[4] = "aaa";
	//list[3] = 'b';
	//cout << list;
	//output: aaab�������������������������������� ���롣ԭ���ǽ�'\0' -> 'b' �ַ�������������������־

	//char list[4] = "aaa";
	//list[3] = 'b';
	//*(list + 4) = '\0';
	//cout << list;
	//Run-Time Check Failure #2 - Stack around the variable 'list' was corrupted.
	//ʹ��[]�����ַ�����Сʱ�������ĸ�char�ܹ�ռ�еĿռ���Ϊlist�Ŀռ䣬list + 4�����Խ�硣


	//char ch = 'a';
	//char * list = &ch;
	//*(list + 1) = 'b';
	//cout << list;
	//output: aaab�������������������������������� ���롣ԭ�����ַ���û������������־��

	//char ch = 'a';
	//char * list = &ch;
	//*(list + 1) = 'b';
	//cout << list;
	//���������������Ǳ��� Run-Time Check Failure #2 - Stack around the variable 'ch' was corrupted.
	//ԭ���� list ָ��'a'��������һ���ڴ�ȷʵҲָ��'b' 

	//char *list = new char;
	//*list = 'a';
	//*(list + 1) = 'b';
	//cout << list;
	//delete list;
	//output: ab�� ?  ԭ�� ��*(list + 2) = '��' û�к��ʵĽ�����־��
	//list �������ָ��һ���ַ�������list����ַ��������׵���

	//char *list = new char[3];
	//list[0] = 'a';
	//list[1] = 'b';
	//list[2] = 'c';
	//cout << list;
	//delete [] list;
	//return 0;
	//output: abc �������С�why������������ָ���˴�С����������list��ַ��ʼ��������list��ʼ�������ַ���


}