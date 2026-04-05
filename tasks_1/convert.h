#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual void draw() const { cout << "Рисую фигуру" << endl; }
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    void draw() const override {
        cout << "Рисую круг (радиус = " << radius << ")" << endl;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    void draw() const override {
        cout << "Рисую прямоугольник (ширина = " << width << ", высота = " << height << ")" << endl;
    }
};

class DataHolder {
    vector<int> data;
public:
    DataHolder(const vector<int>& d) : data(d) {}
    const vector<int>& getData() const { return data; }
    void print() const {
        cout << "Данные: ";
        for (int v : data) cout << v << " ";
        cout << endl;
    }
};
