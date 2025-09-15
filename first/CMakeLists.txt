cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# ВЫБЕРИ ОДНУ ИЗ ЭТИХ РАБОЧИХ ССЫЛОК:
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
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