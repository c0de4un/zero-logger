# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

cmake_minimum_required( VERSION 3.16 )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONFIGS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Project Name
set( PROJECT_NAME "zero.Logger" )

# Project Version
set( PROJECT_VERSION 0.1.0 )

# Project Description
set( PROJECT_DESCRIPTION "" )

# Platform
include( "cmake/platform.cmake" )

# Debug
include( "cmake/buildType.cmake" )

# Test-App
if ( NOT DEFINED ZERO_LOGGER_TEST )
    message( STATUS "${PROJECT_NAME} - tests enabled. Set <ZERO_LOGGER_TEST> to <OFF>, if you dont need them" )

    set( ZERO_LOGGER_TEST ON )
endif ( NOT DEFINED ZERO_LOGGER_TEST )

# Sources Dir
set( ZERO_SRC_DIR "${CMAKE_SOURCE_DIR}/src" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Configure Project
project( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C CXX )

# Include Compiler Configs
include( "cmake/compiler.cmake" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# MODULES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Library

# Test-App
if ( ZERO_LOGGER_TEST )
    add_subdirectory( "src/test" )
endif ( ZERO_LOGGER_TEST )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
