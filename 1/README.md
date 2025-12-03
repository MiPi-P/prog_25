# HMI2 — Компоненты ввода-вывода для XSmall-HMI SCADA

Минимальная реализация HMI-компонентов на C++20 и SFML.

## Структура
- `CMakeLists.txt` — корневой CMake
- `LICENSE` — MIT
- `README.md` — этот файл
- `src/` — исходники
- `tests/` — тесты (gtest)

## Сборка
Установите SFML и GTest на системе.

Пример (Linux):
```bash
sudo apt install libsfml-dev libgtest-dev cmake g++
# возможно нужно собрать gtest вручную на некоторых дистрибутивах
mkdir build && cd build
cmake ..
cmake --build .
```

Запуск демо:
```
./hmi2_demo
```

Примечание: путь к шрифту в `src/main.cpp` указывает на `assets/Roboto-Regular.ttf`. Добавьте свой шрифт по этому пути или поправьте путь.
