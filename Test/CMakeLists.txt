set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/Bin)

link_directories(${CommonLibDir})

add_executable(Test main.cpp ${CommonSrcList})

include_directories(${CommonIncludeDir})

target_link_libraries(Test
    libglfw3.a
)