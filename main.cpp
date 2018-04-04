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
  std::ofstream out(argv[3]);

  if (!(in && in2 && out)) {
    std::cerr << "Could not open input/output\n";
    return 1;
  }

  Image puppy(in);

  puppy.sharpen();
  puppy.write_to(out);

  in.close();
  out.close();

  return 0;
}
