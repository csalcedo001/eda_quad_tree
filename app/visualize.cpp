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

	image.print();

	return 0;
}
