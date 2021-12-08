# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

if ( NOT DEFINED ZERO_TEST_ENABLED )
    option( ZERO_TEST_ENABLED "Enable Testing" ON )
endif ( NOT DEFINED ZERO_TEST_ENABLED )

if ( NOT DEFINED ZERO_OUTPUT_DIR )
    set( ZERO_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bin/${PLATFROM}" )

    set( STATUS "${PROJECT_NAME} - output path is '${ZERO_OUTPUT_DIR}'" )
endif ( NOT DEFINED ZERO_OUTPUT_DIR )

if ( NOT DEFINED ZERO_LOGGER_INCLUDE_DIR )
    set( ZERO_LOGGER_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/lib/public" )
endif ( NOT DEFINED ZERO_LOGGER_INCLUDE_DIR )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
