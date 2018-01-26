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

#include "BoundryCondition.h"

namespace FEMTests {

template<int dim>
class NeumannTypeBC : public BoundryCondition<dim> {
public:
    NeumannTypeBC();

    double getGamma( int inDim = 0 ) const;

    double getQ( int inDim = 0 ) const;

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
    return mGamma[ dim ];
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

} // namespace FEMTests
#endif //FEMTESTS_NEUMANNTYPEBC_H
