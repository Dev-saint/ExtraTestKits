cmake_minimum_required(VERSION 3.10)

project(KitsTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(KitsTest ${SOURCES})

target_include_directories(KitsTest PRIVATE src)