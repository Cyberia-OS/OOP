#include <iostream>

class Circle {
private:
    double radius;

public:
    Circle(double r = 0.0);
    double getRadius() const;
    double length() const; //длина окружности

    bool operator==(const Circle& other) const; //равенство радиусов
    bool operator>(const Circle& other) const; //сравнение длин

    Circle& operator+=(double delta); //увеличение радиуса
    Circle& operator-=(double delta); //уменьшение радиуса

    friend std::ostream& operator<<(std::ostream& os, const Circle& c);
};

