#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat image1 = imread("image1.jpg");
    Mat image2 = imread("image2.jpg");

    if (image1.empty() || image2.empty()) {
        cout << "Error: Unable to load images!" << endl;
        return -1;
    }

    Mat bitwiseOrResult;
    bitwise_or(image1, image2, bitwiseOrResult);


    Mat bitwiseNorResult;
    bitwise_not(bitwiseOrResult, bitwiseNorResult);

    imwrite("nor_operation_result.jpg", bitwiseNorResult);
    imshow("Bitwise NOR Result", bitwiseNorResult);