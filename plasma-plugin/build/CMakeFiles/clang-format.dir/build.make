# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/build

# Utility rule file for clang-format.

# Include any custom commands dependencies for this target.
include CMakeFiles/clang-format.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/clang-format.dir/progress.make

clang-format: CMakeFiles/clang-format.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/akonadipimdatasource.cpp..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/akonadipimdatasource.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/akonadipimdatasource.h..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/akonadipimdatasource.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/autotests/eventdatavisitortest.cpp..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/autotests/eventdatavisitortest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/autotests/eventdatavisitortest.h..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/autotests/eventdatavisitortest.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/autotests/fakepimdatasource.cpp..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/autotests/fakepimdatasource.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/autotests/fakepimdatasource.h..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/autotests/fakepimdatasource.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/autotests/pimeventsplugintest.cpp..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/autotests/pimeventsplugintest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/autotests/pimeventsplugintest.h..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/autotests/pimeventsplugintest.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/autotests/testdataparser.cpp..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/autotests/testdataparser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/autotests/testdataparser.h..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/autotests/testdataparser.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/autotests/testutils.h..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/autotests/testutils.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/connection.cpp..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/connection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/connection.h..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/connection.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/eventdatavisitor.cpp..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/eventdatavisitor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/eventdatavisitor.h..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/eventdatavisitor.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/eventmodel.cpp..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/eventmodel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/eventmodel.h..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/eventmodel.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/settingschangenotifier.cpp..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/settingschangenotifier.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/settingschangenotifier.h..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/settingschangenotifier.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/thunderbirdcalendarsmodel.cpp..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/thunderbirdcalendarsmodel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/thunderbirdcalendarsmodel.h..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/thunderbirdcalendarsmodel.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/thunderbirdcalendarsplugin.cpp..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/thunderbirdcalendarsplugin.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/thunderbirddatasource.h..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/thunderbirddatasource.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/thunderbirdeventsplugin.cpp..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/thunderbirdeventsplugin.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Formatting /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/thunderbirdeventsplugin.h..."
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin && /usr/bin/clang-format -style=file -i /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/thunderbirdeventsplugin.h
.PHONY : clang-format

# Rule to build all files generated by this target.
CMakeFiles/clang-format.dir/build: clang-format
.PHONY : CMakeFiles/clang-format.dir/build

CMakeFiles/clang-format.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clang-format.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clang-format.dir/clean

CMakeFiles/clang-format.dir/depend:
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/build /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/build /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/build/CMakeFiles/clang-format.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/clang-format.dir/depend
