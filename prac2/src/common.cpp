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

cv::Mat createMarker(cv::Ptr<cv::aruco::Dictionary> dictionary, int id, int size){
    cv::Mat image;
    cv::aruco::drawMarker(dictionary, id, size, image, 1); // 1 defineix el bit d'amplada de l'enunciat

    cv::Mat finalImage;
    int padding = size / 10; 
    cv::copyMakeBorder(image, finalImage, padding, padding, padding, padding, cv::BORDER_CONSTANT, cv::Scalar(255));
    return finalImage;
}

cv::Mat createBoard(cv::Ptr<cv::aruco::Dictionary> dictionary, int rows, int columns, int size, int gap){
    cv::Ptr<cv::aruco::GridBoard> board = cv::aruco::GridBoard::create(columns,rows,float(size), float(gap), dictionary);

    int imgWidth = columns * size + (columns - 1) * gap + 2 * gap;
    int imgHeight = rows * size + (rows - 1) * gap + 2 * gap;
    cv::Size imageSize(imgWidth,imgHeight);

    cv::Mat image;

    board->draw(imageSize,image, gap, 1);
    
    return image;
}