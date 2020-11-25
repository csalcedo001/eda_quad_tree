#include <iostream>

#include "image.hpp"
#include "pixel.hpp"
#include "scan_quad_tree.hpp"

using namespace std;

int main() {
	eda::quad_tree::ScanQuadTree s(10, 10);

	eda::quad_tree::Image image(s);

	image.print();
	s.print();
	
	return 0;
}
