//IMAGE.CPP//

/**
Clare DuVal and Isabella Gebhart
CPSC 002, 001 Spring 2018
ckduval, igehbar
**/
#include "Image.h"
#include <iterator>
// Param constructor
Image::Image (ifstream& in):
	HDR(Image::read_header(in)), pixel(Image::read_pixels(this->HDR,in)) {
}

// Copy constructor
Image::Image (const Image& img): HDR(img.HDR), pixel(img.pixel) {
}

// Destructor
Image::~Image () { // Don't allow memory leaks!
}

/*
const Header& Image::header() const { return this->HDR;}
const vector<Pixel>& Image::pixels() const { retrun this->PIX }

Pixel& Image::operator() (int x, int y) {
	int ndx = (this->HDR.width() * y) +x;
	return this->PIX[ndx];
}

*/
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

// This function allocates memory!
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
const vector<Pixel> Image::pixels () const { return this->pixel; }

// If someone wants to change the header, the Image controls
// which fields it will to expose
void Image::make_p3 () { this->HDR.magic() = "P3"; }
void Image::make_p6 () { this->HDR.magic() = "P6"; }

void Image::write_header (ofstream& out) const {
  out << this->HDR.magic() << " "
      << this->HDR.width() << " "
      << this->HDR.height() << " "
      << this->HDR.max_color() << "\n";
}

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

// This function is important!
Image& Image::operator=(const Image& rhs) {
  if (this == &rhs) return *this; // Why do we need this? Hint: delete[]
  // Header is simple
  this->HDR = rhs.HDR;  // Assignment operator

  this->pixel = rhs.pixel;
  return *this;
}

// Get one pixel
Pixel& Image::operator() (int x, int y) {
  int ndx = (this->HDR.width() * y) + x;
  return this->pixel.at(ndx);
}
