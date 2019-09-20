#include <string>
#include <iostream>

/*
class string is only one special situation of class basic_string
i.e. string is a subset of class basic_string through function template<Class Ch> 
e.g. 
typedef basic_string<char> string;
typedef basic_string<wchar> wstring;
typedef bacis_string<Jchar> Jstring; //Japanese string

*/

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;
	using std::getline;

//1.how to creat a string object
	
	string str1("today is a nice day ! ");
	//const char*  -> string
	string str2 = "today is a bad day ! ";
	//copy all str1 as str3
	string str3(str1);
	str3 = "change string3!";
	//output:change string3!
	//copy a part from position 2 with lenth 8 of str1  as  str4
	string str4(str1,2,8);
	cout << str4 << "\tsize:" << str4.length() << endl;
	cout << str3 << endl;
	//output:day is a       size:8
	cout << "----------------------------------" << endl;

//2.how to acess the element of string
	//the difference between [i] and .at(i) is that [] dont check the vailidity of index
	//and .at() do that.
	cout << str1[0] << str1.at(1) << endl;
	//output:to
	cout << "----------------------------------" << endl;


//3.change the element of str1
	str1[0] = 'n';
	str1.at(str1.size() - 2) = '?';
	cout << str1 << endl;
	//output:"nooday is a nice day ? "

	//Func:str.erase() wait until study iterator !!!!!!!
	
	//Func:str.swap(string) exchange str1 & str2
	str1.swap(str2);
	cout << "new str1 :" << str1 << endl << "new str2 :" << str2 << endl;
	//output:new str1 :today is a bad day !
	//		 new str2 : noday is a nice day ?

	//Func:str.insert(int position, string or const char* )
	cout << "old size of str1:" << str1.size() << endl;
	string insertElem("very");
	str1.insert(11, insertElem);
	str1.insert(11 + insertElem.size(), " "); //no ' ' but " "
	cout << str1 << endl;
	cout << "new size of str1:" << str1.size() << endl;
	//output:old size of str1:21
	//		 today is a very bad day !
	//		 new size of str1 : 26



	//Func:str.append(string, int position, int num of add string)
	str1.append(str2, 2, 12);
	cout << str1 << endl;
	//output:today is a very bad day !day is a nic



	//Func:str.replace(int p0, int n0, string, p1, n1)
	//using string[p1,p1 + n1 - 1] replace str[p0,p0 + n0 -1]
	//note that n0 not equal to n1 is available!
	string repElem = "good";
	str1.replace(16, 3, repElem, 0, 4);
	cout << str1 << endl;
	//output:today is a very good day ! day is a nic

//4.find some specific string in str




	cout << "----------------------------------" << endl;
	
//5.logical compare
	str1.at(0) = 'T';
	if (str4 > str1)
		cout << "str4 > str1 is true" << endl;
		//output: str4 > str1 is true
		//in ascii 0 - 9 < A - Z < a - z
	
	string strFlag;
	cin >> strFlag;
	if (strFlag == "nice")
		cout << str1 << str1.size() << endl;
	else if (strFlag == "bad")
		cout << str2 << str2.length() << endl;
	else
		cout << "just soso" << endl;

	
		






//6.stream in & out 
	
	int STREAM_MAXSIZE = 10000;
	//string testString1;
	//cin >> testString1;
	//input: today is a happy day £¡
	//cout << "----------------------------------" << endl;
	//cout << testString1 << endl;
	//output: today ,cin ends when it meet ' '. '\n' or TAB


	//wanna clear the buffer of cin 
	//cin.clear(); ->failed
	//cin.sync();  ->failed too
	//cin.ignore;  ->succeed!

	//abandon the characters in stream  until size = STREAM_MAXSIZE or meet the char '\n' 
	//cin.ignore(STREAM_MAXSIZE,'\n');

	//string testString2;
	//getline(std::cin, testString2);
	//input: today is a happy day £¡. 
	//cout << "----------------------------------" << endl;
	//cout << testString2 << endl;
	//output: today is a happy day £¡. 

	//string testString3 = testString1 + testString2;
	//cout << testString3 << "\nand the size is:" << testString3.size() << endl;

	return 0;
}

