// Time: 14, Nov, 2019
#include <iostream>
#include <fstream>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp> 
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/core/core.hpp>

bool readPt (std::vector<int> &ptIndex_, 
			 std::vector<cv::Point2f> & point1_, 
			 std::vector<cv::Point2f> & point2_);

bool runRansac (std::vector<int> ptIndex_,
				std::vector<cv::Point2f> point1_,
				std::vector<cv::Point2f> point2_);

int main()
{
	std::vector<int> ptIndex;
	std::vector<cv::Point2f> pt1, pt2;
	readPt (ptIndex, pt1, pt2);
	runRansac (ptIndex, pt1, pt2);
}

bool readPt (std::vector<int> &ptIndex,
			 std::vector<cv::Point2f> & point1_, 
	         std::vector<cv::Point2f> & point2_)
{
	int scaleSize = 300;
	size_t numPt1 = 256, numPt2 = 345;
	std::string dir = "D:/code/C++/measurementAdjustment/";
	std::ifstream pointTxt1 (dir + "img1.txt");
	std::ifstream pointTxt2 (dir + "img2.txt");
	
	if ( !pointTxt1.is_open () || !pointTxt2.is_open () )
	{
		std::cout << "open failed" << std::endl;
		exit (1);
	}

	cv::Mat tmpPoint1 = cv::Mat::zeros (numPt1, 3, CV_64F);
	cv::Mat tmpPoint2 = cv::Mat::zeros (numPt2, 3, CV_64F);
	for ( int i = 0; i < numPt1; i++ )
		for ( int j = 0; j < 3; j++ )
			pointTxt1 >> tmpPoint1.at<double> (i, j);
	for ( int i = 0; i < numPt2; i++ )
		for ( int j = 0; j < 3; j++ )
			pointTxt2 >> tmpPoint2.at<double> (i, j);
	
	cv::Point2f tmpPtf1, tmpPtf2;

	for( int i = 0; i < numPt1; i++ )
		for ( int j = 0; j < numPt2; j++ )
		{
			if ( tmpPoint1.at<double> (i, 0) == tmpPoint2.at<double> (j, 0) )
			{
				tmpPtf1.x = tmpPoint1.at<double> (i, 1) * scaleSize;
				tmpPtf1.y = tmpPoint1.at<double> (i, 2) * scaleSize;
				tmpPtf2.x = tmpPoint2.at<double> (j, 1) * scaleSize;
				tmpPtf2.y = tmpPoint2.at<double> (j, 2) * scaleSize;
				point1_.push_back (tmpPtf1);
				point2_.push_back (tmpPtf2);
				ptIndex.push_back ( static_cast<int>(tmpPoint1.at<double>(i, 0)) );
			}
			
		}
	std::cout << point1_.size () << "  " << point2_.size () << std::endl;
	return true;
}

bool runRansac (std::vector<int> ptIndex_, 
				std::vector<cv::Point2f> point1_, 
				std::vector<cv::Point2f> point2_)
{
	std::vector<uchar> ransacFlag;
	cv::Mat fundamentalMat =
		cv::findFundamentalMat (point1_, point2_, ransacFlag, cv::FM_RANSAC);
	
	for ( int i = 0; i < fundamentalMat.rows; i++ )
	{
		for ( int j = 0; j < fundamentalMat.cols; j++ )
			std::cout << fundamentalMat.at<double> (i, j) << "  ";
		std::cout << std::endl;
	}

	int totalNum = 0;
	std::cout << "grossError point ID : " << std::endl;
	for ( int i = 0; i < point1_.size (); i++ ) 
	{
		if ( ransacFlag.at (i) == 0 )
		{
			std::cout << ptIndex_.at (i) <<"  ";
			totalNum++;
			if ( totalNum % 10 == 0 )
				std::cout << std::endl;
		}
	}
	std::cout << "totalNum : " << totalNum << std::endl;
	return true;
}