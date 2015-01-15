#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;
#pragma comment (lib, "opencv_core2410d.lib")
#pragma comment (lib, "opencv_highgui2410d.lib")
#pragma comment (lib, "opencv_imgproc2410d.lib")
#pragma comment (lib, "opencv_video2410d.lib")
#pragma comment (lib, "opencv_features2d2410d.lib")
int main(int argc, char** argv)
{
 	string arg("C:\\Users\\TranBinh\\Desktop\\CS412-FinalProject\\MeanShift\\data\\basketball\\%08d.jpg");
    VideoCapture sequence(arg);
    if (!sequence.isOpened())
    {
        cerr << "Failed to open Image Sequence!\n" << endl;
        return 1;
    }
    Mat image;
    namedWindow("q or esc to quit", CV_WINDOW_NORMAL);
    while(1)
    {
        sequence >> image;
        if(image.empty())
        {
            cout << "End of Sequence" << endl;
            break;
       }
 
        imshow("q or esc to quit", image);
        char key = (char)waitKey(1);
        if(key == 'q' || key == 'Q' || key == 27)
            break;
    }
   return 0;
}
