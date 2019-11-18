#pragma once
#include <algorithm>
#include "Func.h"

bool readCsv (const std::string & dir_, 
	std::vector<std::vector<double>> & point2d_,
	const int & numPt_);

bool mergeVec (std::vector<int> & pt1_, const std::vector<int> & pt2_);

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