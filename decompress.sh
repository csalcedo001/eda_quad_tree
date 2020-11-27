#!/bin/bash

./bin/decompress tests/quad_tree.dat tests/result.out
./bin/visualize < tests/result.out > result.out
