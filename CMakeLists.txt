cmake_minimum_required(VERSION 3.20)

project(LearnOpenGL)

set(CommonDir ${PROJECT_SOURCE_DIR}/Common)

set(CommonIncludeDir ${CommonDir}/Include)
set(CommonSrcDir ${CommonDir}/Src)
set(CommonLibDir ${CommonDir}/Lib)
set(CommonSrcList 
    ${CommonSrcDir}/glad.c 
    ${CommonSrcDir}/OpenGL/Window.cpp
    ${CommonSrcDir}/OpenGL/Shader.cpp
    )

add_subdirectory(Test)

