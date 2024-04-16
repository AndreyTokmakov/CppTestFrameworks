/**============================================================================
Name        : handle_exceptions.cpp
Created on  : 05.09.2023
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : handle_exceptions.cpp
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

BOOST_FIXTURE_TEST_CASE(BoostWarnNoThrowTest, TestFixture)
{
    // Provide a statement that is not expected to throw. If the statement
    // does not throw, the test will pass and not issue a warning.
    BOOST_WARN_NO_THROW(value = 1);

    // Provide a statement that is expected to not throw. If the statement
    // does throw, the test will fail and issue a warning.
    BOOST_WARN_NO_THROW(throw std::range_error("This should fail"));
}


BOOST_FIXTURE_TEST_CASE(BoostCheckNoThrowTest, TestFixture)
{
    // Provide a statement that is not expected to throw. If the statement
    // does not throw, the test will pass and not issue a test failure.
    BOOST_CHECK_NO_THROW(value = 2);

    // Provide a statement that is expected to not throw. If the statement
    // does throw, the test will fail and issue a test failure.
    BOOST_CHECK_NO_THROW( throw std::range_error("this should fail"));
}


BOOST_FIXTURE_TEST_CASE(BoostRequireNoThrowTest, TestFixture)
{
    // Provide a statement that is not expected to throw. If the statement
    // does not throw, the test will pass and not issue a test failure.
    BOOST_REQUIRE_NO_THROW(value = 3);

    // Provide a statement that is expected to not throw. If the statement
    // does throw, the test will fail and issue a test failure.
    BOOST_REQUIRE_NO_THROW(throw std::range_error("This should fail"));
}