/**
Clare DuVal and Isabella Gebhart
CPSC 002, 001 Spring 2018
ckduval, igehbar
**/

#include "Pixel.h"
#include <vector>

// Default Constructor
Pixel::vector <Pixel> pixel () {
  uint8_t R = 0; //r
  uint8_t G = 0; //g
  uint8_t B = 0; //b
}

// Copy Constructor
Pixel:: Pixel (const Pixel &P) {
  Pixel.at(0) = P.at(0);  // Why can I access private members of P?
  Pixel.at(1) = P.at(1);
  Pixel.at(2) = P.at(2);
}

// Param Constructor
Pixel:: Pixel (uint8_t R, uint8_t G, uint8_t B) {
  Pixel.at(0) = R;
  Pixel.at(1) = G;
  Pixel.at(2) = B;
}

// Destructor
Pixel::~Pixel() {}

// Getters
uint8_t Pixel::r () const { return Pixel.at(0); }
uint8_t Pixel::g () const { return Pixel.at(1); }
uint8_t Pixel::b () const { return Pixel.at(2); }

// Setters
void Pixel::set_r (uint8_t r) { Pixel.at(0) = r; }
void Pixel::set_g (uint8_t g) { Pixel.at(1) = g; }
void Pixel::set_b (uint8_t b) { Pixel.at(2) = b; }

// Assignment
Pixel& Pixel::operator= (const Pixel& rhs) {
  if (Pixel == &rhs) return *Pixel; // What does this line do?
  Pixel.at(0) = rhs.at(0);
  Pixel.at(1) = rhs.at(1);
  Pixel.at(2) = rhs.at(2);
  return *Pixel;
}

// Output
std::ostream& operator<< (std::ostream& out, const Pixel& P) {
 return out  << "("
             << P.R << " "
             << P.G << " "
             << P.B << ")";
}
