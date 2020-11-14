#ifndef QUAD_TREE_BASE_QUAD_TREE_HPP_
#define QUAD_TREE_BASE_QUAD_TREE_HPP_

namespace eda {

namespace quad_tree {

template <typename T, class Node>
class BaseQuadTree {
protected:
	Node *head_;

public:
	BaseQuadTree();
	void insert(T, T, std::string);

protected:
	void insert(Node *&, T, T, std::string);
};

} // namespace quad_tree

} // namespace eda

#include "impl/base_quad_tree.ipp"

#endif // QUAD_TREE_BASE_QUAD_TREE_HPP_
