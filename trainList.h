#ifndef SUAI_TP_TRAINLIST_H
#define SUAI_TP_TRAINLIST_H

#include "train.h"

using namespace std;
/**
 * Class TrainList.
 * @author: Ivanov Daniil (dania-spb@mail.ru)
 * @since: 1.10.2018
 */
class TrainList {
private:
    /**
     * Массив объектов типа Train - поезда в списке.
     */
    Train *trains;

    /**
     * Количество поездов в списке.
     */
    int amountTrains;
public:
    /**
     * Конструктор без параметров.
     */
    TrainList();

    /**
     * Конструктор с параметрами.
     */
    TrainList(Train*, int);

    /**
     * Конструктор копии.
     */
    TrainList(const TrainList&);

    /**
     * Деструктор.
     */
    ~TrainList();

    /**
     * Сеттер массива объектов типа Train.
     */
    void setTrains(Train*, int);

    /**
     * Сеттер количества поездов в коллекции.
     */
    void setAmountTrains(int);

    /**
    * Геттер экземпляров класса Train..
    * @return Массив экземпляров класса Train.
    */
    Train* getTrains();

    /**
     * Геттер количества поездов в коллекции.
     * @return Количество поездов в коллекции.
     */
    int getAmountTrains();

    /**
     * Сортировка поездов по времени отправления.
     * @return Коллекцию поездов с выполненной сортировкой.
     */
    TrainList sortTrains();

    /**
     * Метод поиска поездов по заданному направлению.
     * @return Коллекцию найденных поездов.
     */
    TrainList findTrainsByDestinationName(char*);

    /**
     * Перегруженный оператор вывода.
     * @return
     */
    friend ostream &operator<<(ostream&, TrainList &);

    /**
     * Перегруженный оператор ввода.
     * @return
     */
    friend istream &operator>>(istream &, TrainList &);

    /**
     * Добавления поездов в коллекцию.
     * @return
     */
    TrainList &operator+=(Train&);

    /**
     * Перегруженный оператор присваивания.
     * @return
     */
    TrainList &operator=(TrainList &);
//fix this - use << instead
    void showTrains();
};


#endif //SUAI_TP_TRAINLIST_H
