#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>
#include "dictionary.h"
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

    cv::Ptr<cv::aruco::GridBoard> board = cv::aruco::GridBoard::create(columns,rows,float(size), float(gap), dictionary);

    int imgWidth = columns * size + (columns - 1) * gap + 2 * gap;
    int imgHeight = rows * size + (rows - 1) * gap + 2 * gap;
    cv::Size imageSize(imgWidth,imgHeight);

    cv::Mat image;

    board->draw(imageSize,image, gap, 1);
    cv::imwrite(file,image);
    cout << "Image generated correctly at: " << file << endl;

    return 0;
}