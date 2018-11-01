//
// Created by daniil on 30.10.18.
//

#include <cstring>
#include "trainList.h"

#define TRAIN_NUMS 3

TrainList::TrainList() {
    this->trains = new Train[TRAIN_NUMS];
    this->amountTrains = 0;
    cout << "Default constructor called! TL\n";
}

TrainList::TrainList(Train* trains, int count) {
    this->trains = new Train[count];
    for (int i = 0; i < count; i++) {
        this->trains[i] = trains[i];
    }

    this->amountTrains = count;
    /*
    try {
        if (count > TRAIN_NUMS) {
            throw 1;
        }
        this->trains = new Train[count];
        for (int i = 0; i < count; i++) {
            this->trains[i] = trains[i];
        }

        this->amountTrains = count;

        if (!trains) {
            throw 2;
        }

        cout << "Constructor with parameters called" << endl;

    }
    catch (int a) {
        cout << "Caught exception number:  " << a;
        if (a == 1) {
            cout << " - error - too many trains!" << endl;
        }
        if (a == 2) {
            cout << " - memory allocation error for Train[] trains" << endl;
        }
    } */
}



TrainList::~TrainList() {

    delete[] this->trains;
    this->amountTrains = 0;

    cout << "Destructor called! TL" << endl;
}

ostream &operator<<(ostream &stream, TrainList trainList) {

    //Train *trains;
    //trains = trainList.getTrains();
    if (trainList.getAmountTrains() == 0) {
        stream << "There are no trains.";
    } else {
        stream << "Train list: " << endl;
        for (int i = 0; i < trainList.getAmountTrains(); i++) {
            trainList.getTrains()[i].showTrain();
        }
    }
    /*
    int trainsCount = trainList.getAmountTrain();
    Train* trains = trainList.getTrains();
    for (int i = 0; i < trainsCount; i++) {
        stream << "Destination: " << trains[i].getDestination() << endl;
        stream << "Train number: " << trains[i].getTrainNumber() << endl;
        stream << "Departure time: " << trains[i].getDepartureTime() << endl;
    }
    */
    return stream;
}



Train *TrainList::getTrains() {
    return this->trains;
}

int TrainList::getAmountTrains() {
    return this->amountTrains;
}

void TrainList::setAmountTrains(int count) {
    this->amountTrains = count;
}

void TrainList::setTrains(Train *trains, int count) {
    this->trains = new Train[count];
    for (int i = 0; i < count; i++) {
        this->trains[i] = trains[i];
    }

    this->amountTrains = count;
    /*

    try {
        if (count > TRAIN_NUMS) {
            throw 1;
        }
        delete [] trains;
        this->trains = new Train[count];
        this->trains = trains;
        this->amountTrains = count;

        if (!trains) {
            throw 2;
        }

        cout << "Constructor with parameters called" << endl;

    }
    catch (int a) {
        cout << "Caught exception number:  " << a;
        if (a == 1) {
            cout << " - error - too many trains!" << endl;
        }
        if (a == 2) {
            cout << " - memory allocation error for Train[] trains" << endl;
        }
    }
     */
}

TrainList TrainList::findTrainsByDestinationName(char *destination) {
    Train* temp = new Train[amountTrains];
    TrainList trainList;
    size_t searchSize = 0;
    size_t myCharSize = 0;
    size_t searchCharSize = strlen(destination) + 1;
    size_t endOfString = 0;
    int numOfTrainsFound = 0;
    for (int i = 0; i < amountTrains; i++) {
        myCharSize = strlen(trains[i].getDestination() + 1);
        endOfString = searchCharSize < myCharSize ? searchCharSize : myCharSize; //to avoid arrayOutOfBoundException
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
    if (numOfTrainsFound == 0) {
        //cout << "There are no trains of this destination name!" << endl;
        //trainList.setAmountTrains(0);
        return trainList;
    } else {
        //TrainList tempTrainList(temp, numOfTrainsFound);
        //trainList = tempTrainList;
        //cout << "Trains were found:" << endl;
        //cout << trainList;
        //trainList.setAmountTrains(numOfTrainsFound);
        trainList.setTrains(temp, numOfTrainsFound);
    }

    return trainList;
}

TrainList &TrainList::operator+=(Train &train) {

    this->trains[this->amountTrains++] = train;
    cout << "am trains: " << amountTrains << endl;
    return *this;
}

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
                //cout << trains[j] << trains[j + 1];
            }
        }
        if(!swapped) {
            break;
        }
    }
    //TrainList trainList(trains, amountTrains);

    return *this;
}

istream &operator>>(istream &stream, TrainList &trainList) {
    /*
    for (int i = 0; i < trains.getAmountTrains(); i++) {
        stream >> trainList.trains[i];
    }
    */

    Train *trains = new Train[TRAIN_NUMS];
    char *dest = new char[50];
    int trNum;
    char* depTime = new char[6];

    for (int i = 0; i < TRAIN_NUMS; i++) {
        cout << "Enter destination: ";
        cin >> dest;
        trainList.trains[i].setDestination(dest);

        cout << "Enter train number: ";
        cin >> trNum;
        trainList.trains[i].setTrainNumber(trNum);

        cout << "Enter departure time in format (00:00): ";
        cin >> depTime;
        trainList.trains[i].setDepartureTime(depTime);

        trainList+=trainList.trains[i];
    }
    delete [] dest;
    delete [] depTime;

    return stream;
}

void TrainList::addTrains() {
    //Train *trains = new Train[TRAIN_NUMS];
    char *dest = new char[50];
    int trNum;
    char* depTime = new char[10];

    for (int i = 0; i < TRAIN_NUMS; i++) {
        cout << "Enter destination: ";
        cin >> dest;
        trains[i].setDestination(dest);

        cout << "Enter train number: ";
        cin >> trNum;
        trains[i].setTrainNumber(trNum);

        cout << "Enter departure time in format (00:00): ";
        cin >> depTime;
        trains[i].setDepartureTime(depTime);

        amountTrains++;

        //*this+=trains[i];
    }
    delete [] dest;
    delete [] depTime;
}

TrainList::TrainList(const TrainList &trainList) {
    int count = trainList.amountTrains;
    this->trains = new Train[count];
    for (int i = 0; i < count; i++) {
        this->trains[i] = trains[i];
    }

    this->amountTrains = count;

    /*
    try {
        cout << "TEST IN CC1: " << trainList.trains[0] << trainList.trains[1] << trainList.trains[2] << endl;
        int count = trainList.amountTrains;
        delete[] this->trains;
        this->trains = new Train[count];
        if (!(this->trains)) {
            throw 1;
        }
        for (int i = 0; i < trainList.amountTrains; i++) {
            this->trains[i] = trainList.trains[i];
        }
        //this->trains = trainList.trains;
        cout << "TEST IN CC2: " << this->trains[0] << trains[1] << trains[2] << endl;
        this->amountTrains = trainList.amountTrains;
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
     */
}

TrainList &TrainList::operator=(TrainList &trainList) {
    int count = trainList.amountTrains;
    this->trains = new Train[count];
    for (int i = 0; i < count; i++) {
        this->trains[i] = trains[i];
    }

    this->amountTrains = count;
    /*
    try {
        int count = trainList.amountTrains;
        delete[] this->trains;
        this->trains = new Train[count];
        if (!(this->trains)) {
            throw 1;
        }
        for (int i = 0; i < trainList.amountTrains; i++) {
            this->trains[i] = trainList.trains[i];
        }
        //this->trains = trainList.trains;
        cout << "TEST IN CC2: " << this->trains[0] << trains[1] << trains[2] << endl;
        this->amountTrains = trainList.amountTrains;

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
         */
    /*}
    catch (int a) {
        cout << "Caught exception number:  " << a;
        if (a == 1) {
            cout << " - memory allocation error for char[] destination" << endl;
        }
        else if (a == 2) {
            cout << " - memory allocation error for char[] departureTime" << endl;
        }
        exit(1);
    }*/
    return *this;
}

void TrainList::showTrains() {
    if (amountTrains == 0) {
        cout << "There are no trains.";
    } else {
        cout << "Train list: " << endl;
        for (int i = 0; i < amountTrains; i++) {
            trains[i].showTrain();
        }
    }
}







