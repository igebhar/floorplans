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
   
   Image pic;

   //If the matrix is 3x3
   if (k == 3) {
      for (
         if (a > 1 || a < (img.width - 1) || b > 1 || b < (img.height - 1)) {
            pic.pixel[a][b] = img([a][b]);
         } else {
            pic.apply_kernel(img[a][b]);
         }       
      }
   }
   
   //If the matrix is 5x5
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
