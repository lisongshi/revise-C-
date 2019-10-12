
#include <iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp> 
#include<opencv2/xfeatures2d.hpp>
#include<opencv2/core/core.hpp>


int main()
{
	// loading images
	cv::Mat img1 = cv::imread ("D:/code/C++/temp/adam/Img1.png");
	cv::Mat img2 = cv::imread ("D:/code/C++/temp/adam/Img2.png");
	if ( !img1.data || !img2.data )
	{
		std::cout << "Reading picture error！" << std::endl;
		exit (1);
	}

	// create SIFT class pointer
	cv::Ptr<cv::Feature2D> f2d = cv::xfeatures2d::SIFT::create();

	// calculate run time
	double timeBegin = cv::getTickCount ();
	// detect the keypoints
	std::vector<cv::KeyPoint> keyPoints1, keyPoints2;
	f2d->detect(img1, keyPoints1);
	f2d->detect(img2, keyPoints2);
	std::cout << "The keypoints number of img1:" << keyPoints1.size() << std::endl;
	std::cout << "The keypoints number of img2:" << keyPoints2.size() << std::endl;

	// calculate descriptors (feature vectors)
	cv::Mat descriptors1, descriptors2;
	f2d->compute(img1, keyPoints1, descriptors1);
	f2d->compute(img2, keyPoints2, descriptors2);
	double freq = cv::getTickFrequency();
	double tt = ((double)cv::getTickCount() - timeBegin) / freq;
	std::cout << "Extract SIFT Time:" << tt << "ms" << std::endl;

	// draw the key points in img1 & img2
	cv::Mat imgKeypoints1, imgKeypoints2;
	drawKeypoints(img1, keyPoints1, imgKeypoints1, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT);
	drawKeypoints(img2, keyPoints2, imgKeypoints2, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT);
	//imshow("imgKeypoints1",imgKeypoints1);
	//imshow("imgKeypoints2",imgKeypoints2);

	// matching descriptor vector by BFMatcher
	cv::BFMatcher matcher;
	std::vector<cv::DMatch> matches;
	matcher.match(descriptors1, descriptors2, matches);
	std::cout << "The number of match:" << matches.size() << std::endl;
	// draw the match result
	cv::Mat img_matches;
	cv::drawMatches(img1, keyPoints1, img2, keyPoints2, matches, img_matches);

	// calculate the max & min distance in the match pairs set
	double min_dist = matches[0].distance, max_dist = matches[0].distance;
	for (int m = 0; m < matches.size(); m++)
	{
		if (matches[m].distance < min_dist)
		{
			min_dist = matches[m].distance;
		}
		if (matches[m].distance > max_dist)
		{
			max_dist = matches[m].distance;
		}
	}
	std::cout << "min dist=" << min_dist << std::endl;
	std::cout << "max dist=" << max_dist << std::endl;
	// select the better match pairs
	std::vector<cv::DMatch> betterMatches;
	for (int m = 0; m < matches.size(); m++)
	{
		if (matches[m].distance < 0.6*max_dist)
			betterMatches.push_back(matches[m]);
	}
	std::cout << "The number of better matches:" << betterMatches.size() << std::endl;
	// draw the result
	cv::Mat img_out;
	drawMatches(img1, keyPoints1, img2, keyPoints2, betterMatches, img_out);
	cv::namedWindow("good Matches", 0);
	cv::imshow("good Matches", img_out);
	
	
	

	// with RANSAC
	std::vector<cv::DMatch> m_Matches;
	m_Matches = betterMatches;
	int ptCount = betterMatches.size();

	if (ptCount < 100)
	{
		std::cout << "Don't find enough match points" << std::endl;
		exit(1);
	}


	std::vector <cv::KeyPoint> keyPointR1, keyPointR2;
	for (size_t i = 0; i < m_Matches.size(); i++)
	{
		keyPointR1.push_back(keyPoints1[betterMatches[i].queryIdx]);
		keyPointR2.push_back(keyPoints2[betterMatches[i].trainIdx]);

	}
	// change the type
	std::vector <cv::Point2f> p1, p2;
	for (size_t i = 0; i < m_Matches.size(); i++)
	{
		p1.push_back(keyPointR1[i].pt);
		p2.push_back(keyPointR2[i].pt);
	}

	/*vector <Point2f> img1_corners(4);
	img1_corners[0] = Point(0,0);
	img1_corners[1] = Point(img1.cols,0);
	img1_corners[2] = Point(img1.cols, img1.rows);
	img1_corners[3] = Point(0, img1.rows);
	vector <Point2f> img2_corners(4);*/
	//Mat m_homography;
	//vector<uchar> m;
	//m_homography = findHomography(p01, p02, RANSAC);
	
	// calculate Fundamental matrix
	std::vector<uchar> RansacStatus;
	cv::Mat Fundamental = findFundamentalMat(p1, p2, RansacStatus, cv::FM_RANSAC);

	// store key points after RANSAC by keyPointAfterR1 & 2
	std::vector <cv::KeyPoint> keyPointAfterR1, keyPointAfterR2;
	std::vector <cv::DMatch> ransacMatches;
	int index = 0;
	for (size_t i = 0; i < m_Matches.size(); i++)
	{
		if (RansacStatus[i] != 0)
		{
			keyPointAfterR1.push_back(keyPointR1[i]);
			keyPointAfterR2.push_back(keyPointR2[i]);
			m_Matches[i].queryIdx = index;
			m_Matches[i].trainIdx = index;
			ransacMatches.push_back(m_Matches[i]);
			index++;
		}
	}

	std::cout << "after RANSAC,the match pairs number:" << ransacMatches.size() << std::endl;

	
	cv::Mat imgAfterRansac;
	drawMatches(img1, keyPointAfterR1, img2, keyPointAfterR2, ransacMatches, imgAfterRansac);
	cv::namedWindow("afterRANSAC", 0);
	cv::imshow("afterRANSAC", imgAfterRansac);
	
	cv::waitKey(0);
	return 0;
}
