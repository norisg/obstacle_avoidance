#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <chrono>

using namespace cv;
using namespace std;

#ifdef __linux__
    #define ROTATION 180
#else
    #define ROTATION 0
#endif





int main (){



    // Create a VideoCapture object and use camera to capture the video
    VideoCapture cap(0);

    // Check if camera opened successfully
    if(!cap.isOpened()){
         cout << "Error opening video stream" << endl;
          return -1;
    }
    
    // Default resolutions of the frame are obtained.The default resolutions are system dependent.
    int frame_width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int frame_height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    
     std::time_t logtime_unix = std::time(0);  // t is an integer type
    
    string logfileName = "video_recording" + std::to_string(logtime_unix) + ".avi";
    
    // Define the codec and create VideoWriter object.The output is stored in 'outcpp.avi' file.
    VideoWriter video( logfileName, cv::VideoWriter::fourcc('M','J','P','G'), 10, Size(frame_width,frame_height));
    
    
    while(1){
        

      Mat frame;
     
      // Capture frame-by-frame
      cap >> frame;
   
      // If the frame is empty, break immediately
      if (frame.empty())
        break;
      
      int Rotation = ROTATION;
      int Height = frame.rows / 2;//getting middle point of rows//
      int Width = frame.cols / 2;//getting middle point of height//
      Mat for_Rotation = getRotationMatrix2D(Point(Width, Height), (Rotation),1);//declaring matrix for rotated image
      Mat rotated180;
        warpAffine(frame, rotated180, for_Rotation, frame.size());
      // Write the frame into the file 'outcpp.avi'
      video.write(frame);
     
      // Display the resulting frame
      imshow( "Frame", frame );
   
      // Press  ESC on keyboard to  exit
      char c = (char)waitKey(1);
      if( c == 27 )
        break;
    }

    // When everything done, release the video capture and write object
    cap.release();
    video.release();

    // Closes all the frames
    destroyAllWindows();
    return 0;
}
