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

#include "OneDProblemFormulation.h"
#include "BCReader.h"

#include <tinyxml2.h>

namespace FEMTests {

std::ostream &operator<<( std::ostream &os, const OneDProblemFormulation &odpf ) {
    os << "Problem Data: " << std::endl;
    os << "*****************************************************************************************" << std::endl;
    os << "Number of Elements: " << odpf.numElements << std::endl;
    os << std::setw( 10 ) << "element"
       << std::setw( 10 ) << "alpha"
       << std::setw( 10 ) << "beta"
       << std::setw( 10 ) << "f"
       << std::setw( 10 ) << "l" << std::endl;
    for ( int iElement = 0; iElement < odpf.numElements; iElement++ ) {
        os << std::setw( 10 ) << iElement
           << std::setw( 10 ) << odpf.alpha[ iElement ]
           << std::setw( 10 ) << odpf.beta[ iElement ]
           << std::setw( 10 ) << odpf.f[ iElement ]
           << std::setw( 10 ) << odpf.l[ iElement ] << std::endl;

    }
    return os;
}

OneDProblemFormulation::err_t OneDProblemFormulation::setFromXmlString( std::string xmlData ) {

    tinyxml2::XMLDocument document;
    document.Parse( xmlData.c_str());

    tinyxml2::XMLElement *problemData = document.FirstChildElement( "ProblemData" );
    int dimension = problemData->FirstChildElement( "Dim" )->IntText();
    if ( dimension != 1 ) {
        return -1;
    }
    int elements = problemData->FirstChildElement( "Elements" )->IntText();
    numElements = elements;

    std::vector<double> alphaVec;
    tinyxml2::XMLElement *currentNode = problemData->FirstChildElement( "alpha" );
    for ( tinyxml2::XMLElement *valueNode = currentNode->FirstChildElement( "value" );
          valueNode != NULL; valueNode = valueNode->NextSiblingElement()) {
        double val = valueNode->DoubleText();
        alphaVec.push_back( val );
    }
    alpha = alphaVec;

    std::vector<double> betaVec;
    currentNode = problemData->FirstChildElement( "alpha" );
    for ( tinyxml2::XMLElement *valueNode = currentNode->FirstChildElement( "value" );
          valueNode != NULL; valueNode = valueNode->NextSiblingElement()) {
        double val = valueNode->DoubleText();
        betaVec.push_back( val );
    }
    beta = betaVec;

    std::vector<double> fVec;
    currentNode = problemData->FirstChildElement( "alpha" );
    for ( tinyxml2::XMLElement *valueNode = currentNode->FirstChildElement( "value" );
          valueNode != NULL; valueNode = valueNode->NextSiblingElement()) {
        double val = valueNode->DoubleText();
        fVec.push_back( val );
    }
    f = fVec;

    std::vector<double> lVec;
    currentNode = problemData->FirstChildElement( "alpha" );
    for ( tinyxml2::XMLElement *valueNode = currentNode->FirstChildElement( "value" );
          valueNode != NULL; valueNode = valueNode->NextSiblingElement()) {
        double val = valueNode->DoubleText();
        lVec.push_back( val );
    }
    l = lVec;

    if ( alphaVec.size() != elements || betaVec.size() != elements || fVec.size() != numElements ||
         lVec.size() != numElements ) {
        return -1;
    }

    BCReader reader;
    tinyxml2::XMLElement *bcElement;
    bool foundNeumann = false, foundDirichlet = false;
    std::shared_ptr<NeumannTypeBC<1> > neumannBC;
    std::shared_ptr<DirichletTypeBC<1> > dirichletBC;

    auto tryAndMaybeSetNeumann = [ & ]() {
        if ( !foundNeumann ) {
            neumannBC = reader.tryReader<NeumannTypeBC<1> >( foundNeumann, bcElement );
            if ( foundNeumann ) {
                endNodeBG = neumannBC;
            }
        }
    };

    auto tryAndMaybeSetDirichlet = [ & ]() {
        if ( !foundDirichlet ) {
            dirichletBC = reader.tryReader<DirichletTypeBC<1> >( foundDirichlet, bcElement );
            if ( foundDirichlet ) {
                startNode = dirichletBC;
            }
        }
    };

    for( bcElement = problemData->FirstChildElement( "BoundaryCondition");
            bcElement != NULL; bcElement = bcElement->NextSiblingElement() ) {
        tryAndMaybeSetDirichlet();
        tryAndMaybeSetNeumann();
    }

    if ( !foundNeumann || !foundDirichlet ) {
        return -1;
    }
    return 0;
}

bool OneDProblemFormulation::isEdgeElement( int elementIndex ) {
    return elementIndex == 0 || elementIndex == ( numElements - 1 );
}
}