#include <iostream>
#include <windows.h>
#include "PhoneBook.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    PhoneBook pb;
    int choice;
    do {
        cout << "1.Добавить 2.Показать 3.Поиск 4.Удалить 5.Сохранить 6.Загрузить 0.Выход: ";
        cin >> choice;
        if (choice == 1) pb.addContact();
        else if (choice == 2) pb.showAll();
        else if (choice == 4) { int id; cin >> id; pb.deleteContact(id); }
        else if (choice == 5) pb.save("base.txt");
        else if (choice == 6) pb.load("base.txt");
    } while (choice != 0);

    return 0;
}
