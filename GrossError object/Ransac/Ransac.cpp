// Time: 14, Nov, 2019
#include "Func.h"

int main()
{
	// 1 means to fundamentalMat & 2 means to homographMat
	std::vector<int> ptIndex;
	std::vector<cv::Point2f> pt1, pt2;
	cv::Mat model;
	readPt (ptIndex, pt1, pt2);
	runRansac (model, ptIndex, pt1, pt2, MODEL_TYPE);
}
