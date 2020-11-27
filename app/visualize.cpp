#include <iostream>

#include "scan_quad_tree.hpp"
#include "pixel.hpp"

using namespace std;

int main() {
	int n;

	cin >> n;

	eda::quad_tree::Image image(n, n);

	int c;

	eda::quad_tree::Pixel pixel;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> pixel;

			image.set_cell(j, i, pixel);
		}
	}

	image.print();

	return 0;
}
