#ifndef QUAD_TREE_PIXEL_HPP_
#define QUAD_TREE_PIXEL_HPP_

#include <fstream>

namespace eda {

namespace quad_tree {

struct Pixel {
	int r;
	int g;
	int b;

	Pixel(const Pixel &);
	Pixel(int, int, int);
	Pixel(int = 0);

	double average();

	friend std::ostream& operator<<(std::ostream &, const Pixel &);
	friend std::istream& operator>>(std::istream &, Pixel &);
};

} // namespace quad_tree

} // namespace eda

#endif // QUAD_TREE_PIXEL_HPP_
