#ifndef QUAD_TREE_BASE_NODE_HPP_
#define QUAD_TREE_BASE_NODE_HPP_

namespace eda {

namespace quad_tree {

template <typename T, class Node>
class BaseNode {
public:
	T x_;
	T y_;
	std::string name_;
	Node *children_[4];

	BaseNode(T, T, std::string);
};

} // namespace quad_tree

} // namespace eda

#include "impl/base_node.ipp"

#endif // QUAD_TREE_BASE_NODE_HPP_
