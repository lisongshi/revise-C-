// Time: 14, Nov, 2019 
// Author: lisong.shi, lisong.shi@whu.edu.cn


#include "Func.h"
// 1 means fundamentalMat & 2 means homographMat
#define MODEL_TYPE 1

int main()
{
	std::vector<int> ptIndex;
	std::vector<cv::Point2f> pt1, pt2, outliers;
	cv::Mat model;
	std::string dir = "D:/code/C++/measurementAdjustment/";
	readPt (dir,ptIndex, pt1, pt2);
	runRansac (model, ptIndex, pt1, pt2, outliers, MODEL_TYPE);
	saveRes (dir, model, outliers, MODEL_TYPE);
	return 0;
}
