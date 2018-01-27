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

#include <MatrixFillOneD.h>

namespace FEMTests {

std::vector<double> MatrixFillOneD::computeDiagonalElements( const OneDProblemFormulation &problem ) {
    std::vector<double> diagonalElements;

    diagonalElements.resize( problem.numElements );

    auto kii = [ &problem ]( int index ) {
        return problem.alpha[ index ] / problem.l[ index ] +
        problem.beta[ index ] * problem.l[ index ] / 3.0;
    };

    int currentElement = 0;
    diagonalElements[ currentElement ] = kii( currentElement );

    for ( currentElement = 1; currentElement < problem.numElements - 1; currentElement++ ) {
        diagonalElements[ currentElement ] = diagonalElements[ currentElement - 1 ] + kii( currentElement );
    }

    diagonalElements[ currentElement ] = kii( currentElement );

    return diagonalElements;
}

std::vector<double> MatrixFillOneD::computeOffDiagonalElements( const OneDProblemFormulation &problem ) {

    std::vector< double > offDiagonalElements;
    offDiagonalElements.resize( problem.numElements );

    auto kii = [ &problem ]( int index ) {
        return problem.alpha[ index ] / problem.l[ index ] +
               problem.beta[ index ] * problem.l[ index ] / 6.0;
    };

    for( int ii=0; ii<problem.numElements; ii++) {
        offDiagonalElements[ ii ] = kii(ii);
    }

    return offDiagonalElements;
}
} // namespace FEMTests
