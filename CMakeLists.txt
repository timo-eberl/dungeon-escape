cmake_minimum_required(VERSION 3.0.0)
project(dungeon-escape VERSION 1.0.0)

include(CTest)
enable_testing()

set(SOURCES
    src/dungeon.cpp
    src/vector2d.cpp
    src/player.cpp
    src/itile.cpp
    src/floor.cpp
    src/wall.cpp
    src/exit.cpp
    src/tile_factory.cpp
    src/breakable_wall.cpp
    src/mud.cpp
    src/console.cpp
)

add_executable(dungeon-escape
    src/main.cpp
    ${SOURCES}
)

if(UNIX)
    find_package(Curses REQUIRED)
    target_link_libraries(dungeon-escape ${CURSES_LIBRARIES})
endif()

target_include_directories(dungeon-escape PRIVATE include)
