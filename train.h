#ifndef UNTITLED_TRAIN_H
#define UNTITLED_TRAIN_H

#include <iostream>

using namespace std;
/**
 * Class Train.
 * @author: Ivanov Daniil (dania-spb@mail.ru)
 * @since: 1.10.2018
 */
class Train {
private:

    /**
     * Contains destination name.
     */
    char* destination;

    /**
     * Contains train number.
     */
    int trainNumber;

    /**
     * Contains departure time.
     */
    char* departureTime;
public:

    /**
     * Конструктор с параметрами.
     */
    Train(char*, int, char*);

    /**
     * Конструктор без параметров.
     */
    Train();

    /**
     * Деструктор.
     */
    ~Train();

    /**
     * Сеттер направления.
     */
    void setDestination(char*);

    /**
     * Сеттер номера поезда.
     */
    void setTrainNumber(int);

    /**
     * Сеттер времени отправления поезда.
     */
    void setDepartureTime(char*);

    /**
     * Геттер направления.
     */
    char* getDestination();

    /**
     * Геттер номера поезда.
     * @return
     */
    int getTrainNumber();

    /**
     * Геттер времени отправления поезда.
     * @return
     */
    char* getDepartureTime();

    /**
     * Перегруженный оператор вывода.
     * @return
     */
    friend ostream& operator<<(ostream&, Train);

    /**
     * Перегруженный оператор ввода.
     * @return
     */
   // friend istream&operator>>(istream&, Train&);

    /**
     * Метод конвертирует строковое представление времени отправления поезда в целочисленный тип. Возвращает время в минутах.
     * В минутах - для удобства последующей сортировки по времени отправления.
     * @return
     */
    int getConvertedDepartureTime();

    /**
     * Метод сортирует экземпляры класса Train по времени отправления поезда.
     * В хронологическом порядке - от более раннего к более позднему.
     * @return
     */
    //static Train* sortTrains(Train*);

    /**
     * Конструктор копии.
     */
    Train(const Train&);

    /**
     * Перегруженный оператор присваивания.
     * @return
     */
    Train &operator=(const Train&);

    /**
     * Статический метод поиска поездов по направлению поезда.
     * @return Найденные поезда.
     */
    //static Train* findTrainsByDestinationName(char*, Train*);

    /**
     * Статический метод пользовательского ввода направления поезда с клавиатуры.
     * @return
     */
    //static char* inputDestinationFromKeyboard();

    void showTrain();
};


#endif //UNTITLED_TRAIN_H
