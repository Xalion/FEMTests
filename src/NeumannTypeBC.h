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
#ifndef FEMTESTS_NEUMANNTYPEBC_H
#define FEMTESTS_NEUMANNTYPEBC_H

#include <vector>
#include <cassert>
#include <iomanip>

#include "BoundaryCondition.h"

namespace FEMTests {

template<int dim>
class NeumannTypeBC : public BoundaryCondition<dim> {
public:
    NeumannTypeBC();

    double getGamma( int inDim = 0 ) const;

    double getQ( int inDim = 0 ) const;

    static NeumannTypeBC<dim> parseXmlString( bool &valid, tinyxml2::XMLElement *BoundaryNode );

    template<int T>
    friend std::ostream &operator<<( std::ostream &os, const NeumannTypeBC<T> &bc );

private:
    std::vector<double> mGamma;
    std::vector<double> mQ;
};

//***************************** FUNCTION DEFINITIONS ****************************************
template<int dim>
NeumannTypeBC<dim>::NeumannTypeBC() : mGamma( dim ), mQ( dim ) {}

template<int dim>
double NeumannTypeBC<dim>::getGamma( int inDim ) const {
    assert( inDim < dim );
    return mGamma[ inDim ];
}

template<int dim>
double NeumannTypeBC<dim>::getQ( int inDim ) const {
    assert( inDim < dim );
    return mQ[ inDim ];
}

template<int T>
std::ostream &operator<<( std::ostream &os, const NeumannTypeBC<T> &bc ) {
    os << "Neumann Type Boundary Condition:" << std::endl;
    os << std::setw( 10 ) << " Dim " << std::setw( 10 ) << "gamma" << std::setw( 10 ) << "q" << std::endl;
    for ( int ii = 0; ii < bc.getDim(); ii++ ) {
        os << std::setw( 10 ) << ii << " "
           << std::setw( 10 ) << bc.mGamma[ ii ] << " "
           << std::setw( 10 ) << bc.mQ[ ii ] << std::endl;
    }
    return os;
}

template<int dim>
NeumannTypeBC<dim> NeumannTypeBC<dim>::parseXmlString( bool &valid, tinyxml2::XMLElement *BoundaryNode ) {
    NeumannTypeBC<dim> bc;
    tinyxml2::XMLText *typeNode = BoundaryNode->FirstChildElement( "Type" )->FirstChild()->ToText();
    std::string type( typeNode->Value());

    valid = true;

    if ( type != "Neumann" ) {
        valid = false;
        return bc;
    }

    int dimension = BoundaryNode->FirstChildElement("Dim")->IntText();
    if ( dimension != dim ) {
        valid = false;
        return bc;
    }

    tinyxml2::XMLElement *currentNode = BoundaryNode->FirstChildElement( "gamma" );
    std::vector<double> gammaVec;
    for ( tinyxml2::XMLElement *valueNode = currentNode->FirstChildElement( "value" );
          valueNode != NULL; valueNode = valueNode->NextSiblingElement()) {
        double val = valueNode->DoubleText();
        gammaVec.push_back( val );
    }
    bc.mGamma = gammaVec;

    currentNode = BoundaryNode->FirstChildElement( "q" );
    std::vector<double> qVec;
    for ( tinyxml2::XMLElement *valueNode = currentNode->FirstChildElement( "value" );
          valueNode != NULL; valueNode = valueNode->NextSiblingElement()) {
        double val = valueNode->DoubleText();
        qVec.push_back( val );
    }
    bc.mQ = qVec;
    return bc;
}

} // namespace FEMTests
#endif //FEMTESTS_NEUMANNTYPEBC_H
