cmake_minimum_required(VERSION 3.21)
project(AoC)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY})

find_package(Threads REQUIRED)

add_executable(solution
	src/CSolution.cc
	src/main.cc
)

target_link_libraries(solution
	Threads::Threads
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


