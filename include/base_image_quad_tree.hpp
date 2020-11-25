#ifndef QUAD_TREE_BASE_IMAGE_QUAD_TREE_HPP_
#define QUAD_TREE_BASE_IMAGE_QUAD_TREE_HPP_

#include <vector>

namespace eda {

namespace quad_tree {

class BaseImageQuadTree;

} // namespace quad_tree

} // namespace eda

#include "base_quad_tree.hpp"
#include "image.hpp"
#include "node.hpp"

namespace eda {

namespace quad_tree {

class BaseImageQuadTree : public BaseQuadTree<int, Node<int> > {
protected:
	int width_;
	int height_;

public:
	BaseImageQuadTree(int, int);
	BaseImageQuadTree(Image &);

	void print_grid();
	int width();
	int height();

protected:
	void print_grid(Node<int> *, std::vector<std::vector<int> > &);
};

} // namespace quad_tree

} // namespace eda

// #include "impl/base_image_quad_tree.ipp"

#endif // QUAD_TREE_BASE_IMAGE_QUAD_TREE_HPP_
