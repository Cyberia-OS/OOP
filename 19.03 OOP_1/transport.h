#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

using namespace std;

class Point {
private:
    double x, y;
    static int pointCount;
public:
    Point() : x(0), y(0) { ++pointCount; }
    Point(double x, double y) : x(x), y(y) { ++pointCount; }
    Point(const Point& other) : x(other.x), y(other.y) { ++pointCount; }
    ~Point() { --pointCount; }

    double getX() const { return x; }
    double getY() const { return y; }
    double distance() const { return sqrt(x*x + y*y); }

    static int getPointCount() { return pointCount; }

    bool operator==(const Point& other) const { return x == other.x && y == other.y; }
    bool operator!=(const Point& other) const { return !(*this == other); }

    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << "; " << p.y << ")";
        return os;
    }
    friend istream& operator>>(istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }
};

int Point::pointCount = 0;

class Vehicle {
protected:
    string model;
    int year;
    Point position;
    static int totalVehicles;
public:
    Vehicle(const string& model, int year, const Point& pos)
        : model(model), year(year), position(pos) { ++totalVehicles; }
    explicit Vehicle(const string& model)
        : model(model), year(2020), position(0,0) { ++totalVehicles; }
    Vehicle(const Vehicle& other)
        : model(other.model), year(other.year), position(other.position) { ++totalVehicles; }
    virtual ~Vehicle() { --totalVehicles; }

    virtual double getMaxSpeed() const = 0;
    virtual void print() const = 0;
    virtual Vehicle* clone() const = 0;

    void move(const Point& newPos) { position = newPos; }
    static int getTotalVehicles() { return totalVehicles; }
    const string& getModel() const { return model; }
    int getYear() const { return year; }
    const Point& getPosition() const { return position; }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle {
private:
    int doors;
public:
    Car(const string& model, int year, const Point& pos, int doors)
        : Vehicle(model, year, pos), doors(doors) {}

    double getMaxSpeed() const override { return 180.0; }
    void print() const override {
        cout << "[Car] " << model << " (" << year << "), Pos: " << position
             << ", Doors: " << doors << ", MaxSpeed: " << getMaxSpeed() << endl;
    }
    Vehicle* clone() const override { return new Car(*this); }

    Car& operator++() { ++doors; return *this; }
    Car operator++(int) { Car temp = *this; ++doors; return temp; }
};

class Bike : public Vehicle {
private:
    string type;
public:
    Bike(const string& model, int year, const Point& pos, const string& type)
        : Vehicle(model, year, pos), type(type) {}

    double getMaxSpeed() const override { return 60.0; }
    void print() const override {
        cout << "[Bike] " << model << " (" << year << "), Pos: " << position
             << ", Type: " << type << ", MaxSpeed: " << getMaxSpeed() << endl;
    }
    Vehicle* clone() const override { return new Bike(*this); }
};

template<typename T>
class Garage {
private:
    T* items;
    int capacity;
    int count;
    static int garageCount;

    void free() {
        for (int i = 0; i < count; ++i) delete items[i];
        delete[] items;
        items = nullptr;
        count = capacity = 0;
    }

    void copyFrom(const Garage& other) {
        capacity = other.capacity;
        count = other.count;
        items = new T[capacity];
        for (int i = 0; i < count; ++i)
            items[i] = other.items[i]->clone();
    }

public:
    Garage() : items(nullptr), capacity(0), count(0) { ++garageCount; }
    explicit Garage(size_t size) : capacity(size), count(0) {
        items = new T[capacity];
        ++garageCount;
    }
    Garage(const Garage& other) : items(nullptr), capacity(0), count(0) {
        ++garageCount;
        if (other.count > 0) copyFrom(other);
    }
    ~Garage() { free(); --garageCount; }

    Garage& operator=(const Garage& other) {
        if (this != &other) {
            free();
            if (other.count > 0) copyFrom(other);
        }
        return *this;
    }

    Garage& add(const T& item) {
        if (count >= capacity) {
            int newCap = (capacity == 0) ? 2 : capacity * 2;
            T* newItems = new T[newCap];
            for (int i = 0; i < count; ++i) newItems[i] = items[i];
            delete[] items;
            items = newItems;
            capacity = newCap;
        }
        items[count++] = item->clone();
        return *this;
    }

    int getCount() const { return count; }

    T& operator[](int index) {
        if (index < 0 || index >= count) throw out_of_range("Index out of range");
        return items[index];
    }
    const T& operator[](int index) const {
        if (index < 0 || index >= count) throw out_of_range("Index out of range");
        return items[index];
    }

    Garage operator+(const Garage& other) const {
        Garage result(capacity + other.capacity);
        for (int i = 0; i < count; ++i) result.add(items[i]);
        for (int i = 0; i < other.count; ++i) result.add(other.items[i]);
        return result;
    }

    static int getTotalGarages() { return garageCount; }
};

template<typename T>
int Garage<T>::garageCount = 0;
