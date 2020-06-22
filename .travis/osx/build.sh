export PATH=/usr/local/opt/qt5/bin/:$PATH
mkdir build
cd build
cmake -DMVVM_ENABLE_FILESYSTEM=OFF -DCMAKE_PREFIX_PATH=/usr/local -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DMVVM_DISCOVER_TESTS=$TESTS_AUTODISCOVRY ..
make -j4
