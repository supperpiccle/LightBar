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
include third-party/curl/tests/libtest/CMakeFiles/lib671.dir/depend.make

# Include the progress variables for this target.
include third-party/curl/tests/libtest/CMakeFiles/lib671.dir/progress.make

# Include the compile flags for this target's objects.
include third-party/curl/tests/libtest/CMakeFiles/lib671.dir/flags.make

third-party/curl/tests/libtest/CMakeFiles/lib671.dir/lib670.c.o: third-party/curl/tests/libtest/CMakeFiles/lib671.dir/flags.make
third-party/curl/tests/libtest/CMakeFiles/lib671.dir/lib670.c.o: ../third-party/curl/tests/libtest/lib670.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justin/Desktop/LightBar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object third-party/curl/tests/libtest/CMakeFiles/lib671.dir/lib670.c.o"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lib671.dir/lib670.c.o   -c /home/justin/Desktop/LightBar/third-party/curl/tests/libtest/lib670.c

third-party/curl/tests/libtest/CMakeFiles/lib671.dir/lib670.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib671.dir/lib670.c.i"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/justin/Desktop/LightBar/third-party/curl/tests/libtest/lib670.c > CMakeFiles/lib671.dir/lib670.c.i

third-party/curl/tests/libtest/CMakeFiles/lib671.dir/lib670.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib671.dir/lib670.c.s"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/justin/Desktop/LightBar/third-party/curl/tests/libtest/lib670.c -o CMakeFiles/lib671.dir/lib670.c.s

third-party/curl/tests/libtest/CMakeFiles/lib671.dir/first.c.o: third-party/curl/tests/libtest/CMakeFiles/lib671.dir/flags.make
third-party/curl/tests/libtest/CMakeFiles/lib671.dir/first.c.o: ../third-party/curl/tests/libtest/first.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justin/Desktop/LightBar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object third-party/curl/tests/libtest/CMakeFiles/lib671.dir/first.c.o"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lib671.dir/first.c.o   -c /home/justin/Desktop/LightBar/third-party/curl/tests/libtest/first.c

third-party/curl/tests/libtest/CMakeFiles/lib671.dir/first.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib671.dir/first.c.i"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/justin/Desktop/LightBar/third-party/curl/tests/libtest/first.c > CMakeFiles/lib671.dir/first.c.i

third-party/curl/tests/libtest/CMakeFiles/lib671.dir/first.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib671.dir/first.c.s"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/justin/Desktop/LightBar/third-party/curl/tests/libtest/first.c -o CMakeFiles/lib671.dir/first.c.s

third-party/curl/tests/libtest/CMakeFiles/lib671.dir/testutil.c.o: third-party/curl/tests/libtest/CMakeFiles/lib671.dir/flags.make
third-party/curl/tests/libtest/CMakeFiles/lib671.dir/testutil.c.o: ../third-party/curl/tests/libtest/testutil.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justin/Desktop/LightBar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object third-party/curl/tests/libtest/CMakeFiles/lib671.dir/testutil.c.o"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lib671.dir/testutil.c.o   -c /home/justin/Desktop/LightBar/third-party/curl/tests/libtest/testutil.c

third-party/curl/tests/libtest/CMakeFiles/lib671.dir/testutil.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib671.dir/testutil.c.i"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/justin/Desktop/LightBar/third-party/curl/tests/libtest/testutil.c > CMakeFiles/lib671.dir/testutil.c.i

third-party/curl/tests/libtest/CMakeFiles/lib671.dir/testutil.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib671.dir/testutil.c.s"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/justin/Desktop/LightBar/third-party/curl/tests/libtest/testutil.c -o CMakeFiles/lib671.dir/testutil.c.s

third-party/curl/tests/libtest/CMakeFiles/lib671.dir/__/__/lib/warnless.c.o: third-party/curl/tests/libtest/CMakeFiles/lib671.dir/flags.make
third-party/curl/tests/libtest/CMakeFiles/lib671.dir/__/__/lib/warnless.c.o: ../third-party/curl/lib/warnless.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justin/Desktop/LightBar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object third-party/curl/tests/libtest/CMakeFiles/lib671.dir/__/__/lib/warnless.c.o"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lib671.dir/__/__/lib/warnless.c.o   -c /home/justin/Desktop/LightBar/third-party/curl/lib/warnless.c

third-party/curl/tests/libtest/CMakeFiles/lib671.dir/__/__/lib/warnless.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib671.dir/__/__/lib/warnless.c.i"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/justin/Desktop/LightBar/third-party/curl/lib/warnless.c > CMakeFiles/lib671.dir/__/__/lib/warnless.c.i

third-party/curl/tests/libtest/CMakeFiles/lib671.dir/__/__/lib/warnless.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib671.dir/__/__/lib/warnless.c.s"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/justin/Desktop/LightBar/third-party/curl/lib/warnless.c -o CMakeFiles/lib671.dir/__/__/lib/warnless.c.s

# Object files for target lib671
lib671_OBJECTS = \
"CMakeFiles/lib671.dir/lib670.c.o" \
"CMakeFiles/lib671.dir/first.c.o" \
"CMakeFiles/lib671.dir/testutil.c.o" \
"CMakeFiles/lib671.dir/__/__/lib/warnless.c.o"

# External object files for target lib671
lib671_EXTERNAL_OBJECTS =

bin/lib671: third-party/curl/tests/libtest/CMakeFiles/lib671.dir/lib670.c.o
bin/lib671: third-party/curl/tests/libtest/CMakeFiles/lib671.dir/first.c.o
bin/lib671: third-party/curl/tests/libtest/CMakeFiles/lib671.dir/testutil.c.o
bin/lib671: third-party/curl/tests/libtest/CMakeFiles/lib671.dir/__/__/lib/warnless.c.o
bin/lib671: third-party/curl/tests/libtest/CMakeFiles/lib671.dir/build.make
bin/lib671: lib/libcurl-d.so
bin/lib671: /usr/lib/x86_64-linux-gnu/libssl.so
bin/lib671: /usr/lib/x86_64-linux-gnu/libcrypto.so
bin/lib671: /usr/lib/x86_64-linux-gnu/libz.so
bin/lib671: third-party/curl/tests/libtest/CMakeFiles/lib671.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/justin/Desktop/LightBar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable ../../../../bin/lib671"
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib671.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
third-party/curl/tests/libtest/CMakeFiles/lib671.dir/build: bin/lib671

.PHONY : third-party/curl/tests/libtest/CMakeFiles/lib671.dir/build

third-party/curl/tests/libtest/CMakeFiles/lib671.dir/clean:
	cd /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest && $(CMAKE_COMMAND) -P CMakeFiles/lib671.dir/cmake_clean.cmake
.PHONY : third-party/curl/tests/libtest/CMakeFiles/lib671.dir/clean

third-party/curl/tests/libtest/CMakeFiles/lib671.dir/depend:
	cd /home/justin/Desktop/LightBar/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/justin/Desktop/LightBar /home/justin/Desktop/LightBar/third-party/curl/tests/libtest /home/justin/Desktop/LightBar/build /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest /home/justin/Desktop/LightBar/build/third-party/curl/tests/libtest/CMakeFiles/lib671.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : third-party/curl/tests/libtest/CMakeFiles/lib671.dir/depend

