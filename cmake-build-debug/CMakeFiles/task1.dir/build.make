# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Repositories\Shtanyuk PO\Ex03"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Repositories\Shtanyuk PO\Ex03\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\task1.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\task1.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\task1.dir\flags.make

CMakeFiles\task1.dir\src\main1.cpp.obj: CMakeFiles\task1.dir\flags.make
CMakeFiles\task1.dir\src\main1.cpp.obj: ..\src\main1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Repositories\Shtanyuk PO\Ex03\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task1.dir/src/main1.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\task1.dir\src\main1.cpp.obj /FdCMakeFiles\task1.dir\ /FS -c "C:\Repositories\Shtanyuk PO\Ex03\src\main1.cpp"
<<

CMakeFiles\task1.dir\src\main1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task1.dir/src/main1.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe > CMakeFiles\task1.dir\src\main1.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Repositories\Shtanyuk PO\Ex03\src\main1.cpp"
<<

CMakeFiles\task1.dir\src\main1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task1.dir/src/main1.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\task1.dir\src\main1.cpp.s /c "C:\Repositories\Shtanyuk PO\Ex03\src\main1.cpp"
<<

# Object files for target task1
task1_OBJECTS = \
"CMakeFiles\task1.dir\src\main1.cpp.obj"

# External object files for target task1
task1_EXTERNAL_OBJECTS =

task1.exe: CMakeFiles\task1.dir\src\main1.cpp.obj
task1.exe: CMakeFiles\task1.dir\build.make
task1.exe: task1_lib.lib
task1.exe: CMakeFiles\task1.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Repositories\Shtanyuk PO\Ex03\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task1.exe"
	"C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\task1.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\task1.dir\objects1.rsp @<<
 /out:task1.exe /implib:task1.lib /pdb:"C:\Repositories\Shtanyuk PO\Ex03\cmake-build-debug\task1.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  task1_lib.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\task1.dir\build: task1.exe

.PHONY : CMakeFiles\task1.dir\build

CMakeFiles\task1.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\task1.dir\cmake_clean.cmake
.PHONY : CMakeFiles\task1.dir\clean

CMakeFiles\task1.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Repositories\Shtanyuk PO\Ex03" "C:\Repositories\Shtanyuk PO\Ex03" "C:\Repositories\Shtanyuk PO\Ex03\cmake-build-debug" "C:\Repositories\Shtanyuk PO\Ex03\cmake-build-debug" "C:\Repositories\Shtanyuk PO\Ex03\cmake-build-debug\CMakeFiles\task1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\task1.dir\depend

