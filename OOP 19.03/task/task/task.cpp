#include "task.h"

int main() {
    setlocale(LC_ALL, "RU");
    using namespace std;

    cout << "задание 1: Голоса животных" << endl;
    vector<Animal*> animals;
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Cow());
    animals.push_back(new Horse());

    for (const auto& animal : animals) {
        animal->speak();
    }

    for (auto& animal : animals) {
        delete animal;
    }
    animals.clear();

    cout << endl << "Задание 2: Геометрические фигуры" << endl;
    vector<Shape*> shapes;

    double radius;
    cout << "Введите радиус круга: ";
    cin >> radius;
    shapes.push_back(new Circle(radius));

    double width, height;
    cout << "Введите ширину и высоту прямоугольника: ";
    cin >> width >> height;
    shapes.push_back(new Rectangle(width, height));

    double a, b, c;
    cout << "Введите три стороны треугольника: ";
    cin >> a >> b >> c;
    shapes.push_back(new Triangle(a, b, c));

    cout << endl << "Информация о фигурах" << endl;
    for (const auto& shape : shapes) {
        shape->printInfo();
        cout << endl << "Площадь: " << shape->area() << endl;
        cout << "Периметр: " << shape->perimeter() << endl << endl;
    }

    for (auto& shape : shapes) {
        delete shape;
    }
    shapes.clear();

    return 0;
}