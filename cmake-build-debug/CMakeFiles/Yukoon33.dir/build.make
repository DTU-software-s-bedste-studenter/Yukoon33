# CMAKE generated file: DO NOT EDIT!
<<<<<<< HEAD
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24
=======
# Generated by "Unix Makefiles" Generator, CMake Version 3.24
>>>>>>> 3871d3d78c08c681fd5eb47a10cc007bcbab4792

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

<<<<<<< HEAD
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.3.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.3.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f
=======
# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f
>>>>>>> 3871d3d78c08c681fd5eb47a10cc007bcbab4792

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
<<<<<<< HEAD
CMAKE_SOURCE_DIR = C:\Users\ansi1\CLionProjects\Yukoon33

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ansi1\CLionProjects\Yukoon33\cmake-build-debug
=======
CMAKE_SOURCE_DIR = /Users/matt/CLionProjects/Yukoon33

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/matt/CLionProjects/Yukoon33/cmake-build-debug
>>>>>>> 3871d3d78c08c681fd5eb47a10cc007bcbab4792

# Include any dependencies generated for this target.
include CMakeFiles/Yukoon33.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Yukoon33.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Yukoon33.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Yukoon33.dir/flags.make

<<<<<<< HEAD
CMakeFiles/Yukoon33.dir/main.c.obj: CMakeFiles/Yukoon33.dir/flags.make
CMakeFiles/Yukoon33.dir/main.c.obj: C:/Users/ansi1/CLionProjects/Yukoon33/main.c
CMakeFiles/Yukoon33.dir/main.c.obj: CMakeFiles/Yukoon33.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ansi1\CLionProjects\Yukoon33\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Yukoon33.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Yukoon33.dir/main.c.obj -MF CMakeFiles\Yukoon33.dir\main.c.obj.d -o CMakeFiles\Yukoon33.dir\main.c.obj -c C:\Users\ansi1\CLionProjects\Yukoon33\main.c

CMakeFiles/Yukoon33.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Yukoon33.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\ansi1\CLionProjects\Yukoon33\main.c > CMakeFiles\Yukoon33.dir\main.c.i

CMakeFiles/Yukoon33.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Yukoon33.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\ansi1\CLionProjects\Yukoon33\main.c -o CMakeFiles\Yukoon33.dir\main.c.s

# Object files for target Yukoon33
Yukoon33_OBJECTS = \
"CMakeFiles/Yukoon33.dir/main.c.obj"
=======
CMakeFiles/Yukoon33.dir/main.c.o: CMakeFiles/Yukoon33.dir/flags.make
CMakeFiles/Yukoon33.dir/main.c.o: /Users/matt/CLionProjects/Yukoon33/main.c
CMakeFiles/Yukoon33.dir/main.c.o: CMakeFiles/Yukoon33.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matt/CLionProjects/Yukoon33/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Yukoon33.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Yukoon33.dir/main.c.o -MF CMakeFiles/Yukoon33.dir/main.c.o.d -o CMakeFiles/Yukoon33.dir/main.c.o -c /Users/matt/CLionProjects/Yukoon33/main.c

CMakeFiles/Yukoon33.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Yukoon33.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/matt/CLionProjects/Yukoon33/main.c > CMakeFiles/Yukoon33.dir/main.c.i

CMakeFiles/Yukoon33.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Yukoon33.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/matt/CLionProjects/Yukoon33/main.c -o CMakeFiles/Yukoon33.dir/main.c.s

# Object files for target Yukoon33
Yukoon33_OBJECTS = \
"CMakeFiles/Yukoon33.dir/main.c.o"
>>>>>>> 3871d3d78c08c681fd5eb47a10cc007bcbab4792

# External object files for target Yukoon33
Yukoon33_EXTERNAL_OBJECTS =

<<<<<<< HEAD
Yukoon33.exe: CMakeFiles/Yukoon33.dir/main.c.obj
Yukoon33.exe: CMakeFiles/Yukoon33.dir/build.make
Yukoon33.exe: CMakeFiles/Yukoon33.dir/linklibs.rsp
Yukoon33.exe: CMakeFiles/Yukoon33.dir/objects1.rsp
Yukoon33.exe: CMakeFiles/Yukoon33.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ansi1\CLionProjects\Yukoon33\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Yukoon33.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Yukoon33.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Yukoon33.dir/build: Yukoon33.exe
.PHONY : CMakeFiles/Yukoon33.dir/build

CMakeFiles/Yukoon33.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Yukoon33.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Yukoon33.dir/clean

CMakeFiles/Yukoon33.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ansi1\CLionProjects\Yukoon33 C:\Users\ansi1\CLionProjects\Yukoon33 C:\Users\ansi1\CLionProjects\Yukoon33\cmake-build-debug C:\Users\ansi1\CLionProjects\Yukoon33\cmake-build-debug C:\Users\ansi1\CLionProjects\Yukoon33\cmake-build-debug\CMakeFiles\Yukoon33.dir\DependInfo.cmake --color=$(COLOR)
=======
Yukoon33: CMakeFiles/Yukoon33.dir/main.c.o
Yukoon33: CMakeFiles/Yukoon33.dir/build.make
Yukoon33: CMakeFiles/Yukoon33.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/matt/CLionProjects/Yukoon33/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Yukoon33"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Yukoon33.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Yukoon33.dir/build: Yukoon33
.PHONY : CMakeFiles/Yukoon33.dir/build

CMakeFiles/Yukoon33.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Yukoon33.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Yukoon33.dir/clean

CMakeFiles/Yukoon33.dir/depend:
	cd /Users/matt/CLionProjects/Yukoon33/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/matt/CLionProjects/Yukoon33 /Users/matt/CLionProjects/Yukoon33 /Users/matt/CLionProjects/Yukoon33/cmake-build-debug /Users/matt/CLionProjects/Yukoon33/cmake-build-debug /Users/matt/CLionProjects/Yukoon33/cmake-build-debug/CMakeFiles/Yukoon33.dir/DependInfo.cmake --color=$(COLOR)
>>>>>>> 3871d3d78c08c681fd5eb47a10cc007bcbab4792
.PHONY : CMakeFiles/Yukoon33.dir/depend

