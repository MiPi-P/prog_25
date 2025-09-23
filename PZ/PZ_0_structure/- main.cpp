#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

// точка
struct Point{
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

// Пересечение фигур

bool intersection_of_circles(const Circle &c, const Circle &c2){
    double dx = c.center.x - c2 .center.x;
    double dy = c.center.y - c2.center.y;
    double d = sqrt(dx*dx + dy*dy);
    return (fabs(c.r - c2.r) <= d) and (d <= c.r + c2.r);
}

bool intersection_of_square(const Square &s, const Square &s2){
    double s_left = s.top.x;
    double s_right = s.top.x + s.side;
    double s_top = s.top.y;
    double s_bottom = s.top.y - s.side;

    double s2_left = s2.top.x;
    double s2_right = s2.top.x + s2.side;
    double s2_top = s2.top.y;
    double s2_bottom = s2.top.y - s2.side;

    if (s_left > s2_right or s_right < s2_left or
        s_top < s2_bottom or s_bottom > s2_top){
            return 0; // не пересекаются
        }
    return 1; // пересекаются 
}

bool intersection_circle_and_square(const Circle &c, const Square &s){
    if (point_in_square(c.center, s) == true){ // центр круга внутри квадрата
        return true;
    }

    Point corners[4] = { // вершины квадрата внутри круга
        {s.top.x, s.top.y},
        {s.top.x + s.side, s.top.y},
        {s.top.x, s.top.y - s.side},
        {s.top.x + s.side, s.top.y - s.side}
    };
    for (int i = 0; i < 4; i += 1) {
        if (point_in_circle(corners[i], c)){
            return true;
        }
    }

    // расстояние от центра круга до ближайшей стороны квадрата
    double nearestX = max(s.top.x, min(c.center.x, s.top.x + s.side));
    double nearestY = max(s.top.y - s.side, min(c.center.y, s.top.y));
    double dx = c.center.x - nearestX;
    double dy = c.center.y - nearestY;
    if (dx*dx + dy*dy <= c.r * c.r){ 
        return true;
    }

    return false;
}



// Принадлежность фигуры

bool circle_in_circle(const Circle &c, const Circle &c2){
    double dx = c.center.x - c2.center.x;
    double dy = c.center.y - c2.center.y;
    double d = sqrt(dx*dx + dy*dy);
    return (d + c.r <= c2.r);
}           

bool square_in_square(const Square &s, const Square &s2) {
    double sL = s.top.x, sR = s.top.x + s.side;
    double sT = s.top.y, sB = s.top.y - s.side;
    double s2L = s2.top.x, s2R = s2.top.x + s2.side;
    double s2T = s2.top.y, s2B = s2.top.y - s2.side;

    return (sL > s2L) and (sR < s2R) and (sT < s2T) and (sB > s2B);
}

bool square_in_circle(const Square &s, const Circle &c) {
    // 4 угла квадрата
    Point corners[4] = {
        {s.top.x, s.top.y},
        {s.top.x + s.side, s.top.y},
        {s.top.x, s.top.y - s.side},
        {s.top.x + s.side, s.top.y - s.side}
    };

    // проверка вершин
    for (int i = 0; i < 4; i++) {
        double dx = corners[i].x - c.center.x;
        double dy = corners[i].y - c.center.y;
        double dist2 = dx*dx + dy*dy;
        if (dist2 > c.r * c.r) {
            return false; // не внутри
        }
    }
    return true; // внутри
}

bool circle_in_square(const Circle &c, const Square &s) {
    double s_left = s.top.x;
    double s_right = s.top.x + s.side;
    double s_top = s.top.y;
    double s_bottom = s.top.y - s.side;

    double cx = c.center.x;
    double cy = c.center.y;
    double r  = c.r;

    return (cx - r >= s_left) and 
           (cx + r <= s_right) and 
           (cy + r <= s_top) and 
           (cy - r >= s_bottom);
}













///*
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

    cout << "Точка в кругу? ";
    if (point_in_circle(a, b) == true){
        cout << "Да"  << endl;
    } else {
        cout << "Нет"  << endl;
    }

    cout << "Точка в квадрате: ";
    if (point_in_square(a, c) == true){
        cout << "Да"  << endl;
    } else {
        cout << "Нет"  << endl;
    }



    cout << "Нахождение точки на контуре (граница)" << endl;
    
    cout << "Точка на границе круга? ";
    if (border_point_in_circle(a, b) == true){
        cout << "Да" << endl;
    } else {
        cout << "Нет" << endl;
    }

    cout << "Точка на границе квадрата? ";
    if (border_point_in_square(a, c) == true){
        cout << "Да" << endl;
    } else {
        cout << "Нет" << endl;
    }



    cout << "Пересечение фигур" << endl;

    Circle b2; // доп круг
    cout << "Введите доп круг" << endl;
    readCircle(b2);
    cout << "Круги пересекаются? ";
    if (intersection_of_circles(b, b2) == true){
        cout << "Да" << endl;
    } else {
        cout << "Нет" << endl;
    }

    Square c2; //доп квадрат
    cout << "Введите доп квадрат" << endl;
    readSquare(c2);
    cout << "Квадраты пересекаются? ";
    if (intersection_of_square(c, c2) == true){
        cout << "Да" << endl;
    } else {
        cout << "Нет" << endl;
    }

    cout << "Круг и квадрат пересекаются?"; 
    if (intersection_circle_and_square(b, c) == true){
        cout << "Да" << endl;
    } else{
        cout << "Нет" << endl;
    }

    // принадлежность

    cout << "Круг внутри доп круга? ";
    if (circle_in_circle(b, b2) == true){
        cout << "Да" << endl;
    } else{
        cout << "Нет" << endl;
    }

    cout << "Квадрат внутри доп квадрата? ";
    if (square_in_square(c, c2) == true){
        cout << "Да" << endl;
    } else{
        cout << "Нет" << endl;
    }

    cout << "Квадрат внутри круга? ";
    if (square_in_circle(c, b) == true){
        cout << "Да" << endl;
    } else{
        cout << "Нет" << endl;
    }    

    cout << "Круг внутри квадрата? ";
    if (circle_in_square(b, c) == true){
        cout << "Да" << endl;
    } else{
        cout << "Нет" << endl;
    }  


}
//*/

// int main(){

//     cout << "квадрат" << endl;
//     Square c;
//     readSquare(c);
//     Square c2; // доп квадр
//     cout << "Введите доп квадр" << endl;
//     readSquare(c2);

//     cout << intersection_of_square(c, c2);

// }