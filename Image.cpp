/**
Clare DuVal and Isabella Gebhart
CPSC 002, 001 Spring 2018
ckduval, igehbar
**/
#include "Image.h"
#include <iterator>
// Param constructor
Image::Image (ifstream& in): HDR(Image::read_header(in)), pixel(Image::read_pixels(this->HDR,in)) {}

// Copy constructor
Image::Image (const Image& img): HDR(img.HDR), pixel(img.pixel) {
}

// Destructor
Image::~Image () { // Don't allow memory leaks!
}

// This fucntion reads the header information found in the ppm
// this function returns the magic number, width, height, 
// and max color 
Header Image::read_header (ifstream& in) {
  string magic;
  int w, h, mc;

  in >> magic;
  Image::ignore_comments(in);
  in >> w;
  Image::ignore_comments(in);
  in >> h;
  Image::ignore_comments(in);
  in >> mc;
  in.ignore(256, '\n');
  return Header(magic, w, h, mc);
}

// this function ignores comments and white space
// that can be found in the header. 
// this will help prevent errors that would be caused by
// these things
void Image::ignore_comments (ifstream& in) {
  char c;
  in.get(c);

  while ( isspace(c) || c == '#') {
    if (c == '#')
      in.ignore(256, '\n');
    in.get(c);
  }

  in.unget();
}

// This function reads in information about the pixels
// this is now set up to return a vector filled with the 
// information about the pixels
// This function  uses information from the header and
// the image that will be taken in
vector<Pixel> Image::read_pixels (const Header& hdr, ifstream& in) {
  vector<Pixel> pixels;
 int num_pixels = hdr.width() * hdr.height();

  if (hdr.magic() == "P3") {
    uint r,g,b;
    for (int i = 0; i < num_pixels; i++) {
      in >> r >> g >> b;
      pixels.push_back(Pixel(r,g,b));
    }
  } else {
    uint8_t r,g,b;
    for (int i = 0; i < num_pixels; i++) {
      r = in.get();
      g = in.get();
      b = in.get();
      pixels.push_back(Pixel(r,g,b));
    }
  }

  return pixels;
}

// accessors
const Header& Image::header () const { return this->HDR; }
const vector<Pixel> Image::pixels () const { return pixels }

// If someone wants to change the header, the Image controls
// which fields it will to expose
void Image::make_p3 () { this->HDR.magic() = "P3"; }
void Image::make_p6 () { this->HDR.magic() = "P6"; }

// This function writes a header for the new image
void Image::write_header (ofstream& out) const {
  out << this->HDR.magic() << " "
      << this->HDR.width() << " "
      << this->HDR.height() << " "
      << this->HDR.max_color() << "\n";
}

// writes values of pixels to new image
//this function used the .at() vector capability
// to help fill the pixel array
void Image::write_to (ofstream& out) const {
  write_header(out);

  int num_pixels = this->HDR.width() * this->HDR.height();

  if (this->HDR.magic() == "P3") {
    for (int i = 0; i < num_pixels; i++) {
       Pixel p = this->pixel.at(i);
      out << (int) p.r() << ' '
          << (int) p.g() << ' '
          << (int) p.b() << ' ';
    }
  } else {
    for (int i = 0; i < num_pixels; i++) {
      Pixel p = this->pixel.at(i);
      out << p.r() << p.g() << p.b();
    }
  }
}

// Returns value of image and will 
Image& Image::operator=(const Image& rhs) {
  if (this == &rhs) return *this; 
  this->HDR = rhs.HDR; 

  this->pixel = rhs.pixel;
  return *this;
}

// This function gets the value of one pixel 
// it will return the point at this value using
// .at() 
Pixel& Image::operator() (int x, int y) {
  int ndx = (this->HDR.width() * y) + x;
  return this->pixel.at(ndx);
}
