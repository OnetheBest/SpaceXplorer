cmake_minimum_required(VERSION 3.21)
project(spaceXplorer C)

set(CMAKE_C_STANDARD 99)

add_executable(spaceXplorer main.c
        game.c
        input.c
        game.h
        entity.h
        input.h
        title.c
        title.h
        scores.c
        scores.h)
