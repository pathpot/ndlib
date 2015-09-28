#ifndef _ND_IMAGEDISPLAY_H_
#define _ND_IMAGEDISPLAY_H_

#include <common/image.h>

namespace nd {
	class ImageDisplay{
	public:
		static void display(std::string window_name, const nd::Image<nd::Rgb> &image);
	};
}


#endif
