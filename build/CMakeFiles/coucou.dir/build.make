# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/riwan/1-OpenGL/OpenGlStart/coucou

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/riwan/1-OpenGL/OpenGlStart/coucou/build

# Include any dependencies generated for this target.
include CMakeFiles/coucou.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/coucou.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/coucou.dir/flags.make

CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.o: CMakeFiles/coucou.dir/flags.make
CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.o: ../Game/Loader/objloader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Loader/objloader.cpp

CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Loader/objloader.cpp > CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.i

CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Loader/objloader.cpp -o CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.s

CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.o.requires:

.PHONY : CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.o.requires

CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.o.provides: CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucou.dir/build.make CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.o.provides.build
.PHONY : CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.o.provides

CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.o.provides.build: CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.o


CMakeFiles/coucou.dir/Game/source/camera.cpp.o: CMakeFiles/coucou.dir/flags.make
CMakeFiles/coucou.dir/Game/source/camera.cpp.o: ../Game/source/camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/coucou.dir/Game/source/camera.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucou.dir/Game/source/camera.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/camera.cpp

CMakeFiles/coucou.dir/Game/source/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucou.dir/Game/source/camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/camera.cpp > CMakeFiles/coucou.dir/Game/source/camera.cpp.i

CMakeFiles/coucou.dir/Game/source/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucou.dir/Game/source/camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/camera.cpp -o CMakeFiles/coucou.dir/Game/source/camera.cpp.s

CMakeFiles/coucou.dir/Game/source/camera.cpp.o.requires:

.PHONY : CMakeFiles/coucou.dir/Game/source/camera.cpp.o.requires

CMakeFiles/coucou.dir/Game/source/camera.cpp.o.provides: CMakeFiles/coucou.dir/Game/source/camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucou.dir/build.make CMakeFiles/coucou.dir/Game/source/camera.cpp.o.provides.build
.PHONY : CMakeFiles/coucou.dir/Game/source/camera.cpp.o.provides

CMakeFiles/coucou.dir/Game/source/camera.cpp.o.provides.build: CMakeFiles/coucou.dir/Game/source/camera.cpp.o


CMakeFiles/coucou.dir/Game/source/light.cpp.o: CMakeFiles/coucou.dir/flags.make
CMakeFiles/coucou.dir/Game/source/light.cpp.o: ../Game/source/light.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/coucou.dir/Game/source/light.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucou.dir/Game/source/light.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/light.cpp

CMakeFiles/coucou.dir/Game/source/light.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucou.dir/Game/source/light.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/light.cpp > CMakeFiles/coucou.dir/Game/source/light.cpp.i

CMakeFiles/coucou.dir/Game/source/light.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucou.dir/Game/source/light.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/light.cpp -o CMakeFiles/coucou.dir/Game/source/light.cpp.s

CMakeFiles/coucou.dir/Game/source/light.cpp.o.requires:

.PHONY : CMakeFiles/coucou.dir/Game/source/light.cpp.o.requires

CMakeFiles/coucou.dir/Game/source/light.cpp.o.provides: CMakeFiles/coucou.dir/Game/source/light.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucou.dir/build.make CMakeFiles/coucou.dir/Game/source/light.cpp.o.provides.build
.PHONY : CMakeFiles/coucou.dir/Game/source/light.cpp.o.provides

CMakeFiles/coucou.dir/Game/source/light.cpp.o.provides.build: CMakeFiles/coucou.dir/Game/source/light.cpp.o


CMakeFiles/coucou.dir/Game/source/main.cpp.o: CMakeFiles/coucou.dir/flags.make
CMakeFiles/coucou.dir/Game/source/main.cpp.o: ../Game/source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/coucou.dir/Game/source/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucou.dir/Game/source/main.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/main.cpp

CMakeFiles/coucou.dir/Game/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucou.dir/Game/source/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/main.cpp > CMakeFiles/coucou.dir/Game/source/main.cpp.i

CMakeFiles/coucou.dir/Game/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucou.dir/Game/source/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/main.cpp -o CMakeFiles/coucou.dir/Game/source/main.cpp.s

CMakeFiles/coucou.dir/Game/source/main.cpp.o.requires:

.PHONY : CMakeFiles/coucou.dir/Game/source/main.cpp.o.requires

CMakeFiles/coucou.dir/Game/source/main.cpp.o.provides: CMakeFiles/coucou.dir/Game/source/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucou.dir/build.make CMakeFiles/coucou.dir/Game/source/main.cpp.o.provides.build
.PHONY : CMakeFiles/coucou.dir/Game/source/main.cpp.o.provides

CMakeFiles/coucou.dir/Game/source/main.cpp.o.provides.build: CMakeFiles/coucou.dir/Game/source/main.cpp.o


CMakeFiles/coucou.dir/Game/source/map.cpp.o: CMakeFiles/coucou.dir/flags.make
CMakeFiles/coucou.dir/Game/source/map.cpp.o: ../Game/source/map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/coucou.dir/Game/source/map.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucou.dir/Game/source/map.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/map.cpp

CMakeFiles/coucou.dir/Game/source/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucou.dir/Game/source/map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/map.cpp > CMakeFiles/coucou.dir/Game/source/map.cpp.i

CMakeFiles/coucou.dir/Game/source/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucou.dir/Game/source/map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/map.cpp -o CMakeFiles/coucou.dir/Game/source/map.cpp.s

CMakeFiles/coucou.dir/Game/source/map.cpp.o.requires:

.PHONY : CMakeFiles/coucou.dir/Game/source/map.cpp.o.requires

CMakeFiles/coucou.dir/Game/source/map.cpp.o.provides: CMakeFiles/coucou.dir/Game/source/map.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucou.dir/build.make CMakeFiles/coucou.dir/Game/source/map.cpp.o.provides.build
.PHONY : CMakeFiles/coucou.dir/Game/source/map.cpp.o.provides

CMakeFiles/coucou.dir/Game/source/map.cpp.o.provides.build: CMakeFiles/coucou.dir/Game/source/map.cpp.o


CMakeFiles/coucou.dir/Game/source/model.cpp.o: CMakeFiles/coucou.dir/flags.make
CMakeFiles/coucou.dir/Game/source/model.cpp.o: ../Game/source/model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/coucou.dir/Game/source/model.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucou.dir/Game/source/model.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/model.cpp

CMakeFiles/coucou.dir/Game/source/model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucou.dir/Game/source/model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/model.cpp > CMakeFiles/coucou.dir/Game/source/model.cpp.i

CMakeFiles/coucou.dir/Game/source/model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucou.dir/Game/source/model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/model.cpp -o CMakeFiles/coucou.dir/Game/source/model.cpp.s

CMakeFiles/coucou.dir/Game/source/model.cpp.o.requires:

.PHONY : CMakeFiles/coucou.dir/Game/source/model.cpp.o.requires

CMakeFiles/coucou.dir/Game/source/model.cpp.o.provides: CMakeFiles/coucou.dir/Game/source/model.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucou.dir/build.make CMakeFiles/coucou.dir/Game/source/model.cpp.o.provides.build
.PHONY : CMakeFiles/coucou.dir/Game/source/model.cpp.o.provides

CMakeFiles/coucou.dir/Game/source/model.cpp.o.provides.build: CMakeFiles/coucou.dir/Game/source/model.cpp.o


CMakeFiles/coucou.dir/Game/source/myevent.cpp.o: CMakeFiles/coucou.dir/flags.make
CMakeFiles/coucou.dir/Game/source/myevent.cpp.o: ../Game/source/myevent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/coucou.dir/Game/source/myevent.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucou.dir/Game/source/myevent.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/myevent.cpp

CMakeFiles/coucou.dir/Game/source/myevent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucou.dir/Game/source/myevent.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/myevent.cpp > CMakeFiles/coucou.dir/Game/source/myevent.cpp.i

CMakeFiles/coucou.dir/Game/source/myevent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucou.dir/Game/source/myevent.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/myevent.cpp -o CMakeFiles/coucou.dir/Game/source/myevent.cpp.s

CMakeFiles/coucou.dir/Game/source/myevent.cpp.o.requires:

.PHONY : CMakeFiles/coucou.dir/Game/source/myevent.cpp.o.requires

CMakeFiles/coucou.dir/Game/source/myevent.cpp.o.provides: CMakeFiles/coucou.dir/Game/source/myevent.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucou.dir/build.make CMakeFiles/coucou.dir/Game/source/myevent.cpp.o.provides.build
.PHONY : CMakeFiles/coucou.dir/Game/source/myevent.cpp.o.provides

CMakeFiles/coucou.dir/Game/source/myevent.cpp.o.provides.build: CMakeFiles/coucou.dir/Game/source/myevent.cpp.o


CMakeFiles/coucou.dir/Game/source/shader.cpp.o: CMakeFiles/coucou.dir/flags.make
CMakeFiles/coucou.dir/Game/source/shader.cpp.o: ../Game/source/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/coucou.dir/Game/source/shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucou.dir/Game/source/shader.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/shader.cpp

CMakeFiles/coucou.dir/Game/source/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucou.dir/Game/source/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/shader.cpp > CMakeFiles/coucou.dir/Game/source/shader.cpp.i

CMakeFiles/coucou.dir/Game/source/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucou.dir/Game/source/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/shader.cpp -o CMakeFiles/coucou.dir/Game/source/shader.cpp.s

CMakeFiles/coucou.dir/Game/source/shader.cpp.o.requires:

.PHONY : CMakeFiles/coucou.dir/Game/source/shader.cpp.o.requires

CMakeFiles/coucou.dir/Game/source/shader.cpp.o.provides: CMakeFiles/coucou.dir/Game/source/shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucou.dir/build.make CMakeFiles/coucou.dir/Game/source/shader.cpp.o.provides.build
.PHONY : CMakeFiles/coucou.dir/Game/source/shader.cpp.o.provides

CMakeFiles/coucou.dir/Game/source/shader.cpp.o.provides.build: CMakeFiles/coucou.dir/Game/source/shader.cpp.o


CMakeFiles/coucou.dir/Game/source/terrain.cpp.o: CMakeFiles/coucou.dir/flags.make
CMakeFiles/coucou.dir/Game/source/terrain.cpp.o: ../Game/source/terrain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/coucou.dir/Game/source/terrain.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucou.dir/Game/source/terrain.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/terrain.cpp

CMakeFiles/coucou.dir/Game/source/terrain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucou.dir/Game/source/terrain.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/terrain.cpp > CMakeFiles/coucou.dir/Game/source/terrain.cpp.i

CMakeFiles/coucou.dir/Game/source/terrain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucou.dir/Game/source/terrain.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/terrain.cpp -o CMakeFiles/coucou.dir/Game/source/terrain.cpp.s

CMakeFiles/coucou.dir/Game/source/terrain.cpp.o.requires:

.PHONY : CMakeFiles/coucou.dir/Game/source/terrain.cpp.o.requires

CMakeFiles/coucou.dir/Game/source/terrain.cpp.o.provides: CMakeFiles/coucou.dir/Game/source/terrain.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucou.dir/build.make CMakeFiles/coucou.dir/Game/source/terrain.cpp.o.provides.build
.PHONY : CMakeFiles/coucou.dir/Game/source/terrain.cpp.o.provides

CMakeFiles/coucou.dir/Game/source/terrain.cpp.o.provides.build: CMakeFiles/coucou.dir/Game/source/terrain.cpp.o


CMakeFiles/coucou.dir/Game/source/util.cpp.o: CMakeFiles/coucou.dir/flags.make
CMakeFiles/coucou.dir/Game/source/util.cpp.o: ../Game/source/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/coucou.dir/Game/source/util.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucou.dir/Game/source/util.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/util.cpp

CMakeFiles/coucou.dir/Game/source/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucou.dir/Game/source/util.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/util.cpp > CMakeFiles/coucou.dir/Game/source/util.cpp.i

CMakeFiles/coucou.dir/Game/source/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucou.dir/Game/source/util.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/util.cpp -o CMakeFiles/coucou.dir/Game/source/util.cpp.s

CMakeFiles/coucou.dir/Game/source/util.cpp.o.requires:

.PHONY : CMakeFiles/coucou.dir/Game/source/util.cpp.o.requires

CMakeFiles/coucou.dir/Game/source/util.cpp.o.provides: CMakeFiles/coucou.dir/Game/source/util.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucou.dir/build.make CMakeFiles/coucou.dir/Game/source/util.cpp.o.provides.build
.PHONY : CMakeFiles/coucou.dir/Game/source/util.cpp.o.provides

CMakeFiles/coucou.dir/Game/source/util.cpp.o.provides.build: CMakeFiles/coucou.dir/Game/source/util.cpp.o


CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.o: CMakeFiles/coucou.dir/flags.make
CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.o: ../Game/source/vaoobject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/vaoobject.cpp

CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/vaoobject.cpp > CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.i

CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/vaoobject.cpp -o CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.s

CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.o.requires:

.PHONY : CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.o.requires

CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.o.provides: CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucou.dir/build.make CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.o.provides.build
.PHONY : CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.o.provides

CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.o.provides.build: CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.o


CMakeFiles/coucou.dir/Game/source/water.cpp.o: CMakeFiles/coucou.dir/flags.make
CMakeFiles/coucou.dir/Game/source/water.cpp.o: ../Game/source/water.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/coucou.dir/Game/source/water.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucou.dir/Game/source/water.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/water.cpp

CMakeFiles/coucou.dir/Game/source/water.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucou.dir/Game/source/water.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/water.cpp > CMakeFiles/coucou.dir/Game/source/water.cpp.i

CMakeFiles/coucou.dir/Game/source/water.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucou.dir/Game/source/water.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/water.cpp -o CMakeFiles/coucou.dir/Game/source/water.cpp.s

CMakeFiles/coucou.dir/Game/source/water.cpp.o.requires:

.PHONY : CMakeFiles/coucou.dir/Game/source/water.cpp.o.requires

CMakeFiles/coucou.dir/Game/source/water.cpp.o.provides: CMakeFiles/coucou.dir/Game/source/water.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucou.dir/build.make CMakeFiles/coucou.dir/Game/source/water.cpp.o.provides.build
.PHONY : CMakeFiles/coucou.dir/Game/source/water.cpp.o.provides

CMakeFiles/coucou.dir/Game/source/water.cpp.o.provides.build: CMakeFiles/coucou.dir/Game/source/water.cpp.o


# Object files for target coucou
coucou_OBJECTS = \
"CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.o" \
"CMakeFiles/coucou.dir/Game/source/camera.cpp.o" \
"CMakeFiles/coucou.dir/Game/source/light.cpp.o" \
"CMakeFiles/coucou.dir/Game/source/main.cpp.o" \
"CMakeFiles/coucou.dir/Game/source/map.cpp.o" \
"CMakeFiles/coucou.dir/Game/source/model.cpp.o" \
"CMakeFiles/coucou.dir/Game/source/myevent.cpp.o" \
"CMakeFiles/coucou.dir/Game/source/shader.cpp.o" \
"CMakeFiles/coucou.dir/Game/source/terrain.cpp.o" \
"CMakeFiles/coucou.dir/Game/source/util.cpp.o" \
"CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.o" \
"CMakeFiles/coucou.dir/Game/source/water.cpp.o"

# External object files for target coucou
coucou_EXTERNAL_OBJECTS =

coucou: CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.o
coucou: CMakeFiles/coucou.dir/Game/source/camera.cpp.o
coucou: CMakeFiles/coucou.dir/Game/source/light.cpp.o
coucou: CMakeFiles/coucou.dir/Game/source/main.cpp.o
coucou: CMakeFiles/coucou.dir/Game/source/map.cpp.o
coucou: CMakeFiles/coucou.dir/Game/source/model.cpp.o
coucou: CMakeFiles/coucou.dir/Game/source/myevent.cpp.o
coucou: CMakeFiles/coucou.dir/Game/source/shader.cpp.o
coucou: CMakeFiles/coucou.dir/Game/source/terrain.cpp.o
coucou: CMakeFiles/coucou.dir/Game/source/util.cpp.o
coucou: CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.o
coucou: CMakeFiles/coucou.dir/Game/source/water.cpp.o
coucou: CMakeFiles/coucou.dir/build.make
coucou: /usr/lib/x86_64-linux-gnu/libGL.so
coucou: /usr/lib/x86_64-linux-gnu/libGLU.so
coucou: /usr/lib/x86_64-linux-gnu/libGLEW.so
coucou: CMakeFiles/coucou.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable coucou"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/coucou.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/coucou.dir/build: coucou

.PHONY : CMakeFiles/coucou.dir/build

CMakeFiles/coucou.dir/requires: CMakeFiles/coucou.dir/Game/Loader/objloader.cpp.o.requires
CMakeFiles/coucou.dir/requires: CMakeFiles/coucou.dir/Game/source/camera.cpp.o.requires
CMakeFiles/coucou.dir/requires: CMakeFiles/coucou.dir/Game/source/light.cpp.o.requires
CMakeFiles/coucou.dir/requires: CMakeFiles/coucou.dir/Game/source/main.cpp.o.requires
CMakeFiles/coucou.dir/requires: CMakeFiles/coucou.dir/Game/source/map.cpp.o.requires
CMakeFiles/coucou.dir/requires: CMakeFiles/coucou.dir/Game/source/model.cpp.o.requires
CMakeFiles/coucou.dir/requires: CMakeFiles/coucou.dir/Game/source/myevent.cpp.o.requires
CMakeFiles/coucou.dir/requires: CMakeFiles/coucou.dir/Game/source/shader.cpp.o.requires
CMakeFiles/coucou.dir/requires: CMakeFiles/coucou.dir/Game/source/terrain.cpp.o.requires
CMakeFiles/coucou.dir/requires: CMakeFiles/coucou.dir/Game/source/util.cpp.o.requires
CMakeFiles/coucou.dir/requires: CMakeFiles/coucou.dir/Game/source/vaoobject.cpp.o.requires
CMakeFiles/coucou.dir/requires: CMakeFiles/coucou.dir/Game/source/water.cpp.o.requires

.PHONY : CMakeFiles/coucou.dir/requires

CMakeFiles/coucou.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/coucou.dir/cmake_clean.cmake
.PHONY : CMakeFiles/coucou.dir/clean

CMakeFiles/coucou.dir/depend:
	cd /home/riwan/1-OpenGL/OpenGlStart/coucou/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/riwan/1-OpenGL/OpenGlStart/coucou /home/riwan/1-OpenGL/OpenGlStart/coucou /home/riwan/1-OpenGL/OpenGlStart/coucou/build /home/riwan/1-OpenGL/OpenGlStart/coucou/build /home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles/coucou.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/coucou.dir/depend

