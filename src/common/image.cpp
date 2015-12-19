#include <common/image.h>
#include <stdio.h>

template<nd::ImageType T>
nd::Image<T>::Image(){
}

template<nd::ImageType T>
nd::Image<T>::~Image(){

}

template<nd::ImageType T>
void nd::Image<T>::setFromCvMat(const cv::Mat &data){
	if(T == GrayScale && data.type() == CV_8UC1){
		mData = data.clone();
	}else if(T == Rgb && data.type() == CV_8UC3){
		mData = data.clone();
	}else{
		printf("Format is not consistent.\n");
	}
}

template<nd::ImageType T>
void nd::Image<T>::getCvMat(cv::Mat &data) const{
	data = mData.clone();
}

// explicit instantiations
template class nd::Image<nd::GrayScale>;
template class nd::Image<nd::Rgb>;
template class nd::Image<nd::Depth>;
