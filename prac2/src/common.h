#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>
using namespace std;


cv::Ptr<cv::aruco::Dictionary> getDictionary(const string& dict);
cv::Mat createMarker(cv::Ptr<cv::aruco::Dictionary> dictionary, int id, int size);
cv::Mat createBoard(cv::Ptr<cv::aruco::Dictionary> dictionary, int rows, int columns, int size, int gap);
