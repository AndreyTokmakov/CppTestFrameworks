cmake_minimum_required(VERSION 3.21)
project(CppTestFrameworks)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(BoostTest)
add_subdirectory(Catch2Tests)
add_subdirectory(GoogleBenchmark)
add_subdirectory(GoogleTests)
