cmake_minimum_required(VERSION 3.8)
project(server)

include_directories(include)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCE "src/*.cpp")

add_executable(server ${SOURCE})