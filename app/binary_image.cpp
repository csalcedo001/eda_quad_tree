#include <iostream>

#include "scan_quad_tree.hpp"
#include "pixel.hpp"

using namespace std;

int main() {
	int n;

	cin >> n;

	eda::quad_tree::Image image(n, n);

	int c;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;

			image.set_cell(j, i, eda::quad_tree::Pixel(c * 255));
		}
	}

	eda::quad_tree::ScanQuadTree scan_quad_tree(image, 0);

	eda::quad_tree::Image reconstructed_image(scan_quad_tree);

	cout << "Input image:" << endl;
	image.print();

	cout << "Compressed quad tree grid:" << endl;
	scan_quad_tree.print_grid();

	cout << "Reconstructed image:" << endl;
	reconstructed_image.print();

	return 0;
}
