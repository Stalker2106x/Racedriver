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
include tests/libtest/CMakeFiles/libntlmconnect.dir/depend.make

# Include the progress variables for this target.
include tests/libtest/CMakeFiles/libntlmconnect.dir/progress.make

# Include the compile flags for this target's objects.
include tests/libtest/CMakeFiles/libntlmconnect.dir/flags.make

tests/libtest/CMakeFiles/libntlmconnect.dir/libntlmconnect.c.obj: tests/libtest/CMakeFiles/libntlmconnect.dir/flags.make
tests/libtest/CMakeFiles/libntlmconnect.dir/libntlmconnect.c.obj: tests/libtest/CMakeFiles/libntlmconnect.dir/includes_C.rsp
tests/libtest/CMakeFiles/libntlmconnect.dir/libntlmconnect.c.obj: tests/libtest/libntlmconnect.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/libtest/CMakeFiles/libntlmconnect.dir/libntlmconnect.c.obj"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\libntlmconnect.dir\libntlmconnect.c.obj   -c D:\Projets\racedriver\old_driver\curl\tests\libtest\libntlmconnect.c

tests/libtest/CMakeFiles/libntlmconnect.dir/libntlmconnect.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libntlmconnect.dir/libntlmconnect.c.i"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projets\racedriver\old_driver\curl\tests\libtest\libntlmconnect.c > CMakeFiles\libntlmconnect.dir\libntlmconnect.c.i

tests/libtest/CMakeFiles/libntlmconnect.dir/libntlmconnect.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libntlmconnect.dir/libntlmconnect.c.s"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projets\racedriver\old_driver\curl\tests\libtest\libntlmconnect.c -o CMakeFiles\libntlmconnect.dir\libntlmconnect.c.s

tests/libtest/CMakeFiles/libntlmconnect.dir/libntlmconnect.c.obj.requires:

.PHONY : tests/libtest/CMakeFiles/libntlmconnect.dir/libntlmconnect.c.obj.requires

tests/libtest/CMakeFiles/libntlmconnect.dir/libntlmconnect.c.obj.provides: tests/libtest/CMakeFiles/libntlmconnect.dir/libntlmconnect.c.obj.requires
	$(MAKE) -f tests\libtest\CMakeFiles\libntlmconnect.dir\build.make tests/libtest/CMakeFiles/libntlmconnect.dir/libntlmconnect.c.obj.provides.build
.PHONY : tests/libtest/CMakeFiles/libntlmconnect.dir/libntlmconnect.c.obj.provides

tests/libtest/CMakeFiles/libntlmconnect.dir/libntlmconnect.c.obj.provides.build: tests/libtest/CMakeFiles/libntlmconnect.dir/libntlmconnect.c.obj


tests/libtest/CMakeFiles/libntlmconnect.dir/first.c.obj: tests/libtest/CMakeFiles/libntlmconnect.dir/flags.make
tests/libtest/CMakeFiles/libntlmconnect.dir/first.c.obj: tests/libtest/CMakeFiles/libntlmconnect.dir/includes_C.rsp
tests/libtest/CMakeFiles/libntlmconnect.dir/first.c.obj: tests/libtest/first.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/libtest/CMakeFiles/libntlmconnect.dir/first.c.obj"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\libntlmconnect.dir\first.c.obj   -c D:\Projets\racedriver\old_driver\curl\tests\libtest\first.c

tests/libtest/CMakeFiles/libntlmconnect.dir/first.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libntlmconnect.dir/first.c.i"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projets\racedriver\old_driver\curl\tests\libtest\first.c > CMakeFiles\libntlmconnect.dir\first.c.i

tests/libtest/CMakeFiles/libntlmconnect.dir/first.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libntlmconnect.dir/first.c.s"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projets\racedriver\old_driver\curl\tests\libtest\first.c -o CMakeFiles\libntlmconnect.dir\first.c.s

tests/libtest/CMakeFiles/libntlmconnect.dir/first.c.obj.requires:

.PHONY : tests/libtest/CMakeFiles/libntlmconnect.dir/first.c.obj.requires

tests/libtest/CMakeFiles/libntlmconnect.dir/first.c.obj.provides: tests/libtest/CMakeFiles/libntlmconnect.dir/first.c.obj.requires
	$(MAKE) -f tests\libtest\CMakeFiles\libntlmconnect.dir\build.make tests/libtest/CMakeFiles/libntlmconnect.dir/first.c.obj.provides.build
.PHONY : tests/libtest/CMakeFiles/libntlmconnect.dir/first.c.obj.provides

tests/libtest/CMakeFiles/libntlmconnect.dir/first.c.obj.provides.build: tests/libtest/CMakeFiles/libntlmconnect.dir/first.c.obj


tests/libtest/CMakeFiles/libntlmconnect.dir/testutil.c.obj: tests/libtest/CMakeFiles/libntlmconnect.dir/flags.make
tests/libtest/CMakeFiles/libntlmconnect.dir/testutil.c.obj: tests/libtest/CMakeFiles/libntlmconnect.dir/includes_C.rsp
tests/libtest/CMakeFiles/libntlmconnect.dir/testutil.c.obj: tests/libtest/testutil.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/libtest/CMakeFiles/libntlmconnect.dir/testutil.c.obj"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\libntlmconnect.dir\testutil.c.obj   -c D:\Projets\racedriver\old_driver\curl\tests\libtest\testutil.c

tests/libtest/CMakeFiles/libntlmconnect.dir/testutil.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libntlmconnect.dir/testutil.c.i"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projets\racedriver\old_driver\curl\tests\libtest\testutil.c > CMakeFiles\libntlmconnect.dir\testutil.c.i

tests/libtest/CMakeFiles/libntlmconnect.dir/testutil.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libntlmconnect.dir/testutil.c.s"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projets\racedriver\old_driver\curl\tests\libtest\testutil.c -o CMakeFiles\libntlmconnect.dir\testutil.c.s

tests/libtest/CMakeFiles/libntlmconnect.dir/testutil.c.obj.requires:

.PHONY : tests/libtest/CMakeFiles/libntlmconnect.dir/testutil.c.obj.requires

tests/libtest/CMakeFiles/libntlmconnect.dir/testutil.c.obj.provides: tests/libtest/CMakeFiles/libntlmconnect.dir/testutil.c.obj.requires
	$(MAKE) -f tests\libtest\CMakeFiles\libntlmconnect.dir\build.make tests/libtest/CMakeFiles/libntlmconnect.dir/testutil.c.obj.provides.build
.PHONY : tests/libtest/CMakeFiles/libntlmconnect.dir/testutil.c.obj.provides

tests/libtest/CMakeFiles/libntlmconnect.dir/testutil.c.obj.provides.build: tests/libtest/CMakeFiles/libntlmconnect.dir/testutil.c.obj


tests/libtest/CMakeFiles/libntlmconnect.dir/__/__/lib/warnless.c.obj: tests/libtest/CMakeFiles/libntlmconnect.dir/flags.make
tests/libtest/CMakeFiles/libntlmconnect.dir/__/__/lib/warnless.c.obj: tests/libtest/CMakeFiles/libntlmconnect.dir/includes_C.rsp
tests/libtest/CMakeFiles/libntlmconnect.dir/__/__/lib/warnless.c.obj: lib/warnless.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object tests/libtest/CMakeFiles/libntlmconnect.dir/__/__/lib/warnless.c.obj"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\libntlmconnect.dir\__\__\lib\warnless.c.obj   -c D:\Projets\racedriver\old_driver\curl\lib\warnless.c

tests/libtest/CMakeFiles/libntlmconnect.dir/__/__/lib/warnless.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libntlmconnect.dir/__/__/lib/warnless.c.i"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projets\racedriver\old_driver\curl\lib\warnless.c > CMakeFiles\libntlmconnect.dir\__\__\lib\warnless.c.i

tests/libtest/CMakeFiles/libntlmconnect.dir/__/__/lib/warnless.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libntlmconnect.dir/__/__/lib/warnless.c.s"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projets\racedriver\old_driver\curl\lib\warnless.c -o CMakeFiles\libntlmconnect.dir\__\__\lib\warnless.c.s

tests/libtest/CMakeFiles/libntlmconnect.dir/__/__/lib/warnless.c.obj.requires:

.PHONY : tests/libtest/CMakeFiles/libntlmconnect.dir/__/__/lib/warnless.c.obj.requires

tests/libtest/CMakeFiles/libntlmconnect.dir/__/__/lib/warnless.c.obj.provides: tests/libtest/CMakeFiles/libntlmconnect.dir/__/__/lib/warnless.c.obj.requires
	$(MAKE) -f tests\libtest\CMakeFiles\libntlmconnect.dir\build.make tests/libtest/CMakeFiles/libntlmconnect.dir/__/__/lib/warnless.c.obj.provides.build
.PHONY : tests/libtest/CMakeFiles/libntlmconnect.dir/__/__/lib/warnless.c.obj.provides

tests/libtest/CMakeFiles/libntlmconnect.dir/__/__/lib/warnless.c.obj.provides.build: tests/libtest/CMakeFiles/libntlmconnect.dir/__/__/lib/warnless.c.obj


# Object files for target libntlmconnect
libntlmconnect_OBJECTS = \
"CMakeFiles/libntlmconnect.dir/libntlmconnect.c.obj" \
"CMakeFiles/libntlmconnect.dir/first.c.obj" \
"CMakeFiles/libntlmconnect.dir/testutil.c.obj" \
"CMakeFiles/libntlmconnect.dir/__/__/lib/warnless.c.obj"

# External object files for target libntlmconnect
libntlmconnect_EXTERNAL_OBJECTS =

tests/libtest/libntlmconnect.exe: tests/libtest/CMakeFiles/libntlmconnect.dir/libntlmconnect.c.obj
tests/libtest/libntlmconnect.exe: tests/libtest/CMakeFiles/libntlmconnect.dir/first.c.obj
tests/libtest/libntlmconnect.exe: tests/libtest/CMakeFiles/libntlmconnect.dir/testutil.c.obj
tests/libtest/libntlmconnect.exe: tests/libtest/CMakeFiles/libntlmconnect.dir/__/__/lib/warnless.c.obj
tests/libtest/libntlmconnect.exe: tests/libtest/CMakeFiles/libntlmconnect.dir/build.make
tests/libtest/libntlmconnect.exe: lib/libcurl_imp.lib
tests/libtest/libntlmconnect.exe: tests/libtest/CMakeFiles/libntlmconnect.dir/linklibs.rsp
tests/libtest/libntlmconnect.exe: tests/libtest/CMakeFiles/libntlmconnect.dir/objects1.rsp
tests/libtest/libntlmconnect.exe: tests/libtest/CMakeFiles/libntlmconnect.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable libntlmconnect.exe"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\libntlmconnect.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/libtest/CMakeFiles/libntlmconnect.dir/build: tests/libtest/libntlmconnect.exe

.PHONY : tests/libtest/CMakeFiles/libntlmconnect.dir/build

tests/libtest/CMakeFiles/libntlmconnect.dir/requires: tests/libtest/CMakeFiles/libntlmconnect.dir/libntlmconnect.c.obj.requires
tests/libtest/CMakeFiles/libntlmconnect.dir/requires: tests/libtest/CMakeFiles/libntlmconnect.dir/first.c.obj.requires
tests/libtest/CMakeFiles/libntlmconnect.dir/requires: tests/libtest/CMakeFiles/libntlmconnect.dir/testutil.c.obj.requires
tests/libtest/CMakeFiles/libntlmconnect.dir/requires: tests/libtest/CMakeFiles/libntlmconnect.dir/__/__/lib/warnless.c.obj.requires

.PHONY : tests/libtest/CMakeFiles/libntlmconnect.dir/requires

tests/libtest/CMakeFiles/libntlmconnect.dir/clean:
	cd /d D:\Projets\racedriver\old_driver\curl\tests\libtest && $(CMAKE_COMMAND) -P CMakeFiles\libntlmconnect.dir\cmake_clean.cmake
.PHONY : tests/libtest/CMakeFiles/libntlmconnect.dir/clean

tests/libtest/CMakeFiles/libntlmconnect.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Projets\racedriver\old_driver\curl D:\Projets\racedriver\old_driver\curl\tests\libtest D:\Projets\racedriver\old_driver\curl D:\Projets\racedriver\old_driver\curl\tests\libtest D:\Projets\racedriver\old_driver\curl\tests\libtest\CMakeFiles\libntlmconnect.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tests/libtest/CMakeFiles/libntlmconnect.dir/depend
