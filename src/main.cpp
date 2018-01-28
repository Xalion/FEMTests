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

    FEMTests::KMatrixOneD kM( problem );
    kM.computeMatrixFill();
    std::cout << kM << std::endl;

    Eigen::VectorXd b = FEMTests::MatrixFillOneD::computeSolutionVector( problem );
    Eigen::MatrixXd k = kM.getMatrix();

    Eigen::VectorXd x = k.colPivHouseholderQr().solve( b );

    std::cout << x << std::endl;
    return 0;
}