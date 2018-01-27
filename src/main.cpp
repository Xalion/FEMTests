#include <iostream>
#include <Utility/SampleProblem.h>
#include "OneDProblemFormulation.h"

int main() {

    FEMTests::OneDProblemFormulation problem;
    problem.setFromXmlString( FEMTests::SampleProblem::getOneDNuemannSampleAsString() );

    std::cout << problem << std::endl;
    return 0;
}