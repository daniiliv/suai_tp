#include "train.h"
#include <iostream>
#include <cstring>

#define TRAIN_NUMS 3

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
        if (!(this->departureTime)) {
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
    cout << "Constructor with parameters called!\n";
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
        cout << "Default constructor called! T\n";
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
 * Деструктор.
 */
Train::~Train() {
    delete [] this->destination;
    delete [] this->departureTime;
    trainNumber = 0;
    cout << "Destructor called! T\n";
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

void Train::showTrain() {
    cout << "Destination: " << this->destination << endl;
    cout << "Train number: " << this->trainNumber << endl;
    cout << "Departure time: " << this->departureTime << endl;
}
/**
 * Метод конвертирует строковое представление времени отправления поезда в целочисленный тип. Возвращает время в минутах.
 * В минутах - для удобства последующей сортировки по времени отправления.
 * @return
 */

int Train::getConvertedDepartureTime() {
    int hours = ((int)departureTime[0] - '0') * 10 + (int)departureTime[1] - '0';
    int minutes = ((int)departureTime[3] - '0') * 10 + (int)departureTime[4] - '0';

    return hours * 60 + minutes;
}


/**
 * Конструктор копии.
 * @param train
 */
Train::Train(const Train &train) {
    size_t len = strlen(train.destination) + 1;
    destination = new char[len];
    strcpy(destination, train.destination);

    len = strlen(train.departureTime) + 1;
    departureTime = new char[len];
    strcpy(departureTime, train.departureTime);

    trainNumber = train.trainNumber;
    /*
    try {/*
        size_t len;
        len = strlen(train.destination) + 1;
        this->destination = new char[len];
        if (!(this->destination)) {
            throw 1;
        }
        strcpy(this->destination, train.destination);

        this->trainNumber = train.trainNumber;

        len = strlen(train.departureTime) + 1;
        this->departureTime = new char[len];
        if (!(this->departureTime)) {
            throw 2;
        }
        strcpy(this->departureTime, train.departureTime);
        */
    /*
        if (strlen(this->destination) < strlen(train.destination)) {
            delete[] this->destination;
            this->destination = new char[strlen(train.destination)];
            if (!(this->destination)) {
                throw 1;
            }
        }
        strcpy(this->destination, train.destination);

        this->trainNumber = train.trainNumber;
        if (strlen(this->departureTime) < strlen(train.departureTime)) {
            delete[] this->departureTime;
            this->departureTime = new char[strlen(train.departureTime)];
            if (!(this->departureTime)) {
                throw 2;
            }
        }
        strcpy(this->departureTime, train.departureTime);
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
    } */
}

/**
 * Перегруженный оператор присваивания.
 * @param train
 * @return
 */
Train &Train::operator=(const Train &train) {

    size_t len = strlen(train.destination) + 1;
    destination = new char[len];
    strcpy(destination, train.destination);

    len = strlen(train.departureTime) + 1;
    departureTime = new char[len];
    strcpy(departureTime, train.departureTime);

    trainNumber = train.trainNumber;

    return *this;

    /*
    try {
        if (strlen(this->destination) < strlen(train.destination)) {
            delete[] this->destination;
            this->destination = new char[strlen(train.destination)];
            if (!(this->destination)) {
                throw 1;
            }
        }
        strcpy(this->destination, train.destination);

        this->trainNumber = train.trainNumber;
        if (strlen(this->departureTime) < strlen(train.departureTime)) {
            delete[] this->departureTime;
            this->departureTime = new char[strlen(train.departureTime)];
            if (!(this->departureTime)) {
                throw 2;
            }
        }
        strcpy(this->departureTime, train.departureTime);

        /*
        size_t len;
        len = strlen(train.destination) + 1;
        this->destination = new char[len];
        if (!(this->destination)) {
            throw 1;
        }
        strcpy(this->destination, train.destination);

        this->trainNumber = train.trainNumber;

        len = strlen(train.departureTime) + 1;
        this->departureTime = new char[len];
        if (!(this->departureTime)) {
            throw 2;
        }
        strcpy(this->departureTime, train.departureTime);

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
    return *this; */

}

/**
 * Статический метод поиска поездов по направлению поезда.
 * @param destination Направление поезда.
 * @param trains Массив экземпляров класса Train.
 * @return Найденные поезда.
 */
 /*
Train *Train::findTrainsByDestinationName(char *destination, Train *trains) {
    Train* temp = new Train[TRAIN_NUMS];
    size_t searchSize = 0;
    size_t myCharSize = 0;
    size_t searchCharSize = strlen(destination) + 1;
    size_t endOfString = 0;
    int numOfTrainsFound = 0;
    for (int i = 0; i < TRAIN_NUMS; i++) {
        myCharSize = strlen(trains[i].getDestination() + 1);
        endOfString = searchCharSize < myCharSize ? searchCharSize : myCharSize; //to avoid arrayOutOfBoundException
        for (int j = 0; j < endOfString; j++) {
            if (trains[i].getDestination()[j] == destination[j]) {
                searchSize++;
            }
        }
        if (searchSize == myCharSize) {

            temp[numOfTrainsFound++] = trains[i];
            searchSize = 0;
        }
    }
    if (numOfTrainsFound == 0) {
        cout << "There are no trains of this destination name!" << endl;
        return trains;
    } else {
        cout << "Trains were found:" << endl;
        for (int i = 0; i < numOfTrainsFound; i++) {
            cout << temp[i];
        }
    }

    return temp;
}
*/
/**
 * Статический метод пользовательского ввода направления поезда с клавиатуры.
 * @return
 */
 /*
char *Train::inputDestinationFromKeyboard() {
    char *temp = new char[50];
    cout << "Enter destination: ";
    cin >> temp;
    size_t len = strlen(temp) + 1;
    char *dest = new char[len];
    if(!dest) {
        cout << "Mem alloc error" << endl;
        exit(1);
    }
    strcpy(dest, temp);
    return dest;
}
*/

/**
* Перегруженный оператор ввода.
* @param stream
* @param obj
* @return
*/
/*
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
*/

/**
 * Метод сортирует экземпляры класса Train по времени отправления поезда.
 * В хронологическом порядке - от более раннего к более позднему.
 * @param train
 * @return
 */
/*
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
*/