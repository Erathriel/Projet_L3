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
CMAKE_SOURCE_DIR = /home/evan/Documents/Projet_L3/jeu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evan/Documents/Projet_L3/jeu

# Include any dependencies generated for this target.
include game/CMakeFiles/game.dir/depend.make

# Include the progress variables for this target.
include game/CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include game/CMakeFiles/game.dir/flags.make

game/CMakeFiles/game.dir/code/main.cc.o: game/CMakeFiles/game.dir/flags.make
game/CMakeFiles/game.dir/code/main.cc.o: game/code/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/evan/Documents/Projet_L3/jeu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object game/CMakeFiles/game.dir/code/main.cc.o"
	cd /home/evan/Documents/Projet_L3/jeu/game && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/code/main.cc.o -c /home/evan/Documents/Projet_L3/jeu/game/code/main.cc

game/CMakeFiles/game.dir/code/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/code/main.cc.i"
	cd /home/evan/Documents/Projet_L3/jeu/game && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/evan/Documents/Projet_L3/jeu/game/code/main.cc > CMakeFiles/game.dir/code/main.cc.i

game/CMakeFiles/game.dir/code/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/code/main.cc.s"
	cd /home/evan/Documents/Projet_L3/jeu/game && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/evan/Documents/Projet_L3/jeu/game/code/main.cc -o CMakeFiles/game.dir/code/main.cc.s

game/CMakeFiles/game.dir/code/main.cc.o.requires:

.PHONY : game/CMakeFiles/game.dir/code/main.cc.o.requires

game/CMakeFiles/game.dir/code/main.cc.o.provides: game/CMakeFiles/game.dir/code/main.cc.o.requires
	$(MAKE) -f game/CMakeFiles/game.dir/build.make game/CMakeFiles/game.dir/code/main.cc.o.provides.build
.PHONY : game/CMakeFiles/game.dir/code/main.cc.o.provides

game/CMakeFiles/game.dir/code/main.cc.o.provides.build: game/CMakeFiles/game.dir/code/main.cc.o


game/CMakeFiles/game.dir/code/local/Level.cpp.o: game/CMakeFiles/game.dir/flags.make
game/CMakeFiles/game.dir/code/local/Level.cpp.o: game/code/local/Level.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/evan/Documents/Projet_L3/jeu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object game/CMakeFiles/game.dir/code/local/Level.cpp.o"
	cd /home/evan/Documents/Projet_L3/jeu/game && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/code/local/Level.cpp.o -c /home/evan/Documents/Projet_L3/jeu/game/code/local/Level.cpp

game/CMakeFiles/game.dir/code/local/Level.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/code/local/Level.cpp.i"
	cd /home/evan/Documents/Projet_L3/jeu/game && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/evan/Documents/Projet_L3/jeu/game/code/local/Level.cpp > CMakeFiles/game.dir/code/local/Level.cpp.i

game/CMakeFiles/game.dir/code/local/Level.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/code/local/Level.cpp.s"
	cd /home/evan/Documents/Projet_L3/jeu/game && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/evan/Documents/Projet_L3/jeu/game/code/local/Level.cpp -o CMakeFiles/game.dir/code/local/Level.cpp.s

game/CMakeFiles/game.dir/code/local/Level.cpp.o.requires:

.PHONY : game/CMakeFiles/game.dir/code/local/Level.cpp.o.requires

game/CMakeFiles/game.dir/code/local/Level.cpp.o.provides: game/CMakeFiles/game.dir/code/local/Level.cpp.o.requires
	$(MAKE) -f game/CMakeFiles/game.dir/build.make game/CMakeFiles/game.dir/code/local/Level.cpp.o.provides.build
.PHONY : game/CMakeFiles/game.dir/code/local/Level.cpp.o.provides

game/CMakeFiles/game.dir/code/local/Level.cpp.o.provides.build: game/CMakeFiles/game.dir/code/local/Level.cpp.o


game/CMakeFiles/game.dir/code/local/GameObject.cpp.o: game/CMakeFiles/game.dir/flags.make
game/CMakeFiles/game.dir/code/local/GameObject.cpp.o: game/code/local/GameObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/evan/Documents/Projet_L3/jeu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object game/CMakeFiles/game.dir/code/local/GameObject.cpp.o"
	cd /home/evan/Documents/Projet_L3/jeu/game && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/code/local/GameObject.cpp.o -c /home/evan/Documents/Projet_L3/jeu/game/code/local/GameObject.cpp

game/CMakeFiles/game.dir/code/local/GameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/code/local/GameObject.cpp.i"
	cd /home/evan/Documents/Projet_L3/jeu/game && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/evan/Documents/Projet_L3/jeu/game/code/local/GameObject.cpp > CMakeFiles/game.dir/code/local/GameObject.cpp.i

game/CMakeFiles/game.dir/code/local/GameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/code/local/GameObject.cpp.s"
	cd /home/evan/Documents/Projet_L3/jeu/game && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/evan/Documents/Projet_L3/jeu/game/code/local/GameObject.cpp -o CMakeFiles/game.dir/code/local/GameObject.cpp.s

game/CMakeFiles/game.dir/code/local/GameObject.cpp.o.requires:

.PHONY : game/CMakeFiles/game.dir/code/local/GameObject.cpp.o.requires

game/CMakeFiles/game.dir/code/local/GameObject.cpp.o.provides: game/CMakeFiles/game.dir/code/local/GameObject.cpp.o.requires
	$(MAKE) -f game/CMakeFiles/game.dir/build.make game/CMakeFiles/game.dir/code/local/GameObject.cpp.o.provides.build
.PHONY : game/CMakeFiles/game.dir/code/local/GameObject.cpp.o.provides

game/CMakeFiles/game.dir/code/local/GameObject.cpp.o.provides.build: game/CMakeFiles/game.dir/code/local/GameObject.cpp.o


game/CMakeFiles/game.dir/code/local/Graphics.cpp.o: game/CMakeFiles/game.dir/flags.make
game/CMakeFiles/game.dir/code/local/Graphics.cpp.o: game/code/local/Graphics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/evan/Documents/Projet_L3/jeu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object game/CMakeFiles/game.dir/code/local/Graphics.cpp.o"
	cd /home/evan/Documents/Projet_L3/jeu/game && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/code/local/Graphics.cpp.o -c /home/evan/Documents/Projet_L3/jeu/game/code/local/Graphics.cpp

game/CMakeFiles/game.dir/code/local/Graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/code/local/Graphics.cpp.i"
	cd /home/evan/Documents/Projet_L3/jeu/game && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/evan/Documents/Projet_L3/jeu/game/code/local/Graphics.cpp > CMakeFiles/game.dir/code/local/Graphics.cpp.i

game/CMakeFiles/game.dir/code/local/Graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/code/local/Graphics.cpp.s"
	cd /home/evan/Documents/Projet_L3/jeu/game && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/evan/Documents/Projet_L3/jeu/game/code/local/Graphics.cpp -o CMakeFiles/game.dir/code/local/Graphics.cpp.s

game/CMakeFiles/game.dir/code/local/Graphics.cpp.o.requires:

.PHONY : game/CMakeFiles/game.dir/code/local/Graphics.cpp.o.requires

game/CMakeFiles/game.dir/code/local/Graphics.cpp.o.provides: game/CMakeFiles/game.dir/code/local/Graphics.cpp.o.requires
	$(MAKE) -f game/CMakeFiles/game.dir/build.make game/CMakeFiles/game.dir/code/local/Graphics.cpp.o.provides.build
.PHONY : game/CMakeFiles/game.dir/code/local/Graphics.cpp.o.provides

game/CMakeFiles/game.dir/code/local/Graphics.cpp.o.provides.build: game/CMakeFiles/game.dir/code/local/Graphics.cpp.o


# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/code/main.cc.o" \
"CMakeFiles/game.dir/code/local/Level.cpp.o" \
"CMakeFiles/game.dir/code/local/GameObject.cpp.o" \
"CMakeFiles/game.dir/code/local/Graphics.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

game/game: game/CMakeFiles/game.dir/code/main.cc.o
game/game: game/CMakeFiles/game.dir/code/local/Level.cpp.o
game/game: game/CMakeFiles/game.dir/code/local/GameObject.cpp.o
game/game: game/CMakeFiles/game.dir/code/local/Graphics.cpp.o
game/game: game/CMakeFiles/game.dir/build.make
game/game: library/libgf0.so.0.6.0
game/game: /usr/lib/x86_64-linux-gnu/libSDL2.so
game/game: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
game/game: /usr/lib/x86_64-linux-gnu/libboost_system.so
game/game: /usr/lib/x86_64-linux-gnu/libfreetype.so
game/game: /usr/lib/x86_64-linux-gnu/libz.so
game/game: library/libBox2D.a
game/game: game/CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/evan/Documents/Projet_L3/jeu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable game"
	cd /home/evan/Documents/Projet_L3/jeu/game && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
game/CMakeFiles/game.dir/build: game/game

.PHONY : game/CMakeFiles/game.dir/build

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/code/main.cc.o" \
"CMakeFiles/game.dir/code/local/Level.cpp.o" \
"CMakeFiles/game.dir/code/local/GameObject.cpp.o" \
"CMakeFiles/game.dir/code/local/Graphics.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

game/CMakeFiles/CMakeRelink.dir/game: game/CMakeFiles/game.dir/code/main.cc.o
game/CMakeFiles/CMakeRelink.dir/game: game/CMakeFiles/game.dir/code/local/Level.cpp.o
game/CMakeFiles/CMakeRelink.dir/game: game/CMakeFiles/game.dir/code/local/GameObject.cpp.o
game/CMakeFiles/CMakeRelink.dir/game: game/CMakeFiles/game.dir/code/local/Graphics.cpp.o
game/CMakeFiles/CMakeRelink.dir/game: game/CMakeFiles/game.dir/build.make
game/CMakeFiles/CMakeRelink.dir/game: library/libgf0.so.0.6.0
game/CMakeFiles/CMakeRelink.dir/game: /usr/lib/x86_64-linux-gnu/libSDL2.so
game/CMakeFiles/CMakeRelink.dir/game: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
game/CMakeFiles/CMakeRelink.dir/game: /usr/lib/x86_64-linux-gnu/libboost_system.so
game/CMakeFiles/CMakeRelink.dir/game: /usr/lib/x86_64-linux-gnu/libfreetype.so
game/CMakeFiles/CMakeRelink.dir/game: /usr/lib/x86_64-linux-gnu/libz.so
game/CMakeFiles/CMakeRelink.dir/game: library/libBox2D.a
game/CMakeFiles/CMakeRelink.dir/game: game/CMakeFiles/game.dir/relink.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/evan/Documents/Projet_L3/jeu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable CMakeFiles/CMakeRelink.dir/game"
	cd /home/evan/Documents/Projet_L3/jeu/game && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/relink.txt --verbose=$(VERBOSE)

# Rule to relink during preinstall.
game/CMakeFiles/game.dir/preinstall: game/CMakeFiles/CMakeRelink.dir/game

.PHONY : game/CMakeFiles/game.dir/preinstall

game/CMakeFiles/game.dir/requires: game/CMakeFiles/game.dir/code/main.cc.o.requires
game/CMakeFiles/game.dir/requires: game/CMakeFiles/game.dir/code/local/Level.cpp.o.requires
game/CMakeFiles/game.dir/requires: game/CMakeFiles/game.dir/code/local/GameObject.cpp.o.requires
game/CMakeFiles/game.dir/requires: game/CMakeFiles/game.dir/code/local/Graphics.cpp.o.requires

.PHONY : game/CMakeFiles/game.dir/requires

game/CMakeFiles/game.dir/clean:
	cd /home/evan/Documents/Projet_L3/jeu/game && $(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : game/CMakeFiles/game.dir/clean

game/CMakeFiles/game.dir/depend:
	cd /home/evan/Documents/Projet_L3/jeu && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evan/Documents/Projet_L3/jeu /home/evan/Documents/Projet_L3/jeu/game /home/evan/Documents/Projet_L3/jeu /home/evan/Documents/Projet_L3/jeu/game /home/evan/Documents/Projet_L3/jeu/game/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : game/CMakeFiles/game.dir/depend

