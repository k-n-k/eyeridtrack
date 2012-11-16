#include <iostream>
#include <string>
 
#include <cv.h>
#include <highgui.h>
#include "opencv2/nonfree/nonfree.hpp"

using namespace std;
using namespace cv;
 
 
int main(int argc, char *argv[])
{
  // (1)load Color Image
  /*
  const char *imagename = argc > 1 ? argv[1] : "../image/lenna.png";
  Mat colorImage = imread(imagename,1);
  if(colorImage.empty())
    return -1;
*/

  Mat grayImage;
  grayImage = cvLoadImage (argv[1], CV_LOAD_IMAGE_GRAYSCALE);
  // (2)convert Color Image to Grayscale for Feature Extraction
  //cvtColor(colorImage, grayImage, CV_BGR2GRAY);
 
  // (3)initialize SURF class
  SURF calc_surf = SURF(500,4,2,true);
 
  // (4)extract SURF
  vector<KeyPoint> kp_vec;
  vector<float> desc_vec;     
  calc_surf(grayImage, Mat(), kp_vec, desc_vec);
 
  // (5)draw keypoints
  cout << "Image Keypoints: " << kp_vec.size() << endl;
#if 1
  vector<KeyPoint>::iterator it = kp_vec.begin(), it_end = kp_vec.end();
  for(; it!=it_end; ++it) {
    circle(grayImage, Point(it->pt.x, it->pt.y), 
       saturate_cast<int>(it->size*0.25), Scalar(255,255,0));
  }
#else
  for(int i = 0; i < kp_vec.size(); i++) {
    KeyPoint* point = &(kp_vec[i]);
    Point center;  // Key Point's Center
    int radius;      // Radius of Key Point
    center.x = cvRound(point->pt.x);
    center.y = cvRound(point->pt.y);
    radius = cvRound(point->size*0.25);
    circle(grayImage, center, radius, Scalar(255,255,0), 1, 8, 0);
  }
#endif
 
  namedWindow("SURF",CV_WINDOW_AUTOSIZE);
  imshow("SURF", grayImage);
  waitKey(0);
 
  return 0;
}
