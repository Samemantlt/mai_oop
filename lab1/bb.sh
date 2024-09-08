rm -rf build
cmake --preset=default
cmake -S . -B build
cmake --build build

pushd build
ctest
popd