#include <iostream>
#include <string>
#include "String.h"


int main() {
    setlocale(LC_ALL, "RU"); 
    std::string input1, input2;

    std::cout << "Введите первую строку: ";
    std::getline(std::cin, input1);

    std::cout << "Введите вторую строку: ";
    std::getline(std::cin, input2);

    String s1(input1.c_str());
    String s2(input2.c_str());
    String s3 = s1 * s2;

    std::cout << "Пересечение \"" << s1 << "\" и \"" << s2 << "\": \"" << s3 << "\"\n";

    return 0;
}