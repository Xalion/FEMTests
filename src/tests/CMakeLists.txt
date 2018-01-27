#*********************************************************************************************************************
# Author: Adam Blake (adamb@quantumbear.com)
# Copyright 2017 Adam Blake
#
#
# This file is part of FEMTests.
#
# FEMTests is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# FEMTests is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with FEMTests.  If not, see <http://www.gnu.org/licenses/>.
#*********************************************************************************************************************/
project( FEMTestsUnitTests )

set( TEST_HEADERS
        )

set( TEST_SOURCES
        NeumannTypeBCTests.cpp
        DirichletTypeBCTests.cpp
        OneDProblemFormulationTests.cpp
        )

set( testname ${PROJECT_NAME} )

source_group( "Test\\Header Files" FILES ${TEST_HEADERS} )
source_group( "Test\\Source Files" FILES ${TEST_SOURCES} )

add_executable( ${testname} ${TEST_SOURCES} ${TEST_HEADERS} )
add_dependencies( ${testname} gtest gtest_main )

target_link_libraries(
        ${testname}
        gtest gtest_main
        ${FEMTEST_LIBRARY}
        ${GTEST_LIBRARY}
        ${XML_LIBRARIES}
        )

