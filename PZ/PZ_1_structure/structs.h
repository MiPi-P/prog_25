#pragma once

struct Point {
    double x, y;
};

struct Circle {
    Point center;
    double r;
};

struct Square {
    Point top;     // левый верхний угол
    double side;   // сторона
};

