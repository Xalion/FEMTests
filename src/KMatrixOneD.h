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

#ifndef FEMTESTS_KMATRIXONED
#define FEMTESTS_KMATRIXONED

#include <OneDProblemFormulation.h>
#include <MatrixFillOneD.h>

#include <Eigen/Dense>
#include <KMatrix.h>

namespace FEMTests {

class KMatrixOneD : public KMatrix {
public:
    KMatrixOneD( const OneDProblemFormulation &problem );

    void computeMatrixFill();

    friend std::ostream &operator<<( std::ostream &os, const KMatrixOneD &k );

    double getElement( const int row, const int column ) const override;

    void setElement( const int row, const int column, double val ) override;

    int elementCount() override;

    Eigen::MatrixXd& getMatrix();
private:
    Eigen::MatrixXd mMatrix;
    const OneDProblemFormulation mProblem;
};


} // namespace FEMTests
#endif //FEMTESTS_KMATRIXONED
