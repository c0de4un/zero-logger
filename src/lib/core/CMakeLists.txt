# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

cmake_minimum_required( VERSION 3.16 )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONFIGS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Project Name
set( PROJECT_NAME "zero.Logger.Core" )

# Project Version
set( PROJECT_VERSION 1.0 )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Configure Project
project( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C CXX )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( HEADERS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/public/zero/core/" )

# Config Headers
if ( NOT DEFINED ZERO_CONFIGS_INCLUDED )
    message( STATUS "${PROJECT_NAME} - <ZERO_CONFIGS_INCLUDED> is not defined. Including base-configs by default" )

    set( HEADERS
        "${HEADERS_DIR}cfg/zero_api.hpp"
        "${HEADERS_DIR}cfg/zero_assert.hpp"
        "${HEADERS_DIR}cfg/zero_platform.hpp" )
endif ( NOT DEFINED ZERO_CONFIGS_INCLUDED )

set( HEADERS
    "${HEADERS_DIR}ILogger.hxx"
    "${HEADERS_DIR}ELogLevels.hpp"
    "${HEADERS_DIR}Log.hpp"
    "${HEADERS_DIR}DefaultLogger.hpp"
    "${HEADERS_DIR}zero_logger.hpp" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( SOURCES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/private/" )
set( SOURCES
    "${SOURCES_DIR}Log.cpp"
    "${SOURCES_DIR}DefaultLogger.cpp"
    "${SOURCES_DIR}zero_logger.cpp" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# BUILD
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

if ( ZERO_BUILD_TYPE EQUAL "STATIC" )
    # Add STATIC Library Object
    add_library( zlog STATIC ${SOURCES} )
else ( ZERO_BUILD_TYPE EQUAL "STATIC" )
    # Add SHARED Library Object
    add_library( zlog SHARED ${SOURCES} )

    # Configure SHARED Library Object
    set_target_properties( zlog PROPERTIES 
        VERSION ${PROJECT_VERSION}
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin" )
endif ( ZERO_BUILD_TYPE EQUAL "STATIC" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
