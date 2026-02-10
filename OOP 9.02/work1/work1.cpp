#include <iostream>
#include "fraction.h"

int main() {
    setlocale(LC_ALL, "RU"); 

    fraction f1, f2, res;

    std::cout << "настройка первой дроби:\n";
    f1.input(); 

    std::cout << "\nнастройка второй дроби:\n";
    f2.input(); 

    std::cout << "\nрезультаты\n";

    res = f1.add(f2);
    std::cout << "сумма: "; res.print(); std::cout << "\n";

    res = f1.subtract(f2);
    std::cout << "разность: "; res.print(); std::cout << "\n";

    res = f1.multiply(f2);
    std::cout << "произведение: "; res.print(); std::cout << "\n";

    res = f1.divide(f2);
    std::cout << "частное: "; res.print(); std::cout << "\n";

    return 0;
}