cmake_minimum_required(VERSION 3.0)
project(pomdTimer)
 
include_directories(include)
file(GLOB SOURCES "src/*.c")
 
add_executable(pomdTimer ${SOURCES})