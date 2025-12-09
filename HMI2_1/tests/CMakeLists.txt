cmake_minimum_required(VERSION 3.24)
project(HMI2_Tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Пути к основной библиотеке HMI2 и её include
include_directories(../)

# Пути к SFML
set(SFML_DIR "C:/SFML-2.6.2/lib/cmake/SFML")
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

# GoogleTest
add_subdirectory(../external/gtest googletest_build)

# Исходники тестов
set(TEST_SOURCES
        test_input_widget.cpp
        test_button_widget.cpp
        # сюда можно добавлять новые тестовые файлы
)

# Собираем исполняемый файл тестов
add_executable(runTests ${TEST_SOURCES}
        ../InputWidget.cpp
        ../ButtonWidget.cpp
        ../VariableManager.cpp
        ../TextWidget.cpp
)

target_link_libraries(runTests PRIVATE gtest gtest_main sfml-graphics sfml-window sfml-system)
