cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(TestCoverage)
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -pthread")
set(PROJECT_VERSION 1.0.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

include(CTest)

add_compile_options(-c -Wall -Wextra -O3 -std=c++26 -fprofile-arcs -ftest-coverage -coverage)

add_executable(${PROJECT_NAME}
        main.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE -coverage)
target_link_options(${PROJECT_NAME} PRIVATE -coverage)

target_link_libraries(${PROJECT_NAME}
        pthread
        gcov
        ${EXTRA_LIBS}
)

add_test(NAME coverage_test333 COMMAND ${PROJECT_NAME})