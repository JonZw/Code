# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/felix/Schreibtisch/Code/IPK/uebung06/6.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/felix/Schreibtisch/Code/IPK/uebung06/6.1/release-build

# Include any dependencies generated for this target.
include CMakeFiles/uniformv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/uniformv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/uniformv.dir/flags.make

CMakeFiles/uniformv.dir/uniform.cc.o: CMakeFiles/uniformv.dir/flags.make
CMakeFiles/uniformv.dir/uniform.cc.o: ../uniform.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/felix/Schreibtisch/Code/IPK/uebung06/6.1/release-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/uniformv.dir/uniform.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/uniformv.dir/uniform.cc.o -c /home/felix/Schreibtisch/Code/IPK/uebung06/6.1/uniform.cc

CMakeFiles/uniformv.dir/uniform.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uniformv.dir/uniform.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/felix/Schreibtisch/Code/IPK/uebung06/6.1/uniform.cc > CMakeFiles/uniformv.dir/uniform.cc.i

CMakeFiles/uniformv.dir/uniform.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uniformv.dir/uniform.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/felix/Schreibtisch/Code/IPK/uebung06/6.1/uniform.cc -o CMakeFiles/uniformv.dir/uniform.cc.s

CMakeFiles/uniformv.dir/uniform.cc.o.requires:

.PHONY : CMakeFiles/uniformv.dir/uniform.cc.o.requires

CMakeFiles/uniformv.dir/uniform.cc.o.provides: CMakeFiles/uniformv.dir/uniform.cc.o.requires
	$(MAKE) -f CMakeFiles/uniformv.dir/build.make CMakeFiles/uniformv.dir/uniform.cc.o.provides.build
.PHONY : CMakeFiles/uniformv.dir/uniform.cc.o.provides

CMakeFiles/uniformv.dir/uniform.cc.o.provides.build: CMakeFiles/uniformv.dir/uniform.cc.o


# Object files for target uniformv
uniformv_OBJECTS = \
"CMakeFiles/uniformv.dir/uniform.cc.o"

# External object files for target uniformv
uniformv_EXTERNAL_OBJECTS =

uniformv: CMakeFiles/uniformv.dir/uniform.cc.o
uniformv: CMakeFiles/uniformv.dir/build.make
uniformv: CMakeFiles/uniformv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/felix/Schreibtisch/Code/IPK/uebung06/6.1/release-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable uniformv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/uniformv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/uniformv.dir/build: uniformv

.PHONY : CMakeFiles/uniformv.dir/build

CMakeFiles/uniformv.dir/requires: CMakeFiles/uniformv.dir/uniform.cc.o.requires

.PHONY : CMakeFiles/uniformv.dir/requires

CMakeFiles/uniformv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/uniformv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/uniformv.dir/clean

CMakeFiles/uniformv.dir/depend:
	cd /home/felix/Schreibtisch/Code/IPK/uebung06/6.1/release-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/felix/Schreibtisch/Code/IPK/uebung06/6.1 /home/felix/Schreibtisch/Code/IPK/uebung06/6.1 /home/felix/Schreibtisch/Code/IPK/uebung06/6.1/release-build /home/felix/Schreibtisch/Code/IPK/uebung06/6.1/release-build /home/felix/Schreibtisch/Code/IPK/uebung06/6.1/release-build/CMakeFiles/uniformv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/uniformv.dir/depend

