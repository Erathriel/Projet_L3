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
CMAKE_SOURCE_DIR = /home/evan/gf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evan/gf/build

# Include any dependencies generated for this target.
include tools/gf_info/CMakeFiles/gf_info.dir/depend.make

# Include the progress variables for this target.
include tools/gf_info/CMakeFiles/gf_info.dir/progress.make

# Include the compile flags for this target's objects.
include tools/gf_info/CMakeFiles/gf_info.dir/flags.make

tools/gf_info/CMakeFiles/gf_info.dir/gf_info.cc.o: tools/gf_info/CMakeFiles/gf_info.dir/flags.make
tools/gf_info/CMakeFiles/gf_info.dir/gf_info.cc.o: ../tools/gf_info/gf_info.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/evan/gf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tools/gf_info/CMakeFiles/gf_info.dir/gf_info.cc.o"
	cd /home/evan/gf/build/tools/gf_info && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gf_info.dir/gf_info.cc.o -c /home/evan/gf/tools/gf_info/gf_info.cc

tools/gf_info/CMakeFiles/gf_info.dir/gf_info.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gf_info.dir/gf_info.cc.i"
	cd /home/evan/gf/build/tools/gf_info && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/evan/gf/tools/gf_info/gf_info.cc > CMakeFiles/gf_info.dir/gf_info.cc.i

tools/gf_info/CMakeFiles/gf_info.dir/gf_info.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gf_info.dir/gf_info.cc.s"
	cd /home/evan/gf/build/tools/gf_info && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/evan/gf/tools/gf_info/gf_info.cc -o CMakeFiles/gf_info.dir/gf_info.cc.s

tools/gf_info/CMakeFiles/gf_info.dir/gf_info.cc.o.requires:

.PHONY : tools/gf_info/CMakeFiles/gf_info.dir/gf_info.cc.o.requires

tools/gf_info/CMakeFiles/gf_info.dir/gf_info.cc.o.provides: tools/gf_info/CMakeFiles/gf_info.dir/gf_info.cc.o.requires
	$(MAKE) -f tools/gf_info/CMakeFiles/gf_info.dir/build.make tools/gf_info/CMakeFiles/gf_info.dir/gf_info.cc.o.provides.build
.PHONY : tools/gf_info/CMakeFiles/gf_info.dir/gf_info.cc.o.provides

tools/gf_info/CMakeFiles/gf_info.dir/gf_info.cc.o.provides.build: tools/gf_info/CMakeFiles/gf_info.dir/gf_info.cc.o


# Object files for target gf_info
gf_info_OBJECTS = \
"CMakeFiles/gf_info.dir/gf_info.cc.o"

# External object files for target gf_info
gf_info_EXTERNAL_OBJECTS =

tools/gf_info/gf_info: tools/gf_info/CMakeFiles/gf_info.dir/gf_info.cc.o
tools/gf_info/gf_info: tools/gf_info/CMakeFiles/gf_info.dir/build.make
tools/gf_info/gf_info: library/libgf0.so.0.6.0
tools/gf_info/gf_info: /usr/lib/x86_64-linux-gnu/libSDL2.so
tools/gf_info/gf_info: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
tools/gf_info/gf_info: /usr/lib/x86_64-linux-gnu/libboost_system.so
tools/gf_info/gf_info: /usr/lib/x86_64-linux-gnu/libfreetype.so
tools/gf_info/gf_info: /usr/lib/x86_64-linux-gnu/libz.so
tools/gf_info/gf_info: tools/gf_info/CMakeFiles/gf_info.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/evan/gf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gf_info"
	cd /home/evan/gf/build/tools/gf_info && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gf_info.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/gf_info/CMakeFiles/gf_info.dir/build: tools/gf_info/gf_info

.PHONY : tools/gf_info/CMakeFiles/gf_info.dir/build

tools/gf_info/CMakeFiles/gf_info.dir/requires: tools/gf_info/CMakeFiles/gf_info.dir/gf_info.cc.o.requires

.PHONY : tools/gf_info/CMakeFiles/gf_info.dir/requires

tools/gf_info/CMakeFiles/gf_info.dir/clean:
	cd /home/evan/gf/build/tools/gf_info && $(CMAKE_COMMAND) -P CMakeFiles/gf_info.dir/cmake_clean.cmake
.PHONY : tools/gf_info/CMakeFiles/gf_info.dir/clean

tools/gf_info/CMakeFiles/gf_info.dir/depend:
	cd /home/evan/gf/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evan/gf /home/evan/gf/tools/gf_info /home/evan/gf/build /home/evan/gf/build/tools/gf_info /home/evan/gf/build/tools/gf_info/CMakeFiles/gf_info.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/gf_info/CMakeFiles/gf_info.dir/depend
