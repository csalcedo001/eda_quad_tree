#!/bin/bash

if [ ! -f bin/compress ]
then
	make
fi

python3 process_image_input.py
./bin/compress data/compressed/test.dat 50 < data/rgb/test.in
