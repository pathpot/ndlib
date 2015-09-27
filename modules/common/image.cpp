#include <common/image.h>
#include <stdio.h>

template<int NumChannels>
nd::Image<NumChannels>::Image(){
	printf("Num Channels %d\n", Image);
}

template<int NumChannels>
nd::Image<NumChannels>::~Image(){

}

// explicit instantiations
template class nd::Image<1>;
template class nd::Image<3>;
