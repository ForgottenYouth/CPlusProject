# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\NDK_workspace\CPlusProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\NDK_workspace\CPlusProject\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CPlugProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CPlugProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPlugProject.dir/flags.make

CMakeFiles/CPlugProject.dir/T7_Demo.cpp.obj: CMakeFiles/CPlugProject.dir/flags.make
CMakeFiles/CPlugProject.dir/T7_Demo.cpp.obj: ../T7_Demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\NDK_workspace\CPlusProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPlugProject.dir/T7_Demo.cpp.obj"
	D:\NDK_environment\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CPlugProject.dir\T7_Demo.cpp.obj -c D:\NDK_workspace\CPlusProject\T7_Demo.cpp

CMakeFiles/CPlugProject.dir/T7_Demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPlugProject.dir/T7_Demo.cpp.i"
	D:\NDK_environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\NDK_workspace\CPlusProject\T7_Demo.cpp > CMakeFiles\CPlugProject.dir\T7_Demo.cpp.i

CMakeFiles/CPlugProject.dir/T7_Demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPlugProject.dir/T7_Demo.cpp.s"
	D:\NDK_environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\NDK_workspace\CPlusProject\T7_Demo.cpp -o CMakeFiles\CPlugProject.dir\T7_Demo.cpp.s

# Object files for target CPlugProject
CPlugProject_OBJECTS = \
"CMakeFiles/CPlugProject.dir/T7_Demo.cpp.obj"

# External object files for target CPlugProject
CPlugProject_EXTERNAL_OBJECTS =

CPlugProject.exe: CMakeFiles/CPlugProject.dir/T7_Demo.cpp.obj
CPlugProject.exe: CMakeFiles/CPlugProject.dir/build.make
CPlugProject.exe: CMakeFiles/CPlugProject.dir/linklibs.rsp
CPlugProject.exe: CMakeFiles/CPlugProject.dir/objects1.rsp
CPlugProject.exe: CMakeFiles/CPlugProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\NDK_workspace\CPlusProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CPlugProject.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CPlugProject.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPlugProject.dir/build: CPlugProject.exe

.PHONY : CMakeFiles/CPlugProject.dir/build

CMakeFiles/CPlugProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CPlugProject.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CPlugProject.dir/clean

CMakeFiles/CPlugProject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\NDK_workspace\CPlusProject D:\NDK_workspace\CPlusProject D:\NDK_workspace\CPlusProject\cmake-build-debug D:\NDK_workspace\CPlusProject\cmake-build-debug D:\NDK_workspace\CPlusProject\cmake-build-debug\CMakeFiles\CPlugProject.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPlugProject.dir/depend
