#include <iostream>
#include "train.h"
#define TRAIN_NUMS 6

using namespace std;




int main() {
    Train* testTrain;

    testTrain = new Train[TRAIN_NUMS];

    for (int i = 0; i < TRAIN_NUMS; i++) {
        cin >> testTrain[i];
    }

    Train::sortTrains(testTrain);

    for (int i = 0; i < TRAIN_NUMS; i++) {
        cout << testTrain[i];
    }

/*
    Train test;

    cin >> test;

    cout << test;
*/
    return 0;

}


