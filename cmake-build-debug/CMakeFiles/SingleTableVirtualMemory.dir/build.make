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
include CMakeFiles/SingleTableVirtualMemory.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/SingleTableVirtualMemory.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SingleTableVirtualMemory.dir/flags.make

CMakeFiles/SingleTableVirtualMemory.dir/VirtualMemory.cpp.o: CMakeFiles/SingleTableVirtualMemory.dir/flags.make
CMakeFiles/SingleTableVirtualMemory.dir/VirtualMemory.cpp.o: ../VirtualMemory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SingleTableVirtualMemory.dir/VirtualMemory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SingleTableVirtualMemory.dir/VirtualMemory.cpp.o -c /cs/usr/nitaiseri/Desktop/OS/virtual-memory/VirtualMemory.cpp

CMakeFiles/SingleTableVirtualMemory.dir/VirtualMemory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SingleTableVirtualMemory.dir/VirtualMemory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cs/usr/nitaiseri/Desktop/OS/virtual-memory/VirtualMemory.cpp > CMakeFiles/SingleTableVirtualMemory.dir/VirtualMemory.cpp.i

CMakeFiles/SingleTableVirtualMemory.dir/VirtualMemory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SingleTableVirtualMemory.dir/VirtualMemory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cs/usr/nitaiseri/Desktop/OS/virtual-memory/VirtualMemory.cpp -o CMakeFiles/SingleTableVirtualMemory.dir/VirtualMemory.cpp.s

CMakeFiles/SingleTableVirtualMemory.dir/PhysicalMemory.cpp.o: CMakeFiles/SingleTableVirtualMemory.dir/flags.make
CMakeFiles/SingleTableVirtualMemory.dir/PhysicalMemory.cpp.o: ../PhysicalMemory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SingleTableVirtualMemory.dir/PhysicalMemory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SingleTableVirtualMemory.dir/PhysicalMemory.cpp.o -c /cs/usr/nitaiseri/Desktop/OS/virtual-memory/PhysicalMemory.cpp

CMakeFiles/SingleTableVirtualMemory.dir/PhysicalMemory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SingleTableVirtualMemory.dir/PhysicalMemory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cs/usr/nitaiseri/Desktop/OS/virtual-memory/PhysicalMemory.cpp > CMakeFiles/SingleTableVirtualMemory.dir/PhysicalMemory.cpp.i

CMakeFiles/SingleTableVirtualMemory.dir/PhysicalMemory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SingleTableVirtualMemory.dir/PhysicalMemory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cs/usr/nitaiseri/Desktop/OS/virtual-memory/PhysicalMemory.cpp -o CMakeFiles/SingleTableVirtualMemory.dir/PhysicalMemory.cpp.s

# Object files for target SingleTableVirtualMemory
SingleTableVirtualMemory_OBJECTS = \
"CMakeFiles/SingleTableVirtualMemory.dir/VirtualMemory.cpp.o" \
"CMakeFiles/SingleTableVirtualMemory.dir/PhysicalMemory.cpp.o"

# External object files for target SingleTableVirtualMemory
SingleTableVirtualMemory_EXTERNAL_OBJECTS =

libSingleTableVirtualMemory.a: CMakeFiles/SingleTableVirtualMemory.dir/VirtualMemory.cpp.o
libSingleTableVirtualMemory.a: CMakeFiles/SingleTableVirtualMemory.dir/PhysicalMemory.cpp.o
libSingleTableVirtualMemory.a: CMakeFiles/SingleTableVirtualMemory.dir/build.make
libSingleTableVirtualMemory.a: CMakeFiles/SingleTableVirtualMemory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libSingleTableVirtualMemory.a"
	$(CMAKE_COMMAND) -P CMakeFiles/SingleTableVirtualMemory.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SingleTableVirtualMemory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SingleTableVirtualMemory.dir/build: libSingleTableVirtualMemory.a
.PHONY : CMakeFiles/SingleTableVirtualMemory.dir/build

CMakeFiles/SingleTableVirtualMemory.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SingleTableVirtualMemory.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SingleTableVirtualMemory.dir/clean

CMakeFiles/SingleTableVirtualMemory.dir/depend:
	cd /cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cs/usr/nitaiseri/Desktop/OS/virtual-memory /cs/usr/nitaiseri/Desktop/OS/virtual-memory /cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug /cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug /cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug/CMakeFiles/SingleTableVirtualMemory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SingleTableVirtualMemory.dir/depend

