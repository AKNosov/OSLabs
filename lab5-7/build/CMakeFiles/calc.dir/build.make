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
CMAKE_SOURCE_DIR = /home/alex/Desktop/OSLabs/lab5-7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alex/Desktop/OSLabs/lab5-7/build

# Include any dependencies generated for this target.
include CMakeFiles/calc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/calc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/calc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/calc.dir/flags.make

CMakeFiles/calc.dir/calc.cpp.o: CMakeFiles/calc.dir/flags.make
CMakeFiles/calc.dir/calc.cpp.o: ../calc.cpp
CMakeFiles/calc.dir/calc.cpp.o: CMakeFiles/calc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Desktop/OSLabs/lab5-7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/calc.dir/calc.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/calc.dir/calc.cpp.o -MF CMakeFiles/calc.dir/calc.cpp.o.d -o CMakeFiles/calc.dir/calc.cpp.o -c /home/alex/Desktop/OSLabs/lab5-7/calc.cpp

CMakeFiles/calc.dir/calc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/calc.dir/calc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Desktop/OSLabs/lab5-7/calc.cpp > CMakeFiles/calc.dir/calc.cpp.i

CMakeFiles/calc.dir/calc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/calc.dir/calc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Desktop/OSLabs/lab5-7/calc.cpp -o CMakeFiles/calc.dir/calc.cpp.s

# Object files for target calc
calc_OBJECTS = \
"CMakeFiles/calc.dir/calc.cpp.o"

# External object files for target calc
calc_EXTERNAL_OBJECTS =

calc: CMakeFiles/calc.dir/calc.cpp.o
calc: CMakeFiles/calc.dir/build.make
calc: /usr/lib/x86_64-linux-gnu/libzmq.so
calc: CMakeFiles/calc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alex/Desktop/OSLabs/lab5-7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable calc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/calc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/calc.dir/build: calc
.PHONY : CMakeFiles/calc.dir/build

CMakeFiles/calc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/calc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/calc.dir/clean

CMakeFiles/calc.dir/depend:
	cd /home/alex/Desktop/OSLabs/lab5-7/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/Desktop/OSLabs/lab5-7 /home/alex/Desktop/OSLabs/lab5-7 /home/alex/Desktop/OSLabs/lab5-7/build /home/alex/Desktop/OSLabs/lab5-7/build /home/alex/Desktop/OSLabs/lab5-7/build/CMakeFiles/calc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/calc.dir/depend

