/**============================================================================
Name        : test_main.cpp
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


struct MockDatabase final : public IDatabase
{
    MOCK_METHOD(bool, storeUser, (const User&), (override));
    MOCK_METHOD(std::optional<User>, loadUser, (uint32_t), (override));
};

TEST(UserServiceTests, VerifyDBMethodCall_StoreUser)
{
    std::shared_ptr<MockDatabase> database { std::make_shared<MockDatabase>() };
    MockDatabase& dbMock = *database;

    // ON_CALL(dbMock, storeUser(::testing::_)).WillByDefault(Return(false));
    ON_CALL(dbMock, storeUser(::testing::_)).WillByDefault(Return(true));

    UserService userService ( database.get() );

    const User user { .userId=1, .name="Alice" };

    // EXPECT_CALL(dbMock, storeUser(user)).WillOnce(Return(true));
    EXPECT_CALL(dbMock, storeUser(user)).Times(AtLeast(1));

    userService.createUser(1, "Alice");
}

TEST(UserServiceTests, VerifyDBMethodCall_StoreUser_CallLambda)
{
    std::shared_ptr<MockDatabase> database { std::make_shared<MockDatabase>() };
    MockDatabase& dbMock = *database;

    ON_CALL(dbMock, storeUser( User { .userId=0, .name="None" })).WillByDefault([] {
        std::println("Call lambda and return False");
        return false;
    });

    UserService userService ( database.get() );

    EXPECT_CALL(dbMock, storeUser(::testing::_)).Times(::testing::AtLeast(1));
    userService.createUser(0, "None");
}

TEST(UserServiceTests, VerifyDBMethodCall_LoadUser)
{
    std::shared_ptr<MockDatabase> database { std::make_shared<MockDatabase>() };
    UserService userService ( database.get() );

    const uint32_t userId = 1;

    EXPECT_CALL(*database, loadUser(userId))
        .WillOnce(Return(std::make_optional<User>(userId, "Alice")));

    const std::optional<User> opUser = userService.findUser(userId);

    const User userExpected { .userId=userId, .name="Alice" };
    EXPECT_EQ(opUser.value(), userExpected);
}

