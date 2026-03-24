#include "Classes.h"

Complex::Complex() : re(0), im(0) {}
Complex::Complex(double r) : re(r), im(0) {}
Complex::Complex(double r, double i) : re(r), im(i) {}

istream& operator>>(istream& in, Complex& c) {
    in >> c.re >> c.im;
    return in;
}

ostream& operator<<(ostream& out, const Complex& c) {
    out << c.re;
    if (c.im >= 0) out << "+" << c.im << "i";
    else out << c.im << "i";
    return out;
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(re + other.re, im + other.im);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(re - other.re, im - other.im);
}

bool Complex::operator==(const Complex& other) const {
    return (re == other.re) && (im == other.im);
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

double Complex::operator()() const {
    return sqrt(re * re + im * im);
}

Time::Time() : hours(0), minutes(0), seconds(0) {}
Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    normalize();
}

void Time::normalize() {
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }
    if (seconds < 0) {
        int mins = (-seconds + 59) / 60;
        minutes -= mins;
        seconds += mins * 60;
    }
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
    if (minutes < 0) {
        int hrs = (-minutes + 59) / 60;
        hours -= hrs;
        minutes += hrs * 60;
    }
    if (hours >= 24) hours %= 24;
    if (hours < 0) hours = (hours % 24 + 24) % 24;
}

void Time::addSecond() {
    seconds++;
    normalize();
}

istream& operator>>(istream& in, Time& t) {
    in >> t.hours >> t.minutes >> t.seconds;
    t.normalize();
    return in;
}

ostream& operator<<(ostream& out, const Time& t) {
    out << setfill('0') << setw(2) << t.hours << ":"
        << setw(2) << t.minutes << ":"
        << setw(2) << t.seconds;
    return out;
}

Time& Time::operator++() {
    addSecond();
    return *this;
}
Time Time::operator++(int) {
    Time tmp = *this;
    addSecond();
    return tmp;
}
Time& Time::operator--() {
    seconds--;
    normalize();
    return *this;
}
Time Time::operator--(int) {
    Time tmp = *this;
    seconds--;
    normalize();
    return tmp;
}

bool Time::operator==(const Time& other) const {
    return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
}
bool Time::operator!=(const Time& other) const {
    return !(*this == other);
}
bool Time::operator>(const Time& other) const {
    if (hours != other.hours) return hours > other.hours;
    if (minutes != other.minutes) return minutes > other.minutes;
    return seconds > other.seconds;
}
bool Time::operator<(const Time& other) const {
    if (hours != other.hours) return hours < other.hours;
    if (minutes != other.minutes) return minutes < other.minutes;
    return seconds < other.seconds;
}

Time& Time::operator=(const Time& other) {
    if (this != &other) {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
    }
    return *this;
}
Time& Time::operator+=(int sec) {
    seconds += sec;
    normalize();
    return *this;
}
Time& Time::operator-=(int sec) {
    seconds -= sec;
    normalize();
    return *this;
}
int Time::operator()() const {
    return hours * 3600 + minutes * 60 + seconds;
}

int main() {
    setlocale(LC_ALL, "RU");

    cout << "Задание 1" << endl;
    Complex a, b;

    cout << "Введите первое комплексное число (real imag): ";
    cin >> a;
    cout << "Введите второе комплексное число (real imag): ";
    cin >> b;

    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n";
    cout << "a + b = " << a + b << "\n";
    cout << "a - b = " << a - b << "\n";
    cout << "a == b? " << (a == b) << "\n";
    cout << "a != b? " << (a != b) << "\n";
    cout << "Модуль a = " << a() << "\n\n";

    cout << "Задание 2" << endl;
    Time t1(10, 30, 45);
    Time t2(8, 15, 30);
    Time t3;

    cout << "t1 = " << t1 << "\n";
    cout << "t2 = " << t2 << "\n";

    cout << "++t1: " << ++t1 << "\n";
    cout << "t1++: " << t1++ << " (старое значение)\n";
    cout << "t1 после: " << t1 << "\n";

    cout << "--t2: " << --t2 << "\n";
    cout << "t2--: " << t2-- << " (старое значение)\n";
    cout << "t2 после: " << t2 << "\n";

    cout << "t1 == t2? " << (t1 == t2) << "\n";
    cout << "t1 != t2? " << (t1 != t2) << "\n";
    cout << "t1 > t2? " << (t1 > t2) << "\n";
    cout << "t1 < t2? " << (t1 < t2) << "\n";

    t3 = t1;
    cout << "t3 = t1 -> " << t3 << "\n";
    t3 += 75;
    cout << "t3 += 75: " << t3 << "\n";
    t3 -= 30;
    cout << "t3 -= 30: " << t3 << "\n";

    cout << "t1 в секундах: " << t1() << "\n";

    cout << "Введите время (часы минуты секунды): " << endl;
    cin >> t3;
    cout << "Вы ввели: " << t3 << "\n";

    return 0;
}