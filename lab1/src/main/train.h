//
// Created by daniil on 01.10.18.
//

#ifndef UNTITLED_TRAIN_H
#define UNTITLED_TRAIN_H

#include <iostream>
#include <string>

using namespace std;
/**
 * Class Train.
 * @author: Ivanov Daniil (dania-spb@mail.ru)
 * @since: 1.10.2018
 * test
 *
 */
class Train {
    //contains destination's name
    string destination;
    //contains train's number
    int trainNumber;
    //contains departure's time
    string departureTime;
public:
    Train(string, int, string);
    Train();
    ~Train();
};


#endif //UNTITLED_TRAIN_H
