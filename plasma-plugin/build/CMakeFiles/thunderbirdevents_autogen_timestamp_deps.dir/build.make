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

# Utility rule file for thunderbirdevents_autogen_timestamp_deps.

# Include any custom commands dependencies for this target.
include CMakeFiles/thunderbirdevents_autogen_timestamp_deps.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/thunderbirdevents_autogen_timestamp_deps.dir/progress.make

CMakeFiles/thunderbirdevents_autogen_timestamp_deps: /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin
CMakeFiles/thunderbirdevents_autogen_timestamp_deps: /usr/bin/moc
CMakeFiles/thunderbirdevents_autogen_timestamp_deps: /usr/lib/libKPim5AkonadiCalendar.so.5.24.4
CMakeFiles/thunderbirdevents_autogen_timestamp_deps: /usr/lib/libKPim5AkonadiCore.so.5.24.4
CMakeFiles/thunderbirdevents_autogen_timestamp_deps: /usr/lib/libKF5ConfigCore.so.5.114.0
CMakeFiles/thunderbirdevents_autogen_timestamp_deps: /usr/lib/libKF5CalendarEvents.so.5.114.0
CMakeFiles/thunderbirdevents_autogen_timestamp_deps: /usr/lib/libKF5KIOCore.so.5.114.0
CMakeFiles/thunderbirdevents_autogen_timestamp_deps: /usr/lib/libKF5CalendarCore.so.5.114.0
CMakeFiles/thunderbirdevents_autogen_timestamp_deps: /usr/lib/libKPim5EventViews.so.5.24.4

thunderbirdevents_autogen_timestamp_deps: CMakeFiles/thunderbirdevents_autogen_timestamp_deps
thunderbirdevents_autogen_timestamp_deps: CMakeFiles/thunderbirdevents_autogen_timestamp_deps.dir/build.make
.PHONY : thunderbirdevents_autogen_timestamp_deps

# Rule to build all files generated by this target.
CMakeFiles/thunderbirdevents_autogen_timestamp_deps.dir/build: thunderbirdevents_autogen_timestamp_deps
.PHONY : CMakeFiles/thunderbirdevents_autogen_timestamp_deps.dir/build

CMakeFiles/thunderbirdevents_autogen_timestamp_deps.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/thunderbirdevents_autogen_timestamp_deps.dir/cmake_clean.cmake
.PHONY : CMakeFiles/thunderbirdevents_autogen_timestamp_deps.dir/clean

CMakeFiles/thunderbirdevents_autogen_timestamp_deps.dir/depend:
	cd /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/build /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/build /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/build/CMakeFiles/thunderbirdevents_autogen_timestamp_deps.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/thunderbirdevents_autogen_timestamp_deps.dir/depend

