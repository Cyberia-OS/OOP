#pragma once

#include <iostream>
using namespace std;

class Date {
    int daysSinceEpoch;
public:
    Date(int d = 1, int m = 1, int y = 1970);
    int operator-(const Date& other) const;
    Date operator+(int days) const;
    Date& operator+=(int days);
    friend ostream& operator<<(ostream& os, const Date& d);
    friend istream& operator>>(istream& is, Date& d);
};
