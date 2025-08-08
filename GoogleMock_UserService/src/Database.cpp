/**============================================================================
Name        : Database.cpp
Created on  : 07.08.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : Database.cpp
============================================================================**/

#include "Database.hpp"
#include <print>

bool Database::storeUser(const User& user)
{
    std::println("[Database] Store User(id: {}, name: {})", user.userId, user.name);
    return true;
}

std::optional<User> Database::loadUser(uint32_t id)
{
    return std::make_optional<User>(id, "User-" + std::to_string(id));
}
