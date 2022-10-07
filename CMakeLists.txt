cmake_minimum_required(VERSION 3.20)

project(LearnOpenGL)

set(CommonDir ${PROJECT_SOURCE_DIR}/Common)

set(CommonIncludeDir ${CommonDir}/Include)
set(CommonSrcDir ${CommonDir}/Src)
set(CommonLibDir ${CommonDir}/Lib)

set(CommonSrcList 
    ${CommonSrcDir}/glad.c 

    ${CommonSrcDir}/OpenGL/Shader.cpp
    ${CommonSrcDir}/OpenGL/Camera.cpp
    ${CommonSrcDir}/OpenGL/Material.cpp
    ${CommonSrcDir}/stb_image.cpp
    )

add_subdirectory(Test)
add_subdirectory(Light)

