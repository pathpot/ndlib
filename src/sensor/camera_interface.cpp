#include <sensor/camera_interface.h>

template <nd::ImageType T>
nd::CameraInterface<T>::CameraInterface(){
}

template <nd::ImageType T>
nd::CameraInterface<T>::~CameraInterface(){
}

// explicit instantiations
template class nd::CameraInterface<nd::GrayScale>;
template class nd::CameraInterface<nd::Rgb>;
template class nd::CameraInterface<nd::Depth>;
