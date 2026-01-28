cmake_minimum_required(VERSION 3.16)

project(ReviewCmake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(CoreLib
    src/lowercase.cpp
)
target_include_directories(CoreLib PUBLIC include)


add_executable(Main
    src/main.cpp
)
target_include_directories(Main PUBLIC include)
target_link_libraries(Main PRIVATE CoreLib)

# GoogleTest(FetchContent)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#Tests
enable_testing()
add_executable(CoreTest 
    tests/test.cpp    
)
target_include_directories(CoreTest PUBLIC include)
target_link_libraries(CoreTest PRIVATE CoreLib gtest_main)

include(GoogleTest)
gtest_discover_tests(CoreTest)