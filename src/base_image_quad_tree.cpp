#include "base_image_quad_tree.hpp"

#include <vector>

#include "base_quad_tree.hpp"
#include "image.hpp"
#include "node.hpp"

namespace eda {

namespace quad_tree {

BaseImageQuadTree::BaseImageQuadTree(int width, int height) :
	BaseQuadTree<int, Node<int> >(),
	width_(width),
	height_(height)
{ }

int BaseImageQuadTree::width() {
	return this->width_;
}

int BaseImageQuadTree::height() {
	return this->height_;
}

void BaseImageQuadTree::print_grid() {
	std::vector<std::vector<int> > data(this->height_, std::vector<int>(this->width_, 0));

	this->print_grid(this->head_, data);

	for (auto v : data) {
		for (auto e : v) {
			std::cout << (e == 0 ? '.' : 'X');
		}
		std::cout << std::endl;
	}
}

void BaseImageQuadTree::print_grid(Node<int> *node, std::vector<std::vector<int> > &data) {
	if (node != nullptr) {
		this->print_grid(node->children_[0], data);
		this->print_grid(node->children_[1], data);

		data[node->y_][node->x_] = 1;

		this->print_grid(node->children_[2], data);
		this->print_grid(node->children_[3], data);
	}
}

} // namespace quad_tree

} // namespace eda
