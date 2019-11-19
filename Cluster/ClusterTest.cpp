#include <iostream>
#include "MeanShift.h"
#include "IOoperate.h"
#include "DBSCAN.h"

int main()
{
	std::string dir = "../";
	std::vector<Point> Points;
	readPt (dir, Points);
	dbscan (Points);
	//meanShift (testPts);
	savePt (dir, Points);
	return 0;
}
