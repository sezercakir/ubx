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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.22.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.22.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sezer/CLionProjects/algo1/read_gnssMsg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sezer/CLionProjects/algo1/read_gnssMsg/build

# Include any dependencies generated for this target.
include App/CMakeFiles/App.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include App/CMakeFiles/App.dir/compiler_depend.make

# Include the progress variables for this target.
include App/CMakeFiles/App.dir/progress.make

# Include the compile flags for this target's objects.
include App/CMakeFiles/App.dir/flags.make

App/CMakeFiles/App.dir/src/main.cpp.o: App/CMakeFiles/App.dir/flags.make
App/CMakeFiles/App.dir/src/main.cpp.o: ../App/src/main.cpp
App/CMakeFiles/App.dir/src/main.cpp.o: App/CMakeFiles/App.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sezer/CLionProjects/algo1/read_gnssMsg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object App/CMakeFiles/App.dir/src/main.cpp.o"
	cd /Users/sezer/CLionProjects/algo1/read_gnssMsg/build/App && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT App/CMakeFiles/App.dir/src/main.cpp.o -MF CMakeFiles/App.dir/src/main.cpp.o.d -o CMakeFiles/App.dir/src/main.cpp.o -c /Users/sezer/CLionProjects/algo1/read_gnssMsg/App/src/main.cpp

App/CMakeFiles/App.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/App.dir/src/main.cpp.i"
	cd /Users/sezer/CLionProjects/algo1/read_gnssMsg/build/App && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sezer/CLionProjects/algo1/read_gnssMsg/App/src/main.cpp > CMakeFiles/App.dir/src/main.cpp.i

App/CMakeFiles/App.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/App.dir/src/main.cpp.s"
	cd /Users/sezer/CLionProjects/algo1/read_gnssMsg/build/App && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sezer/CLionProjects/algo1/read_gnssMsg/App/src/main.cpp -o CMakeFiles/App.dir/src/main.cpp.s

# Object files for target App
App_OBJECTS = \
"CMakeFiles/App.dir/src/main.cpp.o"

# External object files for target App
App_EXTERNAL_OBJECTS =

App/App: App/CMakeFiles/App.dir/src/main.cpp.o
App/App: App/CMakeFiles/App.dir/build.make
App/App: Libs/read_messages/libread_messages.a
App/App: Libs/utils/libutils.a
App/App: App/CMakeFiles/App.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sezer/CLionProjects/algo1/read_gnssMsg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable App"
	cd /Users/sezer/CLionProjects/algo1/read_gnssMsg/build/App && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/App.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
App/CMakeFiles/App.dir/build: App/App
.PHONY : App/CMakeFiles/App.dir/build

App/CMakeFiles/App.dir/clean:
	cd /Users/sezer/CLionProjects/algo1/read_gnssMsg/build/App && $(CMAKE_COMMAND) -P CMakeFiles/App.dir/cmake_clean.cmake
.PHONY : App/CMakeFiles/App.dir/clean

App/CMakeFiles/App.dir/depend:
	cd /Users/sezer/CLionProjects/algo1/read_gnssMsg/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sezer/CLionProjects/algo1/read_gnssMsg /Users/sezer/CLionProjects/algo1/read_gnssMsg/App /Users/sezer/CLionProjects/algo1/read_gnssMsg/build /Users/sezer/CLionProjects/algo1/read_gnssMsg/build/App /Users/sezer/CLionProjects/algo1/read_gnssMsg/build/App/CMakeFiles/App.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : App/CMakeFiles/App.dir/depend

