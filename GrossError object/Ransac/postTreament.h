#pragma once
#include <algorithm>
#include "Func.h"

bool readCsv (const std::string & dir_, 
	std::vector<std::vector<double>> & point2d_,
	const int & numPt_);

bool mergeVec (std::vector<int> & pt1_, const std::vector<int> & pt2_);

bool camparePt (const std::string &dir_);

// read .csv into 2d vector
bool readCsv (const std::string & dir_,
	std::vector<std::vector<double>> & point2d_,
	const int & numPt_)
{
	std::ifstream pointCsv (dir_);
	if ( !pointCsv.is_open() ){ std::cout << "open failed" << std::endl; exit (1); }
	
	std::vector<double> lineDouble;
	std::string lineStr;
	std::string tmpStr;
	while ( std::getline(pointCsv,lineStr) )
	{
		std::stringstream lineStream(lineStr);
		while ( std::getline (lineStream, tmpStr, ',') )
			lineDouble.push_back (std::stod (tmpStr));
		point2d_.push_back (lineDouble);
		lineDouble.clear ();
	}
	pointCsv.close ();
	return true;
}

// merge two vector to one, saving in pt1_
bool mergeVec (std::vector<int> & pt1_,const std::vector<int> & pt2_)
{
	std::vector<int> tmpPt = pt1_;
	for ( auto element : pt2_ )
	{
		auto iter = std::find (pt1_.begin (), pt1_.end (), element);
		if ( iter != pt1_.end () ) continue;
		tmpPt.push_back (element);
	}
	pt1_ = tmpPt;
	return true;
}

// 
bool camparePt (const std::string &dir_)
{
	// img1C: 50 , img2C: 48 , img3C: 32
	size_t numPt1 = 50, numPt2 = 48, numPt3 = 32;
	std::vector<std::vector<double>> tmpPoint1, tmpPoint2, tmpPoint3;
	readCsv (dir_ + "imgCsv1.csv", tmpPoint1, numPt1);
	readCsv (dir_ + "imgCsv2.csv", tmpPoint2, numPt2);
	readCsv (dir_ + "imgCsv3.csv", tmpPoint3, numPt3);

	std::vector<int> indexPt1, indexPt2, indexPt3;
	for ( int i = 0; i < numPt1; i++ )
		indexPt1.push_back (static_cast<int>(tmpPoint1.at (i).at (0)));
	for ( int i = 0; i < numPt2; i++ )
		indexPt2.push_back (static_cast<int>(tmpPoint2.at (i).at (0)));
	for ( int i = 0; i < numPt3; i++ )
		indexPt3.push_back (static_cast<int>(tmpPoint3.at (i).at (0)));

	mergeVec (indexPt1, indexPt2);
	mergeVec (indexPt1, indexPt3);
	std::sort (indexPt1.begin (), indexPt1.end ());
	for ( auto element : indexPt1 )
		std::cout << element << " ";
	std::cout << std::endl;
	std::cout << indexPt1.size () << std::endl;
	return true;
}