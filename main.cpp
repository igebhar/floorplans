//MAIN.CPP// aka DRIVER.CPP

/**
Clare DuVal and Isabella Gebhart
CPSC 002, 001 Spring 2018
ckduval, igehbar
**/

#include <iostream>
#include <string>
#include "image/Pixel.h"
#include "image/Header.h"
#include "image/Image.h"

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    std::cerr << "USAGE: ./out <in.ppm> <out.ppm>";
    return 1;
  }

  // Open files
  std::ifstream in(argv[1]);
  std::ofstream out(k3_+argv[2]);
   std::ofstream out2(k5_+argv[2]);
  
  if (!(in && out)) {
    std::cerr << "Could not open input/output\n";
    return 1;
  }

  Image puppy(in);
  
  // this creates a copy of the puppy
  Image puppy2(puppy);
  puppy.sharpen(in, Filter::K5);
  puppy2.sharpen(in, Filter::K3);
  
  puppy2.write_to(out);
  puppy.write_to(out2);
  
  

  in.close();
  out.close();

  return 0;
}
