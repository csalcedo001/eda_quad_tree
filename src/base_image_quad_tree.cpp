#include "base_image_quad_tree.hpp"

#include <vector>

#include "base_quad_tree.hpp"
#include "image.hpp"
#include "node.hpp"
#include "pixel.hpp"

namespace eda {

namespace quad_tree {

BaseImageQuadTree::BaseImageQuadTree(int width, int height, double threshold) :
	BaseQuadTree<Pixel, Node<Pixel> >(),
	width_(width),
	height_(height),
	threshold_(threshold)
{ }

BaseImageQuadTree::BaseImageQuadTree(Image &image, double threshold) :
	BaseQuadTree<Pixel, Node<Pixel> >(),
	width_(image.width_),
	height_(image.height_),
	threshold_(threshold)
{ }

int BaseImageQuadTree::width() {
	return this->width_;
}

int BaseImageQuadTree::height() {
	return this->height_;
}

void BaseImageQuadTree::print_grid() {
	std::vector<std::vector<bool> > grid(this->height_, std::vector<bool>(this->width_, false));

	this->print_grid(this->head_, grid);

	for (auto row : grid) {
		for (auto cell : row) {
			std::cout << (cell ? 'X' : '.');
		}
		std::cout << std::endl;
	}
}

void BaseImageQuadTree::print_grid(Node<Pixel> *node, std::vector<std::vector<bool> > &grid) {
	if (node != nullptr) {
		this->print_grid(node->children_[0], grid);
		this->print_grid(node->children_[1], grid);

		grid[node->y_][node->x_] = true;

		this->print_grid(node->children_[2], grid);
		this->print_grid(node->children_[3], grid);
	}
}

} // namespace quad_tree

} // namespace eda
