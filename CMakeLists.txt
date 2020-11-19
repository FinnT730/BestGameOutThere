cmake_minimum_required(VERSION 3.15)
project(untitled9 CXX)

set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory("libs/raylib")

add_executable(untitled9 main.cpp World.h)
target_link_libraries(untitled9 PRIVATE raylib)