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
// Created by Adam Blake on 1/26/2018.
//

#ifndef FEMTESTS_ONEDPROBLEMFORMULATION_H
#define FEMTESTS_ONEDPROBLEMFORMULATION_H


#include <BoundryCondition.h>

#include <vector>
#include <iostream>
#include <iomanip>

namespace FEMTests {
class OneDProblemFormulation {
public:
    int numElements;

    std::vector<double> alpha;
    std::vector<double> beta;
    std::vector<double> f;
    std::vector<double> l;

    BoundryCondition<1> boundryCondition;

    friend std::ostream &operator<<( std::ostream &os, const OneDProblemFormulation & );

    void setFromXmlString( std::string xmlData );
};

}


#endif //FEMTESTS_ONEDPROBLEMFORMULATION_H
