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

    Mat result;
    bitwise_or(image1, image2, result);

    imwrite("or_operation_result.jpg", result);
    imshow("Bitwise OR Result", result);
    waitKey(0);
    destroyAllWindows();

    return 0;
}