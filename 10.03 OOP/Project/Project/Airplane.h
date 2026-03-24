#pragma once

#include <iostream>
#include <string>

using namespace std;

class Airplane {
private:
    string type;
    int maxPassengers;
    int currentPassengers;

public:
    Airplane(const string& t = "", int max = 0, int curr = 0);

    string getType() const;
    int getMaxPassengers() const;
    int getCurrentPassengers() const;

    bool operator==(const Airplane& other) const;
    Airplane& operator++();
    Airplane& operator--();
    bool operator>(const Airplane& other) const;
    Airplane& operator=(const Airplane& other);

    friend ostream& operator<<(ostream& os, const Airplane& a);
};