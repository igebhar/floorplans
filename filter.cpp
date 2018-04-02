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
   //Declare x, y as width, and height

   //If the matrix is 3x3
   if (k == 3) {
      for (
         if (x > 1 || x < (img.width - 1) || y > 1 || y < (img.height - 1)) {
            pic.pixel[x][y] = img([x][y]);
         } else {
            pic.apply_kernel(img, x, y, k);
         }       
      }
   }
   
   //If the matrix is 5x5
   if (k == 5) {

   }
}

Pixel Filter::apply_kernel(image& img, int x, int y, Matrix& k){
        //3x3 Matrix
        if (k == 3) {

        } 

        //5x5 Matrix
        if (k == 5) {

        }
}

int Filter::clamp(int lo, int hi, int x) {
        lo = 0;
        hi = 255;
        
        if ( x > hi ) {
                return hi;
                exit;
        } else if ( x < lo ) {
                return lo;
                exit;
        } else {
                return x;
                exit;
        }
}
