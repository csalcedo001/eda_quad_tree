#include <iostream>

#include "scan_quad_tree.hpp"

using namespace std;

int main() {
	int n;

	cin >> n;

	eda::quad_tree::Image image(n, n);

	int c;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;

			image.set_cell(i, j, c);
		}
	}

	eda::quad_tree::ScanQuadTree scan_quad_tree(image);

	scan_quad_tree.print_grid();
	scan_quad_tree.print();

	return 0;
}
