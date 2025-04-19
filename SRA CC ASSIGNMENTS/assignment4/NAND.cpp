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

    Mat bitwiseAndResult;
    bitwise_and(image1, image2, bitwiseAndResult);

    Mat bitwiseNandResult;
    bitwise_not(bitwiseAndResult, bitwiseNandResult);

    imwrite("nand_operation_result.jpg", bitwiseNandResult);
    imshow("Bitwise NAND Result", bitwiseNandResult);
    waitKey(0);
    destroyAllWindows();

    return 0;
}