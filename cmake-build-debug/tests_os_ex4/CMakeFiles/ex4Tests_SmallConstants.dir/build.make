# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/APP/jetbrains/clion/2021.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /usr/local/APP/jetbrains/clion/2021.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cs/usr/nitaiseri/Desktop/OS/virtual-memory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug

# Include any dependencies generated for this target.
include tests_os_ex4/CMakeFiles/ex4Tests_SmallConstants.dir/depend.make
# Include the progress variables for this target.
include tests_os_ex4/CMakeFiles/ex4Tests_SmallConstants.dir/progress.make

# Include the compile flags for this target's objects.
include tests_os_ex4/CMakeFiles/ex4Tests_SmallConstants.dir/flags.make

tests_os_ex4/CMakeFiles/ex4Tests_SmallConstants.dir/kb_tests.cpp.o: tests_os_ex4/CMakeFiles/ex4Tests_SmallConstants.dir/flags.make
tests_os_ex4/CMakeFiles/ex4Tests_SmallConstants.dir/kb_tests.cpp.o: ../tests_os_ex4/kb_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests_os_ex4/CMakeFiles/ex4Tests_SmallConstants.dir/kb_tests.cpp.o"
	cd /cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug/tests_os_ex4 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex4Tests_SmallConstants.dir/kb_tests.cpp.o -c /cs/usr/nitaiseri/Desktop/OS/virtual-memory/tests_os_ex4/kb_tests.cpp

tests_os_ex4/CMakeFiles/ex4Tests_SmallConstants.dir/kb_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex4Tests_SmallConstants.dir/kb_tests.cpp.i"
	cd /cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug/tests_os_ex4 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cs/usr/nitaiseri/Desktop/OS/virtual-memory/tests_os_ex4/kb_tests.cpp > CMakeFiles/ex4Tests_SmallConstants.dir/kb_tests.cpp.i

tests_os_ex4/CMakeFiles/ex4Tests_SmallConstants.dir/kb_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex4Tests_SmallConstants.dir/kb_tests.cpp.s"
	cd /cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug/tests_os_ex4 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cs/usr/nitaiseri/Desktop/OS/virtual-memory/tests_os_ex4/kb_tests.cpp -o CMakeFiles/ex4Tests_SmallConstants.dir/kb_tests.cpp.s

# Object files for target ex4Tests_SmallConstants
ex4Tests_SmallConstants_OBJECTS = \
"CMakeFiles/ex4Tests_SmallConstants.dir/kb_tests.cpp.o"

# External object files for target ex4Tests_SmallConstants
ex4Tests_SmallConstants_EXTERNAL_OBJECTS =

tests_os_ex4/ex4Tests_SmallConstants: tests_os_ex4/CMakeFiles/ex4Tests_SmallConstants.dir/kb_tests.cpp.o
tests_os_ex4/ex4Tests_SmallConstants: tests_os_ex4/CMakeFiles/ex4Tests_SmallConstants.dir/build.make
tests_os_ex4/ex4Tests_SmallConstants: libTestVirtualMemory.a
tests_os_ex4/ex4Tests_SmallConstants: lib/libgtest_main.a
tests_os_ex4/ex4Tests_SmallConstants: lib/libgtest.a
tests_os_ex4/ex4Tests_SmallConstants: tests_os_ex4/CMakeFiles/ex4Tests_SmallConstants.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ex4Tests_SmallConstants"
	cd /cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug/tests_os_ex4 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex4Tests_SmallConstants.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests_os_ex4/CMakeFiles/ex4Tests_SmallConstants.dir/build: tests_os_ex4/ex4Tests_SmallConstants
.PHONY : tests_os_ex4/CMakeFiles/ex4Tests_SmallConstants.dir/build

tests_os_ex4/CMakeFiles/ex4Tests_SmallConstants.dir/clean:
	cd /cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug/tests_os_ex4 && $(CMAKE_COMMAND) -P CMakeFiles/ex4Tests_SmallConstants.dir/cmake_clean.cmake
.PHONY : tests_os_ex4/CMakeFiles/ex4Tests_SmallConstants.dir/clean

tests_os_ex4/CMakeFiles/ex4Tests_SmallConstants.dir/depend:
	cd /cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cs/usr/nitaiseri/Desktop/OS/virtual-memory /cs/usr/nitaiseri/Desktop/OS/virtual-memory/tests_os_ex4 /cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug /cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug/tests_os_ex4 /cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug/tests_os_ex4/CMakeFiles/ex4Tests_SmallConstants.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests_os_ex4/CMakeFiles/ex4Tests_SmallConstants.dir/depend

