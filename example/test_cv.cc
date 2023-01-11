#include "normalize.h"
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

void pre_process(const cv::Mat& img, int width, int height, float* data) {
  cv::Mat rgb_img;
  cv::cvtColor(img, rgb_img, cv::COLOR_BGR2RGB);
  cv::resize(rgb_img, rgb_img, cv::Size(width, height), 0.f, 0.f);
  cv::Mat imgf;
  rgb_img.convertTo(imgf, CV_32FC3, 1 / 255.f);
  float means[3] = {0.5f, 0.5f, 0.5f};
  float scales[3] = {0.5f, 0.5f, 0.5f};
  const float* dimg = reinterpret_cast<const float*>(imgf.data);
  chw_neon_mean_scale(dimg, data, width * height, means, scales);
  //hwc_neon_mean_scale(dimg, data, width * height, means, scales);
}

void RunModel(std::string img_path){
  
  // read img and pre-process
  cv::Mat img = imread(img_path, cv::IMREAD_COLOR);
  
  int w=img.cols;
  int h=img.rows;
  int c=img.channels();
  
  cv::Mat mat_resize=cv::Mat(3,3,CV_8UC3,cv::Scalar::all(0));
  
  cv::resize(img, mat_resize, cv::Size(3, 3), cv::INTER_LINEAR);
  
  int size=9;

  float *data=new float(size);
  
  pre_process(mat_resize, 3, 3, data);
  
  FILE * fp;
  if((fp = fopen("file.txt","wb"))==NULL){
      printf("cant open the file");
      exit(0);
  }
  int i;
  for(i=0;i<3*3*3;i++){
      fprintf(fp,"%d:%f\n",i,data[i]);
  }
  
  fclose(fp);
  
  delete data;
 }

int main(int argc, char** argv) {
  std::string img_path = "fu.jpg";
  
  RunModel(img_path);
  
  return 0;
}
