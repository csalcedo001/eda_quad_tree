#include <iostream>

#include "quad_tree.hpp"

using namespace std;

int main() {
	eda::quad_tree::QuadTree<int> quad_tree;

	int n;

	cin >> n;

	int x, y;
	string name;

	while (n--) {
		cin >> x >> y >> name;

		quad_tree.insert(x, y, name);
	}

	quad_tree.print();

	return 0;
}
