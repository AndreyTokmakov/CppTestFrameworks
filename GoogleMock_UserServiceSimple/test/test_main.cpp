/**============================================================================
Name        : test_main.cpp
Created on  : 16.04.2024
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : GoogleMock
============================================================================**/

#include <cmath>
#include <print>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "user_service.hpp"

/*
class Turtle
{
    virtual ~Turtle() = default;

    virtual void PenUp() = 0;
    virtual void PenDown() = 0;
    virtual void Forward(int distance) = 0;
    virtual void Turn(int degrees) = 0;
    virtual void GoTo(int x, int y) = 0;
    virtual int GetX() const = 0;
    virtual int GetY() const = 0;
};


class MockTurtle : public Turtle {
public:
    MOCK_METHOD(void, PenUp, (), (override));
    MOCK_METHOD(void, PenDown, (), (override));
    MOCK_METHOD(void, Forward, (int distance), (override));
    MOCK_METHOD(void, Turn, (int degrees), (override));
    MOCK_METHOD(void, GoTo, (int x, int y), (override));
    MOCK_METHOD(int, GetX, (), (const, override));
    MOCK_METHOD(int, GetY, (), (const, override));
};

class MockUserRepository : public IUserRepository {
public:
    MOCK_METHOD(std::optional<User>, get_user_by_id, (int), (override));
};



*/


struct StubRepository : public IUserRepository
{
    std::optional<User> get_user_by_id(int id) override
    {
        return User { .id = id, .name = "John Dow" };
    }
};

TEST(SuiteOne, SimpleTest)
{
    std::shared_ptr<IUserRepository> repository { std::make_shared<StubRepository>() };
    UserService service { repository };

    const std::string name = service.get_user_name(12);
    std::println("User: {}", name);
}
