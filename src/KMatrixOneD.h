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

#ifndef FEMTESTS_KMATRIX_H
#define FEMTESTS_KMATRIX_H

#include <OneDProblemFormulation.h>
#include <MatrixFillOneD.h>

namespace FEMTests {

class KMatrixOneD {
public:
    KMatrixOneD( const OneDProblemFormulation& problem );

    void computeMatrixFill();

    std::vector< double > getDiagonalElements();

    friend std::ostream &operator<<( std::ostream &os, const KMatrixOneD &k );

    double getElement( int row, int column ) const;

private:
    const OneDProblemFormulation mProblem;
    std::vector< double > mDiagonalVector;
    std::vector< double > mOffDiagonalVector;
};


} // namespace FEMTests
#endif //FEMTESTS_KMATRIX_H
