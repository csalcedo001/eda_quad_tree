#ifndef QUAD_TREE_BASE_NODE_IPP_
#define QUAD_TREE_BASE_NODE_IPP_

#include "base_node.hpp"

namespace eda {

namespace quad_tree {

template <typename T, class Node>
BaseNode<T, Node>::BaseNode(T x, T y, std::string name) :
	x_(x),
	y_(y),
	name_(name)
{ }

} // namespace quad_tree

} // namespace eda

#endif // QUAD_TREE_BASE_NODE_IPP_
