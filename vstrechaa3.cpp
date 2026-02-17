#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

class MyString {
private:
    char* str;   
    int length;     
    static int objectCount; 

public:
    MyString() {
        length = 80;
        str = new char[length + 1];
        str[0] = '\0'; 
        objectCount++;
    }

    MyString(int size) {
        length = size;
        str = new char[length + 1];
        str[0] = '\0';
        objectCount++;
    }

    MyString(const char* userStr) {
        if (userStr) {
            length = (int)strlen(userStr);
            str = new char[length + 1];
            strcpy(str, userStr);
        }
        else {
            length = 80;
            str = new char[length + 1];
            str[0] = '\0';
        }
        objectCount++;
    }

    ~MyString() {
        delete[] str;
        objectCount--; 
    }

    void input() {
        cout << "Введите строку (макс. " << length << " симв.): ";
        if (cin.peek() == '\n') cin.ignore();
        cin.getline(str, length + 1);
    }

    void print() const {
        if (str[0] == '\0') cout << "[пустая строка]";
        else cout << str;
        cout << " (размер буфера: " << length << ")" << endl;
    }

    // Статическая функция-член
    static int getObjectCount() {
        return objectCount;
    }
};

int MyString::objectCount = 0;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    cout << "--- Демонстрация работы класса String ---" << endl;
    cout << "Объектов в начале: " << MyString::getObjectCount() << endl;

    MyString s1;                  
    MyString s2(25);          
    MyString s3("Привет из конструктора"); /

    cout << "Объектов создано: " << MyString::getObjectCount() << endl;

    cout << "\nПроверка вывода:" << endl;
    cout << "S1: "; s1.print();
    cout << "S2: "; s2.print();
    cout << "S3: "; s3.print();

    cout << "\nПроверка ввода для S2:" << endl;
    s2.input();
    cout << "Теперь S2: "; s2.print();

    cout << "\n--- Конец работы программы ---" << endl;
    // При выходе из main сработают деструкторы и objectCount станет 0

    system("pause");
    return 0;
}
