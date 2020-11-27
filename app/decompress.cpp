#include <iostream>
#include <fstream>
#include <sstream>

#include "image.hpp"
#include "scan_quad_tree.hpp"
#include "pixel.hpp"

using namespace std;

int main(int argc, char **argv) {
	if (argc != 3) {
		cerr << "error: missing argument. Usage: " << argv[0] << " <quad_tree_path> <image_path>" << endl;
		return 1;
	}

	string quad_tree_path(argv[1]);
	fstream quad_tree_file(quad_tree_path, ios::binary | ios::in);

	if (!quad_tree_file.is_open()) {
		cerr << "error: unable to open " << argv[1] << endl;
		return 1;
	}

	string image_path(argv[2]);
	fstream image_file(image_path, ios::out);

	if (!image_file.is_open()) {
		cerr << "error: unable to open " << argv[2] << endl;
		return 1;
	}

	// TODO: update data loading to restore image width and height
	eda::quad_tree::ScanQuadTree quad_tree(0, 0, 0);

	quad_tree.load(quad_tree_file);

	eda::quad_tree::Image image(quad_tree);

	image_file << image.width() << ' ' << image.height() << endl;

	for (auto row : image.grid()) {
		for (auto pixel : row) {
			image_file << pixel << endl;
		}
	}

	return 0;
}
