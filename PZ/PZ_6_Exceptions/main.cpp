#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

class MyArray {
private:
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



    void setValue(int index, int value){ // сеттер СЮДА =============================================
        if (0 > index or index >= size){
            throw out_of_range("Индекс вне диапазона");
        }
        if (-100 > value or value > 100){
            throw invalid_argument("Значение вне диапазона [-100, 100]");
        }
        data[index] = value;
    }

    int getValue(int index){ // гетер СЮДА =============================================
        if (0 > index or index >= size){
            throw out_of_range("Индекс вне диапазона");
        }
        return data[index];

    }

    void print(){
        for (int i = 0; i != size; i += 1){
            cout << data[i] << " ";
        }
        cout << endl;
    }


    //#3 СЮДА =============================================
    void addValue(int value){
        if (-100 > value or value > 100){
            throw invalid_argument("Значение вне диапазона [-100, 100]");
        }

            int* newData = new int[size + 1];

            for (int i = 0; i < size; i += 1) {
                newData[i] = data[i];
            }

            newData[size] = value;

            delete[] data;

            data = newData;
            size += 1;
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

int main() {
    system("chcp 65001");
    MyArray a(3);
    a.print();

    try {
        a.setValue(0, 10);
    } catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    try {
        a.setValue(-1, 20);
    } catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    try {
        a.setValue(2, 300);
    } catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    try {
        a.getValue(10);
    } catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    try {
        a.addValue(101);
    } catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }


    a.print();

}