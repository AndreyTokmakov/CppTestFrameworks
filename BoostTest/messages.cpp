/**============================================================================
Name        : messages.cpp
Created on  : 06.09.2023
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : BoostTest messages tests
============================================================================**/


#include <boost/test/unit_test.hpp>

namespace
{
    struct TestFixture
    {
        TestFixture() : value {0} {
            // Put test initialization here, the constructor will be called prior to the execution of each test case.
            std::cout << "Initialize test" << std::endl;
        }

        ~TestFixture() {
            // Put test cleanup here, the destructor will automatically be invoked at the end of each test case.
            std::cout << "Cleanup test" << std::endl;
        }

        // Public test fixture variables are automatically available to all test cases.
        // Don’t forget to initialize these variables in the constructors to avoid initialized variable errors.
        int value {0};
    };
}

BOOST_FIXTURE_TEST_CASE(BoostCheckMessageTest, TestFixture)
{
    // Provide a test predicate (i.e. a conditional statement) that evaluates to
    // true to allow the test to pass and not will indicate a failed test with message.
    BOOST_CHECK_MESSAGE(true, "This should pass");

    // Provide a test predicate (i.e. a conditional statement) that evaluates to
    // false to force the test to fail and will indicate a test failure with message.
    BOOST_CHECK_MESSAGE(false, "This should fail");

    BOOST_TEST_MESSAGE( " * * ** no one sees this!" );
}