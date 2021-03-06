#include <stdio.h>
#include <sensor/webcam.h>
#include <display/image_display.h>
#include "image_reader_application.h"
int main(){
	nd::Image<nd::Rgb> image;

	// open webcam
	nd::Webcam webcam;
	if(!webcam.open(0)){
		printf("Cannot open camera!\n");
		return 0;
	}

	// set up application
	ImageReaderApplication application(webcam);

	std::string name = "Display";
	while(true){
		// process
		if(!application.process(image))
			break;

		// show image
		nd::ImageDisplay::display(name, image);
	}

	return 0;
}
