cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(GoogleMock_UserServiceSimple)
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")
set(PROJECT_VERSION 1.0.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

add_compile_options(-c -Wall -Wextra -O3 -std=c++26)

include(FetchContent)

# GoogleTest
FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# include all components
add_executable(${PROJECT_NAME}
        test_main.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${SERVICE_SRC_DIR})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        GTest::gtest_main
        GTest::gmock
        ${USER_SERVICE_LIB}
)
