rmdir /s/q Build
md Build
cd Build
cmake .. -G "MinGW Makefiles"
cmake --build .