#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp> 


bool readPt (const std::string & dir_,
	std::vector<Point> & points_);

bool savePt (const std::string & dir_,
	std::vector<Point> & points_);

bool readPt (const std::string & dir_,
	std::vector<Point> & points_)
{
	std::fstream ptCsv (dir_ + "imgCsv.csv");

	std::vector<double> lineDouble;
	std::string lineStr;
	std::string tmpStr;
	Point tmpPt;
	double tmpX, tmpY;
	while ( std::getline (ptCsv, lineStr) )
	{
		std::stringstream lineStream (lineStr);
		while ( std::getline (lineStream, tmpStr, ',') )
			lineDouble.push_back (std::stod (tmpStr));
		tmpPt.pt.x = lineDouble.at (0);
		tmpPt.pt.y = lineDouble.at (1);
		points_.push_back (tmpPt);
		lineDouble.clear ();
	}
	ptCsv.close ();
	return true;
}

bool savePt (const std::string & dir_,
	std::vector<Point> & points_)
{
	std::ofstream resultPt (dir_ + "result.csv");
	for ( size_t i = 0; i < points_.size (); i++ )
	{
		if ( points_.at(i).flag == 1 )
		{
			resultPt << points_.at (i).pt.x << "," << points_.at (i).pt.y;
			resultPt << std::endl;
		}
	}
	return true;
}