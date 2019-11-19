#pragma once
#include <vector>
#include <opencv2/opencv.hpp> 
#include "Estimator.h"


bool ptShift (const Point & point_,
	Point & shiftPoint_,
	const std::vector<Point> & points_);

bool meanShift (const std::vector<Point> & points_);


bool ptShift ( Point & point_,
	Point & shiftPoint_,
	std::vector<Point> & points_)
{
	shiftPoint_.pt.x = shiftPoint_.pt.y = 0.0;
	double tmpWeight, totalWeight = 0;
	for ( auto otherPt : points_ )
	{
		double distance = eculDistance (point_, otherPt);
		if ( distance < RADIUS )
		{
			point_.neiborNum++;
			tmpWeight = gaussKernal (distance);
			shiftPoint_.pt.x += otherPt.pt.x * tmpWeight;
			shiftPoint_.pt.y += otherPt.pt.y * tmpWeight;
			totalWeight += tmpWeight;
		}
	}
	shiftPoint_.pt.x /= totalWeight;
	shiftPoint_.pt.y /= totalWeight;
	
	return true;
}


bool meanShift ( std::vector<Point> & points_ )
{
	std::vector<Point> shiftPt = points_;
	Point tmpPt;
	double distance = 0;
	while ( countNum (shiftPt) < 700 )
	{
		for ( size_t i = 0; i < points_.size (); i++ )
		{
			if ( points_.at (i).flag == 0 )
			{
				ptShift (shiftPt.at(i), tmpPt, points_);
				distance = eculDistance (shiftPt.at (i), tmpPt);
				if ( distance <= SHIFT_TRESHOLD && shiftPt.at(i).neiborNum >= MIN_NEIBOR )
				{
					points_.at (i).flag = 1;
					points_.at (i).neiborNum = shiftPt.at (i).neiborNum;
					shiftPt.at (i).flag = 1;
					std::cout << countNum (shiftPt) << std::endl;
				}
				shiftPt.at (i).pt.x = tmpPt.pt.x;
				shiftPt.at (i).pt.y = tmpPt.pt.y;
			}

		}
	}
	return true;
}