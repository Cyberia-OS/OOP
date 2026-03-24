#pragma once

#include <iostream>

class Date {
private:
    int day, month, year;

    static bool isLeap(int y);
    static int daysInMonth(int m, int y);
    long long toDays() const;

public:
    Date(int d = 1, int m = 1, int y = 1970);

    long long operator-(const Date& other) const;
    Date operator+(int days) const;
    Date& operator+=(int days);

    friend std::ostream& operator<<(std::ostream& os, const Date& d);
};
