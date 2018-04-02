#ifndef FILTER_H
#define FILTER_H
#include <iostream>
#include <string>
#include <vector>
#include "Pixel.h"
#include "Header.h"
#include "Image.h"

using namespace std;
using Matrix = vector<vector<int>>;

namespace Filter{
  extern Matrix K3,K5;
  Image& sharpen(Image&, Matrix&);
  Pixel apply_kernel(Image&, int x, int y, Matrix&);
  int clampt(int, int int);
}
#endif
