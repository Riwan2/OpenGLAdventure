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
include CMakeFiles/coucoue.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/coucoue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/coucoue.dir/flags.make

CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.o: CMakeFiles/coucoue.dir/flags.make
CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.o: ../Game/Basic/camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Basic/camera.cpp

CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Basic/camera.cpp > CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.i

CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Basic/camera.cpp -o CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.s

CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.o.requires:

.PHONY : CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.o.requires

CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.o.provides: CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucoue.dir/build.make CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.o.provides.build
.PHONY : CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.o.provides

CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.o.provides.build: CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.o


CMakeFiles/coucoue.dir/Game/Basic/input.cpp.o: CMakeFiles/coucoue.dir/flags.make
CMakeFiles/coucoue.dir/Game/Basic/input.cpp.o: ../Game/Basic/input.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/coucoue.dir/Game/Basic/input.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucoue.dir/Game/Basic/input.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Basic/input.cpp

CMakeFiles/coucoue.dir/Game/Basic/input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucoue.dir/Game/Basic/input.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Basic/input.cpp > CMakeFiles/coucoue.dir/Game/Basic/input.cpp.i

CMakeFiles/coucoue.dir/Game/Basic/input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucoue.dir/Game/Basic/input.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Basic/input.cpp -o CMakeFiles/coucoue.dir/Game/Basic/input.cpp.s

CMakeFiles/coucoue.dir/Game/Basic/input.cpp.o.requires:

.PHONY : CMakeFiles/coucoue.dir/Game/Basic/input.cpp.o.requires

CMakeFiles/coucoue.dir/Game/Basic/input.cpp.o.provides: CMakeFiles/coucoue.dir/Game/Basic/input.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucoue.dir/build.make CMakeFiles/coucoue.dir/Game/Basic/input.cpp.o.provides.build
.PHONY : CMakeFiles/coucoue.dir/Game/Basic/input.cpp.o.provides

CMakeFiles/coucoue.dir/Game/Basic/input.cpp.o.provides.build: CMakeFiles/coucoue.dir/Game/Basic/input.cpp.o


CMakeFiles/coucoue.dir/Game/Basic/util.cpp.o: CMakeFiles/coucoue.dir/flags.make
CMakeFiles/coucoue.dir/Game/Basic/util.cpp.o: ../Game/Basic/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/coucoue.dir/Game/Basic/util.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucoue.dir/Game/Basic/util.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Basic/util.cpp

CMakeFiles/coucoue.dir/Game/Basic/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucoue.dir/Game/Basic/util.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Basic/util.cpp > CMakeFiles/coucoue.dir/Game/Basic/util.cpp.i

CMakeFiles/coucoue.dir/Game/Basic/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucoue.dir/Game/Basic/util.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Basic/util.cpp -o CMakeFiles/coucoue.dir/Game/Basic/util.cpp.s

CMakeFiles/coucoue.dir/Game/Basic/util.cpp.o.requires:

.PHONY : CMakeFiles/coucoue.dir/Game/Basic/util.cpp.o.requires

CMakeFiles/coucoue.dir/Game/Basic/util.cpp.o.provides: CMakeFiles/coucoue.dir/Game/Basic/util.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucoue.dir/build.make CMakeFiles/coucoue.dir/Game/Basic/util.cpp.o.provides.build
.PHONY : CMakeFiles/coucoue.dir/Game/Basic/util.cpp.o.provides

CMakeFiles/coucoue.dir/Game/Basic/util.cpp.o.provides.build: CMakeFiles/coucoue.dir/Game/Basic/util.cpp.o


CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.o: CMakeFiles/coucoue.dir/flags.make
CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.o: ../Game/Entity/entity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Entity/entity.cpp

CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Entity/entity.cpp > CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.i

CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Entity/entity.cpp -o CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.s

CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.o.requires:

.PHONY : CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.o.requires

CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.o.provides: CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucoue.dir/build.make CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.o.provides.build
.PHONY : CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.o.provides

CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.o.provides.build: CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.o


CMakeFiles/coucoue.dir/Game/Entity/player.cpp.o: CMakeFiles/coucoue.dir/flags.make
CMakeFiles/coucoue.dir/Game/Entity/player.cpp.o: ../Game/Entity/player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/coucoue.dir/Game/Entity/player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucoue.dir/Game/Entity/player.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Entity/player.cpp

CMakeFiles/coucoue.dir/Game/Entity/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucoue.dir/Game/Entity/player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Entity/player.cpp > CMakeFiles/coucoue.dir/Game/Entity/player.cpp.i

CMakeFiles/coucoue.dir/Game/Entity/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucoue.dir/Game/Entity/player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Entity/player.cpp -o CMakeFiles/coucoue.dir/Game/Entity/player.cpp.s

CMakeFiles/coucoue.dir/Game/Entity/player.cpp.o.requires:

.PHONY : CMakeFiles/coucoue.dir/Game/Entity/player.cpp.o.requires

CMakeFiles/coucoue.dir/Game/Entity/player.cpp.o.provides: CMakeFiles/coucoue.dir/Game/Entity/player.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucoue.dir/build.make CMakeFiles/coucoue.dir/Game/Entity/player.cpp.o.provides.build
.PHONY : CMakeFiles/coucoue.dir/Game/Entity/player.cpp.o.provides

CMakeFiles/coucoue.dir/Game/Entity/player.cpp.o.provides.build: CMakeFiles/coucoue.dir/Game/Entity/player.cpp.o


CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.o: CMakeFiles/coucoue.dir/flags.make
CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.o: ../Game/Loader/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Loader/texture.cpp

CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Loader/texture.cpp > CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.i

CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Loader/texture.cpp -o CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.s

CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.o.requires:

.PHONY : CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.o.requires

CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.o.provides: CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucoue.dir/build.make CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.o.provides.build
.PHONY : CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.o.provides

CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.o.provides.build: CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.o


CMakeFiles/coucoue.dir/Game/Map/map.cpp.o: CMakeFiles/coucoue.dir/flags.make
CMakeFiles/coucoue.dir/Game/Map/map.cpp.o: ../Game/Map/map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/coucoue.dir/Game/Map/map.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucoue.dir/Game/Map/map.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Map/map.cpp

CMakeFiles/coucoue.dir/Game/Map/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucoue.dir/Game/Map/map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Map/map.cpp > CMakeFiles/coucoue.dir/Game/Map/map.cpp.i

CMakeFiles/coucoue.dir/Game/Map/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucoue.dir/Game/Map/map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Map/map.cpp -o CMakeFiles/coucoue.dir/Game/Map/map.cpp.s

CMakeFiles/coucoue.dir/Game/Map/map.cpp.o.requires:

.PHONY : CMakeFiles/coucoue.dir/Game/Map/map.cpp.o.requires

CMakeFiles/coucoue.dir/Game/Map/map.cpp.o.provides: CMakeFiles/coucoue.dir/Game/Map/map.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucoue.dir/build.make CMakeFiles/coucoue.dir/Game/Map/map.cpp.o.provides.build
.PHONY : CMakeFiles/coucoue.dir/Game/Map/map.cpp.o.provides

CMakeFiles/coucoue.dir/Game/Map/map.cpp.o.provides.build: CMakeFiles/coucoue.dir/Game/Map/map.cpp.o


CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.o: CMakeFiles/coucoue.dir/flags.make
CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.o: ../Game/Map/skybox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Map/skybox.cpp

CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Map/skybox.cpp > CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.i

CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Map/skybox.cpp -o CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.s

CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.o.requires:

.PHONY : CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.o.requires

CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.o.provides: CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucoue.dir/build.make CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.o.provides.build
.PHONY : CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.o.provides

CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.o.provides.build: CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.o


CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.o: CMakeFiles/coucoue.dir/flags.make
CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.o: ../Game/Map/terrain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Map/terrain.cpp

CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Map/terrain.cpp > CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.i

CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Map/terrain.cpp -o CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.s

CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.o.requires:

.PHONY : CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.o.requires

CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.o.provides: CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucoue.dir/build.make CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.o.provides.build
.PHONY : CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.o.provides

CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.o.provides.build: CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.o


CMakeFiles/coucoue.dir/Game/Map/water.cpp.o: CMakeFiles/coucoue.dir/flags.make
CMakeFiles/coucoue.dir/Game/Map/water.cpp.o: ../Game/Map/water.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/coucoue.dir/Game/Map/water.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucoue.dir/Game/Map/water.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Map/water.cpp

CMakeFiles/coucoue.dir/Game/Map/water.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucoue.dir/Game/Map/water.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Map/water.cpp > CMakeFiles/coucoue.dir/Game/Map/water.cpp.i

CMakeFiles/coucoue.dir/Game/Map/water.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucoue.dir/Game/Map/water.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Map/water.cpp -o CMakeFiles/coucoue.dir/Game/Map/water.cpp.s

CMakeFiles/coucoue.dir/Game/Map/water.cpp.o.requires:

.PHONY : CMakeFiles/coucoue.dir/Game/Map/water.cpp.o.requires

CMakeFiles/coucoue.dir/Game/Map/water.cpp.o.provides: CMakeFiles/coucoue.dir/Game/Map/water.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucoue.dir/build.make CMakeFiles/coucoue.dir/Game/Map/water.cpp.o.provides.build
.PHONY : CMakeFiles/coucoue.dir/Game/Map/water.cpp.o.provides

CMakeFiles/coucoue.dir/Game/Map/water.cpp.o.provides.build: CMakeFiles/coucoue.dir/Game/Map/water.cpp.o


CMakeFiles/coucoue.dir/Game/Model/model.cpp.o: CMakeFiles/coucoue.dir/flags.make
CMakeFiles/coucoue.dir/Game/Model/model.cpp.o: ../Game/Model/model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/coucoue.dir/Game/Model/model.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucoue.dir/Game/Model/model.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Model/model.cpp

CMakeFiles/coucoue.dir/Game/Model/model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucoue.dir/Game/Model/model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Model/model.cpp > CMakeFiles/coucoue.dir/Game/Model/model.cpp.i

CMakeFiles/coucoue.dir/Game/Model/model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucoue.dir/Game/Model/model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Model/model.cpp -o CMakeFiles/coucoue.dir/Game/Model/model.cpp.s

CMakeFiles/coucoue.dir/Game/Model/model.cpp.o.requires:

.PHONY : CMakeFiles/coucoue.dir/Game/Model/model.cpp.o.requires

CMakeFiles/coucoue.dir/Game/Model/model.cpp.o.provides: CMakeFiles/coucoue.dir/Game/Model/model.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucoue.dir/build.make CMakeFiles/coucoue.dir/Game/Model/model.cpp.o.provides.build
.PHONY : CMakeFiles/coucoue.dir/Game/Model/model.cpp.o.provides

CMakeFiles/coucoue.dir/Game/Model/model.cpp.o.provides.build: CMakeFiles/coucoue.dir/Game/Model/model.cpp.o


CMakeFiles/coucoue.dir/Game/Model/shader.cpp.o: CMakeFiles/coucoue.dir/flags.make
CMakeFiles/coucoue.dir/Game/Model/shader.cpp.o: ../Game/Model/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/coucoue.dir/Game/Model/shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucoue.dir/Game/Model/shader.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Model/shader.cpp

CMakeFiles/coucoue.dir/Game/Model/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucoue.dir/Game/Model/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Model/shader.cpp > CMakeFiles/coucoue.dir/Game/Model/shader.cpp.i

CMakeFiles/coucoue.dir/Game/Model/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucoue.dir/Game/Model/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Model/shader.cpp -o CMakeFiles/coucoue.dir/Game/Model/shader.cpp.s

CMakeFiles/coucoue.dir/Game/Model/shader.cpp.o.requires:

.PHONY : CMakeFiles/coucoue.dir/Game/Model/shader.cpp.o.requires

CMakeFiles/coucoue.dir/Game/Model/shader.cpp.o.provides: CMakeFiles/coucoue.dir/Game/Model/shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucoue.dir/build.make CMakeFiles/coucoue.dir/Game/Model/shader.cpp.o.provides.build
.PHONY : CMakeFiles/coucoue.dir/Game/Model/shader.cpp.o.provides

CMakeFiles/coucoue.dir/Game/Model/shader.cpp.o.provides.build: CMakeFiles/coucoue.dir/Game/Model/shader.cpp.o


CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.o: CMakeFiles/coucoue.dir/flags.make
CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.o: ../Game/Renderer/renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Renderer/renderer.cpp

CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Renderer/renderer.cpp > CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.i

CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Renderer/renderer.cpp -o CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.s

CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.o.requires:

.PHONY : CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.o.requires

CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.o.provides: CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucoue.dir/build.make CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.o.provides.build
.PHONY : CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.o.provides

CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.o.provides.build: CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.o


CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.o: CMakeFiles/coucoue.dir/flags.make
CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.o: ../Game/Scene/scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Scene/scene.cpp

CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Scene/scene.cpp > CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.i

CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/Scene/scene.cpp -o CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.s

CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.o.requires:

.PHONY : CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.o.requires

CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.o.provides: CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucoue.dir/build.make CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.o.provides.build
.PHONY : CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.o.provides

CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.o.provides.build: CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.o


CMakeFiles/coucoue.dir/Game/source/main.cpp.o: CMakeFiles/coucoue.dir/flags.make
CMakeFiles/coucoue.dir/Game/source/main.cpp.o: ../Game/source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/coucoue.dir/Game/source/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coucoue.dir/Game/source/main.cpp.o -c /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/main.cpp

CMakeFiles/coucoue.dir/Game/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coucoue.dir/Game/source/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/main.cpp > CMakeFiles/coucoue.dir/Game/source/main.cpp.i

CMakeFiles/coucoue.dir/Game/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coucoue.dir/Game/source/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riwan/1-OpenGL/OpenGlStart/coucou/Game/source/main.cpp -o CMakeFiles/coucoue.dir/Game/source/main.cpp.s

CMakeFiles/coucoue.dir/Game/source/main.cpp.o.requires:

.PHONY : CMakeFiles/coucoue.dir/Game/source/main.cpp.o.requires

CMakeFiles/coucoue.dir/Game/source/main.cpp.o.provides: CMakeFiles/coucoue.dir/Game/source/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/coucoue.dir/build.make CMakeFiles/coucoue.dir/Game/source/main.cpp.o.provides.build
.PHONY : CMakeFiles/coucoue.dir/Game/source/main.cpp.o.provides

CMakeFiles/coucoue.dir/Game/source/main.cpp.o.provides.build: CMakeFiles/coucoue.dir/Game/source/main.cpp.o


# Object files for target coucoue
coucoue_OBJECTS = \
"CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.o" \
"CMakeFiles/coucoue.dir/Game/Basic/input.cpp.o" \
"CMakeFiles/coucoue.dir/Game/Basic/util.cpp.o" \
"CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.o" \
"CMakeFiles/coucoue.dir/Game/Entity/player.cpp.o" \
"CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.o" \
"CMakeFiles/coucoue.dir/Game/Map/map.cpp.o" \
"CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.o" \
"CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.o" \
"CMakeFiles/coucoue.dir/Game/Map/water.cpp.o" \
"CMakeFiles/coucoue.dir/Game/Model/model.cpp.o" \
"CMakeFiles/coucoue.dir/Game/Model/shader.cpp.o" \
"CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.o" \
"CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.o" \
"CMakeFiles/coucoue.dir/Game/source/main.cpp.o"

# External object files for target coucoue
coucoue_EXTERNAL_OBJECTS =

coucoue: CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.o
coucoue: CMakeFiles/coucoue.dir/Game/Basic/input.cpp.o
coucoue: CMakeFiles/coucoue.dir/Game/Basic/util.cpp.o
coucoue: CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.o
coucoue: CMakeFiles/coucoue.dir/Game/Entity/player.cpp.o
coucoue: CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.o
coucoue: CMakeFiles/coucoue.dir/Game/Map/map.cpp.o
coucoue: CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.o
coucoue: CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.o
coucoue: CMakeFiles/coucoue.dir/Game/Map/water.cpp.o
coucoue: CMakeFiles/coucoue.dir/Game/Model/model.cpp.o
coucoue: CMakeFiles/coucoue.dir/Game/Model/shader.cpp.o
coucoue: CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.o
coucoue: CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.o
coucoue: CMakeFiles/coucoue.dir/Game/source/main.cpp.o
coucoue: CMakeFiles/coucoue.dir/build.make
coucoue: CMakeFiles/coucoue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable coucoue"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/coucoue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/coucoue.dir/build: coucoue

.PHONY : CMakeFiles/coucoue.dir/build

CMakeFiles/coucoue.dir/requires: CMakeFiles/coucoue.dir/Game/Basic/camera.cpp.o.requires
CMakeFiles/coucoue.dir/requires: CMakeFiles/coucoue.dir/Game/Basic/input.cpp.o.requires
CMakeFiles/coucoue.dir/requires: CMakeFiles/coucoue.dir/Game/Basic/util.cpp.o.requires
CMakeFiles/coucoue.dir/requires: CMakeFiles/coucoue.dir/Game/Entity/entity.cpp.o.requires
CMakeFiles/coucoue.dir/requires: CMakeFiles/coucoue.dir/Game/Entity/player.cpp.o.requires
CMakeFiles/coucoue.dir/requires: CMakeFiles/coucoue.dir/Game/Loader/texture.cpp.o.requires
CMakeFiles/coucoue.dir/requires: CMakeFiles/coucoue.dir/Game/Map/map.cpp.o.requires
CMakeFiles/coucoue.dir/requires: CMakeFiles/coucoue.dir/Game/Map/skybox.cpp.o.requires
CMakeFiles/coucoue.dir/requires: CMakeFiles/coucoue.dir/Game/Map/terrain.cpp.o.requires
CMakeFiles/coucoue.dir/requires: CMakeFiles/coucoue.dir/Game/Map/water.cpp.o.requires
CMakeFiles/coucoue.dir/requires: CMakeFiles/coucoue.dir/Game/Model/model.cpp.o.requires
CMakeFiles/coucoue.dir/requires: CMakeFiles/coucoue.dir/Game/Model/shader.cpp.o.requires
CMakeFiles/coucoue.dir/requires: CMakeFiles/coucoue.dir/Game/Renderer/renderer.cpp.o.requires
CMakeFiles/coucoue.dir/requires: CMakeFiles/coucoue.dir/Game/Scene/scene.cpp.o.requires
CMakeFiles/coucoue.dir/requires: CMakeFiles/coucoue.dir/Game/source/main.cpp.o.requires

.PHONY : CMakeFiles/coucoue.dir/requires

CMakeFiles/coucoue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/coucoue.dir/cmake_clean.cmake
.PHONY : CMakeFiles/coucoue.dir/clean

CMakeFiles/coucoue.dir/depend:
	cd /home/riwan/1-OpenGL/OpenGlStart/coucou/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/riwan/1-OpenGL/OpenGlStart/coucou /home/riwan/1-OpenGL/OpenGlStart/coucou /home/riwan/1-OpenGL/OpenGlStart/coucou/build /home/riwan/1-OpenGL/OpenGlStart/coucou/build /home/riwan/1-OpenGL/OpenGlStart/coucou/build/CMakeFiles/coucoue.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/coucoue.dir/depend

