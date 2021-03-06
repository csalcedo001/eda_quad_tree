#include <iostream>
#include <fstream>
#include <sstream>

#include "image.hpp"
#include "scan_quad_tree.hpp"
#include "pixel.hpp"

using namespace std;

int main(int argc, char **argv) {
	if (argc != 3) {
		cerr << "error: missing arguments. Usage: " << argv[0] << " <output_path> <threshold>" << endl;
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


	int width, height;

	cin >> width >> height;

	eda::quad_tree::Image image(width, height);

	eda::quad_tree::Pixel pixel;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> pixel;

			image.set_cell(j, i, pixel);
		}
	}

	eda::quad_tree::ScanQuadTree quad_tree(image, threshold);

	quad_tree.save(output_file);

	return 0;
}
