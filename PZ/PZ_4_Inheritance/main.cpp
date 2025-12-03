#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;







class MyArray {
protected:
    int* data;  // указатель на массив
    int size;   // кол-во элементов

public:

    MyArray(int n){ // конструктор
        size = n;
        data = new int[size];

        for (int i = 0; i != size; i += 1){ // заполняем 0
            data[i] = 0;
        }
    }

    //#2
    MyArray(const MyArray& other){ // конструктор 2
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i += 1) {
            data[i] = other.data[i];
        }
    }


    ~MyArray() { // деконструктор,
    delete[] data;
    }



    void setValue(int index, int value){ // сеттер
        if (0 <= index and index < size){
            if (-100 <= value and value <= 100){
                data[index] = value;
            } else {
                cout << "Ошибка в значении" << endl;
                return;
            }
        } else {
            cout << "Ошибка в индексе" << endl;
            return;
        }
    }

    int getValue(int index){ // гетер
        if (0 <= index and index < size){
            return data[index];
        } else {
            cout << "Ошибка индекса" << endl;
            return 0;
        }
    }

    void print(){
        for (int i = 0; i != size; i += 1){
            cout << data[i] << " ";
        }
        cout << endl;
    }


    //#3
    void addValue(int value){
        if (-100 <= value and value <= 100){
            int* newData = new int[size + 1];

        for (int i = 0; i < size; i += 1) {
            newData[i] = data[i];
        }

        newData[size] = value;

        delete[] data;

        data = newData;
        size += 1;

        } else {
            cout << "Ошибка значения" << endl;
        }
    }



    // номер 4
    void add(const MyArray& other){
        int minSize = min(size, other.size);

        for (int i = 0; i < minSize; i += 1){
            data[i] += other.data[i];
        }
    }

    void sub(const MyArray& other){
        int minSize = min(size, other.size);

        for (int i = 0; i < minSize; i += 1){
            data[i] -= other.data[i];
        }
    }
};


// пз наследование
class dop : public MyArray {
public:

    // Вычисление среднего значения
    double average() {
        double sum = 0.0;

        for (int i = 0; i != size; i += 1) {
            sum += data[i];
        }
        return sum / size;
    }

    // Вычисление медианного значения
    double median() {
        vector<int> temp(data, data + size);
        sort(temp.begin(), temp.end());
        if (size % 2 == 0) {
            return (temp[(size / 2) - 1] + temp[size / 2]) / 2.0;
        } else {
            return temp[size / 2];
        }
    }

    // мин и макс значение
    void minValue() {
        int min = data[0];
        for (int i = 1; i != size; i += 1) {
            if (data[i] < min) {
                min = data[i];
            }
        }
        cout << "Минимум: " << min << endl;
    }
    void maxValue() {
        int max = data[0];
        for (int i = 1; i != size; i += 1) {
            if (data[i] > max) {
                max = data[i];
            }
        }
        cout << "Максимум: " << max << endl;

    }


};

int main(){
    system("chcp 65001");


    dop a(5);
    a.setValue(0, 3);
    a.setValue(1, 5);
    a.setValue(2, 6);
    a.setValue(3, 1);
    a.setValue(4, 9);
    a.print();

    cout << a.average() << endl;
    cout << a.median() << endl;
    a.minValue();
    a.maxValue();
}