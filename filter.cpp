//FILTER.CPP//

/**
Clare DuVal and Isabella Gebhart
CPSC 002, 001 Spring 2018
ckduval, igehbar
**/

#include "filter.h"

//Default Constructor
Filter::Filter (ifstream& in): HDR(image::read_header(in)),
        pixel(Image::read_pixels(this->HDR, in)) {}

//Copy COnstructor
Filter::Filter (const Filter& fil): HDR(fil.HDR), pixel(fil.pixel) {}

//Param Consructor
Filter::Filter (): {}

//Destructor
Filter::~Filter() {}

Image& Filter::sharpen(Image& img, Matrix& k) {
        if (k == 3) {

        }
        if (k == 5) {

        }
}

Pixel Filter::apply_kernel(image& img, int x, int y, Matrix& k){

}

int Filter::clamp(int lo, int hi, int x) {
        lo = 0;
        hi = 255;
        return std::max(lo, std::min(x, hi));
}
