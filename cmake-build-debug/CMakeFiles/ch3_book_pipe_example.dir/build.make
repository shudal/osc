# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /tmp/tmp.OvVthRjzYw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.OvVthRjzYw/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ch3_book_pipe_example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ch3_book_pipe_example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ch3_book_pipe_example.dir/flags.make

CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.o: CMakeFiles/ch3_book_pipe_example.dir/flags.make
CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.o: ../ch3/book/pipe_example.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.OvVthRjzYw/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.o   -c /tmp/tmp.OvVthRjzYw/ch3/book/pipe_example.c

CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.OvVthRjzYw/ch3/book/pipe_example.c > CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.i

CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.OvVthRjzYw/ch3/book/pipe_example.c -o CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.s

CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.o.requires:

.PHONY : CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.o.requires

CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.o.provides: CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.o.requires
	$(MAKE) -f CMakeFiles/ch3_book_pipe_example.dir/build.make CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.o.provides.build
.PHONY : CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.o.provides

CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.o.provides.build: CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.o


# Object files for target ch3_book_pipe_example
ch3_book_pipe_example_OBJECTS = \
"CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.o"

# External object files for target ch3_book_pipe_example
ch3_book_pipe_example_EXTERNAL_OBJECTS =

ch3_book_pipe_example: CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.o
ch3_book_pipe_example: CMakeFiles/ch3_book_pipe_example.dir/build.make
ch3_book_pipe_example: CMakeFiles/ch3_book_pipe_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.OvVthRjzYw/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ch3_book_pipe_example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ch3_book_pipe_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ch3_book_pipe_example.dir/build: ch3_book_pipe_example

.PHONY : CMakeFiles/ch3_book_pipe_example.dir/build

CMakeFiles/ch3_book_pipe_example.dir/requires: CMakeFiles/ch3_book_pipe_example.dir/ch3/book/pipe_example.c.o.requires

.PHONY : CMakeFiles/ch3_book_pipe_example.dir/requires

CMakeFiles/ch3_book_pipe_example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ch3_book_pipe_example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ch3_book_pipe_example.dir/clean

CMakeFiles/ch3_book_pipe_example.dir/depend:
	cd /tmp/tmp.OvVthRjzYw/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.OvVthRjzYw /tmp/tmp.OvVthRjzYw /tmp/tmp.OvVthRjzYw/cmake-build-debug /tmp/tmp.OvVthRjzYw/cmake-build-debug /tmp/tmp.OvVthRjzYw/cmake-build-debug/CMakeFiles/ch3_book_pipe_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ch3_book_pipe_example.dir/depend

