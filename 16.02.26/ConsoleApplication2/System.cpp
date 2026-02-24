#define _CRT_SECURE_NO_WARNINGS
#include "System.h"
#include <iostream>
#include <cstring>

using namespace std;

int Person::cnt = 0;

Date::Date(int day, int month, int year) : d(day), m(month), y(year) {}

char* Person::copyStr(const char* s) {
    char* res = new char[strlen(s) + 1];
    strcpy(res, s);
    return res;
}

Person::Person(int id, const char* fn, const char* in, const char* on, Date db)
    : id(id), birth(db) {
    f = copyStr(fn);
    i = copyStr(in);
    o = copyStr(on);
    cnt++;
}

Person::Person() : Person(0, "Нет", "Нет", "Нет", { 1, 1, 2000 }) {}
Person::Person(const Person& other)
    : Person(other.id, other.f, other.i, other.o, other.birth) {
}

Person::~Person() {
    delete[] f;
    delete[] i;
    delete[] o;
    cnt--;
}

int Person::getCnt() { return cnt; }

void Person::print() const {
    cout << "ID " << id << ": " << f << " " << i << " " << o
        << " [" << birth.d << "." << birth.m << "." << birth.y << "]" << endl;
}

Apartment::Apartment() : ppl(nullptr), sz(0) {}

Apartment::Apartment(const Apartment& other) : Apartment() {
    for (int i = 0; i < other.sz; i++) {
        add(*other.ppl[i]);
    }
}

Apartment::~Apartment() {
    for (int i = 0; i < sz; i++) {
        delete ppl[i];
    }
    delete[] ppl;
}

void Apartment::add(const Person& p) {
    Person** tmp = new Person * [sz + 1];
    for (int i = 0; i < sz; i++) {
        tmp[i] = ppl[i];
    }
    tmp[sz] = new Person(p);
    delete[] ppl;
    ppl = tmp;
    sz++;
}

void Apartment::print() const {
    if (sz == 0) cout << "  Пусто" << endl;
    for (int i = 0; i < sz; i++) {
        cout << "  ";
        ppl[i]->print();
    }
}

House::House(int n) : count(n) {
    apts = new Apartment[n];
}

House::~House() {
    delete[] apts;
}

Apartment& House::get(int index) {
    return apts[index];
}

void House::print() const {
    for (int i = 0; i < count; i++) {
        cout << "Квартира №" << i + 1 << ":" << endl;
        apts[i].print();
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    int n, choice;
    cout << "Введите кол-во квартир: ";
    cin >> n;
    House myHouse(n);

    do {
        cout << "\n1. Добавить жильца\n2. Показать дом\n0. Выход\nВыбор: ";
        cin >> choice;

        if (choice == 1) {
            int apt, id, d, m, y;
            char f[50], i[50], o[50];

            cout << "Кв (1-" << n << "): "; cin >> apt;
            cout << "ID: "; cin >> id;
            cout << "Ф И О: "; cin >> f >> i >> o;
            cout << "Дата (Д М Г): "; cin >> d >> m >> y;

            myHouse.get(apt - 1).add(Person(id, f, i, o, { d, m, y }));
        }
        else if (choice == 2) {
            myHouse.print();
        }
    } while (choice != 0);

    return 0;
}
