#ifndef QUAD_TREE_BW_BASE_QUAD_TREE_IPP_
#define QUAD_TREE_BW_BASE_QUAD_TREE_IPP_

#include "black_white_quad_tree.hpp"

#include <vector>

#include "base_quad_tree.hpp"
#include "node.hpp"

namespace eda {

namespace quad_tree {

// void BlackWhiteQuadTree::build(int x_i, int x_f, int y_i, int y_f) {
// 	if (x_i == x_f && y_i == y_f) return;
// 
// 	int mid_x = (x_i + x_f) / 2;
// 	int mid_y = (y_i + y_f) / 2;
// 
// 	int color;
// 
// 	color = data[x][j];
// 
// 	for (int i = x_i; i < mid_x; i++) {
// 		for (int j = 0; j < mid_y; j++) {
// 			if (
// 
// 	int results[4];
// 
// 	results[0] = this->build(x_i, mid_x, y_i, mid_y);
// 	results[1] = this->build(mid_i, x_f, y_i, mid_y);
// 	results[2] = this->build(x_i, mid_x, mid_y, y_f);
// 	results[3] = this->build(mid_i, x_f, mid_y, y_f);
// 
// 	if (results[0] == 0 && results[1] == 0 && results[2] == 0 results[3] == 0) {
// 		return 0;
// 	}
// 	if (results[0] == 1 && results[1] == 1 && results[2] == 1 results[3] == 1) {
// 		return 1;
// 	}
// 
// 	return 2;
// }

void BlackWhiteQuadTree::build(std::vector<std::vector<int> > &data) {
	if (data.size() < 1 || data[0].size() < 1) return;

	this->head_ = this->build(data, 0, data[0].size() - 1, 0, data.size() - 1).second;
}

std::pair<int, Node<int> *> BlackWhiteQuadTree::build(std::vector<std::vector<int> > &data, int x_i, int x_f, int y_i, int y_f) {
	if (x_i == x_f && y_i == y_f) return std::make_pair(data[x_i][y_i] == 0, nullptr);

	int mid_x = (x_i + x_f) / 2;
	int mid_y = (y_i + y_f) / 2;

	std::pair<int, Node<int> *> r[4];

	r[0] = this->build(data, x_i, mid_x, y_i, mid_y);
	r[1] = this->build(data, mid_x + 1, x_f, y_i, mid_y);
	r[2] = this->build(data, x_i, mid_x, mid_y + 1, y_f);
	r[3] = this->build(data, mid_x + 1, x_f, mid_y + 1, y_f);

	if (r[0].first == 0 && r[1].first == 0 && r[2].first == 0 && r[3].first == 0) {
		return std::make_pair(0, nullptr);
	}
	if (r[0].first == 1 && r[1].first == 1 && r[2].first == 1 && r[3].first == 1) {
		return std::make_pair(1, nullptr);
	}

	Node<int> *node = new Node<int>(mid_x, mid_y, "");

	node->children_[0] = r[0].second;
	node->children_[1] = r[1].second;
	node->children_[2] = r[2].second;
	node->children_[3] = r[3].second;

	return std::make_pair(2, node);
}

} // namespace quad_tree

} // namespace eda

#endif // QUAD_TREE_BASE_QUAD_TREE_IPP_
