#ifndef _ND_CAMERAINTERFACE_H_
#define _ND_CAMERAINTERFACE_H_

#include <common/image.h>

namespace nd{
	template <nd::ImageType T>
	class CameraInterface {
	public:
		CameraInterface();
		virtual ~CameraInterface();

		virtual void capture(Image<T> &image) = 0;
		virtual void close() = 0;
	};
}

#endif
