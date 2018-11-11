#include <cstring>
#include "userInterface.h"

/**
 * Точка входа в пользовательский интерфейс.
 */
void UserInterface::init() {
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
        }
    }
}

/**
 * Добавить поезда в коллекцию.
 */
void UserInterface::addTrains() {
    cout << "------------ Add trains --------------" << endl;
    cin >> this->trainList;
}

/**
 * Вывод всех поездов коллекции.
 */
void UserInterface::showTrains() {
    cout << "------------ Show all trains --------------" << endl;
    cout << this->trainList;
}

/**
 * Сортировка поездов коллекции по времени отправления.
 */
void UserInterface::sortTrains() {
    char answer;
    cout << "------------ Sort trains --------------" << endl;
    this->trainList.sortTrains();
    cout << "Done! \nOutput sorted train list? (type in: y/n)" << endl;
    cin >> answer;
    if (answer == 'y') {
        this->showTrains();
    }
}

/**
 * Поиск и вывод поездов по заданному направлению.
 */
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

    TrainList tempTrainList = this->trainList.findTrainsByDestinationName(dest);
    cout << tempTrainList;
    delete [] temp;
    delete [] dest;
}

/**
 * Вывести меню пользователя.
 */
void UserInterface::showMenu() {
    cout << "Type in a number and press \"Enter\" to choose your option:" << endl;
    cout << "1 - Input data about trains." << endl;
    cout << "2 - Ouput data about trains." << endl;
    cout << "3 - Sort trains by departure time." << endl;
    cout << "4 - Find trains by destination name." << endl;
    cout << "0 - Exit." << endl;
}







