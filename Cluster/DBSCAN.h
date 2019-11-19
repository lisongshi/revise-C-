#pragma once

#include "Estimator.h"

bool dbscan (std::vector<Point> & points_);


bool dbscan (std::vector<Point> & points_)
{
	for ( size_t i = 0; i < points_.size(); i++ )
	{
		for ( size_t j = i + 1; j < points_.size (); j++ )
		{
			if ( eculDistance (points_.at (i), points_.at (j)) < RADIUS )
			{
				points_.at (i).neiborNum++;
				points_.at (j).neiborNum++;
			}
		}
	}
	size_t ptCount = 0;
	for ( size_t i = 0; i < points_.size (); i++ )
	{
		if ( points_.at(i).neiborNum >= MIN_NEIBOR )
		{
			points_.at (i).flag = 1;
			ptCount++;
		}
	}
	std::cout << "DBSCAN DONE \t Inlier Num:" << ptCount << std::endl;
	return true;
}