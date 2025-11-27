/**============================================================================
Name        : UserService.hpp
Created on  : 07.08.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : UserService.hpp
============================================================================**/

#ifndef CPPTESTFRAMEWORKS_USERSERVICE_HPP
#define CPPTESTFRAMEWORKS_USERSERVICE_HPP

#include <memory>
#include "IDatabase.hpp"
#include "IService.hpp"

struct UserService final : IService
{
    explicit UserService(IDatabase* dbImpl);

    bool createUser(uint32_t id, const std::string& name) override;
    std::optional<User> findUser(uint32_t id) override;

private:

    IDatabase* database { nullptr };
};

#endif //CPPTESTFRAMEWORKS_USERSERVICE_HPP
