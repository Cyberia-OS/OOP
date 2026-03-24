#include "String.h"
#include <iostream> 
using namespace std;

MyString::MyString(const char* str) : s(str) {}

MyString MyString::operator*(const MyString& other) const {
    string result;
    for (char c : s) {
        if (other.s.find(c) != string::npos && result.find(c) == string::npos) {
            result += c;
        }
    }
    return MyString(result.c_str());
}

ostream& operator<<(ostream& os, const MyString& ms) {
    os << ms.s;
    return os;
}

istream& operator>>(istream& is, MyString& ms) {
    string input;
    is >> input;
    ms = MyString(input.c_str());
    return is;
}

int main() {
    setlocale(LC_ALL, "RU"); 
    cout << "Введите первую строку: ";
    MyString a;
    cin >> a;

    cout << "Введите вторую строку: ";
    MyString b;
    cin >> b;

    MyString c = a * b;
    cout << "Общие символы (пересечение): " << c << endl;

    return 0;
}