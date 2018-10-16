//
// Created by daniil on 01.10.18.
//

#ifndef UNTITLED_TRAIN_H
#define UNTITLED_TRAIN_H

#include <iostream>
#include <string>
#include "time.h"

using namespace std;
/**
 * Class Train.
 * @author: Ivanov Daniil (dania-spb@mail.ru)
 * @since: 1.10.2018
 */
class Train {
private:
    /**
     * Contains destination name.
     */
    char* destination;
    /**
     * Contains train number.
     */
    int trainNumber;
    /**
     * Contains departure time.
     */
    char* departureTime;
public:
    Train(char*, int, char*);
    Train();
    ~Train();
    void setDestination(char*);
    void setTrainNumber(int);
    void setDepartureTime(char*);
    char* getDestination();
    int getTrainNumber();
    char* getDepartureTime();
    friend ostream& operator<<(ostream&, Train);
    friend istream&operator>>(istream&, Train&);
    int getConvertedDepartureTime();
    static Train* sortTrains(Train*);
    Train(const Train&);
    Train &operator=(Train&);

};


#endif //UNTITLED_TRAIN_H
