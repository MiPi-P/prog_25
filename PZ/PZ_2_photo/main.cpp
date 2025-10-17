#include <iostream>
#include <string>
#include <fstream>
#include <vector>





using namespace std;

int main(){


    ifstream fin; // чтение 
    fin.open("photo_PGM_lvl_5.pgm");

    ofstream fout; // запись
    fout.open("rez_5.pgm");

    if (fin.is_open() == false) {
        cout << "no file found1" << endl;
        return 0;
    }
    
    if (fout.is_open() == false) {
        cout << "no file found2" << endl;
        return 0;
    }

    int lineCount = 0;
    string line;

    int length = 0, height = 0;
    while (lineCount != 4) { //копироване начальных строк
        getline(fin, line);
        if (lineCount == 2){
            int space = line.find(" ");
            length = stoi(line.substr(0, space)); // кол-во пикселей по x
            height = stoi(line.substr(space + 1)); // кол-во пикселей по y
            // cout << length << height << endl;
        }
        fout << line << endl;
        lineCount += 1;
    }

    vector<int> data;


    while (fin.eof() == false) // создание вектора
    {
        int number = 0;
        fin >> number;
        data.push_back(number);
    }

    // for (int i = 0; i != size(data); i += 1)
    // {
    //     cout << data[i] << endl;
    // }



    for (int i = 1; i != size(data) - 1; i += 1) {
        //int pixel = data[i];


        if (data[i] == 255 or data[i] == 0) {
            int j = i + 1;
            while (data[j] == 255 or data[j] == 0) {
                j += 1;
            }
             
            if (i < length) {
                data[i] = (data[i - 1] + data[j]) / 2;
            } else {
                data[i] = (data[i - 1] + data[j] + data[i - length]) / 3;
            }
            fout << data[i] << endl;
        } 
        else
        {
            fout << data[i] << endl;
        }
        
        
    }
    




    
    cout << "OK";
    fin.close();
    fout.close();
}