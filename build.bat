@echo OFF

mkdir out
cd out
cmake .. -G Ninja -DCMAKE-C-COMPILER="clang" -DCMAKE-CXX-COMPILER="clang++" -DCMAKE_EXPORT_COMPILE_COMMANDS=1
cd ..
