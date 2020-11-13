#ifndef QUAD_TREE_NODE_HPP_
#define QUAD_TREE_NODE_HPP_

#include "base_node.hpp"

namespace eda {

namespace quad_tree {

template <typename T>
class Node : public BaseNode<T, Node<T> > {
public:
	Node(T, T, std::string);
};

} // namespace quad_tree

} // namespace eda

#include "impl/node.ipp"

#endif // QUAD_TREE_NODE_HPP_
