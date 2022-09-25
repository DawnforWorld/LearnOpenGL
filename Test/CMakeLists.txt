link_directories(${CommonLibDir})

add_executable(Test main.cpp ${CommonSrcList})

include_directories(${CommonIncludeDir})

target_link_libraries(Test
    glfw3.dll
)

install(TARGETS Test DESTINATION Test)
install(DIRECTORY Shader DESTINATION Test)
install(PROGRAMS ${CommonLibDir}/glfw3.dll DESTINATION Test)