//
// Created by daniil on 01.10.18.
//

#include "train.h"
#include <iostream>
#include <cstring>

#define TRAIN_NUMS 6

Train::Train(char* destination, int trainNumber, char* departureTime) {

    size_t len;
    len = strlen(destination) + 1;
    this->destination = new char[len];
    if(!(this->destination)) {
        cout << "Memory allocation error!\n";
        exit(1);
    }
    strcpy(this->destination, destination);

    this->trainNumber = trainNumber;

    len = strlen(departureTime) + 1;
    this->departureTime = new char[len];
    if(!(this->departureTime)) {
        cout << "Memory allocation error!\n";
        exit(1);
    }
    strcpy(this->departureTime, departureTime);

    cout << "Constructor with parameters called!\n";
}
Train::Train() {
    this->destination = new char[50];
    if(!(this->destination)) {
        cout << "Memory allocation error!\n";
        exit(1);
    }

    this->trainNumber = 0;

    this->departureTime = new char[10];
    if(!(this->departureTime)) {
        cout << "Memory allocation error!\n";
        exit(1);
    }

    cout << "Default constructor called!\n";
}
Train::~Train() {
    delete [] this->destination;
    delete [] this->departureTime;
    trainNumber = 0;
    cout << "Destructor called!\n";
}
void Train::setDestination(char* destination) {
    size_t len;
    len = strlen(destination) + 1;
    this->destination = new char[len];
    if(!(this->destination)) {
        cout << "Memory allocation error!\n";
        exit(1);
    }
    strcpy(this->destination, destination);
}
void Train::setTrainNumber(int trainNumber) {
    this->trainNumber = trainNumber;
}
void Train::setDepartureTime(char* departureTime) {
    size_t len;
    len = strlen(departureTime) + 1;
    this->departureTime = new char[len];
    if(!(this->departureTime)) {
        cout << "Memory allocation error!\n";
        exit(1);
    }
    strcpy(this->departureTime, departureTime);
}
char* Train::getDestination() {
    return this->destination;
}
int Train::getTrainNumber() {
    return this->trainNumber;
}
char* Train::getDepartureTime() {
    return this->departureTime;
}
ostream &operator<<(ostream &stream, Train obj) {
    stream << "Destination: " << obj.getDestination() << endl;
    stream << "Train number: " << obj.getTrainNumber() << endl;
    stream << "Departure time: " << obj.getDepartureTime() << endl;

    return stream;
}
istream &operator>>(istream &stream, Train &obj) {
    char *dest = new char[50];
    int trNum;
    char* depTime = new char[10];

    cout << "Enter destination: ";
    stream >> dest; obj.setDestination(dest);

    cout << "Enter train number: ";
    stream >> trNum; obj.setTrainNumber(trNum);

    cout << "Enter departure time in format (00:00): ";
    stream >> depTime; obj.setDepartureTime(depTime);

    delete [] dest;
    delete [] depTime;

    return stream;
}

int Train::getConvertedDepartureTime() {
    int hours = ((int)departureTime[0] - '0') * 10 + (int)departureTime[1] - '0';
    int minutes = ((int)departureTime[3] - '0') * 10 + (int)departureTime[4] - '0';

    return hours * 60 + minutes;
}

Train *Train::sortTrains(Train* train) {
    bool swapped = false;
    Train temp;
    for (int i = 0; i < TRAIN_NUMS - 1; i++) {
        swapped = false;
        for (int j = 0; j < TRAIN_NUMS - i - 1; j++) {
            if(train[j].getConvertedDepartureTime() > train[j + 1].getConvertedDepartureTime()) {
               temp = train[j];
               train[j] = train[j + 1];
               train[j + 1] = temp;
               swapped = true;
            }
        }
        if(!swapped) {
            break;
        }
    }

    return train;
}

Train::Train(const Train &train) {
    size_t len;
    len = strlen(train.destination) + 1;
    this->destination = new char[len];
    if(!(this->destination)) {
        cout << "Memory allocation error!\n";
        exit(1);
    }
    strcpy(this->destination, train.destination);

    this->trainNumber = train.trainNumber;

    len = strlen(train.departureTime) + 1;
    this->departureTime = new char[len];
    if(!(this->departureTime)) {
        cout << "Memory allocation error!\n";
        exit(1);
    }
    strcpy(this->departureTime, train.departureTime);
}

Train &Train::operator=(Train &train) {
    if (strlen(this->destination) < strlen(train.destination)) {
        delete[] this->destination;
        this->destination = new char[strlen(train.destination)];
        if(!(this->destination)) {
            cout << "Memory allocation error!\n";
            exit(1);
        }
    }
    strcpy(this->destination, train.destination);

    this->trainNumber = train.trainNumber;

    if (strlen(this->departureTime) < strlen(train.departureTime)) {
        delete[] this->departureTime;
        this->departureTime = new char[strlen(train.departureTime)];
        if(!(this->departureTime)) {
            cout << "Memory allocation error!\n";
            exit(1);
        }
    }
    strcpy(this->departureTime, train.departureTime);

    return *this;
}




