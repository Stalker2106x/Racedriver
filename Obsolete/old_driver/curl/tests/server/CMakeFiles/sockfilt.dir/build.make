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
include tests/server/CMakeFiles/sockfilt.dir/depend.make

# Include the progress variables for this target.
include tests/server/CMakeFiles/sockfilt.dir/progress.make

# Include the compile flags for this target's objects.
include tests/server/CMakeFiles/sockfilt.dir/flags.make

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/mprintf.c.obj: tests/server/CMakeFiles/sockfilt.dir/flags.make
tests/server/CMakeFiles/sockfilt.dir/__/__/lib/mprintf.c.obj: tests/server/CMakeFiles/sockfilt.dir/includes_C.rsp
tests/server/CMakeFiles/sockfilt.dir/__/__/lib/mprintf.c.obj: lib/mprintf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/server/CMakeFiles/sockfilt.dir/__/__/lib/mprintf.c.obj"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\sockfilt.dir\__\__\lib\mprintf.c.obj   -c D:\Projets\racedriver\old_driver\curl\lib\mprintf.c

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/mprintf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sockfilt.dir/__/__/lib/mprintf.c.i"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projets\racedriver\old_driver\curl\lib\mprintf.c > CMakeFiles\sockfilt.dir\__\__\lib\mprintf.c.i

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/mprintf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sockfilt.dir/__/__/lib/mprintf.c.s"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projets\racedriver\old_driver\curl\lib\mprintf.c -o CMakeFiles\sockfilt.dir\__\__\lib\mprintf.c.s

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/mprintf.c.obj.requires:

.PHONY : tests/server/CMakeFiles/sockfilt.dir/__/__/lib/mprintf.c.obj.requires

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/mprintf.c.obj.provides: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/mprintf.c.obj.requires
	$(MAKE) -f tests\server\CMakeFiles\sockfilt.dir\build.make tests/server/CMakeFiles/sockfilt.dir/__/__/lib/mprintf.c.obj.provides.build
.PHONY : tests/server/CMakeFiles/sockfilt.dir/__/__/lib/mprintf.c.obj.provides

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/mprintf.c.obj.provides.build: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/mprintf.c.obj


tests/server/CMakeFiles/sockfilt.dir/__/__/lib/nonblock.c.obj: tests/server/CMakeFiles/sockfilt.dir/flags.make
tests/server/CMakeFiles/sockfilt.dir/__/__/lib/nonblock.c.obj: tests/server/CMakeFiles/sockfilt.dir/includes_C.rsp
tests/server/CMakeFiles/sockfilt.dir/__/__/lib/nonblock.c.obj: lib/nonblock.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/server/CMakeFiles/sockfilt.dir/__/__/lib/nonblock.c.obj"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\sockfilt.dir\__\__\lib\nonblock.c.obj   -c D:\Projets\racedriver\old_driver\curl\lib\nonblock.c

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/nonblock.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sockfilt.dir/__/__/lib/nonblock.c.i"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projets\racedriver\old_driver\curl\lib\nonblock.c > CMakeFiles\sockfilt.dir\__\__\lib\nonblock.c.i

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/nonblock.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sockfilt.dir/__/__/lib/nonblock.c.s"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projets\racedriver\old_driver\curl\lib\nonblock.c -o CMakeFiles\sockfilt.dir\__\__\lib\nonblock.c.s

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/nonblock.c.obj.requires:

.PHONY : tests/server/CMakeFiles/sockfilt.dir/__/__/lib/nonblock.c.obj.requires

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/nonblock.c.obj.provides: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/nonblock.c.obj.requires
	$(MAKE) -f tests\server\CMakeFiles\sockfilt.dir\build.make tests/server/CMakeFiles/sockfilt.dir/__/__/lib/nonblock.c.obj.provides.build
.PHONY : tests/server/CMakeFiles/sockfilt.dir/__/__/lib/nonblock.c.obj.provides

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/nonblock.c.obj.provides.build: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/nonblock.c.obj


tests/server/CMakeFiles/sockfilt.dir/__/__/lib/strtoofft.c.obj: tests/server/CMakeFiles/sockfilt.dir/flags.make
tests/server/CMakeFiles/sockfilt.dir/__/__/lib/strtoofft.c.obj: tests/server/CMakeFiles/sockfilt.dir/includes_C.rsp
tests/server/CMakeFiles/sockfilt.dir/__/__/lib/strtoofft.c.obj: lib/strtoofft.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/server/CMakeFiles/sockfilt.dir/__/__/lib/strtoofft.c.obj"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\sockfilt.dir\__\__\lib\strtoofft.c.obj   -c D:\Projets\racedriver\old_driver\curl\lib\strtoofft.c

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/strtoofft.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sockfilt.dir/__/__/lib/strtoofft.c.i"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projets\racedriver\old_driver\curl\lib\strtoofft.c > CMakeFiles\sockfilt.dir\__\__\lib\strtoofft.c.i

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/strtoofft.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sockfilt.dir/__/__/lib/strtoofft.c.s"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projets\racedriver\old_driver\curl\lib\strtoofft.c -o CMakeFiles\sockfilt.dir\__\__\lib\strtoofft.c.s

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/strtoofft.c.obj.requires:

.PHONY : tests/server/CMakeFiles/sockfilt.dir/__/__/lib/strtoofft.c.obj.requires

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/strtoofft.c.obj.provides: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/strtoofft.c.obj.requires
	$(MAKE) -f tests\server\CMakeFiles\sockfilt.dir\build.make tests/server/CMakeFiles/sockfilt.dir/__/__/lib/strtoofft.c.obj.provides.build
.PHONY : tests/server/CMakeFiles/sockfilt.dir/__/__/lib/strtoofft.c.obj.provides

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/strtoofft.c.obj.provides.build: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/strtoofft.c.obj


tests/server/CMakeFiles/sockfilt.dir/__/__/lib/timeval.c.obj: tests/server/CMakeFiles/sockfilt.dir/flags.make
tests/server/CMakeFiles/sockfilt.dir/__/__/lib/timeval.c.obj: tests/server/CMakeFiles/sockfilt.dir/includes_C.rsp
tests/server/CMakeFiles/sockfilt.dir/__/__/lib/timeval.c.obj: lib/timeval.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object tests/server/CMakeFiles/sockfilt.dir/__/__/lib/timeval.c.obj"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\sockfilt.dir\__\__\lib\timeval.c.obj   -c D:\Projets\racedriver\old_driver\curl\lib\timeval.c

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/timeval.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sockfilt.dir/__/__/lib/timeval.c.i"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projets\racedriver\old_driver\curl\lib\timeval.c > CMakeFiles\sockfilt.dir\__\__\lib\timeval.c.i

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/timeval.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sockfilt.dir/__/__/lib/timeval.c.s"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projets\racedriver\old_driver\curl\lib\timeval.c -o CMakeFiles\sockfilt.dir\__\__\lib\timeval.c.s

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/timeval.c.obj.requires:

.PHONY : tests/server/CMakeFiles/sockfilt.dir/__/__/lib/timeval.c.obj.requires

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/timeval.c.obj.provides: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/timeval.c.obj.requires
	$(MAKE) -f tests\server\CMakeFiles\sockfilt.dir\build.make tests/server/CMakeFiles/sockfilt.dir/__/__/lib/timeval.c.obj.provides.build
.PHONY : tests/server/CMakeFiles/sockfilt.dir/__/__/lib/timeval.c.obj.provides

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/timeval.c.obj.provides.build: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/timeval.c.obj


tests/server/CMakeFiles/sockfilt.dir/__/__/lib/warnless.c.obj: tests/server/CMakeFiles/sockfilt.dir/flags.make
tests/server/CMakeFiles/sockfilt.dir/__/__/lib/warnless.c.obj: tests/server/CMakeFiles/sockfilt.dir/includes_C.rsp
tests/server/CMakeFiles/sockfilt.dir/__/__/lib/warnless.c.obj: lib/warnless.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object tests/server/CMakeFiles/sockfilt.dir/__/__/lib/warnless.c.obj"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\sockfilt.dir\__\__\lib\warnless.c.obj   -c D:\Projets\racedriver\old_driver\curl\lib\warnless.c

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/warnless.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sockfilt.dir/__/__/lib/warnless.c.i"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projets\racedriver\old_driver\curl\lib\warnless.c > CMakeFiles\sockfilt.dir\__\__\lib\warnless.c.i

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/warnless.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sockfilt.dir/__/__/lib/warnless.c.s"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projets\racedriver\old_driver\curl\lib\warnless.c -o CMakeFiles\sockfilt.dir\__\__\lib\warnless.c.s

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/warnless.c.obj.requires:

.PHONY : tests/server/CMakeFiles/sockfilt.dir/__/__/lib/warnless.c.obj.requires

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/warnless.c.obj.provides: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/warnless.c.obj.requires
	$(MAKE) -f tests\server\CMakeFiles\sockfilt.dir\build.make tests/server/CMakeFiles/sockfilt.dir/__/__/lib/warnless.c.obj.provides.build
.PHONY : tests/server/CMakeFiles/sockfilt.dir/__/__/lib/warnless.c.obj.provides

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/warnless.c.obj.provides.build: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/warnless.c.obj


tests/server/CMakeFiles/sockfilt.dir/getpart.c.obj: tests/server/CMakeFiles/sockfilt.dir/flags.make
tests/server/CMakeFiles/sockfilt.dir/getpart.c.obj: tests/server/CMakeFiles/sockfilt.dir/includes_C.rsp
tests/server/CMakeFiles/sockfilt.dir/getpart.c.obj: tests/server/getpart.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object tests/server/CMakeFiles/sockfilt.dir/getpart.c.obj"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\sockfilt.dir\getpart.c.obj   -c D:\Projets\racedriver\old_driver\curl\tests\server\getpart.c

tests/server/CMakeFiles/sockfilt.dir/getpart.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sockfilt.dir/getpart.c.i"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projets\racedriver\old_driver\curl\tests\server\getpart.c > CMakeFiles\sockfilt.dir\getpart.c.i

tests/server/CMakeFiles/sockfilt.dir/getpart.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sockfilt.dir/getpart.c.s"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projets\racedriver\old_driver\curl\tests\server\getpart.c -o CMakeFiles\sockfilt.dir\getpart.c.s

tests/server/CMakeFiles/sockfilt.dir/getpart.c.obj.requires:

.PHONY : tests/server/CMakeFiles/sockfilt.dir/getpart.c.obj.requires

tests/server/CMakeFiles/sockfilt.dir/getpart.c.obj.provides: tests/server/CMakeFiles/sockfilt.dir/getpart.c.obj.requires
	$(MAKE) -f tests\server\CMakeFiles\sockfilt.dir\build.make tests/server/CMakeFiles/sockfilt.dir/getpart.c.obj.provides.build
.PHONY : tests/server/CMakeFiles/sockfilt.dir/getpart.c.obj.provides

tests/server/CMakeFiles/sockfilt.dir/getpart.c.obj.provides.build: tests/server/CMakeFiles/sockfilt.dir/getpart.c.obj


tests/server/CMakeFiles/sockfilt.dir/__/__/lib/base64.c.obj: tests/server/CMakeFiles/sockfilt.dir/flags.make
tests/server/CMakeFiles/sockfilt.dir/__/__/lib/base64.c.obj: tests/server/CMakeFiles/sockfilt.dir/includes_C.rsp
tests/server/CMakeFiles/sockfilt.dir/__/__/lib/base64.c.obj: lib/base64.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object tests/server/CMakeFiles/sockfilt.dir/__/__/lib/base64.c.obj"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\sockfilt.dir\__\__\lib\base64.c.obj   -c D:\Projets\racedriver\old_driver\curl\lib\base64.c

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/base64.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sockfilt.dir/__/__/lib/base64.c.i"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projets\racedriver\old_driver\curl\lib\base64.c > CMakeFiles\sockfilt.dir\__\__\lib\base64.c.i

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/base64.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sockfilt.dir/__/__/lib/base64.c.s"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projets\racedriver\old_driver\curl\lib\base64.c -o CMakeFiles\sockfilt.dir\__\__\lib\base64.c.s

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/base64.c.obj.requires:

.PHONY : tests/server/CMakeFiles/sockfilt.dir/__/__/lib/base64.c.obj.requires

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/base64.c.obj.provides: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/base64.c.obj.requires
	$(MAKE) -f tests\server\CMakeFiles\sockfilt.dir\build.make tests/server/CMakeFiles/sockfilt.dir/__/__/lib/base64.c.obj.provides.build
.PHONY : tests/server/CMakeFiles/sockfilt.dir/__/__/lib/base64.c.obj.provides

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/base64.c.obj.provides.build: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/base64.c.obj


tests/server/CMakeFiles/sockfilt.dir/__/__/lib/memdebug.c.obj: tests/server/CMakeFiles/sockfilt.dir/flags.make
tests/server/CMakeFiles/sockfilt.dir/__/__/lib/memdebug.c.obj: tests/server/CMakeFiles/sockfilt.dir/includes_C.rsp
tests/server/CMakeFiles/sockfilt.dir/__/__/lib/memdebug.c.obj: lib/memdebug.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object tests/server/CMakeFiles/sockfilt.dir/__/__/lib/memdebug.c.obj"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\sockfilt.dir\__\__\lib\memdebug.c.obj   -c D:\Projets\racedriver\old_driver\curl\lib\memdebug.c

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/memdebug.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sockfilt.dir/__/__/lib/memdebug.c.i"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projets\racedriver\old_driver\curl\lib\memdebug.c > CMakeFiles\sockfilt.dir\__\__\lib\memdebug.c.i

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/memdebug.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sockfilt.dir/__/__/lib/memdebug.c.s"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projets\racedriver\old_driver\curl\lib\memdebug.c -o CMakeFiles\sockfilt.dir\__\__\lib\memdebug.c.s

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/memdebug.c.obj.requires:

.PHONY : tests/server/CMakeFiles/sockfilt.dir/__/__/lib/memdebug.c.obj.requires

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/memdebug.c.obj.provides: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/memdebug.c.obj.requires
	$(MAKE) -f tests\server\CMakeFiles\sockfilt.dir\build.make tests/server/CMakeFiles/sockfilt.dir/__/__/lib/memdebug.c.obj.provides.build
.PHONY : tests/server/CMakeFiles/sockfilt.dir/__/__/lib/memdebug.c.obj.provides

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/memdebug.c.obj.provides.build: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/memdebug.c.obj


tests/server/CMakeFiles/sockfilt.dir/util.c.obj: tests/server/CMakeFiles/sockfilt.dir/flags.make
tests/server/CMakeFiles/sockfilt.dir/util.c.obj: tests/server/CMakeFiles/sockfilt.dir/includes_C.rsp
tests/server/CMakeFiles/sockfilt.dir/util.c.obj: tests/server/util.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object tests/server/CMakeFiles/sockfilt.dir/util.c.obj"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\sockfilt.dir\util.c.obj   -c D:\Projets\racedriver\old_driver\curl\tests\server\util.c

tests/server/CMakeFiles/sockfilt.dir/util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sockfilt.dir/util.c.i"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projets\racedriver\old_driver\curl\tests\server\util.c > CMakeFiles\sockfilt.dir\util.c.i

tests/server/CMakeFiles/sockfilt.dir/util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sockfilt.dir/util.c.s"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projets\racedriver\old_driver\curl\tests\server\util.c -o CMakeFiles\sockfilt.dir\util.c.s

tests/server/CMakeFiles/sockfilt.dir/util.c.obj.requires:

.PHONY : tests/server/CMakeFiles/sockfilt.dir/util.c.obj.requires

tests/server/CMakeFiles/sockfilt.dir/util.c.obj.provides: tests/server/CMakeFiles/sockfilt.dir/util.c.obj.requires
	$(MAKE) -f tests\server\CMakeFiles\sockfilt.dir\build.make tests/server/CMakeFiles/sockfilt.dir/util.c.obj.provides.build
.PHONY : tests/server/CMakeFiles/sockfilt.dir/util.c.obj.provides

tests/server/CMakeFiles/sockfilt.dir/util.c.obj.provides.build: tests/server/CMakeFiles/sockfilt.dir/util.c.obj


tests/server/CMakeFiles/sockfilt.dir/sockfilt.c.obj: tests/server/CMakeFiles/sockfilt.dir/flags.make
tests/server/CMakeFiles/sockfilt.dir/sockfilt.c.obj: tests/server/CMakeFiles/sockfilt.dir/includes_C.rsp
tests/server/CMakeFiles/sockfilt.dir/sockfilt.c.obj: tests/server/sockfilt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object tests/server/CMakeFiles/sockfilt.dir/sockfilt.c.obj"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\sockfilt.dir\sockfilt.c.obj   -c D:\Projets\racedriver\old_driver\curl\tests\server\sockfilt.c

tests/server/CMakeFiles/sockfilt.dir/sockfilt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sockfilt.dir/sockfilt.c.i"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projets\racedriver\old_driver\curl\tests\server\sockfilt.c > CMakeFiles\sockfilt.dir\sockfilt.c.i

tests/server/CMakeFiles/sockfilt.dir/sockfilt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sockfilt.dir/sockfilt.c.s"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projets\racedriver\old_driver\curl\tests\server\sockfilt.c -o CMakeFiles\sockfilt.dir\sockfilt.c.s

tests/server/CMakeFiles/sockfilt.dir/sockfilt.c.obj.requires:

.PHONY : tests/server/CMakeFiles/sockfilt.dir/sockfilt.c.obj.requires

tests/server/CMakeFiles/sockfilt.dir/sockfilt.c.obj.provides: tests/server/CMakeFiles/sockfilt.dir/sockfilt.c.obj.requires
	$(MAKE) -f tests\server\CMakeFiles\sockfilt.dir\build.make tests/server/CMakeFiles/sockfilt.dir/sockfilt.c.obj.provides.build
.PHONY : tests/server/CMakeFiles/sockfilt.dir/sockfilt.c.obj.provides

tests/server/CMakeFiles/sockfilt.dir/sockfilt.c.obj.provides.build: tests/server/CMakeFiles/sockfilt.dir/sockfilt.c.obj


tests/server/CMakeFiles/sockfilt.dir/__/__/lib/inet_pton.c.obj: tests/server/CMakeFiles/sockfilt.dir/flags.make
tests/server/CMakeFiles/sockfilt.dir/__/__/lib/inet_pton.c.obj: tests/server/CMakeFiles/sockfilt.dir/includes_C.rsp
tests/server/CMakeFiles/sockfilt.dir/__/__/lib/inet_pton.c.obj: lib/inet_pton.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object tests/server/CMakeFiles/sockfilt.dir/__/__/lib/inet_pton.c.obj"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\sockfilt.dir\__\__\lib\inet_pton.c.obj   -c D:\Projets\racedriver\old_driver\curl\lib\inet_pton.c

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/inet_pton.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sockfilt.dir/__/__/lib/inet_pton.c.i"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projets\racedriver\old_driver\curl\lib\inet_pton.c > CMakeFiles\sockfilt.dir\__\__\lib\inet_pton.c.i

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/inet_pton.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sockfilt.dir/__/__/lib/inet_pton.c.s"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && D:\mingw-w64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projets\racedriver\old_driver\curl\lib\inet_pton.c -o CMakeFiles\sockfilt.dir\__\__\lib\inet_pton.c.s

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/inet_pton.c.obj.requires:

.PHONY : tests/server/CMakeFiles/sockfilt.dir/__/__/lib/inet_pton.c.obj.requires

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/inet_pton.c.obj.provides: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/inet_pton.c.obj.requires
	$(MAKE) -f tests\server\CMakeFiles\sockfilt.dir\build.make tests/server/CMakeFiles/sockfilt.dir/__/__/lib/inet_pton.c.obj.provides.build
.PHONY : tests/server/CMakeFiles/sockfilt.dir/__/__/lib/inet_pton.c.obj.provides

tests/server/CMakeFiles/sockfilt.dir/__/__/lib/inet_pton.c.obj.provides.build: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/inet_pton.c.obj


# Object files for target sockfilt
sockfilt_OBJECTS = \
"CMakeFiles/sockfilt.dir/__/__/lib/mprintf.c.obj" \
"CMakeFiles/sockfilt.dir/__/__/lib/nonblock.c.obj" \
"CMakeFiles/sockfilt.dir/__/__/lib/strtoofft.c.obj" \
"CMakeFiles/sockfilt.dir/__/__/lib/timeval.c.obj" \
"CMakeFiles/sockfilt.dir/__/__/lib/warnless.c.obj" \
"CMakeFiles/sockfilt.dir/getpart.c.obj" \
"CMakeFiles/sockfilt.dir/__/__/lib/base64.c.obj" \
"CMakeFiles/sockfilt.dir/__/__/lib/memdebug.c.obj" \
"CMakeFiles/sockfilt.dir/util.c.obj" \
"CMakeFiles/sockfilt.dir/sockfilt.c.obj" \
"CMakeFiles/sockfilt.dir/__/__/lib/inet_pton.c.obj"

# External object files for target sockfilt
sockfilt_EXTERNAL_OBJECTS =

tests/server/sockfilt.exe: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/mprintf.c.obj
tests/server/sockfilt.exe: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/nonblock.c.obj
tests/server/sockfilt.exe: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/strtoofft.c.obj
tests/server/sockfilt.exe: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/timeval.c.obj
tests/server/sockfilt.exe: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/warnless.c.obj
tests/server/sockfilt.exe: tests/server/CMakeFiles/sockfilt.dir/getpart.c.obj
tests/server/sockfilt.exe: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/base64.c.obj
tests/server/sockfilt.exe: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/memdebug.c.obj
tests/server/sockfilt.exe: tests/server/CMakeFiles/sockfilt.dir/util.c.obj
tests/server/sockfilt.exe: tests/server/CMakeFiles/sockfilt.dir/sockfilt.c.obj
tests/server/sockfilt.exe: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/inet_pton.c.obj
tests/server/sockfilt.exe: tests/server/CMakeFiles/sockfilt.dir/build.make
tests/server/sockfilt.exe: tests/server/CMakeFiles/sockfilt.dir/linklibs.rsp
tests/server/sockfilt.exe: tests/server/CMakeFiles/sockfilt.dir/objects1.rsp
tests/server/sockfilt.exe: tests/server/CMakeFiles/sockfilt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Projets\racedriver\old_driver\curl\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking C executable sockfilt.exe"
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sockfilt.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/server/CMakeFiles/sockfilt.dir/build: tests/server/sockfilt.exe

.PHONY : tests/server/CMakeFiles/sockfilt.dir/build

tests/server/CMakeFiles/sockfilt.dir/requires: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/mprintf.c.obj.requires
tests/server/CMakeFiles/sockfilt.dir/requires: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/nonblock.c.obj.requires
tests/server/CMakeFiles/sockfilt.dir/requires: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/strtoofft.c.obj.requires
tests/server/CMakeFiles/sockfilt.dir/requires: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/timeval.c.obj.requires
tests/server/CMakeFiles/sockfilt.dir/requires: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/warnless.c.obj.requires
tests/server/CMakeFiles/sockfilt.dir/requires: tests/server/CMakeFiles/sockfilt.dir/getpart.c.obj.requires
tests/server/CMakeFiles/sockfilt.dir/requires: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/base64.c.obj.requires
tests/server/CMakeFiles/sockfilt.dir/requires: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/memdebug.c.obj.requires
tests/server/CMakeFiles/sockfilt.dir/requires: tests/server/CMakeFiles/sockfilt.dir/util.c.obj.requires
tests/server/CMakeFiles/sockfilt.dir/requires: tests/server/CMakeFiles/sockfilt.dir/sockfilt.c.obj.requires
tests/server/CMakeFiles/sockfilt.dir/requires: tests/server/CMakeFiles/sockfilt.dir/__/__/lib/inet_pton.c.obj.requires

.PHONY : tests/server/CMakeFiles/sockfilt.dir/requires

tests/server/CMakeFiles/sockfilt.dir/clean:
	cd /d D:\Projets\racedriver\old_driver\curl\tests\server && $(CMAKE_COMMAND) -P CMakeFiles\sockfilt.dir\cmake_clean.cmake
.PHONY : tests/server/CMakeFiles/sockfilt.dir/clean

tests/server/CMakeFiles/sockfilt.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Projets\racedriver\old_driver\curl D:\Projets\racedriver\old_driver\curl\tests\server D:\Projets\racedriver\old_driver\curl D:\Projets\racedriver\old_driver\curl\tests\server D:\Projets\racedriver\old_driver\curl\tests\server\CMakeFiles\sockfilt.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tests/server/CMakeFiles/sockfilt.dir/depend
