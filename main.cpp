#include <iostream>
#include "train.h"
#define TRAIN_NUMS 3

using namespace std;




int main() {
    Train* testTrain;

    testTrain = new Train[TRAIN_NUMS];

    char choice;

    char* destination;
    cout << "Type in a number and press \"Enter\" to choose your option:" << endl;
    cout << "1 - Input data about trains." << endl;
    cout << "2 - Ouput data about trains." << endl;
    cout << "3 - Sort trains by departure time." << endl;
    cout << "4 - Find trains by destination name." << endl;
    cout << "0 - Exit." << endl;

    for(;;) {
        switch (choice = getchar()) {
            case '0':
                cout << "Exit!" << endl;
                return 0;
            case '1':
                for (int i = 0; i < TRAIN_NUMS; i++) {
                    cin >> testTrain[i];
                }
                break;
            case '2':
                for (int i = 0; i < TRAIN_NUMS; i++) {
                    cout << testTrain[i];
                }
                break;
            case '3':
                Train::sortTrains(testTrain);
                break;
            case '4':
                destination = Train::inputDestinationFromKeyboard();
                Train::findTrainsByDestinationName(destination, testTrain);
                break;
            default:
                cout << "An invalid choice." << endl;
        }
    }


    return 0;

}


