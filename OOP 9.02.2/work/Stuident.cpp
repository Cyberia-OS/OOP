#include "student.h"
#include <iostream>
#include <string>

using namespace std;

void Student::input() {
    cout << "ФИО: "; getline(cin, fullName);
    cout << "Дата рождения: "; getline(cin, birthDate);
    cout << "Телефон: "; getline(cin, phone);
    cout << "Город: "; getline(cin, city);
    cout << "Страна: "; getline(cin, country);
    cout << "Учебное заведение: "; getline(cin, schoolName);
    cout << "Город учебного заведения: "; getline(cin, schoolCity);
    cout << "Страна учебного заведения: "; getline(cin, schoolCountry);
    cout << "Номер группы: "; getline(cin, groupNumber);
}

void Student::print() {
    cout << "----------------------------" << endl;
    cout << "Карточка студента" << endl;
    cout << "Студент: " << fullName << " (Группа: " << groupNumber << ")" << endl;
    cout << "Дата рождения: " << birthDate << endl;
    cout << "Контакты: " << phone << endl;
    cout << "Место жительства: " << city << ", " << country << endl;
    cout << "Место учебы: " << schoolName << " (" << schoolCity << ", " << schoolCountry << ")" << endl;
    cout << "----------------------------" << endl;
}