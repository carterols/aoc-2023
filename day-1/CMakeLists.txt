cmake_minimum_required(VERSION 3.24)
project(aoc-2023-1 LANGUAGES CXX)

add_executable(day1)
target_sources(day1 PRIVATE
    "main.cpp"
)
target_compile_features(day1 PUBLIC cxx_std_23)

