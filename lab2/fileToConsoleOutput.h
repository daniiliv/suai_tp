#ifndef LAB2_FILETOCONSOLEOUTPUT_H
#define LAB2_FILETOCONSOLEOUTPUT_H


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class fileToConsoleOutput {
private:

    /**
     * Имя файла.
     */
    string const fileName = "/home/daniil/projects/suai_tp/lab2/sometext.txt";

    /**
     * Поток последовательного чтения символов из файла.
     */
    ifstream file;

    /**
     * Строковый поток, в который записываются цитаты.
     */
    stringstream stream;

    /**
     * Количество кавычек.
     */
    int count;

    /**
     * Текущий символ, прочитанный из файла.
     */
    char currChar;
public:
    fileToConsoleOutput();
    ~fileToConsoleOutput();
    void execute();
};

#endif //LAB2_FILETOCONSOLEOUTPUT_H
