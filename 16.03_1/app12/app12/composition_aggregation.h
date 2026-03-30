#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Room {
    string name;
public:
    Room(const string& n) : name(n) {
        cout << "комната \"" << name << "\" создана" << endl;
    }
    void info() const {
        cout << "комната: " << name;
    }
    ~Room() {
        cout << "комната \"" << name << "\" уничтожена" << endl;
    }
};

class House {
    vector<Room> rooms;
public:
    House() {
        cout << "дом построен." << endl;
    }
    void addRoom(const string& name) {
        rooms.push_back(Room(name));
    }
    void showRooms() const {
        cout << "в доме " << rooms.size() << " комнат: ";
        for (size_t i = 0; i < rooms.size(); i++) {
            rooms[i].info();
            if (i != rooms.size() - 1) cout << ", ";
        }
        cout << endl;
    }
    ~House() {
        cout << "дом снесён." << endl;
    }
};

class Processor {
    string model;
public:
    Processor(const string& m) : model(m) {
        cout << "процессор " << model << " создан" << endl;
    }
    void info() const {
        cout << "процессор: " << model;
    }
    ~Processor() {
        cout << "процессор " << model << " уничтожен" << endl;
    }
};

class Computer {
    Processor* cpu;
public:
    Computer(const string& cpuModel) : cpu(new Processor(cpuModel)) {
        cout << "компьютер собран" << endl;
    }
    Computer(const Computer&) = delete;
    Computer& operator=(const Computer&) = delete;
    void show() const {
        cpu->info();
        cout << endl;
    }
    ~Computer() {
        cout << "компьютер уничтожается" << endl;
        delete cpu;
    }
};

class Student {
    string name;
public:
    Student(const string& n) : name(n) {
        cout << "студент " << name << " создан" << endl;
    }
    void info() const {
        cout << "студент: " << name;
    }
    ~Student() {
        cout << "студент " << name << " отчислен (уничтожен)" << endl;
    }
};

class University {
    vector<Student*> students;
public:
    University() {
        cout << "университет открыт" << endl;
    }
    void enroll(Student* s) {
        students.push_back(s);
        cout << "студент зачислен" << endl;
    }
    void listStudents() const {
        cout << "список студентов (" << students.size() << " чел): ";
        for (size_t i = 0; i < students.size(); i++) {
            students[i]->info();
            if (i != students.size() - 1) cout << ", ";
        }
        cout << endl;
    }
    ~University() {
        cout << "университет закрывается" << endl;
    }
};

class Book {
    string title;
public:
    Book(const string& t) : title(t) {
        cout << "книга \"" << title << "\" появилась" << endl;
    }
    void info() const {
        cout << "книга: " << title;
    }
    ~Book() {
        cout << "книга \"" << title << "\" исчезла" << endl;
    }
};

class Library {
    vector<Book*> books;
public:
    Library() {
        cout << "библиотека открыта" << endl;
    }
    void addBook(Book* b) {
        books.push_back(b);
        cout << "книга добавлена в библиотеку" << endl;
    }
    void showBooks() const {
        cout << "в библиотеке " << books.size() << " книг: ";
        for (size_t i = 0; i < books.size(); i++) {
            books[i]->info();
            if (i != books.size() - 1) cout << ", ";
        }
        cout << endl;
    }
    ~Library() {
        cout << "библиотека закрывается" << endl;
    }
};