#include <iostream>
#include <fstream>
#include <sstream>

#include "image.hpp"
#include "scan_quad_tree.hpp"
#include "pixel.hpp"

using namespace std;

int main(int argc, char **argv) {
	if (argc != 3) {
		cerr << "error: missing argument. Usage: " << argv[0] << " <path> <threshold>" << endl;
		return 1;
	}

	string output_path(argv[1]);
	fstream output_file(output_path, ios::binary | ios::out);

	if (!output_file.is_open()) {
		cerr << "error: unable to open " << argv[1] << endl;
		return 1;
	}

	stringstream ss(argv[2]);
	int threshold;

	ss >> threshold;


	int n, m;

	cin >> n >> m;

	eda::quad_tree::Image image(n, m);

	int r, g, b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> r >> g >> b;

			image.set_cell(j, i, eda::quad_tree::Pixel(r, g, b));
		}
	}

	eda::quad_tree::ScanQuadTree quad_tree(image, threshold);
}
