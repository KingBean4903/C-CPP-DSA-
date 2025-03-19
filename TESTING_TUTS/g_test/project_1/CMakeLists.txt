cmake_minimum_required(VERSION 3.14)
project(project_1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/commit/6910c9d9165801d8827d628cb72eb7ea9dd538c5
)

enable_testing()

add_executable(
	hello_test
	hello_test.cc
)

target_link_libraries(
	hello_test
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)
