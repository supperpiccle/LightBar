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
include StockUtil/CMakeFiles/StockUtils_lib.dir/depend.make

# Include the progress variables for this target.
include StockUtil/CMakeFiles/StockUtils_lib.dir/progress.make

# Include the compile flags for this target's objects.
include StockUtil/CMakeFiles/StockUtils_lib.dir/flags.make

StockUtil/CMakeFiles/StockUtils_lib.dir/Stock.cpp.o: StockUtil/CMakeFiles/StockUtils_lib.dir/flags.make
StockUtil/CMakeFiles/StockUtils_lib.dir/Stock.cpp.o: ../StockUtil/Stock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justin/Desktop/LightBar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object StockUtil/CMakeFiles/StockUtils_lib.dir/Stock.cpp.o"
	cd /home/justin/Desktop/LightBar/build/StockUtil && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StockUtils_lib.dir/Stock.cpp.o -c /home/justin/Desktop/LightBar/StockUtil/Stock.cpp

StockUtil/CMakeFiles/StockUtils_lib.dir/Stock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StockUtils_lib.dir/Stock.cpp.i"
	cd /home/justin/Desktop/LightBar/build/StockUtil && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justin/Desktop/LightBar/StockUtil/Stock.cpp > CMakeFiles/StockUtils_lib.dir/Stock.cpp.i

StockUtil/CMakeFiles/StockUtils_lib.dir/Stock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StockUtils_lib.dir/Stock.cpp.s"
	cd /home/justin/Desktop/LightBar/build/StockUtil && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justin/Desktop/LightBar/StockUtil/Stock.cpp -o CMakeFiles/StockUtils_lib.dir/Stock.cpp.s

# Object files for target StockUtils_lib
StockUtils_lib_OBJECTS = \
"CMakeFiles/StockUtils_lib.dir/Stock.cpp.o"

# External object files for target StockUtils_lib
StockUtils_lib_EXTERNAL_OBJECTS =

lib/libStockUtils_lib.a: StockUtil/CMakeFiles/StockUtils_lib.dir/Stock.cpp.o
lib/libStockUtils_lib.a: StockUtil/CMakeFiles/StockUtils_lib.dir/build.make
lib/libStockUtils_lib.a: StockUtil/CMakeFiles/StockUtils_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/justin/Desktop/LightBar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../lib/libStockUtils_lib.a"
	cd /home/justin/Desktop/LightBar/build/StockUtil && $(CMAKE_COMMAND) -P CMakeFiles/StockUtils_lib.dir/cmake_clean_target.cmake
	cd /home/justin/Desktop/LightBar/build/StockUtil && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StockUtils_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
StockUtil/CMakeFiles/StockUtils_lib.dir/build: lib/libStockUtils_lib.a

.PHONY : StockUtil/CMakeFiles/StockUtils_lib.dir/build

StockUtil/CMakeFiles/StockUtils_lib.dir/clean:
	cd /home/justin/Desktop/LightBar/build/StockUtil && $(CMAKE_COMMAND) -P CMakeFiles/StockUtils_lib.dir/cmake_clean.cmake
.PHONY : StockUtil/CMakeFiles/StockUtils_lib.dir/clean

StockUtil/CMakeFiles/StockUtils_lib.dir/depend:
	cd /home/justin/Desktop/LightBar/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/justin/Desktop/LightBar /home/justin/Desktop/LightBar/StockUtil /home/justin/Desktop/LightBar/build /home/justin/Desktop/LightBar/build/StockUtil /home/justin/Desktop/LightBar/build/StockUtil/CMakeFiles/StockUtils_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : StockUtil/CMakeFiles/StockUtils_lib.dir/depend
