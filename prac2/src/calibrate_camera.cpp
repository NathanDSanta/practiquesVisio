#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>
#include "common.h"
using namespace std;

int main(int argc, char* argv[]){
    if (argc != 9) {
        cerr << "Us: " << argv[0] << " <dictionary> <board.png> <params.yml> <rows> <columns> <size> <gap> <output.yml>" << endl;
        return -1;
    }

    string dict = argv[1];
    int rows = atoi(argv[4]);
    int columns = atoi(argv[5]);
    float size = atof(argv[6]);
    float gap = atof(argv[7]);
    string file = argv[8];

    cv::Ptr<cv::aruco::Dictionary> dictionary = getDictionary(dict);

    cv::Ptr<cv::aruco::GridBoard> board = cv::aruco::GridBoard::create(columns, rows, size, gap, dictionary);
    cv::Ptr<cv::aruco::DetectorParameters> detectorParams = cv::aruco::DetectorParameters::create();
    return 0;
}