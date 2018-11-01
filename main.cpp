#include <iostream>
#include <cstring>
#include "train.h"
#include "userInterface.h"

#define TRAIN_NUMS 3

using namespace std;

int main() {
    /*
    Train* trains;

    trains = new Train[TRAIN_NUMS];

    char* destination;
    cout << "Type in a number and press \"Enter\" to choose your option:" << endl;
    cout << "1 - Input data about trains." << endl;
    cout << "2 - Ouput data about trains." << endl;
    cout << "3 - Sort trains by departure time." << endl;
    cout << "4 - Find trains by destination name." << endl;
    cout << "0 - Exit." << endl;

    for(;;) {
        switch (getchar()) {
            case '0':
                cout << "Exit!" << endl;
                return 0;
            case '1':
                for (int i = 0; i < TRAIN_NUMS; i++) {
                    cin >> trains[i];
                }
                break;
            case '2':
                for (int i = 0; i < TRAIN_NUMS; i++) {
                    cout << trains[i];
                }
                break;
            case '3':
                Train::sortTrains(trains);
                break;
            case '4':
                destination = Train::inputDestinationFromKeyboard();
                Train::findTrainsByDestinationName(destination, trains);
                break;
            default:
                cout << "An invalid choice." << endl;
        }
    }
     */
    UserInterface UI;
    UI.init();

/*
    TrainList trainList;

    static const char EXIT = '0';
    static const char ADD = '1';
    static const char SHOW = '2';
    static const char SORT = '3';
    static const char FIND_BY_DESTINATION = '4';




    bool exit = false;
    cout << "Type in a number and press \"Enter\" to choose your option:" << endl;
    cout << "1 - Input data about trains." << endl;
    cout << "2 - Ouput data about trains." << endl;
    cout << "3 - Sort trains by departure time." << endl;
    cout << "4 - Find trains by destination name." << endl;
    cout << "0 - Exit." << endl;
    while(!exit) {
        int answer = getchar();
        switch (answer) {
            case EXIT:
                cout << "Exit!" << endl;
                exit = true;
                break;
            case ADD:
                trainList.addTrains();
                break;
            case SHOW:
                trainList.showTrains();
                break;
            case SORT:
                trainList.sortTrains();
                break;
            case FIND_BY_DESTINATION:
                char *temp = new char[50];
                cout << "Enter destination: ";
                cin >> temp;
                size_t len = strlen(temp) + 1;
                char *dest = new char[len];
                /*if(!dest) {
                    cout << "Mem alloc error" << endl;
                    exit(1);
                }
                strcpy(dest, temp);
                trainList.findTrainsByDestinationName(dest);
                break;*/
           // default:
           //     cout << "An invalid choice." << endl;
           //     break;


    return 0;
}


