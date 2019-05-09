#!/bin/bash

set -e
set -x

if [[ $TRAVIS_OS_NAME == "linux" ]]; then
    docker run --rm -v "$TRAVIS_BUILD_DIR":/home/conan "$DOCKER_IMAGE" bash -c \
        "mkdir -p build && cd build && cmake -G Ninja -DCMAKE_BUILD_TYPE=Release .. && cmake --build . && ctest --verbose"
fi
if [[ $TRAVIS_OS_NAME == "windows" ]]; then
    mkdir -p build && cd build
    cmake -G "Visual Studio 15 2017 Win64" ..
    cmake --build . --config Release
    ctest --verbose --build-config Release
fi

