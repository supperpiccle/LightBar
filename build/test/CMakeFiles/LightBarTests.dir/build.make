# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/justin/Desktop/LightBar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/justin/Desktop/LightBar/build

# Include any dependencies generated for this target.
include test/CMakeFiles/LightBarTests.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/LightBarTests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/LightBarTests.dir/flags.make

test/CMakeFiles/LightBarTests.dir/LightBarTests.cpp.o: test/CMakeFiles/LightBarTests.dir/flags.make
test/CMakeFiles/LightBarTests.dir/LightBarTests.cpp.o: ../test/LightBarTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justin/Desktop/LightBar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/LightBarTests.dir/LightBarTests.cpp.o"
	cd /home/justin/Desktop/LightBar/build/test && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LightBarTests.dir/LightBarTests.cpp.o -c /home/justin/Desktop/LightBar/test/LightBarTests.cpp

test/CMakeFiles/LightBarTests.dir/LightBarTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LightBarTests.dir/LightBarTests.cpp.i"
	cd /home/justin/Desktop/LightBar/build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justin/Desktop/LightBar/test/LightBarTests.cpp > CMakeFiles/LightBarTests.dir/LightBarTests.cpp.i

test/CMakeFiles/LightBarTests.dir/LightBarTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LightBarTests.dir/LightBarTests.cpp.s"
	cd /home/justin/Desktop/LightBar/build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justin/Desktop/LightBar/test/LightBarTests.cpp -o CMakeFiles/LightBarTests.dir/LightBarTests.cpp.s

# Object files for target LightBarTests
LightBarTests_OBJECTS = \
"CMakeFiles/LightBarTests.dir/LightBarTests.cpp.o"

# External object files for target LightBarTests
LightBarTests_EXTERNAL_OBJECTS =

bin/LightBarTests: test/CMakeFiles/LightBarTests.dir/LightBarTests.cpp.o
bin/LightBarTests: test/CMakeFiles/LightBarTests.dir/build.make
bin/LightBarTests: lib/libgtest_main.so.1.12.1
bin/LightBarTests: lib/libgtest.so.1.12.1
bin/LightBarTests: lib/libLightBar_main.a
bin/LightBarTests: lib/libStockUtils_lib.a
bin/LightBarTests: lib/libcurl-d.so
bin/LightBarTests: /usr/lib/x86_64-linux-gnu/libssl.so
bin/LightBarTests: /usr/lib/x86_64-linux-gnu/libcrypto.so
bin/LightBarTests: /usr/lib/x86_64-linux-gnu/libz.so
bin/LightBarTests: test/CMakeFiles/LightBarTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/justin/Desktop/LightBar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/LightBarTests"
	cd /home/justin/Desktop/LightBar/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LightBarTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/LightBarTests.dir/build: bin/LightBarTests

.PHONY : test/CMakeFiles/LightBarTests.dir/build

test/CMakeFiles/LightBarTests.dir/clean:
	cd /home/justin/Desktop/LightBar/build/test && $(CMAKE_COMMAND) -P CMakeFiles/LightBarTests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/LightBarTests.dir/clean

test/CMakeFiles/LightBarTests.dir/depend:
	cd /home/justin/Desktop/LightBar/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/justin/Desktop/LightBar /home/justin/Desktop/LightBar/test /home/justin/Desktop/LightBar/build /home/justin/Desktop/LightBar/build/test /home/justin/Desktop/LightBar/build/test/CMakeFiles/LightBarTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/LightBarTests.dir/depend
