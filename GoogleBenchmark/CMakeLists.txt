cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(GoogleBenchmark)
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")
set(PROJECT_VERSION 1.0.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

add_compile_options(-c -Wall -Wextra -O3 -std=c++26)

include_directories(${THIRD_PARTY_DIR}/benchmark/include)
link_directories(${THIRD_PARTY_DIR}/benchmark/build/lib)
link_directories(${THIRD_PARTY_DIR}/benchmark/build/src)

message(${THIRD_PARTY_DIR}/benchmark/build/lib)
message(${THIRD_PARTY_DIR}/benchmark/build/src)

# find_package(benchmark REQUIRED)

# include all components
add_executable(${PROJECT_NAME}
    main.cpp
)

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        # tbb
        benchmark
        pthread
)
