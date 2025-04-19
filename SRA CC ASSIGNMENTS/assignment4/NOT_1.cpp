#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat image = imread("sample1.jpg");

    if (image.empty()) {
        cout << "Error: Unable to load image!" << endl;
        return -1;
    }

    Mat invertedImage;
    bitwise_not(image, invertedImage);

    imwrite("not_operation_result.jpg", invertedImage);
    imshow("Bitwise NOT Result", invertedImage);
    waitKey(0);
    destroyAllWindows();

    return 0;
}