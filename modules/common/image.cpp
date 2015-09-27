#include <common/image.h>
#include <stdio.h>

template<nd::ImageType T>
nd::Image<T>::Image(){
}

template<nd::ImageType T>
nd::Image<T>::~Image(){

}

// explicit instantiations
template class nd::Image<nd::GrayScale>;
template class nd::Image<nd::Rgb>;
template class nd::Image<nd::Depth>;
