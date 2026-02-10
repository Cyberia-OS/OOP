#pragma once

class fraction {
public:

    int numerator;
    int denominator;

    void input() {
        std::cout << "введите числитель: ";
        std::cin >> numerator;

        do {
            std::cout << "введите знаменатель (не 0): ";
            std::cin >> denominator;
            if (denominator == 0) {
                std::cout << "ошибка: знаменатель не может быть нулевым!\n";
            }
        } while (denominator == 0);

        simplify();
    }

    void print() {
        std::cout << numerator << "/" << denominator;
    }

    //функция сложения
    fraction add(fraction other) {
        fraction result;
        result.numerator = numerator * other.denominator + other.numerator * denominator; //(a*d + c*b) / (b*d)
        result.denominator = denominator * other.denominator;
        result.simplify();
        return result;
    }

    fraction subtract(fraction other) {
        fraction result;
        result.numerator = numerator * other.denominator - other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        result.simplify();
        return result;
    }

    fraction multiply(fraction other) {
        fraction result;
        result.numerator = numerator * other.numerator; //формула: (a*c) / (b*d)
        result.denominator = denominator * other.denominator;
        result.simplify();
        return result;
    }

    fraction divide(fraction other) {
        fraction result;
        //умножение на перевернутую дробь (a/b * d/c)
        result.numerator = numerator * other.denominator;
        result.denominator = denominator * other.numerator;

        if (result.denominator == 0) {
            std::cout << "ошибка деления на 0 ";
            result.denominator = 1;
        }

        result.simplify();
        return result;
    }

    void simplify() {
        int a = (numerator < 0) ? -numerator : numerator;
        int b = (denominator < 0) ? -denominator : denominator;

        while (a > 0 && b > 0) {
            if (a > b) a %= b;
            else b %= a;
        }
        int nod = a + b;

        if (nod > 0) {
            numerator /= nod;
            denominator /= nod;
        }

        //если знаменатель отрицательный переносим минус наверх
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
};  