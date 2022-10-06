link_directories(${CommonLibDir})

add_executable(Light main.cpp Window.cpp ${CommonSrcList})

include_directories(${CommonIncludeDir})

target_link_libraries(Light
    glfw3.dll
)

install(TARGETS Light DESTINATION Light)
install(DIRECTORY Shader DESTINATION Light)
install(DIRECTORY Texture DESTINATION Light)
install(PROGRAMS ${CommonLibDir}/glfw3.dll DESTINATION Light)