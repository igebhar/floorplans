//FILTER.CPP//

/**
Clare DuVal and Isabella Gebhart
CPSC 002, 001 Spring 2018
ckduval, igehbar
**/

#include <iterator>
#include "filter.h"
#include "Image.h"

Matrix Filter::K3 =
{{0,-1,0},
 {-1,5,-1},
 {0,-1,0}};

Matrix Filter::K5 =
{{0,0,-1,0,0},
 {0,0,-1,0,0},
 {-1,-1,9,-1,-1},
 {0,0,-1,0,0},
 {0,0,-1,0,0}};
// This function takes one pixel passes the pixel to apply_kernel function
// calculates the new RGB values returns the new pixel values
// Parameters: input image, kernel filter
// output new image returned
Image& Filter::sharpen(Image& img, Matrix& k) {

	int i = 0;

	int center = k.size()/2;
	int rows = img.header().height();
	int columns = img.header().width();

	Image copy(img);

	for (int y = center; y < (columns - center); y++) {
		for (int x = center; x < (rows - center); x++) {
			img.pixel[i] = apply_kernel(img, x, y, k);
			i++;
		}
	}

   return img;
}



// This function applies the new kernel filter to a single pixel
// Parameters: Image passes in from sharpen function (image& img)
// column location of the current pixel (x0
//  row location of the current pixel (y)
// kernel filter
// returns the new pixel

Pixel Filter::apply_kernel(Image& img, int x, int y, Matrix& k){
        Pixel pix;
	//3x3 Matrix
        if (k.size() == 3) {
		int i, j;
                //Accesses all of the neighboring pixels
		int center = k.size / 2;
		for (int y = center; y < 9; y++) {
			pix.r =+ y.r*k<>; //
			pix.g =+ y.g*k<>;
			pix.b =+ y.b*k<>;
		}
		for( int i = -center; i <= center; i++){
			for( int j = -center; j <= center; j++){
				Pixel& pix = img (x+i, y+j);
				red += pix.r * k[center+i] [center +j]; 
			}
		}

        }

        //5x5 Matrix
	        if (k.size() == 5) {
			int i, i; 
			// Accesses all of the neighboring pixels
			int center = k.size() /2;
			for (int y = center ; y < 25; y++) {
				pix.r =+ y.r*k<>;
				pix.g =+ y.g*k<>;
				pix.b =+ y.b*k<>;
			}
			for( int i = -center; i <= center; i++){
				for( int j = -center; j <= center; j++){
					Pixel& pix = img (x+i, y+j);
					red += pix.r * k[center+i] [center +j]; 
				}
			}
			
        }

	pix.r = clamp(0, 255, pix.r);
	pix.g = clamp(0, 255, pix.g);
	pix.b = clamp(0, 255, pix.b);

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
