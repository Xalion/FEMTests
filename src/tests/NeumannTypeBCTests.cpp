//
// Created by Adam Blake on 1/26/2018.
//

#include <gtest/gtest.h>
#include <DirichletTypeBC.h>
#include <NeumannTypeBC.h>

namespace FEMTests {
namespace tests {

std::string sXmlBcData (
"<BoundryCondition>"
"   <Type>Neumann</Type>"
"   <Dim>1</Dim>"
"   <gamma>"
"       <value>0.1</value>"
"   </gamma>"
"   <q>"
"       <value>0.1</value>"
"   </q>"
"</BoundryCondition>"
);

TEST( DirichletTypeBCTests, testFromXML ) {

    tinyxml2::XMLDocument doc;
    doc.SetValue( sXmlBcData.c_str() );
    tinyxml2::XMLElement *xmlElement = doc.FirstChild()->ToElement();

    bool isValid = false;

    NeumannTypeBC<1> bc = NeumannTypeBC<1>::parseXmlString(isValid, xmlElement);

    ASSERT_TRUE( isValid ) << "isValid returned false.";
    ASSERT_EQ( 1, bc.getDim() ) << "getDim returned the wrong value.";
    ASSERT_EQ( 0.1, bc.getGamma( 0 ) ) << "getGamma returned the wrong value";
    ASSERT_EQ( 0.1, bc.getQ( 0 ) ) << "getQ returned the wrong value.";
}

}
}