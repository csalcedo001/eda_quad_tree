#ifndef QUAD_TREE_NODE_IPP_
#define QUAD_TREE_NODE_IPP_

#include "base_node.hpp"

namespace eda {

namespace quad_tree {

template <typename T>
Node<T>::Node(int x, int y, T &data) :
	BaseNode<T, Node<T> >(x, y, data)
{ }

} // namespace quad_tree

} // namespace eda

#endif // QUAD_TREE_NODE_IPP_
