cmake_minimum_required( VERSION 3.9 )
project( FEMTests )
### include xml reader expat
# Leaving this here for now because I'd like to get it working.  It currently doesn't though.
option( BUILD_TESTS "Built the unit tests" OFF )

set( GTEST_LIBRARIES "" )

if ( BUILD_TESTS )
    set( BUILD_TESTING ON )
    enable_testing()
    # Download and unpack gtest at configure time
    configure_file( GTestCMake.in googletest-download/CMakeLists.txt )
    execute_process( COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
    execute_process( COMMAND "${CMAKE_COMMAND}" --build .
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )

    set( gtest_force_shared_crt ON CACHE BOOL "" FORCE )

    add_subdirectory( "${CMAKE_BINARY_DIR}/googletest-src"
            "${CMAKE_BINARY_DIR}/googletest-build" )
    set( GTEST_LIBRARIES gtest gtest_main )
else()
    set( BUILD_TESTING OFF )
endif (BUILD_TESTS)

set( XML_LIBRARIES "" )
set( XML_INCLUDE_DIRS "" )

option( BUILD_EXPAT "Build the EXPAT xml library" OFF )
if ( BUILD_EXPAT )
    configure_file( ExpatCmake.in expat-download/CMakeLists.txt )

    execute_process( COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/expat-download" )
    execute_process( COMMAND "${CMAKE_COMMAND}" --build .
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/expat-download" )

    add_subdirectory( "${CMAKE_BINARY_DIR}/expat-src/expat"
            "${CMAKE_BINARY_DIR}/expat-build" )

    set( EXPAT_LIBRARIES expat )
    set( EXPAT_INCLUDE_DIRS "${CMAKE_BINARY_DIR}/expat-download/expat/lib" )
    add_definitions( -DEXPAT_AVAILABLE )
    set( XML_LIBRARIES "${XML_LIBRARIES} ${EXPAT_LIBRARIES}" )
    set( XML_INCLUDE_DIRS "${XML_INCLUDE_DIRS} ${EXPAT_INCLUDE_DIRS}" )
    string(STRIP "${XML_LIBRARIES}" XML_LIBRARIES )
endif ()

option ( BUILD_TINYXML2 "Build the TinyXML2 library" ON )
if ( BUILD_TINYXML2 )
    configure_file( TinyXMLCmake.in tinyxml-download/CMakeLists.txt )

    execute_process( COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/tinyxml-download" )
    execute_process( COMMAND "${CMAKE_COMMAND}" --build .
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/tinyxml-download" )

    set( BUILD_SHARED_LIBS ON )
    add_subdirectory( "${CMAKE_BINARY_DIR}/tinyxml-src"
            "${CMAKE_BINARY_DIR}/tinyxml-build" )

    set( TINYXML_LIBRARIES tinyxml2 )
    set( TINYXML_INCLUDE_DIRS "${CMAKE_BINARY_DIR}/tinyxml-src/" )
    add_definitions( -DTINYXML_AVAILABLE )
    set( XML_LIBRARIES "${XML_LIBRARIES} ${TINYXML_LIBRARIES}" )
    set( XML_INCLUDE_DIRS "${XML_INCLUDE_DIRS} ${TINYXML_INCLUDE_DIRS}" )
    string(STRIP "${XML_LIBRARIES}" XML_LIBRARIES )
endif()

add_subdirectory( src )
