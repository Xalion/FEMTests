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

#ifndef FEMTESTS_ONEDBOUNDRYCONDITION_H
#define FEMTESTS_ONEDBOUNDRYCONDITION_H

#include <tinyxml2.h>

#include <iostream>

namespace FEMTests {

template< int dim >
class BoundryCondition
{
public:

    int getDim() const;

    // Make one of these for parsing.
    // static BoundryCondition parseXmlString( bool &valid, tinyxml2::XMLText* boundryNode ) = 0;

    // TODO : write XML type.  Not necissary right off.
private:

};

template<int dim>
int BoundryCondition<dim>::getDim() const { return dim; }

}



#endif //FEMTESTS_ONEDBOUNDRYCONDITION_H
