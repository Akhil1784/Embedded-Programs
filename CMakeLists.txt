#*************************** CMake Configuration ******************************
# Copyright (c) 2026 Trenser
# All Rights Reserved
#******************************************************************************
# 
# Project : Embedded Singleton Program
# Summary : Build configuration for Singleton-based Device Configuration.
# Note    : Implements private static instance pattern with pointer access.
# 
#******************************************************************************

#------------------------------------------------------------------------------
# Project and Toolchain Settings
#------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.16)
project(EmbeddedSingletonProgram LANGUAGES C)

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
    src/deviceConfig.c
)

#------------------------------------------------------------------------------
# End of File
#------------------------------------------------------------------------------