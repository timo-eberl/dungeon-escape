cmake_minimum_required(VERSION 3.0.0)
project(dungeon-escape VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(dungeon-escape
    src/main.cpp
)
