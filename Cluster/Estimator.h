#pragma once
#include <opencv2/opencv.hpp> 
#include <vector>
#include <cmath>

#define RADIUS 5.0
#define SHIFT_TRESHOLD 0.0001
#define MIN_NEIBOR 10

struct Point
{
	cv::Point2f pt;
	int flag = 0;
	size_t neiborNum = 0;
};

struct Cluster
{
	Point center;
	std::vector<Point> clusterPt;
};

size_t countNum (std::vector<Point> & points_);

size_t countNum (std::vector<Point> & points_)
{
	size_t ptNum = 0;
	for ( size_t i = 0; i < points_.size (); i++ )
	{
		if ( points_.at (i).flag == 1 ) ptNum++;
	}
	return ptNum;
}

double eculDistance (const Point & point1_, const Point & point2_);
inline double eculDistance (const Point & point1_, const Point & point2_)
{
	double distanceSqr = pow (point1_.pt.x - point2_.pt.x, 2) + pow (point1_.pt.y - point2_.pt.y, 2);
	return sqrt (distanceSqr);
}

double gaussKernal (double distance_, double kernelBandwidth_ = RADIUS);
inline double gaussKernal (double distance_, double kernelBandwidth_)
{
	double weight = exp ((-1.0 / 2.0) * pow (distance_, 2) / pow (kernelBandwidth_, 2));
	return weight;
}

