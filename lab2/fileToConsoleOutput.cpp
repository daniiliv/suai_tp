#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include "fileToConsoleOutput.h"


fileToConsoleOutput::fileToConsoleOutput() {
    this->file.open(fileName, ios_base::in);
    this->count = 0;
    file.get(currChar);
}

fileToConsoleOutput::~fileToConsoleOutput() {
    this->file.close();
    this->stream.str("");
    this->count = 0;
}

void fileToConsoleOutput::execute() {
    while (!this->file.eof()) {
        if (this->currChar  == '\"') {
            this->count++;
            this->file.get(this->currChar);
            for (; this->currChar != '\"' && !this->file.eof();) {
                stream << this->currChar;
                this->file.get(this->currChar);
            }
            if (this->currChar  == '\"') {
                this->count++;
            }
            this->stream << '\n';
        }
        this->file.get(this->currChar);
    }
    if (!this->count) {
        cout << "---- There are no quotes! ----" << endl;
    } else if (!(this->count % 2)) {
        cout << "---- Quotes found ----" << endl;
        cout << this->stream.str();
    } else {
        cout << "Incorrect numbers of quote signs!" << endl;
    }
}