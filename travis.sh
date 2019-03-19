 #!/bin/bash

set -e
set -x

cmake --version
ninja --version

rm -rf build && mkdir -p build && cd build

cmake -G Ninja -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
ctest --verbose

