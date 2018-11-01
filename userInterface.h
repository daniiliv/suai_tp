#ifndef SUAI_TP_USERINTERFACE_H
#define SUAI_TP_USERINTERFACE_H

#include "train.h"
#include "trainList.h"

#define TRAIN_NUMS 3

using namespace std;
/**
 * Class UserInterface.
 * @author: Ivanov Daniil (dania-spb@mail.ru)
 * @since: 1.10.2018
 */
class UserInterface {
private:
    static const char EXIT = '0';
    static const char ADD = '1';
    static const char SHOW = '2';
    static const char SORT = '3';
    static const char FIND_BY_DESTINATION = '4';

    TrainList trainList;
public:

    UserInterface();

    void init();

    void addTrains();

    void showTrains();

    void sortTrains();

    void findTrainsByDestination();

    void showMenu();

};

#endif //SUAI_TP_USERINTERFACE_H
