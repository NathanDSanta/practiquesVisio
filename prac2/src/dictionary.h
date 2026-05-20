#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>
using namespace std;


cv::Ptr<cv::aruco::Dictionary> getDictionary(const string& dict);