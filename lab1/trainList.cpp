#include <cstring>
#include "trainList.h"

#define TRAIN_NUMS 6

/**
 * Конструктор по умолчанию.
 */
TrainList::TrainList() {
    this->trains = new Train[TRAIN_NUMS];
    if (!this->trains) {
        cout << " - memory allocation error for Train[] trains" << endl;
    }
    this->amountTrains = 0;
    //cout << "Default constructor called! TrainList object." << endl;
}

/**
 * Конструктор с параметрами
 * @param trains Массив объектов типа Train.
 * @param count Количество объектов.
 */
TrainList::TrainList(Train* trains, int count) {
    this->trains = new Train[count];
    if (!this->trains) {
        cout << " - memory allocation error for Train[] trains" << endl;
    }
    for (int i = 0; i < count; i++) {
        this->trains[i] = trains[i];
    }

    this->amountTrains = count;
   // cout << "Constructor with parameters called. TrainList object." << endl;
}

/**
 * Конструктор копии.
 * @param trainList
 */
TrainList::TrainList(const TrainList &trainList) {
    int count = trainList.amountTrains;
    this->trains = new Train[count];
    if (!this->trains) {
        cout << " - memory allocation error for Train[] trains" << endl;
    }
    for (int i = 0; i < count; i++) {
        this->trains[i] = trainList.trains[i];
    }
    this->amountTrains = count;
}

/**
 * Деструктор.
 */
TrainList::~TrainList() {
    delete[] this->trains;
    this->amountTrains = 0;
   // cout << "Destructor called! TrainList object." << endl;
}

/**
 * Сеттер количества поездов в коллекции.
 */
void TrainList::setAmountTrains(int count) {
    this->amountTrains = count;
}

/**
 * Сеттер массива объектов типа Train.
 */
void TrainList::setTrains(Train *trains, int count) {
    this->trains = new Train[count];
    if (!this->trains) {
        cout << " - memory allocation error for Train[] trains" << endl;
    }
    for (int i = 0; i < count; i++) {
        this->trains[i] = trains[i];
    }
    this->amountTrains = count;
}

/**
 * Геттер экземпляров класса Train..
 * @return Массив экземпляров класса Train.
 */
Train *TrainList::getTrains() {
    return this->trains;
}

/**
 * Геттер количества поездов в коллекции.
 * @return Количество поездов в коллекции.
 */
int TrainList::getAmountTrains() {
    return this->amountTrains;
}

/**
 * Сортировка поездов по времени отправления.
 * @return Коллекцию поездов с выполненной сортировкой.
 */
TrainList TrainList::sortTrains() {
    bool swapped = false;
    Train temp;
    for (int i = 0; i < amountTrains - 1; i++) {
        swapped = false;
        for (int j = 0; j < amountTrains - i - 1; j++) {
            if(trains[j].getConvertedDepartureTime() > trains[j + 1].getConvertedDepartureTime()) {
                temp = trains[j];
                trains[j] = trains[j + 1];
                trains[j + 1] = temp;
                swapped = true;
            }
        }
        if(!swapped) {
            break;
        }
    }
    return *this;
}

/**
 * Метод поиска поездов по заданному направлению.
 * @return Коллекцию найденных поездов.
 */
TrainList TrainList::findTrainsByDestinationName(char *destination) {
    Train* temp = new Train[amountTrains]; //временная переменная для хранения необходимых поездов
    TrainList trainList; //объект, который вернет функция
    size_t searchSize, myCharSize, endOfString;
    int numOfTrainsFound = 0;
    searchSize = 0;
    size_t searchCharSize = strlen(destination) + 1; //длина названия искомого направления

    for (int i = 0; i < amountTrains; i++) {
        myCharSize = strlen(trains[i].getDestination() + 1); //длина названия направления текущего поезда
        endOfString = searchCharSize < myCharSize ? searchCharSize : myCharSize; //to avoid arrayOutOfBoundException, конец сравнивых строк
        char* currTrainDestintaion = trains[i].getDestination();
        for (int j = 0; j < endOfString; j++) {
            if (currTrainDestintaion[j] == destination[j]) {
                searchSize++;
            }
        }
        if (searchSize == myCharSize) {
            temp[numOfTrainsFound++] = trains[i];
            searchSize = 0;
        }
    }
    if (numOfTrainsFound) {
        trainList.setTrains(temp, numOfTrainsFound);
    }
    return trainList;
}

/**
 * Перегруженный оператор вывода.
 * @param stream
 * @param trainList
 * @return
 */
ostream &operator<<(ostream &stream, TrainList &trainList) {
    if (trainList.getAmountTrains() == 0) {
        stream << "There are no trains." << endl;
    } else {
        stream << "Train list: " << endl;
        for (int i = 0; i < trainList.getAmountTrains(); i++) {
            stream << trainList.getTrains()[i];
        }
    }
    return stream;
}

/**
 * Перегруженный оператор ввода.
 * @return
 */
istream &operator>>(istream &stream, TrainList &trainList) {
    Train *tempTrains = new Train[TRAIN_NUMS];
    if (!tempTrains) {
        cout << "Mem alloc error!" << endl;
    }
    char *dest = new char[50];
    if (!dest) {
        cout << "Mem alloc error!" << endl;
    }
    int trNum;
    char* depTime = new char[10];
    if (!depTime) {
        cout << "Mem alloc error!" << endl;
    }

    for (int i = 0; i < TRAIN_NUMS; i++) {
        cout << "Enter destination: ";
        cin >> dest;
        tempTrains[i].setDestination(dest);

        cout << "Enter train number: ";
        cin >> trNum;
        tempTrains[i].setTrainNumber(trNum);

        cout << "Enter departure time in format (00:00): ";
        cin >> depTime;
        tempTrains[i].setDepartureTime(depTime);

        trainList+=tempTrains[i];
    }
    delete [] dest;
    delete [] depTime;
    delete [] tempTrains;
    return stream;
}

/**
 * Добавление поездов в коллекцию.
 * @return
 */
TrainList &TrainList::operator+=(Train &train) {
    trains[amountTrains].setDestination(train.getDestination());
    trains[amountTrains].setTrainNumber(train.getTrainNumber());
    trains[amountTrains].setDepartureTime(train.getDepartureTime());
    amountTrains++;
    return *this;
}

/**
 * Перегруженный оператор присваивания.
 * @return
 */
TrainList &TrainList::operator=(TrainList &trainList) {
    int count = trainList.amountTrains;
    this->trains = new Train[count];
    if (!this->trains) {
        cout << "Mem alloc error!" << endl;
    }
    for (int i = 0; i < count; i++) {
        this->trains[i] = trainList.trains[i];
    }

    this->amountTrains = count;
    return *this;
}

//fix this - use << instead
void TrainList::showTrains() {
    if (this->amountTrains == 0) {
        cout << "There are no trains.";
    } else {
        cout << "Train list: " << endl;
        for (int i = 0; i < this->amountTrains; i++) {
            cout << this->trains[i];
        }
    }
}








