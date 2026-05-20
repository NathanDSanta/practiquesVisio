#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>
#include "common.h"
using namespace std;



int main(int argc, char* argv[]) {
    if (argc != 5) {
        cerr << "Usage: " << argv[0] << " <dictionary> <id> <sizeInPixels> <fileName.png>" << endl;
        return -1;
    }

    string dict = argv[1];
    int id = atoi(argv[2]);
    int size = atoi(argv[3]);
    string file = argv[4];

    cv::Ptr<cv::aruco::Dictionary> dictionary = getDictionary(dict);

    cv::Mat finalImage = createMarker(dictionary, id, size);

    cv::imwrite(file, finalImage);
    cout << "Image generated correctly at: " << file << endl;

    return 0;
}
