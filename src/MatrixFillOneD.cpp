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

/**
 * \brief Formulas 3.48 - 3.50 in Jin, page 48
 * @param problem
 * @return
 */
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

/**
 * \brief Formula 3.51 in Jin, page 48
 * @param problem
 * @return
 */
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

/**
 * \brief Formulas 3.52 - 3.54 in Jin page 48
 * @param problem
 * @return
 */
Eigen::VectorXd MatrixFillOneD::computeSolutionVector( const OneDProblemFormulation &problem ) {
    Eigen::VectorXd b = Eigen::VectorXd::Constant( problem.numElements, 0.0 );

    auto bi = [ &problem ]( int index ) {
        return problem.f[ index ] * problem.l[ index ] / 2.0;
    };

    int currentIndex = 0;
    b[currentIndex] = bi(currentIndex);

    for( currentIndex = 1; currentIndex < problem.numElements - 1; currentIndex ++ ) {
        b[currentIndex] = b[currentIndex - 1] + b[currentIndex];
    }

    b[currentIndex] = bi(currentIndex);

    return b;
}
} // namespace FEMTests
