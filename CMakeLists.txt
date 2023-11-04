cmake_minimum_required(VERSION 3.10)
project(LinkedList)

set(CMAKE_CXX_STANDARD 17)

# Add compiler warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra ")

include_directories(src)

add_subdirectory(src)
enable_testing()
add_subdirectory(tst)
add_subdirectory(lib/googletest)
