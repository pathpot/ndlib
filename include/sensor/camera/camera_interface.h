#ifndef _ND_CAMERAINTERFACE_H_
#define _ND_CAMERAINTERFACE_H_

#include <common/Image.h>

namespace nd{

	template <int NumChannels>
	class CameraInterface {
	public:
		CameraInterface();
		virtual ~CameraInterface();

		virtual void capture(Image<NumChannels> &image) = 0;
		virtual void close() = 0;
	};

}

#endif
