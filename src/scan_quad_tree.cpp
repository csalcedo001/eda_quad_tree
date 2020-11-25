#include "scan_quad_tree.hpp"
#include "node.hpp"

namespace eda {

namespace quad_tree {

ScanQuadTree::ScanQuadTree(int width, int height) :
	BaseImageQuadTree(width, height)
{ }

ScanQuadTree::ScanQuadTree(Image &image) :
	BaseImageQuadTree(image)
{ }

void ScanQuadTree::build(Node<int> *&node, Image &image, int x_i, int x_f, int y_i, int y_f) {
	if (this->same_color(image, x_i, x_f, y_i, y_f)) {
		return;
	}

	int mid_x = (x_i + x_f) / 2;
	int mid_y = (y_i + y_f) / 2;

	int value = 0;
	node = new Node<int>(mid_x, mid_y, value);
	
	this->build(node->children_[0], image, x_i, mid_x, y_i, mid_y);
	this->build(node->children_[1], image, mid_x + 1, x_f, y_i, mid_y);
	this->build(node->children_[2], image, x_i, mid_x, mid_y + 1, y_f);
	this->build(node->children_[3], image, mid_x + 1, x_f, mid_y + 1, y_f);
}

bool ScanQuadTree::same_color(Image &image, int x_i, int x_f, int y_i, int y_f) {
	int color = image.grid()[x_i][y_i];

	for (int i = x_i; i <= x_f; i++) {
		for (int j = y_i; j <= y_f; i++) {
			if (image.grid()[i][j] != color) {
				return false;
			}
		}
	}

	return true;
}

// void ScanQuadTree::build(std::vector<std::vector<int> > &data) {
// 	if (data.size() < 1 || data[0].size() < 1) return;
// 
// 	this->build(this->head_, data, 0, data[0].size() - 1, 0, data.size() - 1);
// }
// 
// void ScanQuadTree::print_grid(int n) {
// 	std::vector<std::vector<int> > data(n, std::vector<int>(n, 0));
// 
// 	this->print_grid(this->head_, data);
// 
// 	for (auto v : data) {
// 		for (auto e : v) {
// 			std::cout << (e == 0 ? '.' : 'X');
// 		}
// 		std::cout << std::endl;
// 	}
// }
// 
// void ScanQuadTree::build(Node<int> *&node, std::vector<std::vector<int> > &data, int x_i, int x_f, int y_i, int y_f) {
// 	if (this->same_color(data, x_i, x_f, y_i, y_f)) {
// 		return;
// 	}
// 
// 	int mid_x = (x_i + x_f) / 2;
// 	int mid_y = (y_i + y_f) / 2;
// 
// 	node = new Node<int>(mid_x, mid_y, "");
// 	
// 	this->build(node->children_[0], data, x_i, mid_x, y_i, mid_y);
// 	this->build(node->children_[1], data, mid_x + 1, x_f, y_i, mid_y);
// 	this->build(node->children_[2], data, x_i, mid_x, mid_y + 1, y_f);
// 	this->build(node->children_[3], data, mid_x + 1, x_f, mid_y + 1, y_f);
// }
// 
// bool ScanQuadTree::same_color(std::vector<std::vector<int> > &data, int x_i, int x_f, int y_i, int y_f) {
// 	int color = data[x_i][y_i];
// 
// 	for (int i = x_i; i <= x_f; i++) {
// 		for (int j = y_i; j <= y_f; i++) {
// 			if (data[i][j] != color) {
// 				return false;
// 			}
// 		}
// 	}
// 
// 	return true;
// }
// 
// void ScanQuadTree::print_grid(Node<int> *node, std::vector<std::vector<int> > &data) {
// 	if (node != nullptr) {
// 		this->print_grid(node->children_[0], data);
// 		this->print_grid(node->children_[1], data);
// 
// 		data[node->y_][node->x_] = 1;
// 
// 		this->print_grid(node->children_[2], data);
// 		this->print_grid(node->children_[3], data);
// 	}
// }

} // namespace quad_tree

} // namespace eda
