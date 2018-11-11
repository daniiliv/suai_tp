#include "train.h"
#include <iostream>
#include <cstring>

/**
 * Конструктор с параметрами.
 * @param destination
 * @param trainNumber
 * @param departureTime
 */
Train::Train(char* destination, int trainNumber, char* departureTime) {
    try {
        size_t len;
        len = strlen(destination) + 1;
        this->destination = new char[len];
        if (!(this->destination)) {
            throw 1;
        }
        strcpy(this->destination, destination);

        this->trainNumber = trainNumber;

        len = strlen(departureTime) + 1;
        this->departureTime = new char[len];
        if (!this->departureTime) {
            throw 2;
        }
        strcpy(this->departureTime, departureTime);
    }
    catch (int a) {
        cout << "Caught exception number:  " << a;
        if (a == 1) {
            cout << " - memory allocation error for char[] destination" << endl;
        }
        else if (a == 2) {
            cout << " - memory allocation error for char[] departureTime" << endl;
        }
        exit(1);
    }
    //cout << "Constructor with parameters called! Train object." << endl;
}

/**
 * Конструктор без параметров.
 */
Train::Train() {
    try {
        this->destination = new char[50];
        if (!(this->destination)) {
            throw 1;
        }
        this->trainNumber = 0;
        this->departureTime = new char[10];
        if (!(this->departureTime)) {
            throw 2;
        }
        //cout << "Default constructor called! Train object" << endl;
    }
    catch(int a) {
        cout << "Caught exception number:  " << a;
        if (a == 1) {
            cout << " - memory allocation error for char[] destination" << endl;
        }
        else if (a == 2) {
            cout << " - memory allocation error for char[] departureTime" << endl;
        }
        exit(1);
    }
}

/**
 * Конструктор копии.
 * @param train
 */
Train::Train(const Train &train) {
    size_t len = strlen(train.destination) + 1;
    this->destination = new char[len];
    if (!this->destination) {
        cout << " - memory allocation error for char[] destination" << endl;
        exit(1);
    }
    strcpy(this->destination, train.destination);

    this->trainNumber = train.trainNumber;

    len = strlen(train.departureTime) + 1;
    this->departureTime = new char[len];
    if (!this->departureTime) {
        cout << " - memory allocation error for char[] departureTime" << endl;
        exit(1);
    }
    strcpy(this->departureTime, train.departureTime);
}


/**
 * Деструктор.
 */
Train::~Train() {
    delete [] this->destination;
    delete [] this->departureTime;
    this->trainNumber = 0;
    //cout << "Destructor called! Train object." << endl;
}

/**
 * Сеттер направления.
 * @param destination
 */
void Train::setDestination(char* destination) {
    try {
        size_t len;
        len = strlen(destination) + 1;
        this->destination = new char[len];
        if (!(this->destination)) {
            throw 1;
        }
        strcpy(this->destination, destination);
    }
    catch (int a) {
        cout << " - memory allocation error for char[] destination" << endl;
        exit(1);
    }
}

/**
 * Сеттер номера поезда.
 * @param trainNumber
 */
void Train::setTrainNumber(int trainNumber) {
    this->trainNumber = trainNumber;
}

/**
 * Сеттер времени отправления поезда.
 * @param departureTime
 */
void Train::setDepartureTime(char* departureTime) {
    try {
        size_t len;
        len = strlen(departureTime) + 1;
        this->departureTime = new char[len];
        if (!(this->departureTime)) {
            throw 1;
        }
        strcpy(this->departureTime, departureTime);
    }
    catch (int a) {
        cout << " - memory allocation error for char[] destination" << endl;
        exit(1);
    }
}

/**
 * Геттер направления поезда.
 * @return
 */
char* Train::getDestination() {
    return this->destination;
}

/**
 * Геттер номера поезда.
 * @return
 */
int Train::getTrainNumber() {
    return this->trainNumber;
}

/**
 * Геттер времени отправления поезда.
 * @return
 */
char* Train::getDepartureTime() {
    return this->departureTime;
}

/**
 * Метод конвертирует строковое представление времени отправления поезда в целочисленный тип. Возвращает время в минутах.
 * В минутах - для удобства последующей сортировки по времени отправления.
 * @return
 */
int Train::getConvertedDepartureTime() {
    int hours = ((int) this->departureTime[0] - '0') * 10 + (int) this->departureTime[1] - '0';
    int minutes = ((int) this->departureTime[3] - '0') * 10 + (int) this->departureTime[4] - '0';
    return hours * 60 + minutes;
}

/**
 * Перегруженный оператор вывода.
 * @param stream
 * @param obj
 * @return
 */
ostream &operator<<(ostream &stream, Train &obj) {
    stream << "Destination: " << obj.getDestination() << endl;
    stream << "Train number: " << obj.getTrainNumber() << endl;
    stream << "Departure time: " << obj.getDepartureTime() << endl;
    return stream;
}

/**
 * Перегруженный оператор присваивания.
 * @param train
 * @return
 */
Train &Train::operator=(const Train &train) {
    size_t len = strlen(train.destination) + 1;
    this->destination = new char[len];
    if (!this->destination) {
        cout << " - memory allocation error for char[] destination" << endl;
        exit(1);
    }
    strcpy(this->destination, train.destination);

    this->trainNumber = train.trainNumber;

    len = strlen(train.departureTime) + 1;
    this->departureTime = new char[len];
    if (!this->departureTime) {
        cout << " - memory allocation error for char[] departureTime" << endl;
        exit(1);
    }
    strcpy(this->departureTime, train.departureTime);
    return *this;
}