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

#include <gtest/gtest.h>
#include <DirichletTypeBC.h>
namespace FEMTests {
namespace tests {

namespace {


std::string sXmlBcData(
        "<BoundaryCondition>"
        "   <Type>Dirichlet</Type>"
        "   <Dim>1</Dim>"
        "   <rho>"
        "       <value>0.1</value>"
        "   </rho>"
        "</BoundaryCondition>"
);

}

TEST( DirichletTypeBCTest, testFromXML ) {
    tinyxml2::XMLDocument doc;
    doc.Parse( sXmlBcData.c_str() );
    tinyxml2::XMLElement *xmlElement = doc.FirstChild()->ToElement();

    bool isValid = false;

    DirichletTypeBC<1> bc = DirichletTypeBC<1>::parseXmlString(isValid, xmlElement);

    ASSERT_TRUE( isValid ) << "isValid returned false.";
    ASSERT_EQ( 1, bc.getDim() ) << "getDim returned the wrong value.";
    ASSERT_EQ( 0.1, bc.getRho( 0 ) ) << "getRho returned the wrong value";
}

}
}