cmake_minimum_required( VERSION 3.9 )
project( FEMTests )

option( BUILD_TESTS "Built the unit tests" OFF )

if( BUILD_TESTS )
    enable_testing()
    # Download and unpack gtest at configure time
    configure_file( GTestCMake.in googletest-download/CMakeLists.txt )
    execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
    execute_process(COMMAND "${CMAKE_COMMAND}" --build .
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
            "${CMAKE_BINARY_DIR}/googletest-build")
endif( BUILD_TESTS )

add_subdirectory( src )
