#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

Mat applyKernel(const Mat& input, const vector<vector<float>>& kernel) {
    int rows = input.rows;
    int cols = input.cols;
    Mat output = Mat::zeros(rows, cols, CV_8UC1);

    for (int i = 1; i < rows - 1; ++i) {
        for (int j = 1; j < cols - 1; ++j) {
            float sum = 0.0;
            for (int ki = -1; ki <= 1; ++ki) {
                for (int kj = -1; kj <= 1; ++kj) {
                    int pixel = input.at<uchar>(i + ki, j + kj);
                    sum += pixel * kernel[ki + 1][kj + 1];
                }
            }
            output.at<uchar>(i, j) = saturate_cast<uchar>(sum);
        }
    }
    return output;
}

int main() {
    Mat image1 = imread("kitty.jpg", IMREAD_GRAYSCALE);
    if (image1.empty()) {
        cout << "Error: kitty.jpg not found!" << endl;
        return -1;
    }

    vector<vector<float>> blurKernel = {
        {1.0f/9, 1.0f/9, 1.0f/9},
        {1.0f/9, 1.0f/9, 1.0f/9},
        {1.0f/9, 1.0f/9, 1.0f/9}
    };

    vector<vector<float>> sharpenKernel = {
        { 0, -1,  0},
        {-1,  5, -1},
        { 0, -1,  0}
    };

    vector<vector<float>> edgeKernel = {
        {-1, -1, -1},
        {-1,  8, -1},
        {-1, -1, -1}
    };

    Mat blurOutput2 = applyKernel(image1, blurKernel);
    Mat sharpenOutput1 = applyKernel(image1, sharpenKernel);
    Mat edgeOutput1 = applyKernel(image1, edgeKernel);

    imwrite("blur_output.png", blurOutput1);
    imwrite("sharpen_output.png", sharpenOutput1);
    imwrite("edge_output.png", edgeOutput1);

    return 0;
}