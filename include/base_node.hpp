#ifndef QUAD_TREE_BASE_NODE_HPP_
#define QUAD_TREE_BASE_NODE_HPP_

namespace eda {

namespace quad_tree {

template <typename T, class Node>
class BaseNode {
public:
	int x_;
	int y_;
	T data_;
	Node *children_[4];

public:
	BaseNode(int, int, T &);
	bool is_leave();
};

} // namespace quad_tree

} // namespace eda

#include "impl/base_node.ipp"

#endif // QUAD_TREE_BASE_NODE_HPP_
