//DRIVER.CPP//

/**
Clare DuVal and Isabella Gebhart
CPSC 002, 002 Spring 2018
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
    std::string k3 = "k3_";
    std::ofstream out(k3 + argv[2]);
    std::string k5 = "k5_";
    std::ofstream out2(k5 + argv[2]);

    if (!(in && out)) {
      std::cerr << "Could not open input/output\n";
      return 1;
    }

    //Creates 2 images with the input 
    Image puppy(in); //To be altered by K3
    // this creates a copy of the puppy
    Image puppy2(puppy); //To be altered by K5

    //Sharpens both images with corresponding matrix (K3/K5)
    Filter::sharpen(puppy, Filter::K3);
    Filter::sharpen(puppy2, Filter::K5);

    //Writes a new image according to the returned img from sharpen
    puppy.write_to(out);
    puppy2.write_to(out2);
  
    //Closes the files
    in.close();
    out.close();
    out2.close();
  
    return 0;
}
