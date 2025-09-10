#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

struct  Point{
    double x;
    double y;
};

void readPoint(Point &p){
    cin >> p.x >> p.y;
}

void printPoint(const Point &p){
    cout << "X = " << p.x << ",Y = " << p.y << endl;
}




struct  Circle{
    Point center;
    double r;
};

void readCircle(Circle &c){
    cin >> c.center.x >> c.center.y >> c.r;
}

void printCircle(const Circle &c){
    cout << "X = " << c.center.x <<",Y = " << c.center.y << ", R = " << c.r << endl;
}

double circumference(const Circle &c){
    return 2 * 3.14 * c.r;
}

double areaCircle(const Circle &c){
    return 3.14 * c.r * c.r;
}




struct Square{
    Point top;
    double side;
};

void readSquare(Square &s){
    cin >> s.top.x >> s.top.y >> s.side;
}

void printSquare(const Square &s){
    cout << "X = " << s.top.x << ",Y = " << s.top.y << ",Сторона = " << s.side << endl;
}

double perimeter(const Square &s){
    return s.side * 4;
}

double areaSquare(const Square &s){
    return s.side * s.side;
}








double point_in_circle(const Point &p, const Circle &c){
    double dx = p.x - c.center.x;
    double dy = p.y - c.center.y;
    double distance = sqrt(dx * dx + dy * dy);
    return distance <= c.r;
}





int main(){
    
    cout << "Точка:" << endl;
    Point a;
    readPoint(a);
    printPoint(a);
    cout << endl;

    cout << "Круг:" << endl;
    Circle b;
    readCircle(b);
    printCircle(b);
    cout << "Длина круга: " << circumference(b) << endl;
    cout << "Площадь круга: " << areaCircle(b) << endl;

    

    cout << "Квадрат:" << endl;
    Square c;
    readSquare(c);
    printSquare(c);
    cout << "Периметр квадрата: " << perimeter(c) << endl;
    cout << "Площадь квадрата: " << areaSquare(c) << endl;


    cout << "Принадлежность точки фигуре:" << endl;
    cout << "Точка в круг: ";
    if (point_in_circle(a, b) == true){
        cout << "Принадлежит"  << endl;
    } else {
        cout << "Не принадлежит"  << endl;
    }
}
