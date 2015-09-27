#include <stdio.h>
#include <sensor/webcam.h>

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

	// read image
	webcam.read(image);

	return 0;
}
