//FILTER.CPP//

/**
Clare DuVal and Isabella Gebhart
CPSC 002, 001 Spring 2018
ckduval, igehbar
**/

#include "filter.h"

Matrix Filter:: K3 = 
{{0,-1,0}, 
 {-1,5,-1},
 {0,-1,0}};

Matrix Filter:: K5= 
{{0,0,-1,0 ,0}, 
 {0,0,-1,0,0}, 
 {-1,-1,9,-1,-1}, 
 {0,0,-1,0,0},
 {0,0,-1,0,0},
 
//Default Constructor
Filter::Filter (ifstream& in): HDR(image::read_header(in)),
        pixel(Image::read_pixels(this->HDR, in)) {}

//Copy COnstructor
Filter::Filter (const Filter& fil): HDR(fil.HDR), pixel(fil.pixel) {}

//Param Consructor
Filter::Filter (): {}

//Destructor
Filter::~Filter() {}

// This function takes one pixel 
// passes the pixel to apply_kernel function 
// calculates the new RGB values
// returns the new pixel values
// Parameters: input image
// kernel filter
// outpur new image returned
Image& Filter::sharpen(Image& img, Matrix& k) {
   
   Image pic;
   //Declare x, y as width, and height

   //If the matrix is 3x3
   if (k == 3) {
      for ( //Can I use the (auto height : width) here?
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

              
              
// This function applies the new kernel filter to a single pixel
// Parameters: Image passes in from sharpen function (image& img)
// column location of the current pixel (x0
//  row location of the current pixel (y)
// kernel filter 
// returns the new pixel 
Pixel Filter::apply_kernel(image& img, int x, int y, Matrix& k){
        //3x3 Matrix
        //A way to change 4 neighboring pixels and center pixel (switch case?)
        if (k == 3) {
                //Pixel to the LEFT of center, this might work....?
                
        } 

        //5x5 Matrix
        if (k == 5) {

        }
}

//checks to make sure the new pixel is within the correct values
// parameters: lo - value of 0
// hi- value of 255
// x- current value of pixel being checked
int Filter::clamp(int lo, int hi, int x) {
        lo = 0;
        hi = 255;
        return std::max(lo, std::min(x, hi));
}
