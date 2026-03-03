#pragma once
#include <string>

class Book {
    std::string author, title, publisher;
    int year, pages;
public:
    explicit Book(std::string a, std::string t, std::string p, int y, int pg);
    void display() const; 
    std::string getAuthor() const { return author; }
    std::string getPublisher() const { return publisher; }
    int getYear() const { return year; }
};

class Worker {
    std::string fio, pos;
    int year;
    double salary;
public:
    explicit Worker(std::string f, std::string p, int y, double s);
    void display() const;
    int getYear() const { return year; }
    double getSalary() const { return salary; }
    std::string getPos() const { return pos; }
};
