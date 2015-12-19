#include "image_reader_application.h"


ImageReaderApplication::ImageReaderApplication(nd::CameraInterface<nd::Rgb> &cameraInterface) :
	mCameraInterface(cameraInterface)
{
	// nothing else to do
}

bool ImageReaderApplication::process(nd::Image<nd::Rgb> &outputImage)
{
	// read image
	return mCameraInterface.read(outputImage);
}
