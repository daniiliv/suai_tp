//
// Created by daniil on 01.10.18.
//

#include "train.h"
#include <iostream>

Train::Train(char[] destination, int trainNumber, char[] departureTime) {
    this.destination = destination;
    this.trainNumber = trainNumber;
    this.departureTime = departureTime;
}
Train::Train() {}
Train::~Train() {}
void Train::setDestination(char[] destination) {
    this.destination = destination;
}
void Train::setTrainNumber(int trainNumber) {
    this.trainNumber = trainNumber;
}
void Train::setDepartureTime(char[] departureTime) {
    this.departureTime = departureTime;
}
char[] Train::getDestination() {
    return this.destination;
}
int Train::getTrainNumber() {
    return this.trainNumber;
}
char[] Train::getDepartureTime() {
    return this.departureTime;
}