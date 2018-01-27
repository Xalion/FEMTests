set( CMAKE_CXX_STANDARD 11 )

set( FEMTests_SOURCE_FILES
        OneDFEMSOlver.cpp
        OneDProblemFormulation.cpp
        BoundaryCondition.cpp
        DirichletTypeBC.cpp
        NeumannTypeBC.cpp
        BCReader.cpp
        Utility/SampleProblem.cpp
        MatrixFillOneD.cpp
        KMatrixOneD.cpp )

set( FEMTests_HEADER_FILES
        OneDFEMSOlver.h
        OneDProblemFormulation.h
        BoundaryCondition.h
        DirichletTypeBC.h
        NeumannTypeBC.h
        BCReader.h
        Utility/SampleProblem.h
        MatrixFillOneD.h
        KMatrixOneD.h )

include_directories( ${CMAKE_CURRENT_LIST_DIR} ${XML_INCLUDE_DIRS} )

set( FEMTEST_LIBRARY femtestlib CACHE STRING "" FORCE )

add_library( ${FEMTEST_LIBRARY} STATIC ${FEMTests_SOURCE_FILES} ${FEMTests_HEADER_FILES} )
target_link_libraries( ${FEMTEST_LIBRARY} ${XML_LIBRARIES} )
if (BUILD_TESTS)
    add_subdirectory( tests )
endif ()

add_executable( FEMTests main.cpp )
target_link_libraries( FEMTests femtestlib ${XML_LIBRARIES} )