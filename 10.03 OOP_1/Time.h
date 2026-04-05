#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int h, m, s;

    void norm() {
        m += s / 60; s %= 60;
        h += m / 60; m %= 60;
        h %= 24;
        if (s < 0) { s += 60; m--; }
        if (m < 0) { m += 60; h--; }
        if (h < 0) h = 0;
    }

public:
    Time(int h = 0, int m = 0, int s = 0) : h(h), m(m), s(s) { norm(); }
    Time(const Time& t) : h(t.h), m(t.m), s(t.s) {}

    void addOneSecond() { ++s; norm(); }

    Time& operator++() { addOneSecond(); return *this; }
    Time operator++(int) { Time t = *this; addOneSecond(); return t; }
    Time& operator--() { --s; norm(); return *this; }
    Time operator--(int) { Time t = *this; --(*this); return t; }
    Time& operator+=(int sec) { s += sec; norm(); return *this; }
    Time& operator-=(int sec) { s -= sec; norm(); return *this; }
    int operator()() const { return h*3600 + m*60 + s; }

    friend bool operator==(const Time& a, const Time& b) { return a.h==b.h && a.m==b.m && a.s==b.s; }
    friend bool operator!=(const Time& a, const Time& b) { return !(a==b); }
    friend bool operator<(const Time& a, const Time& b) {
        if (a.h != b.h) return a.h < b.h;
        if (a.m != b.m) return a.m < b.m;
        return a.s < b.s;
    }
    friend bool operator>(const Time& a, const Time& b) { return b < a; }

    friend istream& operator>>(istream& in, Time& t) {
        in >> t.h >> t.m >> t.s;
        t.norm();
        return in;
    }
    friend ostream& operator<<(ostream& out, const Time& t) {
        out << setw(2) << setfill('0') << t.h << ":"
            << setw(2) << setfill('0') << t.m << ":"
            << setw(2) << setfill('0') << t.s;
        return out;
    }
};
