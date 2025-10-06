#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

class MyArray {
private:
    int* data;  // указатель на массив
    int size;   // количество элементов

public:

    MyArray(int n){ // конструктор
        size = n;
        data = new int[size];

        for (int i = 0; i != size; i += 1){ // заполняем 0
            data[i] = 0;
        }
    }

    MyArray(const MyArray& other){ // rjycnhernjh2
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

    
};

int main(){
    MyArray a(5);
    a.print();
    a.setValue(1, 5);
    a.print();
    cout << a.getValue(1) << endl;
    a.addValue(99);
    a.print();
}