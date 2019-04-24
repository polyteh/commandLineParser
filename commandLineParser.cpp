#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>



#include <iostream>
#include <string>
using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
    const string keys =
            "{@image1        |  ../data/HappyFish.jpg       | image to process   }"
           // "{path         |  ../data/HappyFish.jpg       | image to process   }"
            "{thresh         |          100                 | threshold limit   }"
            "{help h usage ? |                              | print this message   }";

    CommandLineParser parser(argc, argv, keys);
    parser.about("Just OpenCV command line parser example");

    if (parser.has("help"))
    {
        parser.printMessage();
        return 0;
    };



    string imageName = parser.get<cv::String>(0);       //parse as positional argument
    //string imageName = parser.get<String>("path");    //parse with argument name
    int thresh = parser.get<int>("thresh");

    if (!parser.check()) {
        parser.printErrors();
        return -1;
    };


    Mat image;
    image = imread( imageName, IMREAD_COLOR );      // Read the file
    if(image.empty() )      // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
		waitKey(0);
        return -1;
    }
    namedWindow("Display window", WINDOW_AUTOSIZE );    // Create a window for display.
	moveWindow("Display window",100,100);//window position

    cvtColor(image, image, COLOR_BGRA2GRAY );
    cv::threshold(image,image,thresh,256,THRESH_BINARY);


    imshow("Display window", image );       // Show our image inside it.
    waitKey(0);     // Wait for a keystroke in the window


    return 0;
}
