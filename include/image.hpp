#ifndef QUAD_TREE_IMAGE_HPP_
#define QUAD_TREE_IMAGE_HPP_

#include <vector>

namespace eda {

namespace quad_tree {

class Image;

} // namespace quad_tree

} // namespace eda

#include "base_image_quad_tree.hpp"

namespace eda {

namespace quad_tree {

class Image {
public:
	friend BaseImageQuadTree;

protected:
	int width_;
	int height_;
	std::vector<std::vector<int> > grid_;

public:
	Image(const Image &);
	Image(int, int);
	Image(BaseImageQuadTree &);

	int width();
	int height();
	std::vector<std::vector<int> > &grid();
	void set_cell(int, int, int);
	void print();
};

} // namespace quad_tree

} // namespace eda

#endif // QUAD_TREE_IMAGE_HPP_
