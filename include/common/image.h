#ifndef _ND_IMAGE_H_
#define _ND_IMAGE_H_

namespace nd{
	enum ImageType{
		GrayScale,
		Rgb,
		Depth
	};

	template <ImageType T>
	class Image {
	public:
		Image();
		~Image();


	};

}

#endif
