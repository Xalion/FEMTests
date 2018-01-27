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

#ifndef FEMTESTS_DIRICHLETTYPEBC_H
#define FEMTESTS_DIRICHLETTYPEBC_H

#include <BoundryCondition.h>

#include <vector>
#include <cassert>
#include <iomanip>

namespace FEMTests {

template<int dim>
class DirichletTypeBC : public BoundryCondition<dim> {
public:

    DirichletTypeBC();

    double getRho( int inDim = 0 ) const;

    template<int T>
    friend std::ostream &operator<<( std::ostream &os, const DirichletTypeBC<T> &bc );

    static DirichletTypeBC<dim> parseXmlString( bool &valid, tinyxml2::XMLElement *boundryNode );
private:
    std::vector<double> mRho;

};

//***************************** FUNCTION DEFINITIONS ****************************************

template<int dim>
double DirichletTypeBC<dim>::getRho( int inDim ) const {
    assert( inDim < dim );
    return mRho[ inDim ];
}

template<int dim>
DirichletTypeBC<dim>::DirichletTypeBC() : mRho( dim ) {}


template<int T>
std::ostream &operator<<( std::ostream &os, const DirichletTypeBC<T> &bc ) {
    os << "Dirichlet Type Boundary Condition:" << std::endl;
    os << std::setw( 10 ) << " Dim " << std::setw( 10 ) << "rho" << std::endl;
    for ( int ii = 0; ii < bc.getDim(); ii++ ) {
        os << std::setw( 10 ) << ii << " "
           << std::setw( 10 ) << bc.mRho[ ii ] << std::endl;
    }
    return os;
}

template<int dim>
DirichletTypeBC<dim> DirichletTypeBC<dim>::parseXmlString( bool &valid, tinyxml2::XMLElement *boundryNode ) {
    DirichletTypeBC<dim> bc;

    tinyxml2::XMLText *typeNode = boundryNode->FirstChildElement( "Type" )->FirstChild()->ToText();
    std::string type( typeNode->Value());
    valid = true;
    if ( type != "Dirichlet" ) {
        valid = false;
        return bc;
    }

    int dimension = boundryNode->FirstChildElement("Dim")->IntText();
    if ( dimension != dim ) {
        valid = false;
        return bc;
    }

    tinyxml2::XMLElement *currentNode = boundryNode->FirstChildElement( "rho" );
    std::vector<double> rhoVec;
    for ( tinyxml2::XMLElement *valueNode = currentNode->FirstChildElement( "value" );
          valueNode != NULL; valueNode = valueNode->NextSiblingElement()) {
        double val = valueNode->DoubleText();
        rhoVec.push_back( val );
    }
    bc.mRho = rhoVec;
    return bc;
}
}


#endif //FEMTESTS_DIRICHLETTYPEBC_H
