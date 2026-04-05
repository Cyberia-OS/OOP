#include <iostream>
#include <vector>
#include "StringHolder.h"
#include "Interfaces.h"
#include "Vehicle.h"

using namespace std;

void demoTask3() {
    cout << "\nЗадание 3=\n";

    StringHolder* p1 = new StringHolder("Привет");
    p1->print();
    delete p1;  

    StringHolder* p2 = new ReverseString("Мир");
    p2->print();
    delete p2;

    StringHolder* arr[] = {
        new StringHolder("Один"),
        new ReverseString("Два"),
        new StringHolder("Три")
    };
    cout << "\nМассив указателей:\n";
    for (auto ptr : arr) {
        ptr->print();
    }
    for (auto ptr : arr) {
        delete ptr;
    }
}

void demoTask4() {
    cout << "\n Задание 4\n";

    vector<Drawable*> shapes;
    shapes.push_back(new Circle(10, 20, 5));
    shapes.push_back(new Rectangle(0, 0, 30, 15));
    shapes.push_back(new Circle(5, 5, 3));

    cout << "Вызов draw() для всех Drawable:\n";
    for (auto d : shapes) {
        d->draw();
    }

    vector<Serializable*> serials;
    serials.push_back(new Circle(10, 20, 5));
    serials.push_back(new Rectangle(0, 0, 30, 15));

    cout << "\nСериализация объектов:\n";
    for (auto s : serials) {
        cout << "Строка: " << s->serialize() << endl;
    }
  
    Drawable* dptr = new Circle(100, 200, 10);
    Serializable* sptr = dynamic_cast<Serializable*>(dptr);
    if (sptr) {
        cout << "\ndynamic_cast успешен: " << sptr->serialize() << endl;
    } else {
        cout << "\ndynamic_cast не удался" << endl;
    }

    for (auto d : shapes) delete d;
    for (auto s : serials) delete s;
    delete dptr;
}

void demoTask5() {
    cout << "\nЗадание 5\n";

    vector<Vehicle*> fleet;
    fleet.push_back(new Car());
    fleet.push_back(new ElectricCar());
    fleet.push_back(new SportsCar());
    fleet.push_back(new Bicycle());

    for (size_t i = 0; i < fleet.size(); ++i) {
        cout << "\n--- Транспорт " << (i + 1) << " ---" << endl;
        fleet[i]->startEngine();
        cout << "Максимальная скорость: " << fleet[i]->getMaxSpeed() << " км/ч" << endl;
        fleet[i]->info();
    }

    ElectricCar ec;
    cout << "\nПрямой вызов ElectricCar:" << endl;
    ec.startEngine();
    cout << "Макс. скорость: " << ec.getMaxSpeed() << " км/ч" << endl;
    ec.info();

    for (auto v : fleet) delete v;
}

int main() {
    setlocale(LC_ALL, "ru");

    demoTask3();   
    demoTask4();   
    demoTask5();  

    return 0;
}
