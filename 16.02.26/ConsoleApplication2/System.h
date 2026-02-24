#pragma once

struct Date {
    int d, m, y;
    Date(int day = 1, int month = 1, int year = 2000);
};

class Person {
    int id;
    char* f, * i, * o;
    Date birth;
    static int cnt;
    char* copyStr(const char* s);
public:
    Person(int id, const char* fn, const char* in, const char* on, Date db);
    Person();
    Person(const Person& other);
    ~Person();

    static int getCnt();
    void print() const;
};

class Apartment {
    Person** ppl;
    int sz;
public:
    Apartment();
    Apartment(const Apartment& other);
    ~Apartment();

    void add(const Person& p);
    void print() const;
};

class House {
    Apartment* apts;
    int count;
public:
    House(int n);
    ~House();

    Apartment& get(int index);
    void print() const;
};

