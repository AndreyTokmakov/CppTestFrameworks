/**============================================================================
Name        : user_repository.hpp
Created on  : 07.08.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#ifndef CPPTESTFRAMEWORKS_USER_REPOSITORY_HPP
#define CPPTESTFRAMEWORKS_USER_REPOSITORY_HPP

#include <string>
#include <optional>

struct User
{
    int id { 0 };
    std::string name;
};

struct IUserRepository
{
    virtual ~IUserRepository() = default;
    virtual std::optional<User> get_user_by_id(int id) = 0;
};


#endif //CPPTESTFRAMEWORKS_USER_REPOSITORY_HPP
