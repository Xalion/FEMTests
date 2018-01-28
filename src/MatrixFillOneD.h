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

#ifndef FEMTESTS_MATRIXFILL_H
#define FEMTESTS_MATRIXFILL_H

#include <OneDProblemFormulation.h>

#include <vector>

namespace FEMTests {


class MatrixFillOneD {
public:
    /**
     * \brief Compute the diagonal elements for the k matrix.  These are the elements k_i,i
     *
     * @param problem
     * @return
     */
    static std::vector<double> computeDiagonalElements( const OneDProblemFormulation &problem );

    /**
     * \brief Compute the off diagonal elements for the matrix.  Note that for a 1D matrix like this, there
     * are only 2 values per row that are off diagonal, and they are equal.  So this just returns a vector of k
     * where k satisfies:
     *  k_i+1, i = k_i, i+1
     * and
     *  returnVec[ i ] = k_i+1, i
     *
     * @param problem
     * @return
     */
    static std::vector<double> computeOffDiagonalElements( const OneDProblemFormulation &problem );

    static Eigen::VectorXd computeSolutionVector( const OneDProblemFormulation &problem );
};


} // namespace FEMTests
#endif //FEMTESTS_MATRIXFILL_H
