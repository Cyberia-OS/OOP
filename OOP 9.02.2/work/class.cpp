#include <iostream>
#include <windows.h>
#include "student.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Student student;
    cout << "Введите данные студента:" << endl;
    student.input();
    student.print();
    return 0;
}
