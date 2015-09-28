#include <stdio.h>
#include <sensor/webcam.h>
#include <display/image_display.h>
int main(){
	nd::Image<nd::Rgb> image;

	nd::Webcam webcam;

	// open webcam
	if(!webcam.open(0)){
		printf("Cannot open camera!\n");
		return 0;
	}else{
		printf("Open camera successfully!\n");
	}

	std::string name = "Display";
	while(true){
		// read image
		webcam.read(image);

		// show image
		nd::ImageDisplay::display(name, image);

		// TODO: remove opencv dependency
		cv::waitKey(100);
	}

	return 0;
}
