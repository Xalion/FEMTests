set( CMAKE_CXX_STANDARD 11 )

set( FEMTests_SOURCE_FILES
        OneDFEMSOlver.cpp
        OneDProblemFormulation.cpp
        BoundryCondition.cpp DirichletTypeBC.cpp DirichletTypeBC.h NeumannTypeBC.cpp NeumannTypeBC.h )

set( FEMTests_HEADER_FILES
        OneDFEMSOlver.h
        OneDProblemFormulation.h
        BoundryCondition.h DirichletTypeBC.cpp DirichletTypeBC.h NeumannTypeBC.cpp NeumannTypeBC.h )

include_directories( ${CMAKE_CURRENT_LIST_DIR} )
add_executable( FEMTests main.cpp ${FEMTests_SOURCE_FILES} ${FEMTests_HEADER_FILES} )