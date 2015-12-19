#include <sensor/webcam.h>

nd::Webcam::Webcam(){

}

nd::Webcam::~Webcam(){

}

bool nd::Webcam::open(int deviceId){
	bool result = true;

	// open device
	mDevice.open(deviceId);
	if(!mDevice.isOpened()){
		result = false;
	}

	// disable auto exposure
	mDevice.set(CV_CAP_PROP_AUTO_EXPOSURE, 0 );

	return result;
}

bool nd::Webcam::read(Image<nd::Rgb> &image){
	bool result = true;
	if(mDevice.isOpened()){
		// read frame
		mDevice >> mFrameBuffer;

		// copy to image attribute
		image.setFromCvMat(mFrameBuffer);
	}else{
		result = false;
	}

	return result;
}

void nd::Webcam::close(){

}
