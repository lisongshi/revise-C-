#pragma once
#include <iostream>
#include <opencv2/opencv.hpp> 

// estimate the distance in fundamentalMat model.
double symmetricEpipolarDistance (const cv::Mat &model_,
	const cv::Point2f &pt1_,
	const cv::Point2f &pt2_)
{
	const double x1 = pt1_.x;
	const double y1 = pt1_.y;
	const double x2 = pt2_.x;
	const double y2 = pt2_.y;

	const double f11 = model_.at<double> (0, 0);
	const double f12 = model_.at<double> (0, 1);
	const double f13 = model_.at<double> (0, 2);
	const double f21 = model_.at<double> (1, 0);
	const double f22 = model_.at<double> (1, 1);
	const double f23 = model_.at<double> (1, 2);
	const double f31 = model_.at<double> (2, 0);
	const double f32 = model_.at<double> (2, 1);
	const double f33 = model_.at<double> (2, 2);

	
	const double rxc = f11 * x2 + f21 * y2 + f31;
	const double ryc = f12 * x2 + f22 * y2 + f32;
	const double rwc = f13 * x2 + f23 * y2 + f33;
	const double r = (x1 * rxc + y1 * ryc + rwc);
	const double rx = f11 * x1 + f12 * y1 + f13;
	const double ry = f21 * x1 + f22 * y1 + f23;
	const double a = rxc * rxc + ryc * ryc;
	const double b = rx * rx + ry * ry;

	return r * r * (a + b) / (a * b);
	/*
	const double A = f11 * x1 + f12 * y1 + f13;
	const double B = f21 * x1 + f22 * y1 + f23;
	const double C = f31 * x1 + f32 * y2 + f33;
	double k = - A / C;
	double b = - C / B;
	double ry = y2 - (k * x2 + b);
	return ry;
	*/
}

// estimate the distance in HomographMat model.
double* residualHomograph (const cv::Mat &model_,
	const cv::Point2f &pt1_,
	const cv::Point2f &pt2_)
{
	const double x1 = pt1_.x;
	const double y1 = pt1_.y;
	const double x2 = pt2_.x;
	const double y2 = pt2_.y;

	const double h11 = model_.at<double> (0, 0);
	const double h12 = model_.at<double> (0, 1);
	const double h13 = model_.at<double> (0, 2);
	const double h21 = model_.at<double> (1, 0);
	const double h22 = model_.at<double> (1, 1);
	const double h23 = model_.at<double> (1, 2);
	const double h31 = model_.at<double> (2, 0);
	const double h32 = model_.at<double> (2, 1);
	const double h33 = model_.at<double> (2, 2);

	const double t1 = h11 * x1 + h12 * y1 + h13;
	const double t2 = h21 * x1 + h22 * y1 + h23;
	const double t3 = h31 * x1 + h32 * y1 + h33;

	static double res[2];
	res[0] = x2 - (t1 / t3);
	res[1] = y2 - (t2 / t3);
	return res;
}