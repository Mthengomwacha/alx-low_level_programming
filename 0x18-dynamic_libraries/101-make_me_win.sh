#!/bin/bash
wget -P /tmp -q "https://github.com/Mthengomwacha/alx-low_level_programming/master/0x18-dynamic_libraries/libmmw.so"
export LD_PRELOAD="/tmp/libmmw.so"
