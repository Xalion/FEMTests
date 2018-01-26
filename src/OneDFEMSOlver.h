/*********************************************************************************************************************
* Author: Adam Blake (adamb@quantumbear.com)
* Copyright 2018 Adam Blake
*
*
* This file is part of FEMTest.
*
* FEMTest is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* FEMTest is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with FEMTest.  If not, see <http://www.gnu.org/licenses/>.
**********************************************************************************************************************/

#ifndef FEMTESTS_ONEDFEMSOLVER_H
#define FEMTESTS_ONEDFEMSOLVER_H

#include "OneDProblemFormulation.h"

namespace FEMTests {

/**
 * \brief One Dimensional FEM solver based on Excercise 3.2 from Jian-Ming Jin's
 * "The Finite Element Method in Electromagnetics"
 */
class OneDFEMSOlver {
public:
    OneDFEMSOlver( OneDProblemFormulation problem ) : mProblem( problem ) {};

private:
    OneDProblemFormulation mProblem;
};

}


#endif //FEMTESTS_ONEDFEMSOLVER_H
