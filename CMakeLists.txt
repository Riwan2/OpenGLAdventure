cmake_minimum_required(VERSION 2.6)
project(coucou)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SOURCES Source/*.cpp)
add_executable(coucou ${SOURCES} )

find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${GLEW_INCUDE_DIRS})

target_link_libraries(coucou ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY})

install(TARGETS coucou RUNTIME DESTINATION bin)
