#include <iostream>

#include "image.hpp"
#include "pixel.hpp"
#include "scan_quad_tree.hpp"

using namespace std;

int main() {
	eda::quad_tree::ScanQuadTree s(10, 10);

	s.insert(5, 5, 0);
	s.insert(2, 0, 1);
	s.insert(4, 9, 0);
	s.insert(8, 7, 0);
	s.insert(7, 6, 1);

	eda::quad_tree::Image image(s);

	image.print();
	s.print();
	s.print_grid();

	image.set_cell(5, 5, 1);

	eda::quad_tree::ScanQuadTree s2(image);

	cout << "OK" << endl;

	s2.print();
	s2.print_grid();
	
	return 0;
}
