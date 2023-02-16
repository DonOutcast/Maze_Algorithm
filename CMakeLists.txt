cmake_minimum_required(VERSION 3.21)
project(Maze_Algorithm)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/build-maze_view-Desktop_x86_darwin_generic_mach_o_64bit-Debug)
include_directories(src/controller)
include_directories(src/maze_view)
include_directories(src/model/core)

add_executable(Maze_Algorithm
        src/build-maze_view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/moc_mainwindow.cpp
        src/build-maze_view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/moc_predefs.h
        src/build-maze_view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/ui_mainwindow.h
        src/controller/controller.cpp
        src/controller/controller.h
        src/maze_view/main.cpp
        src/maze_view/mainwindow.cpp
        src/maze_view/mainwindow.h
        src/maze_view/maze_scene.cpp
        src/maze_view/maze_scene.h
        src/model/core/core.cc
        src/model/core/core.h)
