cmake_minimum_required(VERSION 3.14)
project(my_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Используй современную версию Google Test
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Основная программа
add_executable(vowel_remover 
    src/main.cpp
    src/vowel_utils.cpp
)
target_include_directories(vowel_remover PUBLIC include)

# Тесты
enable_testing()
add_executable(run_tests tests/test_vowel_remover.cpp src/vowel_utils.cpp)
target_include_directories(run_tests PUBLIC include)
target_link_libraries(run_tests PRIVATE gtest_main)

add_test(NAME VowelRemoverTests COMMAND run_tests)