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
CMAKE_SOURCE_DIR = /home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/widgetdemo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/widgetdemo.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/widgetdemo.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/widgetdemo.dir/flags.make

examples/CMakeFiles/widgetdemo.dir/widgetdemo.cpp.o: examples/CMakeFiles/widgetdemo.dir/flags.make
examples/CMakeFiles/widgetdemo.dir/widgetdemo.cpp.o: ../examples/widgetdemo.cpp
examples/CMakeFiles/widgetdemo.dir/widgetdemo.cpp.o: examples/CMakeFiles/widgetdemo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/widgetdemo.dir/widgetdemo.cpp.o"
	cd /home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/build/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/CMakeFiles/widgetdemo.dir/widgetdemo.cpp.o -MF CMakeFiles/widgetdemo.dir/widgetdemo.cpp.o.d -o CMakeFiles/widgetdemo.dir/widgetdemo.cpp.o -c /home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/examples/widgetdemo.cpp

examples/CMakeFiles/widgetdemo.dir/widgetdemo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/widgetdemo.dir/widgetdemo.cpp.i"
	cd /home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/build/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/examples/widgetdemo.cpp > CMakeFiles/widgetdemo.dir/widgetdemo.cpp.i

examples/CMakeFiles/widgetdemo.dir/widgetdemo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/widgetdemo.dir/widgetdemo.cpp.s"
	cd /home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/build/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/examples/widgetdemo.cpp -o CMakeFiles/widgetdemo.dir/widgetdemo.cpp.s

# Object files for target widgetdemo
widgetdemo_OBJECTS = \
"CMakeFiles/widgetdemo.dir/widgetdemo.cpp.o"

# External object files for target widgetdemo
widgetdemo_EXTERNAL_OBJECTS =

../bin/widgetdemo: examples/CMakeFiles/widgetdemo.dir/widgetdemo.cpp.o
../bin/widgetdemo: examples/CMakeFiles/widgetdemo.dir/build.make
../bin/widgetdemo: ../lib/libkshark-gui.so.2.1.0
../bin/widgetdemo: ../lib/libkshark-plot.so.2.1.0
../bin/widgetdemo: ../lib/libkshark.so.2.1.0
../bin/widgetdemo: /usr/local/lib64/libtracecmd.so
../bin/widgetdemo: /usr/local/lib64/libtracefs.so
../bin/widgetdemo: /usr/local/lib64/libtraceevent.so
../bin/widgetdemo: /usr/lib/x86_64-linux-gnu/libjson-c.so
../bin/widgetdemo: /usr/lib/x86_64-linux-gnu/libglut.so
../bin/widgetdemo: /usr/lib/x86_64-linux-gnu/libXmu.so
../bin/widgetdemo: /usr/lib/x86_64-linux-gnu/libXi.so
../bin/widgetdemo: /usr/lib/x86_64-linux-gnu/libGLU.so
../bin/widgetdemo: /usr/lib/x86_64-linux-gnu/libGL.so
../bin/widgetdemo: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
../bin/widgetdemo: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
../bin/widgetdemo: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.3
../bin/widgetdemo: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
../bin/widgetdemo: examples/CMakeFiles/widgetdemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/widgetdemo"
	cd /home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/widgetdemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/widgetdemo.dir/build: ../bin/widgetdemo
.PHONY : examples/CMakeFiles/widgetdemo.dir/build

examples/CMakeFiles/widgetdemo.dir/clean:
	cd /home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/widgetdemo.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/widgetdemo.dir/clean

examples/CMakeFiles/widgetdemo.dir/depend:
	cd /home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0 /home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/examples /home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/build /home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/build/examples /home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/build/examples/CMakeFiles/widgetdemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/widgetdemo.dir/depend

