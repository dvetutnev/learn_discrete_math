 #!/bin/bash

set -e
set -x

rm -rf build && mkdir -p build && cd build
cmake -G Ninja -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
ctest --verbose
