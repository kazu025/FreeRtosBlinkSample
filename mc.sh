#!/usr/bin/env bash
rm -rf build
mkdir build && cd $_
#cmake ..
cmake .. -DPICO_BOARD=pico_w
make -j4
