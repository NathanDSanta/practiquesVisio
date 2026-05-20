#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>
using namespace std;

cv::Ptr<cv::aruco::Dictionary> getDictionary(const string& dict) {
    if (dict == "DICT_ARUCO_ORIGINAL") return cv::aruco::getPredefinedDictionary(cv::aruco::DICT_ARUCO_ORIGINAL);
    if (dict == "DICT_4X4_50") return cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);
    if (dict == "DICT_6X6_250") return cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    return cv::aruco::getPredefinedDictionary(cv::aruco::DICT_ARUCO_ORIGINAL);
}