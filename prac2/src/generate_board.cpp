#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>
#include "common.h"
using namespace std;


int main(int argc, char* argv[]){

    if (argc != 7) {
        cerr << "Usage: " << argv[0] << " <rows> <columns> <dictionary> <sizeInPixels> <gapInBetween> <fileName.png>" << endl;
        return -1;
    }

    int rows = atoi(argv[1]);
    int columns = atoi(argv[2]);
    string dict = argv[3];
    int size = atoi(argv[4]);
    int gap = atoi(argv[5]);
    string file = argv[6];

    cv::Ptr<cv::aruco::Dictionary> dictionary = getDictionary(dict);

    cv::Mat image = createBoard(dictionary, rows, columns, size, gap);

    cv::imwrite(file,image);
    cout << "Image generated correctly at: " << file << endl;

    return 0;
}