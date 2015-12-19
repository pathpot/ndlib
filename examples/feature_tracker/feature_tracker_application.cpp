#include "feature_tracker_application.h"


FeatureTrackerApplication::FeatureTrackerApplication(nd::CameraInterface<nd::Rgb> &cameraInterface) :
	mCameraInterface(cameraInterface)
{
	// nothing else to do
}

bool FeatureTrackerApplication::process(nd::Image<nd::Rgb> &outputImage)
{
	// read image
	return mCameraInterface.read(outputImage);
}
