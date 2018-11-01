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
    Train *trains; // = new Train[TRAIN_NUMS];
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

    int getAmountTrains();

    Train* getTrains();

    void setAmountTrains(int);

    void setTrains(Train*, int);

    /**
     * Перегруженный оператор вывода.
     * @return
     */
    friend ostream &operator<<(ostream&, TrainList);

    friend istream &operator>>(istream &, TrainList &);

    /**
     * Метод добавления поездов в коллекцию.
     * @return
     */
    TrainList &operator+=(Train&);

    /**
     * Метод поиска поездов по направлению.
     * @return
     */
    TrainList findTrainsByDestinationName(char*);

    /**
     * Сортировка поездов по направлению.
     * @return
     */
    TrainList sortTrains();

    TrainList &operator=(TrainList &);

    void showTrains();

    void addTrains();
};


#endif //SUAI_TP_TRAINLIST_H
