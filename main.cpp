#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

String face_cascade_name = "/Users/abu/Developer/opencv_example/haarcascade_frontalface_alt2.xml";

CascadeClassifier face_cascade;

int main() {
	// --1. Load the cascades
	if (!face_cascade.load(face_cascade_name)) {
		printf("--(!) Error loading face cascade\n");
	}

	Mat test = imread("/Users/abu/Developer/opencv_example/subject01.png", 0);
	cout << "Cols: "<< test.cols << " Rows: " << test.rows << endl;
	std::vector<Rect> faces;
	
	face_cascade.detectMultiScale(test, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(20,20));
	printf("Detecting...\n");
	for (size_t i = 0; i < faces.size(); i++) {
		printf("Face found\n");
	}

	return 0;
}
