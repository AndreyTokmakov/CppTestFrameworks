/**============================================================================
Name        : IDatabase.hpp
Created on  : 07.08.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : UserService.hpp
============================================================================**/

#ifndef CPPTESTFRAMEWORKS_IDATABASE_HPP
#define CPPTESTFRAMEWORKS_IDATABASE_HPP

#include "User.hpp"
#include <optional>


struct IDatabase
{
    virtual ~IDatabase() = default;

    virtual bool storeUser(const User& user) = 0;
    virtual std::optional<User> loadUser(uint32_t id) = 0;
};

#endif //CPPTESTFRAMEWORKS_IDATABASE_HPP
