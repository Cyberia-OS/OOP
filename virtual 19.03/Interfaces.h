#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Drawable {
public:
    virtual void draw() const = 0;
    virtual ~Drawable() {}
};

class Serializable {
public:
    virtual string serialize() const = 0;
    virtual ~Serializable() {}
};

class Circle : public Drawable, public Serializable {
private:
    double cx, cy, radius;
public:
    Circle(double x, double y, double r) : cx(x), cy(y), radius(r) {}

    void draw() const override {
        cout << "Рисую круг в (" << cx << ", " << cy
             << ") радиусом " << radius << endl;
    }

    string serialize() const override {
        return "Circle " + to_string((int)cx) + " "
               + to_string((int)cy) + " "
               + to_string((int)radius);
    }

    double getX() const { return cx; }
    double getY() const { return cy; }
    double getRadius() const { return radius; }
};

// ----- класс Rectangle -----
class Rectangle : public Drawable, public Serializable {
private:
    double x0, y0, width, height;
public:
    Rectangle(double x, double y, double w, double h)
        : x0(x), y0(y), width(w), height(h) {}

    void draw() const override {
        cout << "Рисую прямоугольник в (" << x0 << ", " << y0
             << ") ширина " << width << " высота " << height << endl;
    }

    string serialize() const override {
        return "Rectangle " + to_string((int)x0) + " "
               + to_string((int)y0) + " "
               + to_string((int)width) + " "
               + to_string((int)height);
    }

    double getX() const { return x0; }
    double getY() const { return y0; }
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};
