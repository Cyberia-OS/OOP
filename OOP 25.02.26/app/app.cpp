#include "app.h"
#include <iostream>
#include <windows.h> 

Book::Book(std::string a, std::string t, std::string p, int y, int pg)
    : author(a), title(t), publisher(p), year(y), pages(pg) {
}

void Book::display() const {
    std::cout << author << " | " << title << " | " << publisher << " | " << year << std::endl;
}

Worker::Worker(std::string f, std::string p, int y, double s)
    : fio(f), pos(p), year(y), salary(s) {
}

void Worker::display() const {
    std::cout << fio << " | " << pos << " | ЗП: " << salary << " | Год: " << year << std::endl;
}

int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);


    int n;
    std::cout << "количество книг: "; std::cin >> n;

    Book** books = new Book * [n];

    for (int i = 0; i < n; i++) {
        std::string a, t, p; int y, pg;
        std::cout << "Автор: "; std::cin.ignore(); getline(std::cin, a);
        std::cout << "Название: "; getline(std::cin, t);
        std::cout << "Издательство: "; getline(std::cin, p);
        std::cout << "Год и страницы: "; std::cin >> y >> pg;
        books[i] = new Book(a, t, p, y, pg);
    }

    std::string searchAuthor;
    std::cout << "Введите автора для поиска: " << std::endl; std::cin.ignore(); getline(std::cin, searchAuthor);
    for (int i = 0; i < n; i++) {
        if (books[i]->getAuthor() == searchAuthor) books[i]->display();
    }

    std::cout << "Количество работников: "; std::cin >> n;
    Worker** workers = new Worker * [n];

    for (int i = 0; i < n; i++) {
        std::string f, pos; int y; double s;
        std::cout << "ФИО: "; std::cin.ignore(); getline(std::cin, f);
        std::cout << "Должность: "; getline(std::cin, pos);
        std::cout << "Год и ЗП: "; std::cin >> y >> s;
        workers[i] = new Worker(f, pos, y, s);
    }

    double minSalary;
    std::cout << "Минимальная ЗП для фильтра: "; std::cin >> minSalary;
    for (int i = 0; i < n; i++) {
        if (workers[i]->getSalary() > minSalary) workers[i]->display();
    }

    return 0;
}
