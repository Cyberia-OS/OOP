#include <iostream>
#include "Date.h"

int main() {
    setlocale(LC_ALL, "RU");
    Date d1(15, 3, 2020);
    Date d2(10, 3, 2020);
    std::cout << "Разница между " << d1 << " и " << d2 << ": " << (d1 - d2) << " дней\n";

    Date d3(28, 2, 2020);
    Date d4 = d3 + 3;
    std::cout << d3 << " + 3 дня = " << d4 << std::endl;

    d3 += 5;
    std::cout << "После +=5: " << d3 << std::endl;

    return 0;
}