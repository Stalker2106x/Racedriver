# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Projets\racedriver\old_driver\curl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Projets\racedriver\old_driver\curl

# Include any dependencies generated for this target.
include tests/libtest/CMakeFiles/lib1520.dir/depend.make

# Include the progress variables for this target.
include tests/libtest/CMakeFiles/lib1520.dir/progress.make

# Include the compile flags for this target's objects.
include tests/libtest/CMakeFiles/lib1520.dir/flags.make

tests/libtest/CMakeFiles/lib1520.dir/lib1520.c.obj: tests/libtest/CMakeFiles/lib1520.dir/flags.make
tests/libtest/CMakeFiles/lib1520.dir/lib1520.c.obj: tests/libtest/CMakeFiles/lib1520.dir/includes_C.rsp
tests/libtest/CMakeFiles/lib1520.dir/lib1520.c.obj: tests/libtest/lib1520.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/libtest/CMakeFiles/lib1520.dir/lib1520.c.obj"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\lib1520.dir\lib1520.c.obj   -c D:\Projets\racedriver\old_driver\curl\tests\libtest\lib1520.c

tests/libtest/CMakeFiles/lib1520.dir/lib1520.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib1520.dir/lib1520.c.i"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projets\racedriver\old_driver\curl\tests\libtest\lib1520.c > CMakeFiles\lib1520.dir\lib1520.c.i

tests/libtest/CMakeFiles/lib1520.dir/lib1520.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib1520.dir/lib1520.c.s"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projets\racedriver\old_driver\curl\tests\libtest\lib1520.c -o CMakeFiles\lib1520.dir\lib1520.c.s

tests/libtest/CMakeFiles/lib1520.dir/lib1520.c.obj.requires:

.PHONY : tests/libtest/CMakeFiles/lib1520.dir/lib1520.c.obj.requires

tests/libtest/CMakeFiles/lib1520.dir/lib1520.c.obj.provides: tests/libtest/CMakeFiles/lib1520.dir/lib1520.c.obj.requires
	$(MAKE) -f tests\libtest\CMakeFiles\lib1520.dir\build.make tests/libtest/CMakeFiles/lib1520.dir/lib1520.c.obj.provides.build
.PHONY : tests/libtest/CMakeFiles/lib1520.dir/lib1520.c.obj.provides

tests/libtest/CMakeFiles/lib1520.dir/lib1520.c.obj.provides.build: tests/libtest/CMakeFiles/lib1520.dir/lib1520.c.obj


tests/libtest/CMakeFiles/lib1520.dir/first.c.obj: tests/libtest/CMakeFiles/lib1520.dir/flags.make
tests/libtest/CMakeFiles/lib1520.dir/first.c.obj: tests/libtest/CMakeFiles/lib1520.dir/includes_C.rsp
tests/libtest/CMakeFiles/lib1520.dir/first.c.obj: tests/libtest/first.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/libtest/CMakeFiles/lib1520.dir/first.c.obj"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\lib1520.dir\first.c.obj   -c D:\Projets\racedriver\old_driver\curl\tests\libtest\first.c

tests/libtest/CMakeFiles/lib1520.dir/first.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib1520.dir/first.c.i"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projets\racedriver\old_driver\curl\tests\libtest\first.c > CMakeFiles\lib1520.dir\first.c.i

tests/libtest/CMakeFiles/lib1520.dir/first.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib1520.dir/first.c.s"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projets\racedriver\old_driver\curl\tests\libtest\first.c -o CMakeFiles\lib1520.dir\first.c.s

tests/libtest/CMakeFiles/lib1520.dir/first.c.obj.requires:

.PHONY : tests/libtest/CMakeFiles/lib1520.dir/first.c.obj.requires

tests/libtest/CMakeFiles/lib1520.dir/first.c.obj.provides: tests/libtest/CMakeFiles/lib1520.dir/first.c.obj.requires
	$(MAKE) -f tests\libtest\CMakeFiles\lib1520.dir\build.make tests/libtest/CMakeFiles/lib1520.dir/first.c.obj.provides.build
.PHONY : tests/libtest/CMakeFiles/lib1520.dir/first.c.obj.provides

tests/libtest/CMakeFiles/lib1520.dir/first.c.obj.provides.build: tests/libtest/CMakeFiles/lib1520.dir/first.c.obj


# Object files for target lib1520
lib1520_OBJECTS = \
"CMakeFiles/lib1520.dir/lib1520.c.obj" \
"CMakeFiles/lib1520.dir/first.c.obj"

# External object files for target lib1520
lib1520_EXTERNAL_OBJECTS =

tests/libtest/lib1520.exe: tests/libtest/CMakeFiles/lib1520.dir/lib1520.c.obj
tests/libtest/lib1520.exe: tests/libtest/CMakeFiles/lib1520.dir/first.c.obj
tests/libtest/lib1520.exe: tests/libtest/CMakeFiles/lib1520.dir/build.make
tests/libtest/lib1520.exe: lib/libcurl_imp.lib
tests/libtest/lib1520.exe: tests/libtest/CMakeFiles/lib1520.dir/linklibs.rsp
tests/libtest/lib1520.exe: tests/libtest/CMakeFiles/lib1520.dir/objects1.rsp
tests/libtest/lib1520.exe: tests/libtest/CMakeFiles/lib1520.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable lib1520.exe"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lib1520.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/libtest/CMakeFiles/lib1520.dir/build: tests/libtest/lib1520.exe

.PHONY : tests/libtest/CMakeFiles/lib1520.dir/build

tests/libtest/CMakeFiles/lib1520.dir/requires: tests/libtest/CMakeFiles/lib1520.dir/lib1520.c.obj.requires
tests/libtest/CMakeFiles/lib1520.dir/requires: tests/libtest/CMakeFiles/lib1520.dir/first.c.obj.requires

.PHONY : tests/libtest/CMakeFiles/lib1520.dir/requires

tests/libtest/CMakeFiles/lib1520.dir/clean:
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && $(CMAKE_COMMAND) -P CMakeFiles\lib1520.dir\cmake_clean.cmake
.PHONY : tests/libtest/CMakeFiles/lib1520.dir/clean

tests/libtest/CMakeFiles/lib1520.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Projets\racedriver\old_driver\curl D:\Projets\racedriver\old_driver\curl\tests\libtest D:\Projets\racedriver\old_driver\curl D:\Projets\racedriver\old_driver\curl\tests\libtest D:\Projets\racedriver\old_driver\curl\tests\libtest\CMakeFiles\lib1520.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tests/libtest/CMakeFiles/lib1520.dir/depend
