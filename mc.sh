#!/usr/bin/env bash
rm -rf build
mkdir build && cd $_
cmake ..
make -j4
