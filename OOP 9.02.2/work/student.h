#pragma once

#include <string>

class Student {
private:
    std::string fullName;
    std::string birthDate;
    std::string phone;
    std::string city;
    std::string country;
    std::string schoolName;
    std::string schoolCity;
    std::string schoolCountry;
    std::string groupNumber;

public:
    void input();
    void print();
};