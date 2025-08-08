/**============================================================================
Name        : UserService.cpp
Created on  : 07.08.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : UserService.cpp
============================================================================**/

#include "UserService.hpp"
#include <print>

UserService::UserService(std::unique_ptr<IDatabase>&& dbImpl) : database { std::move(dbImpl) }{
}

bool UserService::createUser(const uint32_t id, const std::string& name)
{
    std::println("[UserService] Create User(id: {}, name: {})", id, name);
    return database->storeUser(User {.userId=id, .name= name});
}

std::optional<User> UserService::findUser(const uint32_t id)
{
    return database->loadUser(id);
}

