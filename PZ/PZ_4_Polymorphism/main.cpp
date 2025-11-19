#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <algorithm>
#include <fstream>

#include <chrono> // дата время
#include <format>

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



    void setValue(int index, int value){ // сеттер (записат знач)
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

    int getValue(int index){ // гетер (получить знач)
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
    void addValue(int value){ // добавить элем в конец
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
    void add(const MyArray& other){ // приплюсовать знач 2-х массивов
        int minSize = min(size, other.size);

        for (int i = 0; i < minSize; i += 1){
            data[i] += other.data[i];
        }
    }

    void sub(const MyArray& other){ // минусануть знач 2-х массивов
        int minSize = min(size, other.size);

        for (int i = 0; i < minSize; i += 1){
            data[i] -= other.data[i];
        }
    }
};




// ПЗ 5



class ArrTxt : public MyArray {
    public:
    string time = format("{:%d-%m-%Y %H-%M}", chrono::floor<chrono::seconds>(chrono::system_clock::now())) + ".txt";

    void print_txt(){
        ofstream fout;
        fout.open(time);
        if (fout.is_open() == false) {
            cout << "Ошибка записи файла";
            return;
        }
        fout << size << endl;
        for (int i = 0; i != size; i += 1) {
            fout << data[i] << " ";
        }
        cout << endl;
        fout.close();
    }
};




class ArrCSV : public MyArray {
public:
    string time = format("{:%d-%m-%Y %H-%M}", chrono::floor<chrono::seconds>(chrono::system_clock::now())) + ".csv";

    void print_csv(){
        ofstream fout;
        fout.open(time);
        if (fout.is_open() == false) {
            cout << "Ошибка записи файла";
            return;
        }
        fout << size << endl;
        for (int i = 0; i != size; i += 1) {
            fout << data[i] << ";";
        }
        cout << endl;
        fout.close();
    }
};


int main(){
    system("chcp 65001");

    ArrCSV a(5);
    a.setValue(0, 1);
    a.setValue(1, 2);
    a.setValue(2, 3);
    a.setValue(3, 4);
    a.setValue(4, 5);

    // string time = format("{:%d-%m-%Y %H-%M}", chrono::floor<chrono::seconds>(chrono::system_clock::now())) + ".txt";
    // cout << time;


    //a.print_txt();
    a.print_csv();





    //
    //
    // MyArray a(3);
    // a.print();
    // a.setValue(0, 1);
    // a.setValue(1, 2);
    // a.setValue(2, 3);
    // a.print();
    // cout << a.getValue(1) << endl;
    // a.addValue(4);
    // a.print();
    //
    //
    // cout << "\n#4\n";
    // MyArray b(3);
    // b.setValue(0, 10);
    // b.setValue(1, 20);
    // b.setValue(2, 30);
    // cout << "a = ";
    // a.print();
    // cout << "b = " ;
    // b.print();
    // cout << "a + b: ";
    // a.add(b);
    // a.print();
    // cout << "a(новый) - b: ";
    // a.sub(b);
    // a.print();


}
