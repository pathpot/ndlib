#include <sensor/webcam.h>

nd::Webcam::Webcam(){

}

nd::Webcam::~Webcam(){

}

bool nd::Webcam::open(int deviceId){
	bool result = true;

	mDevice.open(deviceId);
	if(!mDevice.isOpened()){
		result = false;
	}

	return result;
}

bool nd::Webcam::read(Image<nd::Rgb> &image){
	bool result = true;
	if(mDevice.isOpened()){
		mDevice >> mFrameBuffer;

		while(true){
			cv::waitKey(1000);
			mDevice >> mFrameBuffer;
			printf("%d %d\n", mFrameBuffer.rows, mFrameBuffer.cols);

			if(mFrameBuffer.rows > 0)
				cv::imshow("Test", mFrameBuffer);
		}
	}else{
		result = false;
	}

	return result;
}

void nd::Webcam::close(){

}
