# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

cmake_minimum_required( VERSION ${CMAKE_VERSION} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONFIGS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Project Name
set( PROJECT_NAME "zero-logger.lib" )

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
    "${HEADERS_DIR}log/ILogger.hxx"
    "${HEADERS_DIR}log/ELogLevels.hpp"
    "${HEADERS_DIR}log/Log.hpp"
    "${HEADERS_DIR}log/DefaultLogger.hpp" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( SOURCES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/private/zero/core/" )
set( SOURCES
    "${SOURCES_DIR}log/Log.cpp"
    "${SOURCES_DIR}log/DefaultLogger.cpp" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# BUILD
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

message( STATUS "${PROJECT_NAME} - building ${ZERO_BUILD_TYPE} Library" )
if ( ZERO_BUILD_TYPE STREQUAL "STATIC" )
    # Add STATIC Library Object
    add_library( zero_logger STATIC ${SOURCES} )
else ( ZERO_BUILD_TYPE STREQUAL "STATIC" )
    # Add SHARED Library Object
    add_library( zero_logger SHARED ${SOURCES} )

    # Configure SHARED Library Object
    set_target_properties( zero_logger PROPERTIES
        VERSION ${PROJECT_VERSION}
        LIBRARY_OUTPUT_NAME "zero_logger"
        RUNTIME_OUTPUT_DIRECTORY "${ZERO_OUTPUT_DIR}"
        ARCHIVE_OUTPUT_DIRECTORY "${ZERO_OUTPUT_DIR}"
        LIBRARY_OUTPUT_DIRECTORY "${ZERO_OUTPUT_DIR}" )
endif ( ZERO_BUILD_TYPE STREQUAL "STATIC" )

# Link with zero-config
target_include_directories( zero_logger PUBLIC ${ZERO_CONFIG_INCLUDE_DIR} )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
