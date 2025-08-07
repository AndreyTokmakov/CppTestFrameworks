/**============================================================================
Name        : user_service.cpp
Created on  : 07.08.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "user_service.hpp"

UserService::UserService(std::shared_ptr<IUserRepository> repo)
        : repository(std::move(repo)) {

}

std::string UserService::get_user_name(int id)
{
    return repository->get_user_by_id(id).and_then([](const User& usr) {
        return std::make_optional<std::string>(usr.name);
    }).value_or("Unknown");
}
