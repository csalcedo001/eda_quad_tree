#ifndef QUAD_TREE_SCAN_QUAD_TREE_HPP_
#define QUAD_TREE_SCAN_QUAD_TREE_HPP_

#include "base_image_quad_tree.hpp"
#include "node.hpp"
#include "pixel.hpp"

namespace eda {

namespace quad_tree {

class ScanQuadTree : public BaseImageQuadTree {
public:
	ScanQuadTree(int, int);
	ScanQuadTree(Image &);

private:
	void build(Node<Pixel> *&, Image &, int, int, int, int);
	bool same_color(Image &, int, int, int, int);
};

} // namespace quad_tree

} // namespace eda

#endif // QUAD_TREE_SCAN_QUAD_TREE_HPP_
