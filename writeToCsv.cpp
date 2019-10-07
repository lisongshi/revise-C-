// .csv is easy to show in excel and transform to .xlsx 
// it's a convenent way to save data to excel 

#include <iostream>
#include <fstream>

#define MAX_ITER 100

int main()
{
	std::fstream outfile;
	outfile.open("result.csv", std::ios::out | std::ios::app);
	if ( !outfile.is_open() )
	{
		std::cout << "can't open file !" << std::endl;
		std::exit(0);
	}
	for ( int i = 0; i < MAX_ITER; ++i )
	{
		// csv divide element by "," change the row by endl
		outfile << i << "," << i * i << std::endl;
	}
	outfile.close();

	return 0;

}