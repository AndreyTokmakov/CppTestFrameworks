cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(GoogleMock)
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")
set(PROJECT_VERSION 1.0.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

add_compile_options(-c -Wall -Wextra -O3 -std=c++26)

find_package(GTest REQUIRED)
find_package(GMock REQUIRED)
include_directories(${GMOCK_INCLUDE_DIRS})

# include all components
add_executable(${PROJECT_NAME}
        main.cpp
)

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        ${GMOCK_BOTH_LIBRARIES}
        tbb -lbenchmark -lpthread
)
