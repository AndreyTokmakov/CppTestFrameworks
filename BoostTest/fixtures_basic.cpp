/**============================================================================
Name        : fixtures_basic.cpp
Created on  : 05.09.2023
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : fixtures_basic
============================================================================**/

#include <boost/test/unit_test.hpp>

namespace
{
    struct TestFixture
    {
        // Public test fixture variables are automatically available to all test cases.
        // Don’t forget to initialize these variables in the constructors to avoid initialized variable errors.
        int value {0};

        TestFixture() : value {0} {
            // Put test initialization here, the constructor will be called prior to the execution of each test case.
            std::cout << "Initialize test" << std::endl;
        }

        ~TestFixture() {
            // Put test cleanup here, the destructor will automatically be invoked at the end of each test case.
            std::cout << "Cleanup test" << std::endl;
        }
    };
}

BOOST_AUTO_TEST_SUITE(FixtureBasicTests)

BOOST_AUTO_TEST_CASE(test_case_1)
{
    TestFixture fixture;
    BOOST_CHECK_EQUAL(fixture.value, 0);
}

BOOST_FIXTURE_TEST_CASE(test_fixture_1, TestFixture)
{
    BOOST_CHECK_EQUAL(value, 0);
}

BOOST_FIXTURE_TEST_CASE(test_fixture_to_fail, TestFixture)
{
    BOOST_CHECK_EQUAL(value, 1);
}

BOOST_AUTO_TEST_SUITE_END()