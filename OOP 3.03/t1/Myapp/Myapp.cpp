#include "Date.h"
#include <iostream>

using namespace std;

static bool isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

static int daysInMonth(int m, int y) {
    static const int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (m == 2 && isLeap(y)) return 29;
    return days[m - 1];
}

static int dateToDays(int d, int m, int y) {
    int total = 0;
    for (int yy = 1970; yy < y; ++yy)
        total += isLeap(yy) ? 366 : 365;
    for (int mm = 1; mm < m; ++mm)
        total += daysInMonth(mm, y);
    total += d - 1;
    return total;
}

static void daysToDate(int days, int& d, int& m, int& y) {
    y = 1970;
    while (days >= (isLeap(y) ? 366 : 365)) {
        days -= (isLeap(y) ? 366 : 365);
        ++y;
    }
    for (m = 1; m <= 12; ++m) {
        int dim = daysInMonth(m, y);
        if (days < dim) break;
        days -= dim;
    }
    d = days + 1;
}

Date::Date(int d, int m, int y) {
    daysSinceEpoch = dateToDays(d, m, y);
}

int Date::operator-(const Date& other) const {
    return daysSinceEpoch - other.daysSinceEpoch;
}

Date Date::operator+(int days) const {
    Date res;
    res.daysSinceEpoch = daysSinceEpoch + days;
    return res;
}

Date& Date::operator+=(int days) {
    daysSinceEpoch += days;
    return *this;
}

ostream& operator<<(ostream& os, const Date& d) {
    int day, month, year;
    daysToDate(d.daysSinceEpoch, day, month, year);
    os << day << '.' << month << '.' << year;
    return os;
}

istream& operator>>(istream& is, Date& d) {
    int day, month, year;
    char dot;
    is >> day >> dot >> month >> dot >> year;
    d = Date(day, month, year);
    return is;
}

int main() {
    setlocale(LC_ALL, "RU"); 
    cout << "Введите первую дату (день.месяц.год): ";
    Date d1;
    cin >> d1;

    cout << "Введите вторую дату (день.месяц.год): ";
    Date d2;
    cin >> d2;

    cout << "Разность в днях: " << (d2 - d1) << " дней" << endl;

    cout << "Введите количество дней для прибавления к первой дате: ";
    int days;
    cin >> days;

    Date d3 = d1 + days;
    cout << "Первая дата + " << days << " дней = " << d3 << endl;

    d1 += days;
    cout << "После += " << days << " дней: " << d1 << endl;

    return 0;
}