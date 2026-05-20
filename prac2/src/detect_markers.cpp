#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>
#include "dictionary.h"
using namespace std;

int main(int argc, char* argv[]){
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <dictionary> <webcam source>" << endl;
        return -1;
    }

    string dict = argv[1];
    int source = atoi(argv[2]);

    cv::Ptr<cv::aruco::Dictionary> dictionary = getDictionary(dict);

    cv::VideoCapture webCam(0);
    if (!webCam.isOpened()){
        cerr << "Error: Webcam source could not be opened" << endl;
        return -1;
    }


    return 0;
}