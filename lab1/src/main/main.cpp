#include <iostream>

int main() {
    Train testTrain = new Train("Gatchina", 1337, "13:37");

    cout << testTrain.getDestination();
    return 0;
}