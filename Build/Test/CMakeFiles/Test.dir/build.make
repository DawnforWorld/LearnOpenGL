# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = E:\cmake-3.24.2-windows-x86_64\bin\cmake.exe

# The command to remove a file.
RM = E:\cmake-3.24.2-windows-x86_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\LearnOpenGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\LearnOpenGL\Build

# Include any dependencies generated for this target.
include Test/CMakeFiles/Test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Test/CMakeFiles/Test.dir/compiler_depend.make

# Include the progress variables for this target.
include Test/CMakeFiles/Test.dir/progress.make

# Include the compile flags for this target's objects.
include Test/CMakeFiles/Test.dir/flags.make

Test/CMakeFiles/Test.dir/main.cpp.obj: Test/CMakeFiles/Test.dir/flags.make
Test/CMakeFiles/Test.dir/main.cpp.obj: Test/CMakeFiles/Test.dir/includes_CXX.rsp
Test/CMakeFiles/Test.dir/main.cpp.obj: D:/LearnOpenGL/Test/main.cpp
Test/CMakeFiles/Test.dir/main.cpp.obj: Test/CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\LearnOpenGL\Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Test/CMakeFiles/Test.dir/main.cpp.obj"
	cd /d D:\LearnOpenGL\Build\Test && C:\TDM-GCC-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Test/CMakeFiles/Test.dir/main.cpp.obj -MF CMakeFiles\Test.dir\main.cpp.obj.d -o CMakeFiles\Test.dir\main.cpp.obj -c D:\LearnOpenGL\Test\main.cpp

Test/CMakeFiles/Test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/main.cpp.i"
	cd /d D:\LearnOpenGL\Build\Test && C:\TDM-GCC-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\LearnOpenGL\Test\main.cpp > CMakeFiles\Test.dir\main.cpp.i

Test/CMakeFiles/Test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/main.cpp.s"
	cd /d D:\LearnOpenGL\Build\Test && C:\TDM-GCC-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\LearnOpenGL\Test\main.cpp -o CMakeFiles\Test.dir\main.cpp.s

Test/CMakeFiles/Test.dir/__/Common/Src/glad.c.obj: Test/CMakeFiles/Test.dir/flags.make
Test/CMakeFiles/Test.dir/__/Common/Src/glad.c.obj: Test/CMakeFiles/Test.dir/includes_C.rsp
Test/CMakeFiles/Test.dir/__/Common/Src/glad.c.obj: D:/LearnOpenGL/Common/Src/glad.c
Test/CMakeFiles/Test.dir/__/Common/Src/glad.c.obj: Test/CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\LearnOpenGL\Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object Test/CMakeFiles/Test.dir/__/Common/Src/glad.c.obj"
	cd /d D:\LearnOpenGL\Build\Test && C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Test/CMakeFiles/Test.dir/__/Common/Src/glad.c.obj -MF CMakeFiles\Test.dir\__\Common\Src\glad.c.obj.d -o CMakeFiles\Test.dir\__\Common\Src\glad.c.obj -c D:\LearnOpenGL\Common\Src\glad.c

Test/CMakeFiles/Test.dir/__/Common/Src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Test.dir/__/Common/Src/glad.c.i"
	cd /d D:\LearnOpenGL\Build\Test && C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\LearnOpenGL\Common\Src\glad.c > CMakeFiles\Test.dir\__\Common\Src\glad.c.i

Test/CMakeFiles/Test.dir/__/Common/Src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Test.dir/__/Common/Src/glad.c.s"
	cd /d D:\LearnOpenGL\Build\Test && C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\LearnOpenGL\Common\Src\glad.c -o CMakeFiles\Test.dir\__\Common\Src\glad.c.s

Test/CMakeFiles/Test.dir/__/Common/Src/OpenGL/Window.cpp.obj: Test/CMakeFiles/Test.dir/flags.make
Test/CMakeFiles/Test.dir/__/Common/Src/OpenGL/Window.cpp.obj: Test/CMakeFiles/Test.dir/includes_CXX.rsp
Test/CMakeFiles/Test.dir/__/Common/Src/OpenGL/Window.cpp.obj: D:/LearnOpenGL/Common/Src/OpenGL/Window.cpp
Test/CMakeFiles/Test.dir/__/Common/Src/OpenGL/Window.cpp.obj: Test/CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\LearnOpenGL\Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Test/CMakeFiles/Test.dir/__/Common/Src/OpenGL/Window.cpp.obj"
	cd /d D:\LearnOpenGL\Build\Test && C:\TDM-GCC-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Test/CMakeFiles/Test.dir/__/Common/Src/OpenGL/Window.cpp.obj -MF CMakeFiles\Test.dir\__\Common\Src\OpenGL\Window.cpp.obj.d -o CMakeFiles\Test.dir\__\Common\Src\OpenGL\Window.cpp.obj -c D:\LearnOpenGL\Common\Src\OpenGL\Window.cpp

Test/CMakeFiles/Test.dir/__/Common/Src/OpenGL/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/__/Common/Src/OpenGL/Window.cpp.i"
	cd /d D:\LearnOpenGL\Build\Test && C:\TDM-GCC-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\LearnOpenGL\Common\Src\OpenGL\Window.cpp > CMakeFiles\Test.dir\__\Common\Src\OpenGL\Window.cpp.i

Test/CMakeFiles/Test.dir/__/Common/Src/OpenGL/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/__/Common/Src/OpenGL/Window.cpp.s"
	cd /d D:\LearnOpenGL\Build\Test && C:\TDM-GCC-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\LearnOpenGL\Common\Src\OpenGL\Window.cpp -o CMakeFiles\Test.dir\__\Common\Src\OpenGL\Window.cpp.s

# Object files for target Test
Test_OBJECTS = \
"CMakeFiles/Test.dir/main.cpp.obj" \
"CMakeFiles/Test.dir/__/Common/Src/glad.c.obj" \
"CMakeFiles/Test.dir/__/Common/Src/OpenGL/Window.cpp.obj"

# External object files for target Test
Test_EXTERNAL_OBJECTS =

Bin/Test.exe: Test/CMakeFiles/Test.dir/main.cpp.obj
Bin/Test.exe: Test/CMakeFiles/Test.dir/__/Common/Src/glad.c.obj
Bin/Test.exe: Test/CMakeFiles/Test.dir/__/Common/Src/OpenGL/Window.cpp.obj
Bin/Test.exe: Test/CMakeFiles/Test.dir/build.make
Bin/Test.exe: Test/CMakeFiles/Test.dir/linklibs.rsp
Bin/Test.exe: Test/CMakeFiles/Test.dir/objects1.rsp
Bin/Test.exe: Test/CMakeFiles/Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\LearnOpenGL\Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ..\Bin\Test.exe"
	cd /d D:\LearnOpenGL\Build\Test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Test/CMakeFiles/Test.dir/build: Bin/Test.exe
.PHONY : Test/CMakeFiles/Test.dir/build

Test/CMakeFiles/Test.dir/clean:
	cd /d D:\LearnOpenGL\Build\Test && $(CMAKE_COMMAND) -P CMakeFiles\Test.dir\cmake_clean.cmake
.PHONY : Test/CMakeFiles/Test.dir/clean

Test/CMakeFiles/Test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\LearnOpenGL D:\LearnOpenGL\Test D:\LearnOpenGL\Build D:\LearnOpenGL\Build\Test D:\LearnOpenGL\Build\Test\CMakeFiles\Test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : Test/CMakeFiles/Test.dir/depend

