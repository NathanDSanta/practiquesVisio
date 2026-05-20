#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>
#include "dictionary.h"
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

    cv::Mat image;
    cv::aruco::drawMarker(dictionary, id, size, image, 1); // 1 defineix el bit d'amplada de l'enunciat

    cv::Mat finalImage;
    int padding = size / 10; 
    cv::copyMakeBorder(image, finalImage, padding, padding, padding, padding, cv::BORDER_CONSTANT, cv::Scalar(255));

    cv::imwrite(file, finalImage);
    cout << "Image generated correctly at: " << file << endl;

    return 0;
}
