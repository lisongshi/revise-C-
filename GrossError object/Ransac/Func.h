#pragma once
#include <fstream>
#include <string>
#include "estimator.h"

// 1 means fundamentalMat & 2 means homographMat
#define MODEL_TYPE 2
#define SCALE_SIZE 300
#define lambda 1
#define SCALE_SQUARED 90000
// 4 * 2.8um = 11.2um i.e. 0.0112mm
#define RES_THRESHOLD 0.0112


bool readPt (std::vector<int> & ptIndex_,
	std::vector<cv::Point2f> & point1_,
	std::vector<cv::Point2f> & point2_);

bool runRansac (cv::Mat & model_,
	const std::vector<int> & ptIndex_,
	const std::vector<cv::Point2f> & point1_,
	const std::vector<cv::Point2f> & point2_,
	int type_ = 1);

double symmetricEpipolarDistance (const cv::Mat &model_,
	const cv::Point2f &pt1_,
	const cv::Point2f &pt2_);

double* residualHomograph (const cv::Mat &model_,
	const cv::Point2f &pt1_,
	const cv::Point2f &pt2_);

// read point from txt to cv::Mat.
bool readPt (std::vector<int> &ptIndex,
			 std::vector<cv::Point2f> & point1_,
			 std::vector<cv::Point2f> & point2_)
{
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

	for ( int i = 0; i < numPt1; i++ )
		for ( int j = 0; j < numPt2; j++ )
		{
			if ( tmpPoint1.at<double> (i, 0) == tmpPoint2.at<double> (j, 0) )
			{
				tmpPtf1.x = tmpPoint1.at<double> (i, 1) * SCALE_SIZE * lambda;
				tmpPtf1.y = tmpPoint1.at<double> (i, 2) * SCALE_SIZE;
				tmpPtf2.x = tmpPoint2.at<double> (j, 1) * SCALE_SIZE * lambda;
				tmpPtf2.y = tmpPoint2.at<double> (j, 2) * SCALE_SIZE;
				point1_.push_back (tmpPtf1);
				point2_.push_back (tmpPtf2);
				ptIndex.push_back (static_cast<int>(tmpPoint1.at<double> (i, 0)));
			}

		}
	std::cout << point1_.size () << "  " << point2_.size () << std::endl;
	return true;
}

// run RANSAC algorithm using fundamentalMat or homographMat
bool runRansac (cv::Mat & model_,
	const std::vector<int> & ptIndex_,
	const std::vector<cv::Point2f> & point1_,
	const std::vector<cv::Point2f> & point2_,
	int type_)
{
	std::vector<uchar> ransacFlag;
	if ( type_ == 1 )
	{
		model_ = cv::findFundamentalMat (point1_, point2_, ransacFlag, cv::FM_RANSAC);
		std::cout << "Fundamental Matrix:" << std::endl;
	}
	else if ( type_ == 2 )
	{
		model_ = cv::findHomography (point1_, point2_, ransacFlag, cv::FM_RANSAC);
		std::cout << "Homograph Matrix:" << std::endl;
	}
	else
		exit (1);

	// show the element of model matrix
	for ( int i = 0; i < model_.rows; i++ )
	{
		for ( int j = 0; j < model_.cols; j++ )
			std::cout << model_.at<double> (i, j) << "  ";
		std::cout << std::endl;
	}

	int totalNum = 0;
	double * tmpResHomograph = NULL;
	std::vector<double> resY;
	std::cout << "grossError point ID \t distance to model  " << std::endl;
	for ( int i = 0; i < point1_.size (); i++ )
	{
		if ( ransacFlag.at (i) == 0 )
		{

			if ( type_ == 1 )
			{
				std::cout << ptIndex_.at (i) << " \t\t\t ";
				std::cout << symmetricEpipolarDistance (model_, point1_.at (i), point2_.at (i)) / SCALE_SQUARED << std::endl;
				totalNum++;
			}
			else if ( type_ == 2 )
			{
				tmpResHomograph = residualHomograph (model_, point1_.at (i), point2_.at (i));
				if ( *(tmpResHomograph + 1) > RES_THRESHOLD )
				{
					std::cout << ptIndex_.at (i) << " \t\t\t ";
					std::cout << "res in X:" << -(*tmpResHomograph++) / SCALE_SIZE << "  " <<
						"res in Y:" << -(*tmpResHomograph) / SCALE_SIZE << std::endl;
					resY.push_back ( -(*tmpResHomograph) );
					totalNum++;
				}
			}
			else
				exit (1);
		}
	}
	std::cout << "totalNum : " << totalNum << std::endl;
	return true;
}
