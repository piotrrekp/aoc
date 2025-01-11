cmake_minimum_required(VERSION 3.21)
project(AoC)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY})

add_executable(solution
	src/CSolution.cc
	src/main.cc
)

enable_testing()
find_package(GTest REQUIRED)

add_executable(unitTest
	src/CSolution.cc
	test/CSolutionTest.cc
)

target_link_libraries(unitTest
	GTest::gtest_main
	GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(unitTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
