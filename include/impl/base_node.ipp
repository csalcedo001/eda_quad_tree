#ifndef QUAD_TREE_BASE_NODE_IPP_
#define QUAD_TREE_BASE_NODE_IPP_

#include "base_node.hpp"

namespace eda {

namespace quad_tree {

template <typename T, class Node>
BaseNode<T, Node>::BaseNode(int x, int y, T &data) :
	x_(x),
	y_(y),
	data_(data)
{
	int l = 4;

	while (l--) {
		this->children_[l] = nullptr;
	}
}

template <typename T, class Node>
bool BaseNode<T, Node>::is_leave() {
	int l = 4;

	while (l--) {
		if (this->children_[l] != nullptr) return false;
	}

	return true;
}

} // namespace quad_tree

} // namespace eda

#endif // QUAD_TREE_BASE_NODE_IPP_
