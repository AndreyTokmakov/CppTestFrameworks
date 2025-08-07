cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(${USER_SERVICE_LIB})
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -pthread")
set(PROJECT_VERSION 1.0.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

add_compile_options(-c -Wall -Werror -Wextra -O3 -std=c++26)


add_library(${USER_SERVICE_LIB}
        IDatabase.hpp
        IService.hpp
        User.hpp
        Database.cpp Database.hpp
        UserService.cpp UserService.hpp
)

target_include_directories(${USER_SERVICE_LIB} PUBLIC src)