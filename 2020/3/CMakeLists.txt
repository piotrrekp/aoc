cmake_minimum_required(VERSION 3.21)
project(AoC_2020_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(solution src/main.cc)

find_package(GTest REQUIRED)
target_link_libraries(solution GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(solution)

target_compile_options(solution PRIVATE -Wall -Wextra -Werror -fsanitize=address -g)
target_link_options(solution PRIVATE -fsanitize=address)

