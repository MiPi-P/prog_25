#pragma once
#include "structs.h"

// ввод вывод
void readPoint(Point &p);
void printPoint(const Point &p);
void readCircle(Circle &c);
void printCircle(const Circle &c);
void readSquare(Square &s);
void printSquare(const Square &s);

// геом
double circumference(const Circle &c);
double areaCircle(const Circle &c);
double perimeter(const Square &s);
double areaSquare(const Square &s);

// точки внутри/ на границе
bool point_in_circle(const Point &p, const Circle &c);
bool point_in_square(const Point &p, const Square &s);
bool border_point_in_circle(const Point &p, const Circle &c);
bool border_point_in_square(const Point &p, const Square &s);

// Пересечения
bool intersection_of_circles(const Circle &c1, const Circle &c2);
bool intersection_of_square(const Square &s1, const Square &s2);
bool intersection_circle_and_square(const Circle &c, const Square &s);

// Принадлежность фигур
bool circle_in_circle(const Circle &inner, const Circle &outer);
bool square_in_square(const Square &inner, const Square &outer);
bool square_in_circle(const Square &s, const Circle &c);
bool circle_in_square(const Circle &c, const Square &s);
