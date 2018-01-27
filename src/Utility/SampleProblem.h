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

#ifndef FEMTESTS_SAMPLEPROBLEM_H
#define FEMTESTS_SAMPLEPROBLEM_H

#include <string>

namespace FEMTests {


class SampleProblem {
public:
    static std::string getOneDNuemannSampleAsString();
};


} // namespace FEMTests
#endif //FEMTESTS_SAMPLEPROBLEM_H