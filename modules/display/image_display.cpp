#include <display/image_display.h>

void nd::ImageDisplay::display(std::string window_name, const nd::Image<nd::Rgb> &image){
	cv::Mat data;
	image.getCvMat(data);

	cv::imshow(window_name, data);
}

