# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/fernando/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.5429.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/fernando/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.5429.37/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fernando/Documentos/DevFaculdade/AED/FindMaiorNumeroRecursivo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fernando/Documentos/DevFaculdade/AED/FindMaiorNumeroRecursivo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FindMaiorNumeroRecursivo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FindMaiorNumeroRecursivo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FindMaiorNumeroRecursivo.dir/flags.make

CMakeFiles/FindMaiorNumeroRecursivo.dir/main.c.o: CMakeFiles/FindMaiorNumeroRecursivo.dir/flags.make
CMakeFiles/FindMaiorNumeroRecursivo.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fernando/Documentos/DevFaculdade/AED/FindMaiorNumeroRecursivo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/FindMaiorNumeroRecursivo.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FindMaiorNumeroRecursivo.dir/main.c.o   -c /home/fernando/Documentos/DevFaculdade/AED/FindMaiorNumeroRecursivo/main.c

CMakeFiles/FindMaiorNumeroRecursivo.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FindMaiorNumeroRecursivo.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fernando/Documentos/DevFaculdade/AED/FindMaiorNumeroRecursivo/main.c > CMakeFiles/FindMaiorNumeroRecursivo.dir/main.c.i

CMakeFiles/FindMaiorNumeroRecursivo.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FindMaiorNumeroRecursivo.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fernando/Documentos/DevFaculdade/AED/FindMaiorNumeroRecursivo/main.c -o CMakeFiles/FindMaiorNumeroRecursivo.dir/main.c.s

# Object files for target FindMaiorNumeroRecursivo
FindMaiorNumeroRecursivo_OBJECTS = \
"CMakeFiles/FindMaiorNumeroRecursivo.dir/main.c.o"

# External object files for target FindMaiorNumeroRecursivo
FindMaiorNumeroRecursivo_EXTERNAL_OBJECTS =

FindMaiorNumeroRecursivo: CMakeFiles/FindMaiorNumeroRecursivo.dir/main.c.o
FindMaiorNumeroRecursivo: CMakeFiles/FindMaiorNumeroRecursivo.dir/build.make
FindMaiorNumeroRecursivo: CMakeFiles/FindMaiorNumeroRecursivo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fernando/Documentos/DevFaculdade/AED/FindMaiorNumeroRecursivo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable FindMaiorNumeroRecursivo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FindMaiorNumeroRecursivo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FindMaiorNumeroRecursivo.dir/build: FindMaiorNumeroRecursivo

.PHONY : CMakeFiles/FindMaiorNumeroRecursivo.dir/build

CMakeFiles/FindMaiorNumeroRecursivo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FindMaiorNumeroRecursivo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FindMaiorNumeroRecursivo.dir/clean

CMakeFiles/FindMaiorNumeroRecursivo.dir/depend:
	cd /home/fernando/Documentos/DevFaculdade/AED/FindMaiorNumeroRecursivo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fernando/Documentos/DevFaculdade/AED/FindMaiorNumeroRecursivo /home/fernando/Documentos/DevFaculdade/AED/FindMaiorNumeroRecursivo /home/fernando/Documentos/DevFaculdade/AED/FindMaiorNumeroRecursivo/cmake-build-debug /home/fernando/Documentos/DevFaculdade/AED/FindMaiorNumeroRecursivo/cmake-build-debug /home/fernando/Documentos/DevFaculdade/AED/FindMaiorNumeroRecursivo/cmake-build-debug/CMakeFiles/FindMaiorNumeroRecursivo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FindMaiorNumeroRecursivo.dir/depend

