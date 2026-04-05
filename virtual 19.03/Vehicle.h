#pragma once
#include <iostream>
#include <string>

using namespace std;

class Vehicle {
public:
    virtual void startEngine() const {
        cout << "Двигатель запущен" << endl;
    }
    virtual double getMaxSpeed() const {
        return 0;
    }
    virtual void info() const {
        cout << "Это транспортное средство" << endl;
    }
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void startEngine() const override {
        cout << "Двигатель автомобиля запущен" << endl;
    }
    double getMaxSpeed() const override {
        return 180;
    }
    void info() const override {
        cout << "Я автомобиль" << endl;
    }
};

class ElectricCar : public Car {
public:
    void startEngine() const override {
        cout << "Электромотор бесшумно запущен" << endl;
    }
    double getMaxSpeed() const final override {
        return 180;
    }
};

class SportsCar : public Car {
public:
    double getMaxSpeed() const override {
        return 250;
    }
};

class Bicycle final : public Vehicle {
public:
    void startEngine() const override {
        cout << "Начали педалировать" << endl;
    }
    double getMaxSpeed() const override {
        return 30;
    }
    void info() const override {
        cout << "Я велосипед" << endl;
    }
};
