//============================================================================
// Name        : main.cpp
// Created on  : 17.08.2021
// Author      : Tokmakov Andrey
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : C++ Boost Project
//============================================================================

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MyTest


#include <iostream>
#include <memory>
#include <algorithm>

#include <thread>
#include <future>

#include <vector>
#include <algorithm>
#include <array>
#include <set>
#include <string>
#include <string_view>
#include <mutex>
#include <atomic>
#include <numeric>
#include <iomanip>


#include <boost/version.hpp>
#include <boost/test/unit_test.hpp>

namespace Utilites
{
    void PrintBoostVersion()
    {
        std::cout << "Using Boost " << BOOST_VERSION / 100000     << "."  // major version
                << BOOST_VERSION / 100 % 1000 << "."  // minor version
                << BOOST_VERSION % 100                // patch level
                << std::endl;
    }

    /** Just to print version at the startup: **/
    const static int dummy = []() {
        PrintBoostVersion();
        return 0;
    }();
}

class Calculator
{
public:
    explicit Calculator(int val) : value {val} {
    }

    void Divide(int val)
    {
        if (val == 0)
        {
            throw std::invalid_argument("Zero devistion");
        }
        value /= val;
    }

    void Multiply(int val)
    {
        value *= val;
    }

    [[nodiscard]]
    int Result() const
    {
        return value;
    }

private:
    int value {0};
};


struct Fixture
{
    Fixture(): calculator(12) {
        // Here the test object can be configured
    }

    // And here it is correct to finish working with it
    ~Fixture() = default;

    /** And here is the test object itself **/
    Calculator calculator;
};


BOOST_AUTO_TEST_CASE(MyTestCase)
{
    // To simplify this example test, let's suppose we'll test 'float'.
    // Some test are stupid, but all should pass.
    float x = 9.5f;

    BOOST_CHECK(x != 0.0f);
    BOOST_CHECK_EQUAL((int)x, 9);
    BOOST_CHECK_CLOSE(x, 9.5f, 0.0001f); // Checks differ no more then 0.0001%
}

BOOST_AUTO_TEST_CASE(testCalculator)
{
    Calculator calculator(12);
    BOOST_CHECK_EQUAL(calculator.Result(), 12);
}

BOOST_AUTO_TEST_CASE(testCalculatorDivide)
{
    Calculator calculator(12);
    calculator.Divide(3);
    BOOST_CHECK_EQUAL(calculator.Result(), 4);
    calculator.Divide(2);
    BOOST_CHECK_EQUAL(calculator.Result(), 2);
}

BOOST_AUTO_TEST_CASE(testCalculatorMultiply)
{
    Calculator calculator(12);
    calculator.Multiply(2);
    BOOST_CHECK_EQUAL(calculator.Result(), 24);
    calculator.Multiply(3);
    BOOST_CHECK_EQUAL(calculator.Result(), 72);
}

BOOST_FIXTURE_TEST_CASE(testCalculatorWithFixture, Fixture)
{
    BOOST_CHECK_EQUAL(calculator.Result(), 12);
}

BOOST_FIXTURE_TEST_CASE(testCalculatorDivideWithFixture, Fixture)
{
    calculator.Divide(3);
    BOOST_CHECK_EQUAL(calculator.Result(), 4);
    calculator.Divide(2);
    BOOST_CHECK_EQUAL(calculator.Result(), 2);
}

BOOST_FIXTURE_TEST_CASE(testCalculatorMultiplyWithFixture, Fixture)
{
    calculator.Multiply(2);
    BOOST_CHECK_EQUAL(calculator.Result(), 24);
    calculator.Multiply(3);
    BOOST_CHECK_EQUAL(calculator.Result(), 72);
}