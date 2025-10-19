cmake_minimum_required(VERSION 3.14)
project(TwelveProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0") 

add_library(figure_lib
    src/figure_vector.cpp
    src/hexagon.cpp
    src/octagon.cpp
    src/triangle.cpp
)

target_include_directories(figure_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(figure
    src/main.cpp
)

target_link_libraries(figure
    PRIVATE
    figure_lib
)

target_include_directories(figure
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

add_executable(figure_test
    test/figure_test.cpp
)

target_link_libraries(figure_test
    PRIVATE
    figure_lib
    GTest::gtest_main
)

target_include_directories(figure_test
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(GoogleTest)
gtest_discover_tests(figure_test)