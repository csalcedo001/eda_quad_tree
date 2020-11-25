#ifndef QUAD_TREE_SCAN_QUAD_TREE_HPP_
#define QUAD_TREE_SCAN_QUAD_TREE_HPP_

#include "base_image_quad_tree.hpp"
#include "node.hpp"

namespace eda {

namespace quad_tree {

class ScanQuadTree : public BaseImageQuadTree {
public:
	ScanQuadTree(int, int);
	ScanQuadTree(Image &);

private:
	void build(Node<int> *&, Image &, int, int, int, int);
	bool same_color(Image &, int, int, int, int);

// public:
// 	void build(std::vector<std::vector<int> > &);
// 	void print_grid(int n);
// 
// private:
// 	void build(Node<int> *&, std::vector<std::vector<int> > &, int, int, int, int);
// 	bool same_color(std::vector<std::vector<int> > &, int, int, int, int);
// 	void print_grid(Node<int> *, std::vector<std::vector<int> > &);
};

} // namespace quad_tree

} // namespace eda

#endif // QUAD_TREE_SCAN_QUAD_TREE_HPP_
