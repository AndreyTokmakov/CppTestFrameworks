cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(Catch2Tests)
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -pthread")
set(PROJECT_VERSION 1.0.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

add_compile_options(-c -Wall -Wextra -O3 -std=c++26)

include_directories(${THIRD_PARTY_DIR}/Catch2/src)
include_directories(${THIRD_PARTY_DIR}/Catch2/build/generated-includes)
link_directories(${THIRD_PARTY_DIR}/Catch2/build/src)

# include all components
add_executable(${PROJECT_NAME}
        main.cpp
        factorial_tests.cpp test_sections_1.cpp
        matchers.cpp
        asserts.cpp
        test_controller.h
)

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        pthread
        libCatch2.a
)