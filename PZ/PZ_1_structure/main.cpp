#include <iostream>
#include "structs.h"
#include "func.h"

using namespace std;

int main() {
    system("chcp 65001");
    // --- Точка ---
    cout << "Точка (x y):\n";
    Point a;
    readPoint(a);
    cout << "Точка: ";
    printPoint(a);

    // --- Круг ---
    cout << "Круг: введите центр (x y) и радиус r:\n";
    Circle b;
    readCircle(b);
    cout << "Круг: ";
    printCircle(b);
    cout << "Длина окружности: " << circumference(b) << "\n";
    cout << "Площадь круга: " << areaCircle(b) << "\n\n";

    // --- Квадрат ---
    cout << "Квадрат: введите левый верхний угол (x y) и длину стороны:\n";
    Square c;
    readSquare(c);
    cout << "Квадрат: ";
    printSquare(c);
    cout << "Периметр квадрата: " << perimeter(c) << "\n";
    cout << "Площадь квадрата: " << areaSquare(c) << "\n\n";

    // --- Принадлежность точки фигурам (строго внутри) ---
    cout << "Принадлежность точки фигуре (строго внутри):\n";
    cout << "Точка в круге? " << (point_in_circle(a, b) ? "Да" : "Нет") << "\n";
    cout << "Точка в квадрате? " << (point_in_square(a, c) ? "Да" : "Нет") << "\n\n";

    // --- Точка на границе ---
    cout << "Нахождение точки на границе:\n";
    cout << "Точка на границе круга? " << (border_point_in_circle(a, b) ? "Да" : "Нет") << "\n";
    cout << "Точка на границе квадрата? " << (border_point_in_square(a, c) ? "Да" : "Нет") << "\n\n";

    // --- Пересечения фигур ---
    cout << "Пересечение фигур:\n";
    cout << "Введите второй круг (центр x y и радиус):\n";
    Circle b2;
    readCircle(b2);
    cout << "Круги пересекаются? " << (intersection_of_circles(b, b2) ? "Да" : "Нет") << "\n";

    cout << "Введите второй квадрат (левый верхний x y и сторону):\n";
    Square c2;
    readSquare(c2);
    cout << "Квадраты пересекаются? " << (intersection_of_square(c, c2) ? "Да" : "Нет") << "\n";

    cout << "Круг и квадрат пересекаются? " << (intersection_circle_and_square(b, c) ? "Да" : "Нет") << "\n\n";

    // --- Принадлежность фигуры ---
    cout << "Принадлежность фигуры:\n";
    cout << "Круг b внутри круга b2? " << (circle_in_circle(b, b2) ? "Да" : "Нет") << "\n";
    cout << "Квадрат c внутри квадрата c2? " << (square_in_square(c, c2) ? "Да" : "Нет") << "\n";
    cout << "Квадрат c внутри круга b? " << (square_in_circle(c, b) ? "Да" : "Нет") << "\n";
    cout << "Круг b внутри квадрата c? " << (circle_in_square(b, c) ? "Да" : "Нет") << "\n";

    return 0;
}
