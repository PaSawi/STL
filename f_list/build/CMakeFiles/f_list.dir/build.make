# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/patryks/Workplace/004_STL/f_list

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/patryks/Workplace/004_STL/f_list/build

# Include any dependencies generated for this target.
include CMakeFiles/f_list.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/f_list.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/f_list.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/f_list.dir/flags.make

CMakeFiles/f_list.dir/f_list.cpp.o: CMakeFiles/f_list.dir/flags.make
CMakeFiles/f_list.dir/f_list.cpp.o: ../f_list.cpp
CMakeFiles/f_list.dir/f_list.cpp.o: CMakeFiles/f_list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/patryks/Workplace/004_STL/f_list/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/f_list.dir/f_list.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/f_list.dir/f_list.cpp.o -MF CMakeFiles/f_list.dir/f_list.cpp.o.d -o CMakeFiles/f_list.dir/f_list.cpp.o -c /home/patryks/Workplace/004_STL/f_list/f_list.cpp

CMakeFiles/f_list.dir/f_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/f_list.dir/f_list.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/patryks/Workplace/004_STL/f_list/f_list.cpp > CMakeFiles/f_list.dir/f_list.cpp.i

CMakeFiles/f_list.dir/f_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/f_list.dir/f_list.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/patryks/Workplace/004_STL/f_list/f_list.cpp -o CMakeFiles/f_list.dir/f_list.cpp.s

# Object files for target f_list
f_list_OBJECTS = \
"CMakeFiles/f_list.dir/f_list.cpp.o"

# External object files for target f_list
f_list_EXTERNAL_OBJECTS =

f_list: CMakeFiles/f_list.dir/f_list.cpp.o
f_list: CMakeFiles/f_list.dir/build.make
f_list: CMakeFiles/f_list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/patryks/Workplace/004_STL/f_list/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable f_list"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/f_list.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/f_list.dir/build: f_list
.PHONY : CMakeFiles/f_list.dir/build

CMakeFiles/f_list.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/f_list.dir/cmake_clean.cmake
.PHONY : CMakeFiles/f_list.dir/clean

CMakeFiles/f_list.dir/depend:
	cd /home/patryks/Workplace/004_STL/f_list/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/patryks/Workplace/004_STL/f_list /home/patryks/Workplace/004_STL/f_list /home/patryks/Workplace/004_STL/f_list/build /home/patryks/Workplace/004_STL/f_list/build /home/patryks/Workplace/004_STL/f_list/build/CMakeFiles/f_list.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/f_list.dir/depend

