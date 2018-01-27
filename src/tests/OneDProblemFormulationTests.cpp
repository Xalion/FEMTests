/*********************************************************************************************************************
* Author: Adam Blake (adamb@quantumbear.com)
* Copyright 2018 Adam Blake
*
*
* This file is part of FEMTests.
*
* FEMTests is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* FEMTests is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with FEMTests.  If not, see <http://www.gnu.org/licenses/>.
**********************************************************************************************************************/
//
// Created by Adam Blake on 1/26/2018.
//
#include<gtest/gtest.h>
#include <string>
#include <cmath>

#include <OneDProblemFormulation.h>
#include <NeumannTypeBC.h>

namespace FEMTests {
namespace test {

namespace {
std::string sXmlBcData(
        "<?xml version=\"1.0\" encoding=\"ISO8859-1\" ?>"
                "<ProblemData>"
                "<Dim>1</Dim>"
                "<Elements>5</Elements>"
                "<alpha>"
                "   <value>0.1</value>"
                "   <value>0.2</value>"
                "   <value>0.3</value>"
                "   <value>0.4</value>"
                "   <value>0.5</value>"
                "</alpha>"
                "<beta>"
                "   <value>0.1</value>"
                "   <value>0.2</value>"
                "   <value>0.3</value>"
                "   <value>0.4</value>"
                "   <value>0.5</value>"
                "</beta>"
                "<f>"
                "   <value>0.1</value>"
                "   <value>0.2</value>"
                "   <value>0.3</value>"
                "   <value>0.4</value>"
                "   <value>0.5</value>"
                "</f>"
                "<l>"
                "   <value>0.1</value>"
                "   <value>0.2</value>"
                "   <value>0.3</value>"
                "   <value>0.4</value>"
                "   <value>0.5</value>"
                "</l>"
                "<BoundaryCondition>"
                "   <Type>Neumann</Type>"
                "   <Dim>1</Dim>"
                "   <gamma>"
                "       <value>0.1</value>"
                "   </gamma>"
                "   <q>"
                "       <value>0.1</value>"
                "   </q>"
                "</BoundaryCondition>"
                "<!--"
                "< BoundaryCondition >"
                "<Type>Dirichlet</Type>"
                "<Dim>1</Dim>"
                "<rho>"
                "<value>0.1</value>"
                "</rho>"
                "</BoundaryCondition>"
                "-->"
                "</ProblemData>   " );
}

TEST( OneDProblemFormulationTest, testFromXmlNeumann ) {

    OneDProblemFormulation formulation;
    int err = formulation.setFromXmlString( sXmlBcData );

    ASSERT_EQ( err, 0 );
    ASSERT_EQ( formulation.numElements, 5 );

    bool valsMatch = true;
    for( int ii=0; ii<formulation.numElements; ii++ ) {
        valsMatch = valsMatch && ( std::abs( (double) ( ii + 1 ) / 10.0 - formulation.alpha[ii] ) < 1E-10 );
        valsMatch = valsMatch && ( std::abs( (double) ( ii + 1 ) / 10.0 - formulation.beta[ii] ) < 1E-10 );
        valsMatch = valsMatch && ( std::abs( (double) ( ii + 1 ) / 10.0 - formulation.f[ii] ) < 1E-10 );
        valsMatch = valsMatch && ( std::abs( (double) ( ii + 1 ) / 10.0 - formulation.l[ii] ) < 1E-10 );
    }

    ASSERT_TRUE( valsMatch );

   // TODO : need a decent test for BC.  At least they are tested separately.

}
}
} // namespace FEMTests
