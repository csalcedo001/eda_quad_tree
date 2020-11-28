#include <iostream>

#include "image.hpp"
#include "pixel.hpp"
#include "scan_quad_tree.hpp"

using namespace std;

int main() {
	eda::quad_tree::ScanQuadTree s(10, 10, 1);

	s.insert(5, 5, 0);
	s.insert(2, 0, 255);
	s.insert(4, 9, 0);
	s.insert(8, 7, 0);
	s.insert(7, 6, 255);

	eda::quad_tree::Image image(s);

	cout << "Print image" << endl;
	image.print();
	cout << "Print quad tree" << endl;
	s.print();
	cout << "Print quad tree grid" << endl;
	s.print_grid();

	image.set_cell(1, 8, 255);

	eda::quad_tree::ScanQuadTree s2(image, 1);


	cout << "Print image" << endl;
	image.print();
	cout << "Print quad tree" << endl;
	s2.print();
	cout << "Print quad tree grid" << endl;
	s2.print_grid();
	
	return 0;
}
