#ifndef QUAD_TREE_BASE_QUAD_TREE_IPP_
#define QUAD_TREE_BASE_QUAD_TREE_IPP_

#include "base_quad_tree.hpp"

#include <iostream>
#include <vector>

namespace eda {

namespace quad_tree {

template <typename T, class Node>
BaseQuadTree<T, Node>::BaseQuadTree() :
	head_(nullptr)
{ }

template <typename T, class Node>
BaseQuadTree<T, Node>::~BaseQuadTree() {
	this->clear();
}

template <typename T, class Node>
void BaseQuadTree<T, Node>::insert(int x, int y, T data) {
	this->insert(this->head_, x, y, data);
}

template <typename T, class Node>
void BaseQuadTree<T, Node>::print() {
	this->print(this->head_, 0);
}

template <typename T, class Node>
void BaseQuadTree<T, Node>::clear() {
	this->kill(this->head_);
}

template <typename T, class Node>
void BaseQuadTree<T, Node>::insert(Node *&node, int x, int y, T data) {
	if (node == nullptr) {
		node = new Node(x, y, data);
		return;
	}

	bool right_side = x > node->x_;
	bool down_side = y > node->y_;

	this->insert(node->children_[(down_side << 1) + right_side], x, y, data);
}

template <typename T, class Node>
void BaseQuadTree<T, Node>::print(Node *node, int level) {
	if (node != nullptr) {
		this->print(node->children_[0], level + 1);
		this->print(node->children_[1], level + 1);

		for (int i = 0; i < level; i++) {
			std::cout << "    ";
		}
		std::cout << node->x_ << ' ' << node->y_ << ": " << node->data_ << std::endl;

		this->print(node->children_[2], level + 1);
		this->print(node->children_[3], level + 1);
	}
}

template <typename T, class Node>
void BaseQuadTree<T, Node>::kill(Node *node) {
	if (node != nullptr) {
		this->kill(node->children_[0]);
		this->kill(node->children_[1]);
		this->kill(node->children_[2]);
		this->kill(node->children_[3]);
	}
}

} // namespace quad_tree

} // namespace eda

#endif // QUAD_TREE_BASE_QUAD_TREE_IPP_
