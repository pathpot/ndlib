#ifndef _ND_WEBCAM_H_
#define _ND_WEBCAM_H_

#include <sensor/camera_interface.h>
#include <opencv2/opencv.hpp>

namespace nd{
	class Webcam : public CameraInterface<nd::Rgb> {
	public:
		Webcam();
		virtual ~Webcam();

		bool open(int deviceId = 0);
		virtual bool read(Image<nd::Rgb> &image);
		virtual void close();

	private:
		cv::VideoCapture mDevice;
		cv::Mat mFrameBuffer;
	};
}

#endif
