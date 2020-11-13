#ifndef QUAD_TREE_QUAD_TREE_HPP_
#define QUAD_TREE_QUAD_TREE_HPP_

#include "base_quad_tree.hpp"
#include "node.hpp"

namespace eda {

namespace quad_tree {

template <typename T>
class QuadTree : public BaseQuadTree<T, Node<T> > { };

} // namespace quad_tree

} // namespace eda

#endif // QUAD_TREE_QUAD_TREE_HPP_
