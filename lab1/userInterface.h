#ifndef SUAI_TP_USERINTERFACE_H
#define SUAI_TP_USERINTERFACE_H

#include "train.h"
#include "trainList.h"

using namespace std;
/**
 * Class UserInterface.
 * @author: Ivanov Daniil (dania-spb@mail.ru)
 * @since: 1.10.2018
 */
class UserInterface {
private:
    /**
     * Контстанта выбора меню - выход из программы.
     */
    static const char EXIT = '0';

    /**
     * Константа выбора меню - добавление поездов в коллекцию.
     */
    static const char ADD = '1';

    /**
     * Константа выбора меню - вывод всех поездов коллекции.
     */
    static const char SHOW = '2';

    /**
     * Константа выбора меню - сортировка поездов коллекции по времени отправления.
     */
    static const char SORT = '3';

    /**
     * Константа выбора меню - поиск поездов по заданному направлению.
     */
    static const char FIND_BY_DESTINATION = '4';

    /**
     * Коллекция поездов.
     */
    TrainList trainList;
public:

    /**
     * Точка входа в пользовательский интерфейс.
     */
    void init();

    /**
     * Добавить поезда в коллекцию.
     */
    void addTrains();

    /**
     * Вывод всех поездов коллекции.
     */
    void showTrains();

    /**
     * Сортировка поездов коллекции по времени отправления.
     */
    void sortTrains();

    /**
     * Поиск и вывод поездов по заданному направлению.
     */
    void findTrainsByDestination();

    /**
     * Вывести меню пользователя.
     */
    void showMenu();
};

#endif //SUAI_TP_USERINTERFACE_H
