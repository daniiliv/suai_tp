#ifndef LAB2_FILETOCONSOLEOUTPUT_H
#define LAB2_FILETOCONSOLEOUTPUT_H


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class fileToConsoleOutput {
private:
    string fileName = "/home/daniil/projects/suai_tp/lab2/sometext.txt";
    ifstream file;
    string strFile; //запись файла в эту строку
    stringstream stream; //ввод в этот поток
public:
    fileToConsoleOutput();
    ~fileToConsoleOutput();
    void execute();
    bool checkStr();
};

#endif //LAB2_FILETOCONSOLEOUTPUT_H
