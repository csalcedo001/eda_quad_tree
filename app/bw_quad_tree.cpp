#include <iostream>

#include "black_white_quad_tree.hpp"

using namespace std;

int main() {
	eda::quad_tree::BlackWhiteQuadTree bw_quad_tree;

	int n;

	cin >> n;

	std::vector<std::vector<int> > data(n, std::vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> data[i][j];
		}
	}

	bw_quad_tree.build(data);

	bw_quad_tree.print_grid(n);
	bw_quad_tree.print();

	return 0;
}
