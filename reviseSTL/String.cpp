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

bool testString()
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

	//rend                       end
	//¡ý    iterator in string    ¡ý
	//  wwwwwwwwaaaaaaaaaddddddddd
    // ¡ü                        ¡ü                  	
	//begin                    rbegin
	// str.end() = str.begin() + str.length() 
	// str.rend() = str.rbegin() +str.length()
	// *( str.end() - 1 ) = *str.rbegin() = d  
	// *( str.rend() - 1 ) = *str.beging() = w


	cout << "show the string by iterator:" << endl;
	for (string::iterator lIter = str1.begin(); lIter != str1.end(); ++lIter)
		cout << *lIter;
		//output:today is a nice day !
	cout << endl;
	for (string::reverse_iterator rIter = str1.rbegin(); rIter != str1.rend(); ++rIter)
		cout << *rIter;
	cout << endl;



//3.change the element of str1
	str1[0] = 'n';
	str1.at(str1.size() - 2) = '?';
	cout << str1 << endl;
	//output:"noday is a nice day ? "

	//Func:str.erase(iterator begin, iterator end)
	str1.erase(str1.end() - 5, str1.end());
	cout << str1 << endl;


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
	//	Func:str.find(string, beginning position) from left to right, 
	//		 str.rfind starts at beginning position and from the right to the left
	//	     return  size_t position, if not find the string, return string::npos
	
	size_t position = 0;
	string keyWord = "day";
	position = str1.find(keyWord, 0);
	cout << position << endl;
	// position = 2
	position = str1.rfind(keyWord, str1.size() - 1 );
	cout << position << endl;
	//position  = 27
	string noExist = "keep";
	if (str1.find(noExist, 0) == string::npos)
		cout << noExist << " do not exist in this sentence" << endl;


	//find all keywords in the sentence.
	//1.
	size_t posLeft = 0;
	size_t posRight = str1.length() - 1;
	while (posLeft < str1.length())
	{
		posLeft = str1.find(keyWord, posLeft);
		posRight = str1.rfind(keyWord, posRight);
		cout << posLeft << "\t" << posRight << endl;
		if (posLeft == posRight)
			break;
		else
		{
			posLeft += keyWord.length();
			posRight -= keyWord.length();
		}
	}
	
	//2.
	posLeft = 0;
	while ( 1 )
	{
		posLeft = str1.find(keyWord, posLeft);
		if (posLeft > str1.length())
			break;
		cout << posLeft << endl;
		posLeft += keyWord.length();
		
	}
	cout << "find all keywords" << endl;


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

	return true;
}

