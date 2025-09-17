#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

// точка
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



// круг
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



// квадрат
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



// вхождение без границ
bool point_in_circle(const Point &p, const Circle &c){
    double dx = p.x - c.center.x;
    double dy = p.y - c.center.y;
    double distance = sqrt(dx * dx + dy * dy);
    return distance < c.r;
}


bool point_in_square(const Point &p, const Square &s){
    return (p.x > s.top.x and p.x < (s.top.x + s.side)) and 
    (p.y < s.top.y and p.y > (s.top.y - s.side));
}




// вхождение на границы
bool border_point_in_circle(const Point &p, const Circle &c){
    double dx = p.x - c.center.x;
    double dy = p.y - c.center.y;
    double distance = sqrt(dx * dx + dy * dy);
    return distance == c.r;
}


bool border_point_in_square(const Point &p, const Square &s){
    return (
        ((p.x >= s.top.x and p.x <= (s.top.x + s.side)) and 
                (p.y == s.top.y or p.y == (s.top.y - s.side))) or 
        ((p.y <= s.top.y and p.y >= (s.top.y - s.side)) and
                (p.x == s.top.x or p.x == (s.top.x + s.side)))
            );
}

// Пересечение фигур ...





int main(){
    
    cout << "Точка:" << endl;
    Point a;
    readPoint(a);
    printPoint(a);



    cout << "Круг: (центр, радиус)" << endl;
    Circle b;
    readCircle(b);
    printCircle(b);
    cout << "Длина круга: " << circumference(b) << endl;
    cout << "Площадь круга: " << areaCircle(b) << endl;

    

    cout << "Квадрат: (левый верхний угол, длина стороны)" << endl;
    Square c;
    readSquare(c);
    printSquare(c);
    cout << "Периметр квадрата: " << perimeter(c) << endl;
    cout << "Площадь квадрата: " << areaSquare(c) << endl;



    cout << "Принадлежность точки фигуре (без границ):" << endl;

    cout << "Точка в круг: ";
    if (point_in_circle(a, b) == true){
        cout << "Принадлежит"  << endl;
    } else {
        cout << "Не принадлежит"  << endl;
    }

    cout << "Точка в квадрат: ";
    if (point_in_square(a, c) == true){
        cout << "Принадлежит"  << endl;
    } else {
        cout << "Не принадлежит"  << endl;
    }



    cout << "Нахождение точки на контуре (граница)" << endl;
    
    cout << "Точка круг граница: ";
    if (border_point_in_circle(a, b) == true){
        cout << "На границе груга" << endl;
    } else {
        cout << "Не на границе круга" << endl;
    }

    cout << "Точка квадрат граница: ";
    if (border_point_in_square(a, c) == true){
        cout << "На границе квадрата" << endl;
    } else {
        cout << "Не на границе квадрата" << endl;
    }
    


}
