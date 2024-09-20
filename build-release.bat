@echo OFF

mkdir out-release
cd out-release
cmake .. -G Ninja -DCMAKE-C-COMPILER="clang" -DCMAKE-CXX-COMPILER="clang++" -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_BUILD_TYPE="Release"
cd ..
