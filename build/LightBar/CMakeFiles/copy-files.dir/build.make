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

# Utility rule file for copy-files.

# Include the progress variables for this target.
include LightBar/CMakeFiles/copy-files.dir/progress.make

LightBar/CMakeFiles/copy-files:
	cd /home/justin/Desktop/LightBar/build/LightBar && /usr/bin/cmake -E copy_directory /home/justin/Desktop/LightBar/LightBar/media /home/justin/Desktop/LightBar/build/media

copy-files: LightBar/CMakeFiles/copy-files
copy-files: LightBar/CMakeFiles/copy-files.dir/build.make

.PHONY : copy-files

# Rule to build all files generated by this target.
LightBar/CMakeFiles/copy-files.dir/build: copy-files

.PHONY : LightBar/CMakeFiles/copy-files.dir/build

LightBar/CMakeFiles/copy-files.dir/clean:
	cd /home/justin/Desktop/LightBar/build/LightBar && $(CMAKE_COMMAND) -P CMakeFiles/copy-files.dir/cmake_clean.cmake
.PHONY : LightBar/CMakeFiles/copy-files.dir/clean

LightBar/CMakeFiles/copy-files.dir/depend:
	cd /home/justin/Desktop/LightBar/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/justin/Desktop/LightBar /home/justin/Desktop/LightBar/LightBar /home/justin/Desktop/LightBar/build /home/justin/Desktop/LightBar/build/LightBar /home/justin/Desktop/LightBar/build/LightBar/CMakeFiles/copy-files.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : LightBar/CMakeFiles/copy-files.dir/depend

