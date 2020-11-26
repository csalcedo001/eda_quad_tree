#include "scan_quad_tree.hpp"
#include "node.hpp"

namespace eda {

namespace quad_tree {

ScanQuadTree::ScanQuadTree(int width, int height) :
	BaseImageQuadTree(width, height)
{ }

ScanQuadTree::ScanQuadTree(Image &image) :
	BaseImageQuadTree(image)
{
	this->build(this->head_, image, 0, this->width_ - 1, 0, this->height_ - 1);
}

void ScanQuadTree::build(Node<Pixel> *&node, Image &image, int x_i, int x_f, int y_i, int y_f) {
	int mid_x = (x_i + x_f) / 2;
	int mid_y = (y_i + y_f) / 2;

	if (this->same_color(image, x_i, x_f, y_i, y_f)) {
		node = x_i > x_f || y_i > y_f ? nullptr : new Node<Pixel>(mid_x, mid_y, image.grid()[x_i][y_i]);
		return;
	}

	Pixel tmp;
	node = new Node<Pixel>(mid_x, mid_y, tmp);
	
	this->build(node->children_[0], image, x_i, mid_x, y_i, mid_y);
	this->build(node->children_[1], image, mid_x + 1, x_f, y_i, mid_y);
	this->build(node->children_[2], image, x_i, mid_x, mid_y + 1, y_f);
	this->build(node->children_[3], image, mid_x + 1, x_f, mid_y + 1, y_f);
}

bool ScanQuadTree::same_color(Image &image, int x_i, int x_f, int y_i, int y_f) {
	if (x_i > x_f || y_i > y_f) return true;

	Pixel color = image.grid()[x_i][y_i];

	for (int i = x_i; i <= x_f; i++) {
		for (int j = y_i; j <= y_f; j++) {
			if (image.grid()[i][j].average() != color.average()) {
				return false;
			}
		}
	}

	return true;
}

} // namespace quad_tree

} // namespace eda
