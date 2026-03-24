#include "Airplane.h"

using namespace std;

Airplane::Airplane(const string& t, int max, int curr)
    : type(t), maxPassengers(max), currentPassengers(curr) {
    if (currentPassengers > maxPassengers)
        currentPassengers = maxPassengers;
    if (currentPassengers < 0)
        currentPassengers = 0;
}

string Airplane::getType() const {
    return type;
}

int Airplane::getMaxPassengers() const {
    return maxPassengers;
}

int Airplane::getCurrentPassengers() const {
    return currentPassengers;
}

bool Airplane::operator==(const Airplane& other) const {
    return type == other.type;
}

Airplane& Airplane::operator++() {
    if (currentPassengers < maxPassengers)
        ++currentPassengers;
    return *this;
}

Airplane& Airplane::operator--() {
    if (currentPassengers > 0)
        --currentPassengers;
    return *this;
}

bool Airplane::operator>(const Airplane& other) const {
    return maxPassengers > other.maxPassengers;
}

Airplane& Airplane::operator=(const Airplane& other) {
    if (this != &other) {
        type = other.type;
        maxPassengers = other.maxPassengers;
        currentPassengers = other.currentPassengers;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Airplane& a) {
    os << "Airplane(type=" << a.type
        << ", max=" << a.maxPassengers
        << ", current=" << a.currentPassengers << ")";
    return os;
}

int main() {
    setlocale(LC_ALL, "RU"); 

    Airplane a1("Boeing 737", 150, 120);
    Airplane a2("Airbus A320", 150, 100);
    Airplane a3("Boeing 737", 180, 0);

    cout << "Созданные самолёты" << endl;
    cout << a1 << endl;
    cout << a2 << endl;
    cout << a3 << endl;

    cout << "Проверка равенства типов" << endl;
    cout << "a1 == a2? " << (a1 == a2 ? "да" : "нет") << endl;
    cout << "a1 == a3? " << (a1 == a3 ? "да" : "нет") << endl;

    cout << "Префиксный инкремент и декремент" << endl;
    cout << "a1 до ++: " << a1 << endl;
    ++a1;
    cout << "После ++a1: " << a1 << endl;
    --a1;
    cout << "После --a1: " << a1 << endl;

    cout << "=== Сравнение по максимальной вместимости ===" << endl;
    cout << "a1 > a2? " << (a1 > a2 ? "да" : "нет") << endl;
    cout << "a3 > a1? " << (a3 > a1 ? "да" : "нет") << endl;

    cout << "Проверка границ" << endl;
    Airplane a4("Test", 5, 5);
    cout << "a4: " << a4 << endl;
    ++a4; 
    cout << "После ++a4: " << a4 << endl;
    --a4;
    cout << "После --a4: " << a4 << endl;
    --a4; --a4; --a4; 
    cout << "После нескольких --: " << a4 << endl;
    --a4; 
    cout << "Ещё один --: " << a4 << endl;

    return 0;
}