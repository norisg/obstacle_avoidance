#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#ifdef __linux__
    #define ROTATION 180
#else
    #define ROTATION 0
#endif

/////////////// Color Detection //////////////////////

void getContours(Mat imgDil, Mat img) {

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());

    for (int i = 0; i < contours.size(); i++)
    {
    int area = contourArea(contours[i]);
    cout << "Area:" << area << endl;
    string objectType;

    if (area > 1000)
    {
    float peri = arcLength(contours[i], true);
    approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
    cout << "ConPolySize" << i << ":" << conPoly[i].size() << endl;
    boundRect[i] = boundingRect(conPoly[i]);

    int objCor = (int)conPoly[i].size();

    if (objCor == 3) { objectType = "Tri"; }
    else if (objCor == 4)
    {
    float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
    cout << "AspectRatio: " << aspRatio << endl;
    if (aspRatio> 0.95 && aspRatio< 1.05){ objectType = "Square"; }
    else { objectType = "Rect";}
    }
    else if (objCor > 4) { objectType = "Circle"; }

    drawContours(img, conPoly, i, Scalar(255, 0, 255), 5);
    rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
    putText(img, objectType, { boundRect[i].x,boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN,1, Scalar(0, 69, 255), 2);
    }
    }
    }



int main() {

     Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

     VideoCapture cap(0);
     Mat img;

     while (true) {

         cap.read(img);
         
         //Rotate the image by Rotation angle
        
         int Rotation = ROTATION;
         int Height = img.rows / 2;//getting middle point of rows//
         int Width = img.cols / 2;//getting middle point of height//
         Mat for_Rotation = getRotationMatrix2D(Point(Width, Height), (Rotation),1);//declaring matrix for rotated image
         Mat rotated180;
         warpAffine(img, rotated180, for_Rotation, img.size());

         //imshow("AfterRotation", for_Rotated);//show rotated image//

         // Preprocessing
         cvtColor(rotated180, imgGray, COLOR_BGR2GRAY);
         GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
         Canny(imgBlur, imgCanny, 25, 75);
         Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
         dilate(imgCanny, imgDil, kernel);

         getContours(imgDil,rotated180);


         imshow("Image", rotated180);
         waitKey(20);

     }


}
