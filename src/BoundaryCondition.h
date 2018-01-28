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

#ifndef FEMTESTS_ONEDBoundaryCONDITION_H
#define FEMTESTS_ONEDBoundaryCONDITION_H

#include <tinyxml2.h>

#include <iostream>
#include <Eigen/Dense>
#include "KMatrix.h"

namespace FEMTests {

template< int dim >
class BoundaryCondition
{
public:

    int getDim() const;

    // Make one of these for parsing.
    // static BoundaryCondition parseXmlString( bool &valid, tinyxml2::XMLText* BoundaryNode ) = 0;

    virtual void applyBoundaryCondition( KMatrix &k ) = 0;
    virtual void applyBoundaryCondition( Eigen::VectorXd &b, KMatrix &k ) = 0;
    // TODO : write XML type.  Not necessary right off.
private:

};

template<int dim>
int BoundaryCondition<dim>::getDim() const { return dim; }

}



#endif //FEMTESTS_ONEDBoundaryCONDITION_H
