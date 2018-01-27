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

#include <Utility/SampleProblem.h>

namespace FEMTests {

namespace samples {
static std::string OneDNeumannProblem (
"<?xml version=\"1.0\" encoding=\"ISO8859-1\" ?>"
"<ProblemData>"
"<Dim>1</Dim>"
"<Elements>5</Elements>"
"<alpha>"
"<value>0.1</value>"
"<value>0.2</value>"
"<value>0.3</value>"
"<value>0.4</value>"
"<value>0.5</value>"
"</alpha>"
"<beta>"
"<value>0.1</value>"
"<value>0.2</value>"
"<value>0.3</value>"
"<value>0.4</value>"
"<value>0.5</value>"
"</beta>"
"<f>"
"<value>0.1</value>"
"<value>0.2</value>"
"<value>0.3</value>"
"<value>0.4</value>"
"<value>0.5</value>"
"</f>"
"<l>"
"<value>0.1</value>"
"<value>0.2</value>"
"<value>0.3</value>"
"<value>0.4</value>"
"<value>0.5</value>"
"</l>"
"<BoundaryCondition>"
"<Type>Neumann</Type>"
"<Dim>1</Dim>"
"<gamma>"
"<value>0.1</value>"
"</gamma>"
"<q>"
"<value>0.1</value>"
"</q>"
"</BoundaryCondition>"
"<!--"
"<BoundaryCondition>"
"<Type>Dirichlet</Type>"
"<Dim>1</Dim>"
"<rho>"
"<value>0.1</value>"
"</rho>"
"</BoundaryCondition>"
"-->"
"</ProblemData>"
);
} // namespace samples

std::string SampleProblem::getOneDNuemannSampleAsString() {
    return samples::OneDNeumannProblem;
}

} // namespace FEMTests
