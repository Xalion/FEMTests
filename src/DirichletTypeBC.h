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

#include <BoundaryCondition.h>

#include <vector>
#include <cassert>
#include <iomanip>
#include <memory>

namespace FEMTests {

template<int dim>
class DirichletTypeBC : public BoundaryCondition<dim> {
public:

    DirichletTypeBC();

    double getRho( int inDim = 0 ) const;

    template<int T>
    friend std::ostream &operator<<( std::ostream &os, const DirichletTypeBC<T> &bc );

    void applyBoundaryCondition( KMatrix &k );

    void applyBoundaryCondition( Eigen::VectorXd &b, KMatrix &k ) override;

    static std::shared_ptr< DirichletTypeBC<1> > parseXmlString( bool &valid, tinyxml2::XMLElement *BoundaryNode );

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
std::shared_ptr< DirichletTypeBC<1> > DirichletTypeBC<dim>::parseXmlString( bool &valid,
                                                         tinyxml2::XMLElement *BoundaryNode ) {
    std::shared_ptr<DirichletTypeBC<dim> > bc = std::make_shared<DirichletTypeBC<dim> >();

    tinyxml2::XMLText *typeNode = BoundaryNode->FirstChildElement( "Type" )->FirstChild()->ToText();
    std::string type( typeNode->Value());
    valid = true;
    if ( type != "Dirichlet" ) {
        valid = false;
        return bc;
    }

    int dimension = BoundaryNode->FirstChildElement( "Dim" )->IntText();
    if ( dimension != dim ) {
        valid = false;
        return bc;
    }

    tinyxml2::XMLElement *currentNode = BoundaryNode->FirstChildElement( "rho" );
    std::vector<double> rhoVec;
    for ( tinyxml2::XMLElement *valueNode = currentNode->FirstChildElement( "value" );
          valueNode != NULL; valueNode = valueNode->NextSiblingElement()) {
        double val = valueNode->DoubleText();
        rhoVec.push_back( val );
    }
    bc->mRho = rhoVec;
    return bc;
}

/**
 * \brief Formula 3.60 and 3.63 in Jin on page 49.
 *
 * Right now this is 1D only.  Need to update it for other dimensions.
 * @tparam dim
 * @param k
 */
template<int dim>
void DirichletTypeBC<dim>::applyBoundaryCondition( KMatrix &k ) {
    if ( dim == 1 ) {

        k.setElement( 0, 0, 1.0 ); // K_11 = 1
        // K_1j = 0, K_j1 = 0
        for ( int ii = 1; ii < k.elementCount(); ii++ ) {
            k.setElement( 0, ii, 0.0 );
            k.setElement( ii, 0, 0.0 );
        }
    } else {
        assert( "write me" );
    }
}

template<int dim>
void DirichletTypeBC<dim>::applyBoundaryCondition( Eigen::VectorXd &b, KMatrix &k ) {
    applyBoundaryCondition( k );
    if ( dim == 1 ) {
        b( 0 ) = getRho( 0 ); // 3.60 pp 49
        // 3.63 pp 49
        for ( int ii = 1; ii < b.size(); ii++ ) {
            b( ii ) = b( ii ) - k.getElement( ii, 0 ) * getRho( 0 );
        }
    }
}

}


#endif //FEMTESTS_DIRICHLETTYPEBC_H
