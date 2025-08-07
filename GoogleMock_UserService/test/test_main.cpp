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

/*
#include <gmock/gmock.h>

#include "user_service.hpp"


struct StubRepository : public IUserRepository
{
    std::optional<User> get_user_by_id(int id) override
    {
        return User { .id = id, .name = "John Dow" };
    }
};

class MockUserRepository : public IUserRepository {
public:
    MOCK_METHOD(std::optional<User>, get_user_by_id, (int), (override));
};
*/

TEST(SuiteOne, SimpleTest)
{
    std::unique_ptr<IDatabase> database { std::make_unique<Database>() };
    database->storeUser(User {.userId=12, .name= "Super"});

}
