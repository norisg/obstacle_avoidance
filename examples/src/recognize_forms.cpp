#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/////////////// Resize and Crop //////////////////////

int main() {

    string path = "../Resources/test.png";
    Mat img = imread(path);
    //imshow("Before Rotation",img);
    //namedWindow("AfterRotation");//declaring window to show rotated image//
    Mat imgResize, imgCrop,imgGray;


    //Rotate the image by Rotation angle
    int Rotation = 360;
    int Height = img.rows / 2;//getting middle point of rows//
    int Width = img.cols / 2;//getting middle point of height//
    Mat for_Rotation = getRotationMatrix2D(Point(Width, Height), (Rotation),1);//declaring matrix for rotated image
    Mat for_Rotated;
    warpAffine(img, for_Rotated, for_Rotation, img.size());
    imshow("AfterRotation", for_Rotated);//show rotated image//

    cvtColor(img, imgGray, COLOR_BGR2GRAY);


    cout << img.size() << endl;
    resize(img, imgResize, Size(),0.5,0.5);
//
//
    Rect roi(0, 0, 300, 300);
    imgCrop = img(roi);
//
    imshow("Image", img);
    imshow("Image Resize", imgResize);
    imshow("Image Crop", imgCrop);
    imshow("Image Gray", imgGray);
    waitKey(0);
}
