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
#include "pixel.hpp"

namespace eda {

namespace quad_tree {

class BaseImageQuadTree : public BaseQuadTree<Pixel, Node<Pixel> > {
public:
	friend Image;

protected:
	int width_;
	int height_;
	double threshold_;

public:
	BaseImageQuadTree(int, int, double);
	BaseImageQuadTree(Image &, double);

	void print_grid();
	int width();
	int height();

protected:
	void print_grid(Node<Pixel> *, std::vector<std::vector<bool> > &);
};

} // namespace quad_tree

} // namespace eda

// #include "impl/base_image_quad_tree.ipp"

#endif // QUAD_TREE_BASE_IMAGE_QUAD_TREE_HPP_
