#include "Date.h"

bool Date::isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::daysInMonth(int m, int y) {
    static const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && isLeap(y)) 
        return 29;
    return days[m - 1];
}

long long Date::toDays() const {
    long long total = 0;
    for (int y = 0; y < year; y++)
        total += isLeap(y) ? 366 : 365;
    for (int m = 1; m < month; m++)
        total += daysInMonth(m, year);
    total += day;
    return total;
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

long long Date::operator-(const Date& other) const {
    return toDays() - other.toDays();
}

Date Date::operator+(int days) const {
    Date result = *this;
    result += days;
    return result;
}

Date& Date::operator+=(int days) {
    day += days;
    while (day > daysInMonth(month, year)) {
        day -= daysInMonth(month, year);
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    while (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day += daysInMonth(month, year);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    os << d.day << '.' << d.month << '.' << d.year;
    return os;
}