cmake_minimum_required(VERSION 3.24)

project(HMI2_1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# ----------------- SFML 2.6.2 -----------------
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.2
)
FetchContent_MakeAvailable(SFML)

# ----------------- Исходники -----------------
set(SOURCES
        main.cpp
        TextWidget.cpp
        InputWidget.cpp
        ButtonWidget.cpp
        VariableManager.cpp
)

add_executable(HMI2_1 ${SOURCES})

# Линкуем SFML
target_link_libraries(HMI2_1 PRIVATE sfml-graphics sfml-window sfml-system)

# ----------------- GTest -----------------
enable_testing()

# Подключаем GTest из папки external
add_subdirectory(external/gtest)
include_directories(external/gtest/googletest/include)

# ----------------- Тесты -----------------
set(TEST_SOURCES
        tests/test_variable_manager.cpp
)

add_executable(runTests ${TEST_SOURCES} TextWidget.cpp InputWidget.cpp ButtonWidget.cpp VariableManager.cpp)
target_link_libraries(runTests PRIVATE gtest gtest_main sfml-graphics sfml-window sfml-system)

add_test(NAME HMITests COMMAND runTests)
