#ifndef QUAD_TREE_NODE_IPP_
#define QUAD_TREE_NODE_IPP_

#include "base_node.hpp"

namespace eda {

namespace quad_tree {

template <typename T>
Node<T>::Node(T x, T y, std::string name) :
	BaseNode<T, Node<T> >(x, y, name)
{ }

} // namespace quad_tree

} // namespace eda

#endif // QUAD_TREE_NODE_IPP_
