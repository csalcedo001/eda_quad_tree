#include "image.hpp"

#include <vector>

#include "base_image_quad_tree.hpp"

namespace eda {

namespace quad_tree {

Image::Image(const Image &image) : 
	width_(image.width_),
	height_(image.height_),
	grid_(image.grid_)
{ }

Image::Image(int width, int height) :
	width_(width),
	height_(height),
	grid_(height, std::vector<int>(width, 0))
{ }

Image::Image(BaseImageQuadTree &tree) :
	width_(tree.width()),
	height_(tree.height())
{
	// TODO: fill grid from quad tree
}

int Image::width() {
	return this->width_;
}

int Image::height() {
	return this->height_;
}

void Image::set_cell(int x, int y, int value) {
	this->grid_[x][y] = value;
}

void Image::print() {
	for (auto v : this->grid_) {
		for (auto e : v) {
			std::cout << (e == 0 ? '.' : 'X');
		}
		std::cout << std::endl;
	}
}

} // namespace quad_tree

} // namespace eda
