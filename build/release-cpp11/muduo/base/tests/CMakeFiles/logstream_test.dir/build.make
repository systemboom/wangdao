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
CMAKE_SOURCE_DIR = /home/dx/muduo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dx/build/release-cpp11

# Include any dependencies generated for this target.
include muduo/base/tests/CMakeFiles/logstream_test.dir/depend.make

# Include the progress variables for this target.
include muduo/base/tests/CMakeFiles/logstream_test.dir/progress.make

# Include the compile flags for this target's objects.
include muduo/base/tests/CMakeFiles/logstream_test.dir/flags.make

muduo/base/tests/CMakeFiles/logstream_test.dir/LogStream_test.cc.o: muduo/base/tests/CMakeFiles/logstream_test.dir/flags.make
muduo/base/tests/CMakeFiles/logstream_test.dir/LogStream_test.cc.o: /home/dx/muduo/muduo/base/tests/LogStream_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dx/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object muduo/base/tests/CMakeFiles/logstream_test.dir/LogStream_test.cc.o"
	cd /home/dx/build/release-cpp11/muduo/base/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/logstream_test.dir/LogStream_test.cc.o -c /home/dx/muduo/muduo/base/tests/LogStream_test.cc

muduo/base/tests/CMakeFiles/logstream_test.dir/LogStream_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/logstream_test.dir/LogStream_test.cc.i"
	cd /home/dx/build/release-cpp11/muduo/base/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dx/muduo/muduo/base/tests/LogStream_test.cc > CMakeFiles/logstream_test.dir/LogStream_test.cc.i

muduo/base/tests/CMakeFiles/logstream_test.dir/LogStream_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/logstream_test.dir/LogStream_test.cc.s"
	cd /home/dx/build/release-cpp11/muduo/base/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dx/muduo/muduo/base/tests/LogStream_test.cc -o CMakeFiles/logstream_test.dir/LogStream_test.cc.s

# Object files for target logstream_test
logstream_test_OBJECTS = \
"CMakeFiles/logstream_test.dir/LogStream_test.cc.o"

# External object files for target logstream_test
logstream_test_EXTERNAL_OBJECTS =

bin/logstream_test: muduo/base/tests/CMakeFiles/logstream_test.dir/LogStream_test.cc.o
bin/logstream_test: muduo/base/tests/CMakeFiles/logstream_test.dir/build.make
bin/logstream_test: lib/libmuduo_base.a
bin/logstream_test: muduo/base/tests/CMakeFiles/logstream_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dx/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../bin/logstream_test"
	cd /home/dx/build/release-cpp11/muduo/base/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/logstream_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
muduo/base/tests/CMakeFiles/logstream_test.dir/build: bin/logstream_test

.PHONY : muduo/base/tests/CMakeFiles/logstream_test.dir/build

muduo/base/tests/CMakeFiles/logstream_test.dir/clean:
	cd /home/dx/build/release-cpp11/muduo/base/tests && $(CMAKE_COMMAND) -P CMakeFiles/logstream_test.dir/cmake_clean.cmake
.PHONY : muduo/base/tests/CMakeFiles/logstream_test.dir/clean

muduo/base/tests/CMakeFiles/logstream_test.dir/depend:
	cd /home/dx/build/release-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dx/muduo /home/dx/muduo/muduo/base/tests /home/dx/build/release-cpp11 /home/dx/build/release-cpp11/muduo/base/tests /home/dx/build/release-cpp11/muduo/base/tests/CMakeFiles/logstream_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : muduo/base/tests/CMakeFiles/logstream_test.dir/depend

