#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace Geometry {
    const double PI = 3.14159;

    double circleArea(double radius) {
        return PI * radius * radius;
    }

    double rectangleArea(double width, double height) {
        return width * height;
    }

    namespace Shapes {
        class Circle {
            double radius;
        public:
            Circle(double r) : radius(r) {}
            double area() const {
                return Geometry::circleArea(radius);
            }
        };
    }
}

namespace Logger {
    enum LogLevel { INFO, WARNING, ERROR };

    void log(LogLevel level, const string& message) {
        switch (level) {
        case INFO:    cout << "[INFO] ";
            break;
        case WARNING: cout << "[WARNING] ";
            break;
        case ERROR:   cout << "[ERROR] "; 
            break;
        }
        cout << message << endl;
    }

    namespace FileLogger {
        void logToFile(const string& filename, const string& message) {
            cout << "[FileLogger] запись в '" << filename << "': " << message << endl;
        }
    }
}