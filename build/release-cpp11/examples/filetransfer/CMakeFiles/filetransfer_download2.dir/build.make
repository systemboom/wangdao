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
include examples/filetransfer/CMakeFiles/filetransfer_download2.dir/depend.make

# Include the progress variables for this target.
include examples/filetransfer/CMakeFiles/filetransfer_download2.dir/progress.make

# Include the compile flags for this target's objects.
include examples/filetransfer/CMakeFiles/filetransfer_download2.dir/flags.make

examples/filetransfer/CMakeFiles/filetransfer_download2.dir/download2.cc.o: examples/filetransfer/CMakeFiles/filetransfer_download2.dir/flags.make
examples/filetransfer/CMakeFiles/filetransfer_download2.dir/download2.cc.o: /home/dx/muduo/examples/filetransfer/download2.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dx/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/filetransfer/CMakeFiles/filetransfer_download2.dir/download2.cc.o"
	cd /home/dx/build/release-cpp11/examples/filetransfer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/filetransfer_download2.dir/download2.cc.o -c /home/dx/muduo/examples/filetransfer/download2.cc

examples/filetransfer/CMakeFiles/filetransfer_download2.dir/download2.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/filetransfer_download2.dir/download2.cc.i"
	cd /home/dx/build/release-cpp11/examples/filetransfer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dx/muduo/examples/filetransfer/download2.cc > CMakeFiles/filetransfer_download2.dir/download2.cc.i

examples/filetransfer/CMakeFiles/filetransfer_download2.dir/download2.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/filetransfer_download2.dir/download2.cc.s"
	cd /home/dx/build/release-cpp11/examples/filetransfer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dx/muduo/examples/filetransfer/download2.cc -o CMakeFiles/filetransfer_download2.dir/download2.cc.s

# Object files for target filetransfer_download2
filetransfer_download2_OBJECTS = \
"CMakeFiles/filetransfer_download2.dir/download2.cc.o"

# External object files for target filetransfer_download2
filetransfer_download2_EXTERNAL_OBJECTS =

bin/filetransfer_download2: examples/filetransfer/CMakeFiles/filetransfer_download2.dir/download2.cc.o
bin/filetransfer_download2: examples/filetransfer/CMakeFiles/filetransfer_download2.dir/build.make
bin/filetransfer_download2: lib/libmuduo_net.a
bin/filetransfer_download2: lib/libmuduo_base.a
bin/filetransfer_download2: examples/filetransfer/CMakeFiles/filetransfer_download2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dx/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/filetransfer_download2"
	cd /home/dx/build/release-cpp11/examples/filetransfer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/filetransfer_download2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/filetransfer/CMakeFiles/filetransfer_download2.dir/build: bin/filetransfer_download2

.PHONY : examples/filetransfer/CMakeFiles/filetransfer_download2.dir/build

examples/filetransfer/CMakeFiles/filetransfer_download2.dir/clean:
	cd /home/dx/build/release-cpp11/examples/filetransfer && $(CMAKE_COMMAND) -P CMakeFiles/filetransfer_download2.dir/cmake_clean.cmake
.PHONY : examples/filetransfer/CMakeFiles/filetransfer_download2.dir/clean

examples/filetransfer/CMakeFiles/filetransfer_download2.dir/depend:
	cd /home/dx/build/release-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dx/muduo /home/dx/muduo/examples/filetransfer /home/dx/build/release-cpp11 /home/dx/build/release-cpp11/examples/filetransfer /home/dx/build/release-cpp11/examples/filetransfer/CMakeFiles/filetransfer_download2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/filetransfer/CMakeFiles/filetransfer_download2.dir/depend

