/**============================================================================
Name        : IService.hpp
Created on  : 07.08.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : UserService.hpp
============================================================================**/

#ifndef CPPTESTFRAMEWORKS_ISERVICE_HPP
#define CPPTESTFRAMEWORKS_ISERVICE_HPP

#include <optional>

#include "User.hpp"

struct IService
{
    virtual ~IService() = default;

    virtual bool createUser(uint32_t id, const std::string& name) = 0;
    virtual std::optional<User> findUser(uint32_t id) = 0;
};

#endif //CPPTESTFRAMEWORKS_ISERVICE_HPP
