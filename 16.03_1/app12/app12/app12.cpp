#include "composition_aggregation.h"

int main() {
    setlocale(LC_ALL, "RU");
    int choice;

    cout << "выберите пример:" << endl;
    cout << "1 - композиция (дом и комнаты)" << endl;
    cout << "2 - композиция (компьютер и процессор)" << endl;
    cout << "3 - агрегация (университет и студенты)" << endl;
    cout << "4 - агрегация (библиотека и книги)" << endl;
    cout << "0 - выход" << endl;
    cin >> choice;

    if (choice == 1) {
        House house;
        int n;
        cout << "сколько комнат добавить? ";
        cin >> n;
        cin.ignore();
        for (int i = 0; i < n; i++) {
            string name;
            cout << "название комнаты " << i + 1 << ": ";
            getline(cin, name);
            house.addRoom(name);
        }
        house.showRooms();
    }
    else if (choice == 2) {
        string model;
        cout << "модель процессора: ";
        cin.ignore();
        getline(cin, model);
        Computer pc(model);
        pc.show();
    }
    else if (choice == 3) {
        University uni;
        int n;
        cout << "сколько студентов зачислить? ";
        cin >> n;
        vector<Student*> students;
        for (int i = 0; i < n; i++) {
            string name;
            cout << "имя студента " << i + 1 << ": ";
            cin >> name;
            Student* s = new Student(name);
            students.push_back(s);
            uni.enroll(s);
        }
        uni.listStudents();
        for (size_t i = 0; i < students.size(); i++)
            delete students[i];
    }
    else if (choice == 4) {
        Library lib;
        int n;
        cout << "сколько книг добавить? ";
        cin >> n;
        vector<Book*> books;
        cin.ignore();
        for (int i = 0; i < n; i++) {
            string title;
            cout << "название книги " << i + 1 << ": ";
            getline(cin, title);
            Book* b = new Book(title);
            books.push_back(b);
            lib.addBook(b);
        }
        lib.showBooks();
        for (size_t i = 0; i < books.size(); i++)
            delete books[i];
    }
    else if (choice != 0) {
        cout << "неверный выбор." << endl;
    }

    return 0;
}