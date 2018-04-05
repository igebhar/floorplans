//FILTER.CPP//

/**
Clare DuVal and Isabella Gebhart
CPSC 002, 002 Spring 2018
ckduval, igehbar
**/

//Includes
#include <iterator>
#include "filter.h"
#include "Image.h"

//3x3 Matrix
Matrix Filter::K3 =
{{0,-1,0},
 {-1,5,-1},
 {0,-1,0}};

//5x5 Matrix
Matrix Filter::K5 =
{{0,0,-1,0,0},
 {0,0,-1,0,0},
 {-1,-1,9,-1,-1},
 {0,0,-1,0,0},
 {0,0,-1,0,0}};

// This function takes one pixel passes the pixel to apply_kernel function
// Parameters: input image, kernel filter
// output new image returned
Image& Filter::sharpen(Image& img, Matrix& k) {

	int i = 0;

	int center = k.size()/2;
	int rows = img.header().height();
	int columns = img.header().width();

	Image copy(img);

	for (int x = center; x < (rows - center); x++) {
		for (int y = center; y < (columns - center); y++) {
			img.pixel[i] = apply_kernel(copy, x, y, k);
			i++;
    		}
	}
   	return img;
}

// This function applies the new kernel filter to a single pixel
// Parameters: Image passes in from sharpen function (image& img),
// column location of the current pixel (x),
// row location of the current pixel (y),
// and kernel filter
// returns the new pixel

Pixel Filter::apply_kernel(Image& img, int x, int y, Matrix& k){
	Pixel pix;
	//Dummy variables
        int red = 0;
        int green = 0;
        int blue = 0;
	//3x3 Matrix
	if (k.size() == 3) { //3x3 Matrix
                //Accesses all of the neighboring pixels
		int center = k.size() / 2;
		for( int i = -center; i <= center; i++){
			for( int j = -center; j <= center; j++){
				//Changes rgb values according to the 
				//corresponding value in the matrix
				Pixel& pix = img (x+i, y+j);
				red += pix.r() * k[center+i][center +j];
        			green += pix.g() * k[center+i][center +j];
        			blue += pix.b() * k[center+i][center +j];
     			}
		}
  	}
	//5x5 Matrix
	if (k.size() == 5) {
		// Accesses all of the neighboring pixels
		int center = k.size() /2;
		for( int i = -center; i <= center; i++){
			for( int j = -center; j <= center; j++){
				//Changes rgb values according to the 
				//corresponding value in the matrix
				Pixel& pix = img (x+i, y+j);
				red += pix.r() * k[center+i] [center +j];
          			green += pix.g() * k[center+i] [center +j];
          			blue += pix.b() * k[center+i] [center +j];
			}
		}
    	}

	//Checks all new RGB values are within range [0,255]
	pix.set_r(clamp(0, 255, red));
	pix.set_g(clamp(0, 255, green));
	pix.set_b(clamp(0, 255, blue));
	return pix;
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
