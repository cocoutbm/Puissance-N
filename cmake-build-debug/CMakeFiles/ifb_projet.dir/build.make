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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\coco\CLionProjects\ifb_projet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\coco\CLionProjects\ifb_projet\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ifb_projet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ifb_projet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ifb_projet.dir/flags.make

CMakeFiles/ifb_projet.dir/main.c.obj: CMakeFiles/ifb_projet.dir/flags.make
CMakeFiles/ifb_projet.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\coco\CLionProjects\ifb_projet\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ifb_projet.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ifb_projet.dir\main.c.obj   -c C:\Users\coco\CLionProjects\ifb_projet\main.c

CMakeFiles/ifb_projet.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ifb_projet.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\coco\CLionProjects\ifb_projet\main.c > CMakeFiles\ifb_projet.dir\main.c.i

CMakeFiles/ifb_projet.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ifb_projet.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\coco\CLionProjects\ifb_projet\main.c -o CMakeFiles\ifb_projet.dir\main.c.s

CMakeFiles/ifb_projet.dir/Puissance_N.c.obj: CMakeFiles/ifb_projet.dir/flags.make
CMakeFiles/ifb_projet.dir/Puissance_N.c.obj: ../Puissance_N.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\coco\CLionProjects\ifb_projet\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ifb_projet.dir/Puissance_N.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ifb_projet.dir\Puissance_N.c.obj   -c C:\Users\coco\CLionProjects\ifb_projet\Puissance_N.c

CMakeFiles/ifb_projet.dir/Puissance_N.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ifb_projet.dir/Puissance_N.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\coco\CLionProjects\ifb_projet\Puissance_N.c > CMakeFiles\ifb_projet.dir\Puissance_N.c.i

CMakeFiles/ifb_projet.dir/Puissance_N.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ifb_projet.dir/Puissance_N.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\coco\CLionProjects\ifb_projet\Puissance_N.c -o CMakeFiles\ifb_projet.dir\Puissance_N.c.s

# Object files for target ifb_projet
ifb_projet_OBJECTS = \
"CMakeFiles/ifb_projet.dir/main.c.obj" \
"CMakeFiles/ifb_projet.dir/Puissance_N.c.obj"

# External object files for target ifb_projet
ifb_projet_EXTERNAL_OBJECTS =

ifb_projet.exe: CMakeFiles/ifb_projet.dir/main.c.obj
ifb_projet.exe: CMakeFiles/ifb_projet.dir/Puissance_N.c.obj
ifb_projet.exe: CMakeFiles/ifb_projet.dir/build.make
ifb_projet.exe: CMakeFiles/ifb_projet.dir/linklibs.rsp
ifb_projet.exe: CMakeFiles/ifb_projet.dir/objects1.rsp
ifb_projet.exe: CMakeFiles/ifb_projet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\coco\CLionProjects\ifb_projet\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ifb_projet.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ifb_projet.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ifb_projet.dir/build: ifb_projet.exe

.PHONY : CMakeFiles/ifb_projet.dir/build

CMakeFiles/ifb_projet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ifb_projet.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ifb_projet.dir/clean

CMakeFiles/ifb_projet.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\coco\CLionProjects\ifb_projet C:\Users\coco\CLionProjects\ifb_projet C:\Users\coco\CLionProjects\ifb_projet\cmake-build-debug C:\Users\coco\CLionProjects\ifb_projet\cmake-build-debug C:\Users\coco\CLionProjects\ifb_projet\cmake-build-debug\CMakeFiles\ifb_projet.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ifb_projet.dir/depend
