#include <iostream>

#include "image.hpp"

using namespace std;

int main() {
	eda::quad_tree::Image image(10, 10);

	image.print_grid();
	
	return 0;
}
