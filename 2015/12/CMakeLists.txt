cmake_minimum_required(VERSION 3.21)
project(AoC)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable(solution
	src/CSolution.cc
	src/main.cc
)

target_link_libraries(solution
	nlohmann_json::nlohmann_json
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
	nlohmann_json::nlohmann_json
)

add_custom_target(
	symlink-compile-commands ALL
	COMMAND ${CMAKE_COMMAND} -E create_symlink
	${CMAKE_BINARY_DIR}/compile_commands.json
	${CMAKE_SOURCE_DIR}/compile_commands.json
)

include(GoogleTest)
gtest_discover_tests(unitTest)

target_compile_options(unitTest PRIVATE -fsanitize=address -g)
target_link_options(unitTest PRIVATE -fsanitize=address)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall")
