#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>
#include "common.h"
using namespace std;

int main(int argc, char* argv[]){
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <dictionary> <webcam source>" << endl;
        return -1;
    }

    string dict = argv[1];
    int source = atoi(argv[2]);

    cv::Ptr<cv::aruco::Dictionary> dictionary = getDictionary(dict);

    cv::VideoCapture webCam(source);
    if (!webCam.isOpened()){
        cerr << "Error: Webcam source could not be opened" << endl;
        return -1;
    }

    cv::Mat frame;
    cv::Ptr<cv::aruco::DetectorParameters> params = cv::aruco::DetectorParameters::create();

    while (webCam.read(frame)) {
        std::vector<int> markers;
        std::vector<std::vector<cv::Point2f>> corners, rejected;
        
        cv::aruco::detectMarkers(frame, dictionary, corners, markers, params, rejected);

        if (markers.size() > 0) {
            cv::aruco::drawDetectedMarkers(frame, corners, markers);
            
            for (size_t i = 0; i < corners.size(); i++) {
                cv::circle(frame, corners[i][0], 6, cv::Scalar(0, 0, 255), -1);
            }
        }
        
        cv::imshow("Deteccio ArUco", frame);
        if (cv::waitKey(1) == 27) break; // Surt amb ESC
    }

    return 0;
}