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
include LightBar/CMakeFiles/LightBarmain.dir/depend.make

# Include the progress variables for this target.
include LightBar/CMakeFiles/LightBarmain.dir/progress.make

# Include the compile flags for this target's objects.
include LightBar/CMakeFiles/LightBarmain.dir/flags.make

LightBar/CMakeFiles/LightBarmain.dir/Animation.cpp.o: LightBar/CMakeFiles/LightBarmain.dir/flags.make
LightBar/CMakeFiles/LightBarmain.dir/Animation.cpp.o: ../LightBar/Animation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justin/Desktop/LightBar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object LightBar/CMakeFiles/LightBarmain.dir/Animation.cpp.o"
	cd /home/justin/Desktop/LightBar/build/LightBar && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LightBarmain.dir/Animation.cpp.o -c /home/justin/Desktop/LightBar/LightBar/Animation.cpp

LightBar/CMakeFiles/LightBarmain.dir/Animation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LightBarmain.dir/Animation.cpp.i"
	cd /home/justin/Desktop/LightBar/build/LightBar && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justin/Desktop/LightBar/LightBar/Animation.cpp > CMakeFiles/LightBarmain.dir/Animation.cpp.i

LightBar/CMakeFiles/LightBarmain.dir/Animation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LightBarmain.dir/Animation.cpp.s"
	cd /home/justin/Desktop/LightBar/build/LightBar && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justin/Desktop/LightBar/LightBar/Animation.cpp -o CMakeFiles/LightBarmain.dir/Animation.cpp.s

# Object files for target LightBarmain
LightBarmain_OBJECTS = \
"CMakeFiles/LightBarmain.dir/Animation.cpp.o"

# External object files for target LightBarmain
LightBarmain_EXTERNAL_OBJECTS =

lib/libLightBarmain.a: LightBar/CMakeFiles/LightBarmain.dir/Animation.cpp.o
lib/libLightBarmain.a: LightBar/CMakeFiles/LightBarmain.dir/build.make
lib/libLightBarmain.a: LightBar/CMakeFiles/LightBarmain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/justin/Desktop/LightBar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../lib/libLightBarmain.a"
	cd /home/justin/Desktop/LightBar/build/LightBar && $(CMAKE_COMMAND) -P CMakeFiles/LightBarmain.dir/cmake_clean_target.cmake
	cd /home/justin/Desktop/LightBar/build/LightBar && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LightBarmain.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
LightBar/CMakeFiles/LightBarmain.dir/build: lib/libLightBarmain.a

.PHONY : LightBar/CMakeFiles/LightBarmain.dir/build

LightBar/CMakeFiles/LightBarmain.dir/clean:
	cd /home/justin/Desktop/LightBar/build/LightBar && $(CMAKE_COMMAND) -P CMakeFiles/LightBarmain.dir/cmake_clean.cmake
.PHONY : LightBar/CMakeFiles/LightBarmain.dir/clean

LightBar/CMakeFiles/LightBarmain.dir/depend:
	cd /home/justin/Desktop/LightBar/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/justin/Desktop/LightBar /home/justin/Desktop/LightBar/LightBar /home/justin/Desktop/LightBar/build /home/justin/Desktop/LightBar/build/LightBar /home/justin/Desktop/LightBar/build/LightBar/CMakeFiles/LightBarmain.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : LightBar/CMakeFiles/LightBarmain.dir/depend
