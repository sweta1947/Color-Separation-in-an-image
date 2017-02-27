#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include<iostream>
using namespace cv;
using namespace std;
void thresh_callback(int, void *);
int low_h = 0, low_s = 0, low_v = 0;
int high_h = 255, high_s = 255, high_v = 255;
Mat frame, frame_threshold, fr;
int main()
{
	namedWindow("Video Capture",WINDOW_NORMAL);
	namedWindow("Object Detection", WINDOW_NORMAL);
	namedWindow("Object", WINDOW_AUTOSIZE);
	createTrackbar("Low H","Object Detection",&low_h,255,thresh_callback);
	createTrackbar("High H", "Object Detection", &high_h, 255, thresh_callback);
	createTrackbar("Low S", "Object Detection", &low_s, 255, thresh_callback);
	createTrackbar("High S", "Object Detection", &high_s, 255, thresh_callback);
	createTrackbar("Low V", "Object Detection", &low_v, 255, thresh_callback);
	createTrackbar("High V", "Object Detection", &high_v, 255, thresh_callback);
	fr = imread("images.jpg", 1);
	while (1){
		frame_threshold = Mat::zeros(frame_threshold.size(), CV_8UC3);
		cvtColor(fr, frame, CV_BGR2HSV);
		thresh_callback(0, 0);
		//inRange(frame, Scalar(low_h, low_s, low_v), Scalar(high_h, high_s, high_v), frame_threshold);
		imshow("Video Capture", fr);
		imshow("Object", frame_threshold);
		if (waitKey(10) == 'q')
		{
			break;
		}
	}

		return (0);
}
void thresh_callback(int, void*)
{
	inRange(frame, Scalar(low_h, low_s, low_v), Scalar(high_h, high_s, high_v), frame_threshold);
}