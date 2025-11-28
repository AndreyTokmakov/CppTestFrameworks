/**============================================================================
Name        : fixtures.cpp
Created on  : 16.04.2024
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : GoogleMock
============================================================================**/

#include <print>
#include <memory>

#include "Database.hpp"
#include "UserService.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::_;
using ::testing::Eq;
using ::testing::Return;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;
using ::testing::Truly;
using ::testing::AtLeast;

namespace
{
    struct MockDatabase final : public IDatabase
    {
        MOCK_METHOD(bool, storeUser, (const User&), (override));
        MOCK_METHOD(std::optional<User>, loadUser, (uint32_t), (override));
    };

    struct TestSuite: public ::testing::Test
    {
        std::shared_ptr<IDatabase> database { std::make_shared<MockDatabase>() };
        MockDatabase& dbMock { *(dynamic_cast<MockDatabase*>(database.get())) };

        void SetUp() override
        {
            ON_CALL(dbMock, storeUser(::testing::_)).WillByDefault(Return(true));
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }

        void TearDown() override
        {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
    };
}


TEST_F(TestSuite, Test_1)
{
    UserService userService { &dbMock };

    EXPECT_CALL(dbMock, storeUser(::testing::_)).Times(::testing::AtLeast(1));
    userService.createUser(0, "None");
}


TEST_F(TestSuite, Test_2)
{
    UserService userService { &dbMock };

    EXPECT_CALL(dbMock, storeUser(::testing::_)).Times(::testing::AtLeast(1));
    userService.createUser(0, "None");
}
