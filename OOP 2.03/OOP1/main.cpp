#include "Set.h"
#include <iostream>
#include <algorithm>
#include <windows.h>

using namespace std;

bool Set::contains(int elem) const {
    for (int x : data)
        if (x == elem) return true;
    return false;
}

Set::Set() {}

Set::Set(const vector<int>& vec) {
    for (int x : vec)
        if (!contains(x))
            data.push_back(x);
}

Set::Set(initializer_list<int> list) : Set(vector<int>(list)) {}

Set Set::operator+(int elem) const {
    Set result = *this;
    if (!result.contains(elem))
        result.data.push_back(elem);
    return result;
}

Set Set::operator+(const Set& other) const {
    Set result = *this;
    for (int x : other.data)
        if (!result.contains(x))
            result.data.push_back(x);
    return result;
}

Set Set::operator-(int elem) const {
    Set result;
    for (int x : data)
        if (x != elem)
            result.data.push_back(x);
    return result;
}

Set Set::operator-(const Set& other) const {
    Set result;
    for (int x : data)
        if (!other.contains(x))
            result.data.push_back(x);
    return result;
}

bool Set::operator==(const Set& other) const {
    if (data.size() != other.data.size()) return false;
    for (int x : data)
        if (!other.contains(x)) return false;
    return true;
}

ostream& operator<<(ostream& os, const Set& s) {
    os << "{";
    for (size_t i = 0; i < s.data.size(); ++i) {
        if (i > 0) os << ", ";
        os << s.data[i];
    }
    os << "}";
    return os;
}

Set inputSet(const string& name) {
    cout << "введите количество элементов множества " << name << ": ";
    int n;
    cin >> n;
    vector<int> vec;
    cout << "введите " << n << " элементов: ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    return Set(vec);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Set a = inputSet("a");
    Set b = inputSet("b");

    cout << "\na = " << a << "\nb = " << b << endl;

    int choice;
    do {
        cout << "\nвыберите операцию:\n"
            << "1 - добавить элемент в a (a + elem)\n"
            << "2 - объединить a и b (a + b)\n"
            << "3 - удалить элемент из a (a - elem)\n"
            << "4 - разность a \\ b (a - b)\n"
            << "5 - сравнить a и b (a == b)\n"
            << "0 - выход\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            int x;
            cout << "введите элемент: ";
            cin >> x;
            Set c = a + x;
            cout << "a + " << x << " = " << c << endl;
            break;
        }
        case 2: {
            Set c = a + b;
            cout << "a + b = " << c << endl;
            break;
        }
        case 3: {
            int x;
            cout << "введите элемент для удаления: ";
            cin >> x;
            Set c = a - x;
            cout << "a - " << x << " = " << c << endl;
            break;
        }
        case 4: {
            Set c = a - b;
            cout << "a \\ b = " << c << endl;
            break;
        }
        case 5:
            cout << "a == b : " << (a == b ? "true" : "false") << endl;
            break;
        case 0:
            cout << "выход" << endl;
            break;
        default:
            cout << "неверный выбор" << endl;
        }
    } while (choice != 0);

    return 0;
}