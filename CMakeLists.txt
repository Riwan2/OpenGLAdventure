cmake_minimum_required(VERSION 2.6)
project(coucou)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

file(GLOB_RECURSE SOURCES Game/*.cpp)
add_executable(coucou ${SOURCES} )

find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS}  ${SDL2_INCLUDE_DIRS} ${GLEW_INCUDE_DIRS})

target_link_libraries(coucou ${OPENGL_LIBRARIES} ${SDL2_LIBRARIES} ${GLEW_LIBRARY})

install(TARGETS coucou RUNTIME DESTINATION bin)
