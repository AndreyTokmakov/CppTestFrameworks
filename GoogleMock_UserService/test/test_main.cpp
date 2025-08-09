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

using ::testing::Return;
using ::testing::Eq;


struct MockDatabase : public IDatabase
{
    MOCK_METHOD(bool, storeUser, (const User&), (override));
    MOCK_METHOD(std::optional<User>, loadUser, (uint32_t), (override));
};


TEST(UserServiceTests, VerifyDBMethodCall_StoreUser)
{
    std::shared_ptr<MockDatabase> database { std::make_shared<MockDatabase>() };
    UserService userService ( database );

    const User user { .userId=1, .name="Alice" };

    EXPECT_CALL(*database, storeUser(user)).WillOnce(Return(true));
    userService.createUser(1, "Alice");
}


TEST(UserServiceTests, VerifyDBMethodCall_LoadUser)
{
    std::shared_ptr<MockDatabase> database { std::make_shared<MockDatabase>() };
    UserService userService ( database );

    const uint32_t userId = 1;

    EXPECT_CALL(*database, loadUser(userId))
        .WillOnce(Return(std::make_optional<User>(userId, "Alice")));

    const std::optional<User> opUser = userService.findUser(userId);

    const User userExpected { .userId=userId, .name="Alice" };
    EXPECT_EQ(opUser.value(), userExpected);
}



