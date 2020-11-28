#include <iostream>

#include "scan_quad_tree.hpp"
#include "pixel.hpp"

using namespace std;

int main() {
	int width, height;

	cin >> width >> height;

	eda::quad_tree::Image image(width, height);

	int c;

	eda::quad_tree::Pixel pixel;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> pixel;

			image.set_cell(j, i, pixel);
		}
	}

	eda::quad_tree::ScanQuadTree scan_quad_tree(image, 1);

	eda::quad_tree::Image reconstructed_image(scan_quad_tree);

	cout << "Input image:" << endl;
	image.print();

	cout << "Compressed quad tree grid:" << endl;
	scan_quad_tree.print_grid();

	cout << "Reconstructed image:" << endl;
	reconstructed_image.print();

	return 0;
}
