# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\term 3\Data structure\prj1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\term 3\Data structure\prj1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/prj1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prj1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prj1.dir/flags.make

CMakeFiles/prj1.dir/main.cpp.obj: CMakeFiles/prj1.dir/flags.make
CMakeFiles/prj1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\term 3\Data structure\prj1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/prj1.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\prj1.dir\main.cpp.obj -c "D:\term 3\Data structure\prj1\main.cpp"

CMakeFiles/prj1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prj1.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\term 3\Data structure\prj1\main.cpp" > CMakeFiles\prj1.dir\main.cpp.i

CMakeFiles/prj1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prj1.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\term 3\Data structure\prj1\main.cpp" -o CMakeFiles\prj1.dir\main.cpp.s

# Object files for target prj1
prj1_OBJECTS = \
"CMakeFiles/prj1.dir/main.cpp.obj"

# External object files for target prj1
prj1_EXTERNAL_OBJECTS =

prj1.exe: CMakeFiles/prj1.dir/main.cpp.obj
prj1.exe: CMakeFiles/prj1.dir/build.make
prj1.exe: CMakeFiles/prj1.dir/linklibs.rsp
prj1.exe: CMakeFiles/prj1.dir/objects1.rsp
prj1.exe: CMakeFiles/prj1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\term 3\Data structure\prj1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable prj1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\prj1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prj1.dir/build: prj1.exe

.PHONY : CMakeFiles/prj1.dir/build

CMakeFiles/prj1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\prj1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/prj1.dir/clean

CMakeFiles/prj1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\term 3\Data structure\prj1" "D:\term 3\Data structure\prj1" "D:\term 3\Data structure\prj1\cmake-build-debug" "D:\term 3\Data structure\prj1\cmake-build-debug" "D:\term 3\Data structure\prj1\cmake-build-debug\CMakeFiles\prj1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/prj1.dir/depend

