/**============================================================================
Name        : User.hpp
Created on  : 07.08.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : User.hpp
============================================================================**/

#ifndef CPPTESTFRAMEWORKS_USER_HPP
#define CPPTESTFRAMEWORKS_USER_HPP

#include <cstdint>
#include <string>

struct User
{
    uint32_t userId { 0 };
    std::string name;

    friend auto operator<=>(const User&, const User&) = default;
};

#endif //CPPTESTFRAMEWORKS_USER_HPP
