/**============================================================================
Name        : user_service.hpp
Created on  : 07.08.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#ifndef CPPTESTFRAMEWORKS_USER_SERVICE_HPP
#define CPPTESTFRAMEWORKS_USER_SERVICE_HPP

#include "user_repository.hpp"
#include <string>
#include <memory>

struct UserService
{
    explicit UserService(std::shared_ptr<IUserRepository> repo);
    std::string get_user_name(int id);

private:
    std::shared_ptr<IUserRepository> repository;
};

#endif //CPPTESTFRAMEWORKS_USER_SERVICE_HPP
