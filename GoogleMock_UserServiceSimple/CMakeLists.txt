cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(GoogleMock_UserServiceSimple)
set(PROJECT_VERSION 1.0.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
add_compile_options(-c -Wall -Werror -Wextra -O3 -std=c++26)

set(USER_SERVICE_LIB libuser_service_lib)
set(SERVICE_SRC_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(test)