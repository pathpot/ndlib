#ifndef _ND_IMAGE_H_
#define _ND_IMAGE_H_

#include<opencv2/opencv.hpp>

namespace nd{
	enum ImageType{
		GrayScale, //8UC1
		Rgb, //8UC3
		Depth //64FC1
	};

	template <ImageType T>
	class Image {
	public:
		Image();
		~Image();

		//TODO: opencv
		void setFromCvMat(const cv::Mat &data);
		void getCvMat(cv::Mat &data) const;
	private:
		cv::Mat mData; //TODO: opencv

	};

}

#endif
