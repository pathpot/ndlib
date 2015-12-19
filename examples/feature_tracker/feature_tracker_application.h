#ifndef _IMAGEREADERAPPLICATION_H_
#define _IMAGEREADERAPPLICATION_H_

#include <sensor/camera_interface.h>

class FeatureTrackerApplication{
public:
	FeatureTrackerApplication(nd::CameraInterface<nd::Rgb> &cameraInterface);
	bool process(nd::Image<nd::Rgb> &outputImage);

private:
	nd::CameraInterface<nd::Rgb> &mCameraInterface;
};

#endif
