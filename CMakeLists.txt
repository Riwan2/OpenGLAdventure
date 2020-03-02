cmake_minimum_required(VERSION 2.6)
project(coucou)

add_executable(coucou main.cpp)

install(TARGETS coucou RUNTIME DESTINATION bin)
