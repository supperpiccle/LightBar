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
include third-party/curl/tests/libtest/CMakeFiles/lib517.dir/depend.make

# Include the progress variables for this target.
include third-party/curl/tests/libtest/CMakeFiles/lib517.dir/progress.make

# Include the compile flags for this target's objects.
include third-party/curl/tests/libtest/CMakeFiles/lib517.dir/flags.make

third-party/curl/tests/libtest/CMakeFiles/lib517.dir/lib517.c.o: third-party/curl/tests/libtest/CMakeFiles/lib517.dir/flags.make
third-party/curl/tests/libtest/CMakeFiles/lib517.dir/lib517.c.o: ../third-party/curl/tests/libtest/lib517.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justin/Desktop/LightBar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object third-party/curl/tests/libtest/CMakeFiles/lib517.dir/lib517.c.o"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lib517.dir/lib517.c.o   -c /home/justin/Desktop/LightBar/third-party/curl/tests/libtest/lib517.c

third-party/curl/tests/libtest/CMakeFiles/lib517.dir/lib517.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib517.dir/lib517.c.i"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/justin/Desktop/LightBar/third-party/curl/tests/libtest/lib517.c > CMakeFiles/lib517.dir/lib517.c.i

third-party/curl/tests/libtest/CMakeFiles/lib517.dir/lib517.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib517.dir/lib517.c.s"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/justin/Desktop/LightBar/third-party/curl/tests/libtest/lib517.c -o CMakeFiles/lib517.dir/lib517.c.s

third-party/curl/tests/libtest/CMakeFiles/lib517.dir/first.c.o: third-party/curl/tests/libtest/CMakeFiles/lib517.dir/flags.make
third-party/curl/tests/libtest/CMakeFiles/lib517.dir/first.c.o: ../third-party/curl/tests/libtest/first.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justin/Desktop/LightBar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object third-party/curl/tests/libtest/CMakeFiles/lib517.dir/first.c.o"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lib517.dir/first.c.o   -c /home/justin/Desktop/LightBar/third-party/curl/tests/libtest/first.c

third-party/curl/tests/libtest/CMakeFiles/lib517.dir/first.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib517.dir/first.c.i"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/justin/Desktop/LightBar/third-party/curl/tests/libtest/first.c > CMakeFiles/lib517.dir/first.c.i

third-party/curl/tests/libtest/CMakeFiles/lib517.dir/first.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib517.dir/first.c.s"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/justin/Desktop/LightBar/third-party/curl/tests/libtest/first.c -o CMakeFiles/lib517.dir/first.c.s

# Object files for target lib517
lib517_OBJECTS = \
"CMakeFiles/lib517.dir/lib517.c.o" \
"CMakeFiles/lib517.dir/first.c.o"

# External object files for target lib517
lib517_EXTERNAL_OBJECTS =

bin/lib517: third-party/curl/tests/libtest/CMakeFiles/lib517.dir/lib517.c.o
bin/lib517: third-party/curl/tests/libtest/CMakeFiles/lib517.dir/first.c.o
bin/lib517: third-party/curl/tests/libtest/CMakeFiles/lib517.dir/build.make
bin/lib517: lib/libcurl-d.so
bin/lib517: /usr/lib/x86_64-linux-gnu/libssl.so
bin/lib517: /usr/lib/x86_64-linux-gnu/libcrypto.so
bin/lib517: /usr/lib/x86_64-linux-gnu/libz.so
bin/lib517: third-party/curl/tests/libtest/CMakeFiles/lib517.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/justin/Desktop/LightBar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ../../../../bin/lib517"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib517.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
third-party/curl/tests/libtest/CMakeFiles/lib517.dir/build: bin/lib517

.PHONY : third-party/curl/tests/libtest/CMakeFiles/lib517.dir/build

third-party/curl/tests/libtest/CMakeFiles/lib517.dir/clean:
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && $(CMAKE_COMMAND) -P CMakeFiles/lib517.dir/cmake_clean.cmake
.PHONY : third-party/curl/tests/libtest/CMakeFiles/lib517.dir/clean

third-party/curl/tests/libtest/CMakeFiles/lib517.dir/depend:
	cd /home/justin/Desktop/LightBar/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/justin/Desktop/LightBar /home/justin/Desktop/LightBar/third-party/curl/tests/libtest /home/justin/Desktop/LightBar/build /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest/CMakeFiles/lib517.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : third-party/curl/tests/libtest/CMakeFiles/lib517.dir/depend

