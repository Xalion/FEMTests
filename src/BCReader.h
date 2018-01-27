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

#ifndef FEMTESTS_BCREADER_H
#define FEMTESTS_BCREADER_H

#include <tinyxml2.h>
#include <BoundaryCondition.h>
#include <NeumannTypeBC.h>
#include <DirichletTypeBC.h>

namespace FEMTests {

template<int dim>
class BCReader {
public:

    BoundaryCondition<dim> readBoundryConditions( bool &success, tinyxml2::XMLElement *boundryNode ) {
        success = false;
        
        BoundaryCondition<dim> bc;

        bc = tryReader<NeumannTypeBC<dim>>( success, boundryNode );
        if( success ) {
            return bc;
        }

        bc = tryReader<DirichletTypeBC<dim>>( success, boundryNode );
        if( success ) {
            return bc;
        }

        return bc;
    }

private:
    template<typename T>
    BoundaryCondition<dim> tryReader( bool &success, tinyxml2::XMLElement *boundryNode ) {
        return T::parseXmlString( success, boundryNode );
    }
};


} // namespace FEMTests
#endif //FEMTESTS_BCREADER_H
