#*************************** CMake Configuration ******************************
# Copyright (c) 2026 Trenser
# All Rights Reserved
#******************************************************************************
# 
# Project : 2D Array Program
# Summary : Build configuration for C-based 2D Array.
# Note    : Requires CMake 3.16+
# 
#******************************************************************************

#------------------------------------------------------------------------------
# Project and Toolchain Settings
#------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.16)
project(BinaryConverter LANGUAGES C)

# Ensure C99 compliance as per Trenser standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

#------------------------------------------------------------------------------
# Include Directories
#------------------------------------------------------------------------------
# Header files are located in the /inc directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

#------------------------------------------------------------------------------
# Executable Definition
#------------------------------------------------------------------------------
# Define the final binary and its source dependencies
add_executable(embedded_app 
    src/main.c 
)

#------------------------------------------------------------------------------
# End of File
#------------------------------------------------------------------------------