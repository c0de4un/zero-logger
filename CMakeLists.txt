# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

if ( NOT DEFINED CMAKE_VERSION )
    set( CMAKE_VERSION 3.16 )
endif ( NOT DEFINED CMAKE_VERSION )

cmake_minimum_required( VERSION ${CMAKE_VERSION} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Project Name
set( PROJECT_NAME "zero-logger" )

# Project Version
set( PROJECT_VERSION 1.2 )

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

# BuildType
include( "cmake/buildType.cmake" )

# Test-App
if ( ZLOG_TEST_ENABLED )
    message( STATUS "${PROJECT_NAME} - <ZLOG_TEST_ENABLED> is ON" )
endif ( ZLOG_TEST_ENABLED )

# Sources Dir
set( ZERO_SRC_DIR "${CMAKE_SOURCE_DIR}/src" )

# zeroEngine.API
if ( NOT DEFINED ZERO_CONFIG_INCLUDE_DIR )
    set( ZERO_CONFIG_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/zero-config/public" )

    message( STATUS "${PROJECT_NAME} - including zero-config" )
endif ( NOT DEFINED ZERO_CONFIG_INCLUDE_DIR )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# MODULES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Library
add_subdirectory( "src/lib" )

# Test-App
if ( ZERO_TEST_ENABLED )
    add_subdirectory( "src/test" )
endif ( ZERO_TEST_ENABLED )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
