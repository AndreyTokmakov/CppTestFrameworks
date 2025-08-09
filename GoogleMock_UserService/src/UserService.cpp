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

UserService::UserService(const std::shared_ptr<IDatabase>& dbImpl) : database { dbImpl }{
}

bool UserService::createUser(const uint32_t id, const std::string& name)
{
    const User user { .userId=id, .name= name };
    std::println("[UserService] Create User(id: {}, name: {})", id, name);
    return database->storeUser(user);
}

std::optional<User> UserService::findUser(const uint32_t id)
{
    std::println("[UserService] Find User (id: {})", id);
    return database->loadUser(id);
}

