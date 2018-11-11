#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include "fileToConsoleOutput.h"


fileToConsoleOutput::fileToConsoleOutput() {
    this->file.open(fileName, ios_base::in);
}

fileToConsoleOutput::~fileToConsoleOutput() {
    this->file.close();
}

void fileToConsoleOutput::execute() {

    //считывание данных из файла в строку
    if (file.is_open()) {
        string temp;
        while (getline(file, temp)) {
            strFile += temp;
            if (!file.eof()) {
                strFile += '\n';
            }
        }
    } else {
        cout << "Error opening file" << endl;
    }

    //вывод цитат
    if (checkStr()) {
        for (int i(0), j; i < strFile.size(); i++) {
            if (strFile[i] == '\"') {
                for ((j = i)++; strFile[j] != '\"'; j++) {
                    stream << strFile[j];
                }
                stream << '\n';
                i = j;
            }
        }
    } else {
        cout << "Некорректное число кавычек" << endl;
    }
    stream << '\n';
    cout << stream.str();
}

//верное ли число кавычек
bool fileToConsoleOutput::checkStr() {
    int count = 0;
    int lim = strFile.size();
    for (int i = 0; i < lim;)
        if (strFile[i++] == '\"')
            count++;
    return !(count % 2);
}
