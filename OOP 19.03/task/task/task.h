#pragma once
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

class Animal {
public:
    virtual void speak() const {
        cout << "I am an animal" << endl;
    }
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void speak() const override {
        cout << "Woof! Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        cout << "Meow!" << endl;
    }
};

class Cow : public Animal {
public:
    void speak() const override {
        cout << "Moo!" << endl;
    }
};

class Horse : public Animal {
public:
    void speak() const override {
        cout << "Neigh!" << endl;
    }
};

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void printInfo() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return PI * radius * radius;
    }
    double perimeter() const override {
        return 2 * PI * radius;
    }
    void printInfo() const override {
        cout << "Круг (радиус = " << radius << ")";
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
    double perimeter() const override {
        return 2 * (width + height);
    }
    void printInfo() const override {
        cout << "Прямоугольник (ширина = " << width << ", высота = " << height << ")";
    }
};

class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}
    double area() const override {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    double perimeter() const override {
        return a + b + c;
    }
    void printInfo() const override {
        cout << "Треугольник (стороны = " << a << ", " << b << ", " << c << ")";
    }
};