#include <iostream>
#include <Utility/SampleProblem.h>
#include "OneDProblemFormulation.h"
#include "MatrixFillOneD.h"
#include "KMatrixOneD.h"

#include <vector>

int main() {

    FEMTests::OneDProblemFormulation problem;
    problem.setFromXmlString( FEMTests::SampleProblem::getOneDNuemannSampleAsString() );

    std::cout << problem << std::endl;

    FEMTests::KMatrixOneD k( problem );
    k.computeMatrixFill();

    std::cout << k << std::endl;
    return 0;
}