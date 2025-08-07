/**============================================================================
Name        : Database.hpp
Created on  : 07.08.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : Database.hpp
============================================================================**/

#ifndef CPPTESTFRAMEWORKS_DATABASE_HPP
#define CPPTESTFRAMEWORKS_DATABASE_HPP

#include "IDatabase.hpp"

struct Database: public IDatabase
{
    bool storeUser(const User& user) override;
    std::optional<User> loadUser(uint32_t id) override;
};

#endif //CPPTESTFRAMEWORKS_DATABASE_HPP
