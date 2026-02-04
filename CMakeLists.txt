cmake_minimum_required(VERSION 3.16)
project(Embedded_C_Program LANGUAGES C)
set(CMAKE_C_STANDARD 99)
include_directories(inc)
add_executable(embedded_app 
    src/Main.c
    src/StringProcessor.c
)