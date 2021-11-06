# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( CMAKE_VERSION 3.16 )
cmake_minimum_required( VERSION ${CMAKE_VERSION} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Project Name
set( PROJECT_NAME "zlog" )

# Project Version
set( PROJECT_VERSION 1.1 )

# Configure Project
project( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C CXX )

# Include Compiler Configs
include( "cmake/compiler.cmake" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONFIGS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Options
include( "cmake/options.cmake" )

# Platform
include( "cmake/platform.cmake" )

# Debug
include( "cmake/buildType.cmake" )

# Test-App
if ( ZLOG_TEST_ENABLED )
    message( STATUS "${PROJECT_NAME} - <ZLOG_TEST_ENABLED> is ON" )
endif ( ZLOG_TEST_ENABLED )

# Sources Dir
set( ZERO_SRC_DIR "${CMAKE_SOURCE_DIR}/src" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# MODULES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Library
add_subdirectory( "src/lib" )

# Test-App
if ( ZLOG_TEST_ENABLED )
    add_subdirectory( "src/test" )
endif ( ZLOG_TEST_ENABLED )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
