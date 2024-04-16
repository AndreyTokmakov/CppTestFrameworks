/**============================================================================
Name        : warnings.cpp
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

// Define a test case. The first argument specifies the name of the test.
// Take some care in naming your tests. Do not reuse names or accidentally use
// the same name for a test as specified for the module test suite name.
//
// The second argument provides a test build-up/tear-down object that is
// responsible for creating and destroying any resources needed by the
// unit test
BOOST_FIXTURE_TEST_CASE(BoostWarnTest, TestFixture)
{
    // Provide a test predicate (i.e. a conditional statement) that evaluates
    // to true to allow the test to pass and will not issue a warning.
    BOOST_WARN(true);

    // Provide a test predicate (i.e. a conditional statement) that evaluates
    // to false to force the test to fail and will issue a warning.
    BOOST_WARN(false);
}


BOOST_FIXTURE_TEST_CASE(BoostWarnThrowTest, TestFixture)
{
    // Provide a statement that is expected to throw with a specific exception.
    // Provide the expected exception as the second argument. Since the
    // exception types match, the test will pass and will not issue a warning.

    BOOST_WARN_THROW( throw std::range_error("This should pass"), std::range_error);

    // Provide a statement that is expected to throw with a specific exception.
    // Provide the expected exception as the second argument. Since the
    // exception types do not match, the test will not pass and will issue a warning.

    BOOST_WARN_THROW(throw std::range_error("This should fail"), std::underflow_error);
}