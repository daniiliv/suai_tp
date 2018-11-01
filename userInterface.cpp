
#include <cstring>
#include "userInterface.h"




#define TRAIN_NUMS 3

void UserInterface::showMenu() {
    cout << "Type in a number and press \"Enter\" to choose your option:" << endl;
    cout << "1 - Input data about trains." << endl;
    cout << "2 - Ouput data about trains." << endl;
    cout << "3 - Sort trains by departure time." << endl;
    cout << "4 - Find trains by destination name." << endl;
    cout << "0 - Exit." << endl;
}

void UserInterface::addTrains() {
    cout << "------------ Add trains --------------" << endl;
    //cin >> this->trainList;
    this->trainList.addTrains();
}

void UserInterface::showTrains() {
    //Train *trains = this->trainList.getTrains();


    cout << "------------ Show all trains --------------" << endl;
    //cout << this->trainList;
    this->trainList.showTrains();
    /*
    if (this->trainList.getAmountTrains() == 0) {
        cout << "There are no trains.";
    } else {
        cout << "Train list: " << endl;
        for (int i = 0; i < this->trainList.getAmountTrains(); i++) {
            cout << trains[i];
        }
    }
    */

}

void UserInterface::sortTrains() {
    char answer;
    cout << "------------ Sort trains --------------" << endl;
    this->trainList.sortTrains();
    cout << "Done! \nOutput sorted train list? (type in: y/n)" << endl;
    cin >> answer;
    if (answer == 'y') {
        this->trainList.showTrains();
    }
}
/////stop here
void UserInterface::findTrainsByDestination() {
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

    //cout << trainList.findTrainsByDestinationName(dest);


    delete [] temp;
}

void UserInterface::init() {

    /*
      initscr();
    cbreak();
    noecho();
    scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);
*/
    bool exit = false;
    showMenu();
    while(!exit) {
        int answer = getchar();
        switch (answer) {
            case EXIT:
                cout << "Exit!" << endl;
                exit = true;
                break;
            case ADD:
                addTrains();
                break;
            case SHOW:
                showTrains();
                break;
            case SORT:
                sortTrains();
                break;
            case FIND_BY_DESTINATION:
                findTrainsByDestination();
                break;
            default:
                cout << "An invalid choice." << endl;
                break;
        }
    }
}

UserInterface::UserInterface() {
    cout << "Constructor UI" << endl;
}








