#ifndef QUAD_TREE_BASE_QUAD_TREE_IPP_
#define QUAD_TREE_BASE_QUAD_TREE_IPP_

#include "base_quad_tree.hpp"

namespace eda {

namespace quad_tree {

template <typename T, class Node>
BaseQuadTree<T, Node>::BaseQuadTree() :
	head_(nullptr)
{ }

template <typename T, class Node>
void BaseQuadTree<T, Node>::insert(T x, T y, std::string name) {
	this->insert(this->head_, x, y, name);
}

template <typename T, class Node>
void BaseQuadTree<T, Node>::print() {
	this->print(this->head_, 0);
}

template <typename T, class Node>
void BaseQuadTree<T, Node>::insert(Node *&node, T x, T y, std::string name) {
	if (node == nullptr) {
		node = new Node(x, y, name);
		return;
	}

	bool left_side = x < node->x_;
	bool top_side = y < node->y_;

	this->insert(node->children_[(top_side << 1) | left_side], x, y, name);
}

template <typename T, class Node>
void BaseQuadTree<T, Node>::print(Node *node, int level) {
	if (node != nullptr) {
		this->print(node->children_[0], level + 1);
		this->print(node->children_[1], level + 1);

		for (int i = 0; i < level; i++) {
			std::cout << "    ";
		}
		std::cout << node->x_ << ' ' << node->y_ << std::endl;

		this->print(node->children_[2], level + 1);
		this->print(node->children_[3], level + 1);
	}
}

} // namespace quad_tree

} // namespace eda

#endif // QUAD_TREE_BASE_QUAD_TREE_IPP_
