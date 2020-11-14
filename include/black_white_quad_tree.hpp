#ifndef QUAD_TREE_BLACK_WHITE_QUAD_TREE_HPP_
#define QUAD_TREE_BLACK_WHITE_QUAD_TREE_HPP_

#include "base_quad_tree.hpp"
#include "node.hpp"

namespace eda {

namespace quad_tree {

class BlackWhiteQuadTree : public BaseQuadTree<int, Node<int> > {
public:
	void build(std::vector<std::vector<int> > &);

private:
	std::pair<int, Node<int> *> build(std::vector<std::vector<int> > &, int, int, int, int);
};

} // namespace quad_tree

} // namespace eda

#include "impl/black_white_quad_tree.ipp"

#endif // QUAD_TREE_BASE_QUAD_TREE_HPP_
