#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;


Mat3b canvas;
string buttonText("Click me!");
string winName = "My cool GUI v0.1";

Rect button;


void callBackFunc(int event, int x, int y, int flags, void* userdata)
{
    if (event == EVENT_LBUTTONDOWN)
    {
        if (button.contains(Point(x, y)))
        {
            cout << "Clicked!" << endl;
            //rectangle(canvas(button), button, Scalar(0,0,255), 2);
        }
    }
    if (event == EVENT_LBUTTONUP)
    {
        //rectangle(canvas, button, Scalar(200, 200, 200), 2);
    }

    imshow(winName, canvas);
    waitKey(1);
}

int main() 
{
    // An image
    Mat3b img(300, 300, Vec3b(0, 255, 0));

    // Your button
    button = Rect(0,0,img.cols, 50);

    // The canvas
    canvas = Mat3b(img.rows + button.height, img.cols, Vec3b(0,0,0));

    // Draw the button
    canvas(button) = Vec3b(200,200,200);
    //putText(canvas(button), buttonText, Point(button.width*0.35, button.height*0.7), FONT_HERSHEY_PLAIN, 1, Scalar(0,0,0));

    // Draw the image
    img.copyTo(canvas(Rect(0, button.height, img.cols, img.rows)));

    // Setup callback function
    namedWindow(winName);
    setMouseCallback(winName, callBackFunc);

    imshow(winName, canvas);
    waitKey();

    return 0;
}
