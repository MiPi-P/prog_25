#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;






int main(){

    ifstream fin; // чтение битого
    fin.open("photo_PGM_lvl_5.pgm");

    ifstream forig; // чтение исходного
    forig.open("photo_PGM.pgm");

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

    if (forig.is_open() == false) {
        cout << "no file found3" << endl;
        return 0;
    }


    // int lineCount = 0;
    // string line;
    // string trash;

    // int length = 0, height = 0;
    // while (lineCount != 4) { //копироване начальных строк
    //     getline(fin, line);
    //     getline(forig, trash); // 1-ые строки из оригинала
    //     if (lineCount == 2){
    //         int space = line.find(" ");
    //         length = stoi(line.substr(0, space)); // кол-во пикселей по x
    //         height = stoi(line.substr(space + 1)); // кол-во пикселей по y
    //         // cout << length << height << endl;
    //     }
    //     fout << line << endl;
    //     lineCount += 1;
    // }

    // скип 1-ых строк
    
    string line;
    string trash;
    int length = 0, height = 0, maxval = 0;

    getline(fin, line); // p2
    getline(forig, trash);
    fout << line << endl;

        while (getline(fin, line)) {
        getline(forig, trash);
        if (line[0] == '#') {  // комментарий
            fout << line << endl;
            continue;
        }

        //размеры
        int space = line.find(' ');
        if (space != string::npos) {
            length = stoi(line.substr(0, space));
            height = stoi(line.substr(space + 1));
            fout << line << endl;
            break;
        }
    }

    getline(fin, line); // макс знач
    getline(forig, trash);
    maxval = stoi(line);
    fout << line << endl;
    


    vector<int> data;
    vector<int> new_data;


    while (fin.eof() == false) // создание вектора для бигото
    {
        int number = 0;
        fin >> number;
        data.push_back(number);
    }

    while (forig.eof() == false) // создание вектора для оригинального
    {
        int number = 0;
        forig >> number;
        new_data.push_back(number);
    }

    // for (int i = 0; i != size(data); i += 1)
    // {
    //     cout << data[i] << endl;
    // }


    int error_count = 0;

    for (int i = 1; i != size(data) - 1; i += 1) {
        if (data[i] == maxval or data[i] == 0) {
            int j = i + 1;
            while (data[j] == maxval or data[j] == 0) {
                j += 1;
            }
             
            if (i < length) {
                data[i] = (data[i - 1] + data[j]) / 2;
            } else {
                data[i] = (data[i - 1] + data[j] + data[i - length]) / 3;
            }
            fout << data[i] << endl; // запись в фвйл

            if (data[i] != new_data[i]){ // счёт неточностей 
                error_count += 1;
            }

        } 
        else
        {
            fout << data[i] << endl;
        }
    }

    double percent = error_count * 100.0 / (length * height);

    cout << "Процент неточностей: " << percent << "%" << endl;




    
    cout << "finish";
    fin.close();
    fout.close();
}