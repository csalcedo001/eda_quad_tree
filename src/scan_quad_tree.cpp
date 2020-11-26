#include "scan_quad_tree.hpp"
#include "node.hpp"

namespace eda {

namespace quad_tree {

ScanQuadTree::ScanQuadTree(int width, int height, double threshold) :
	BaseImageQuadTree(width, height, threshold)
{ }

ScanQuadTree::ScanQuadTree(Image &image, double threshold) :
	BaseImageQuadTree(image, threshold)
{
	this->build(this->head_, image, 0, this->width_ - 1, 0, this->height_ - 1);
}

void ScanQuadTree::build(Node<Pixel> *&node, Image &image, int x_i, int x_f, int y_i, int y_f) {
	int mid_x = (x_i + x_f) / 2;
	int mid_y = (y_i + y_f) / 2;

	if (x_i > x_f || y_i > y_f) {
		node = nullptr;
		return;
	}

	if (this->same_color(image, x_i, x_f, y_i, y_f)) {
		node = new Node<Pixel>(mid_x, mid_y, this->average_pixel( image, x_i, x_f, y_i, y_f));
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

	int min_color, max_color;

	min_color = max_color = image.grid()[x_i][y_i].average();

	for (int i = x_i; i <= x_f; i++) {
		for (int j = y_i; j <= y_f; j++) {
			int color = image.grid()[i][j].average();

			if (color < min_color) min_color = color;
			if (color > max_color) max_color = color;

			if (max_color - min_color > this->threshold_) {
				return false;
			}
		}
	}

	return true;
}

Pixel ScanQuadTree::average_pixel(Image &image, int x_i, int x_f, int y_i, int y_f) {
	int r = 0, g = 0, b = 0;

	for (int i = x_i; i <= x_f; i++) {
		for (int j = y_i; j <= y_f; j++) {
			Pixel pixel = image.grid()[i][j];

			r += pixel.r;
			g += pixel.g;
			b += pixel.b;
		}
	}

	int total = (x_f - x_i + 1) * (y_f - y_i + 1);

	return Pixel(r / total, g / total, b / total);
}

} // namespace quad_tree

} // namespace eda
