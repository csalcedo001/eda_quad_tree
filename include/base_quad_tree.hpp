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
	~BaseQuadTree();
	void insert(int, int, T);
	void print();
	void clear();

protected:
	void insert(Node *&, int, int, T);
	void print(Node *, int level);
	void kill(Node *);
};

} // namespace quad_tree

} // namespace eda

#include "impl/base_quad_tree.ipp"

#endif // QUAD_TREE_BASE_QUAD_TREE_HPP_
