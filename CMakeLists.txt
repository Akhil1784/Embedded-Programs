#*************************** CMake Configuration ******************************
# Copyright (c) 2026 Trenser
# All Rights Reserved
#******************************************************************************
# 
# Project : String Program
# Summary : Build configuration for String Program Configuration.
# Note    : Implements private static instance pattern with pointer access.
# 
#******************************************************************************

#------------------------------------------------------------------------------
# Project and Toolchain Settings
#------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.16)
project(Embedded_C_Program LANGUAGES C)

# Ensure C99 compliance as per Trenser standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

#------------------------------------------------------------------------------
# Include Directories
#------------------------------------------------------------------------------
# Header files are located in the /inc directory
include_directories(inc)

#------------------------------------------------------------------------------
# Executable Definition
#------------------------------------------------------------------------------
# Define the final binary and its source dependencies
add_executable(embedded_app 
    src/main.c
    src/stringProcessor.c
)

#------------------------------------------------------------------------------
# End of File
#------------------------------------------------------------------------------
