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
CMAKE_SOURCE_DIR = /home/ricanontherun/Code/Tabulr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ricanontherun/Code/Tabulr/build

# Include any dependencies generated for this target.
include CMakeFiles/tabulr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tabulr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tabulr.dir/flags.make

CMakeFiles/tabulr.dir/main.cpp.o: CMakeFiles/tabulr.dir/flags.make
CMakeFiles/tabulr.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ricanontherun/Code/Tabulr/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tabulr.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tabulr.dir/main.cpp.o -c /home/ricanontherun/Code/Tabulr/main.cpp

CMakeFiles/tabulr.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tabulr.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ricanontherun/Code/Tabulr/main.cpp > CMakeFiles/tabulr.dir/main.cpp.i

CMakeFiles/tabulr.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tabulr.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ricanontherun/Code/Tabulr/main.cpp -o CMakeFiles/tabulr.dir/main.cpp.s

CMakeFiles/tabulr.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/tabulr.dir/main.cpp.o.requires

CMakeFiles/tabulr.dir/main.cpp.o.provides: CMakeFiles/tabulr.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/tabulr.dir/build.make CMakeFiles/tabulr.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/tabulr.dir/main.cpp.o.provides

CMakeFiles/tabulr.dir/main.cpp.o.provides.build: CMakeFiles/tabulr.dir/main.cpp.o


# Object files for target tabulr
tabulr_OBJECTS = \
"CMakeFiles/tabulr.dir/main.cpp.o"

# External object files for target tabulr
tabulr_EXTERNAL_OBJECTS =

tabulr: CMakeFiles/tabulr.dir/main.cpp.o
tabulr: CMakeFiles/tabulr.dir/build.make
tabulr: CMakeFiles/tabulr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ricanontherun/Code/Tabulr/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tabulr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tabulr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tabulr.dir/build: tabulr

.PHONY : CMakeFiles/tabulr.dir/build

CMakeFiles/tabulr.dir/requires: CMakeFiles/tabulr.dir/main.cpp.o.requires

.PHONY : CMakeFiles/tabulr.dir/requires

CMakeFiles/tabulr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tabulr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tabulr.dir/clean

CMakeFiles/tabulr.dir/depend:
	cd /home/ricanontherun/Code/Tabulr/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ricanontherun/Code/Tabulr /home/ricanontherun/Code/Tabulr /home/ricanontherun/Code/Tabulr/build /home/ricanontherun/Code/Tabulr/build /home/ricanontherun/Code/Tabulr/build/CMakeFiles/tabulr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tabulr.dir/depend

