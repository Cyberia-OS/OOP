#include "Circle.h"
#include <iostream>

using namespace std;

const double PI = 3.141592653589793;

Circle::Circle(double r) : radius(r) {}

double Circle::getRadius() const {
    return radius;
}

double Circle::length() const {
    return 2 * PI * radius;
}

bool Circle::operator==(const Circle& other) const {
    return radius == other.radius;
}

bool Circle::operator>(const Circle& other) const {
    return length() > other.length();
}

Circle& Circle::operator+=(double delta) {
    radius += delta;
    return *this;
}

Circle& Circle::operator-=(double delta) {
    radius -= delta;
    return *this;
}

ostream& operator<<(ostream& os, const Circle& c) {
    os << "Circle(radius=" << c.radius << ")";
    return os;
}

int main() {
    setlocale(LC_ALL, "RU");

    Circle c1(5.0);
    Circle c2(5.0);
    Circle c3(3.0);

    cout << c1 << " == " << c2 << " ? " << (c1 == c2 ? "да" : "нет") << endl;
    cout << c1 << " > " << c3 << " ? " << (c1 > c3 ? "да" : "нет") << endl;

    cout << "Длина " << c1 << " = " << c1.length() << endl;
    cout << "Длина " << c3 << " = " << c3.length() << endl;

    c1 += 2.0;
    cout << "После += 2: " << c1 << endl;

    c1 -= 1.0;
    cout << "После -= 1: " << c1 << endl;

    return 0;
}