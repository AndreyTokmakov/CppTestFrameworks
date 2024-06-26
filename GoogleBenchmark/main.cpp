/**============================================================================
Name        : PerformanceGoogleBenchmark.cpp
Created on  : 28.09.2023
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : PerformanceGoogleBenchmark
============================================================================**/

#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

#include <benchmark/benchmark.h>


struct MyFixture : public benchmark::Fixture
{
    void SetUp(::benchmark::State& state) override {
    }

    void TearDown(::benchmark::State& state) override {
    }
};


static void BM_StringCreation(benchmark::State& state) {
    for (auto _ : state)
        std::string empty_string;
}

// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
static void BM_StringCopy(benchmark::State& state) {
    std::string x = "hello";
    for (auto _ : state)
        std::string copy(x);
}

BENCHMARK(BM_StringCopy);

BENCHMARK_MAIN();

