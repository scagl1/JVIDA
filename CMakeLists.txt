cmake_minimum_required(VERSION 3.20)
project(JVIDA C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(JVIDA
        JVIDA-PCRFT-Controller.c
        JVIDA-PCRFT-Controller.h
        JVIDA-PCRFT-Model.c
        JVIDA-PCRFT-Model.h
        JVIDA-PCRFT-View.c
        JVIDA-PCRFT-View.h
        JVIDA-PCRFT.c)
