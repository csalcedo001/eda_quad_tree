#include "pixel.hpp"

#include <fstream>

namespace eda {

namespace quad_tree {

Pixel::Pixel(const Pixel &pixel) {
	this->r = pixel.r;
	this->g = pixel.g;
	this->b = pixel.b;
}

Pixel::Pixel(int r, int g, int b) :
	r(r),
	g(g),
	b(b)
{ }

std::ostream& operator<<(std::ostream &os, const Pixel &pixel) {
	os << pixel.r << ' ' << pixel.g << ' ' << pixel.b;

	return os;
}

std::istream& operator>>(std::istream &is, Pixel &pixel) {
	is >> pixel.r >> pixel.g >> pixel.b;

	return is;
}

} // namespace quad_tree

} // namespace eda
