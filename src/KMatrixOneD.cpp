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
// Created by Adam Blake on 1/27/2018.
//

#include <KMatrixOneD.h>

namespace FEMTests {

KMatrixOneD::KMatrixOneD( const OneDProblemFormulation &problem ) : mProblem( problem ) {}

void KMatrixOneD::computeMatrixFill() {
    mDiagonalVector = MatrixFillOneD::computeDiagonalElements( mProblem );
    mOffDiagonalVector = MatrixFillOneD::computeOffDiagonalElements( mProblem );
    // TODO - off diagonal elements;
}

std::vector<double> KMatrixOneD::getDiagonalElements() {
    return mDiagonalVector;
}

std::ostream &operator<<( std::ostream &os, const KMatrixOneD &k ) {

    os << " K Matrix:" << std::endl;
    os << "*******************************************************************************" << std::endl;

    for( int row = 0; row < k.mProblem.numElements; row ++ ) {
        for( int column =  0; column < k.mProblem.numElements; column ++ ) {
            os << std::setw( 10 ) << k.getElement( row, column );
        }
        os << std::endl;
    }
    os << std::endl;

    return os;
}

double KMatrixOneD::getElement( int row, int column ) const {
    if( row == column ) {
        return mDiagonalVector[ row ];
    } else if ( row == column+1 ) {
        return mOffDiagonalVector[ row ];
    } else if( row + 1 == column ) {
        return mOffDiagonalVector[ column ];
    } else {
        return 0.0;
    };
}
} // namespace FEMTests
