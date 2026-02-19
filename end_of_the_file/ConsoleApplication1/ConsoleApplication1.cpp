#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Elevator {
    int minF, maxF, currF;
    bool active = false;
public:
    Elevator(int min, int max) : minF(min), maxF(max), currF(min) {}
    void power(bool s) { active = s; cout << "питание: " << (s ? "включено" : "выключено") << "\n"; }
    void call(int f) {
        if (!active) { cout << "ошибка: лифт выключен\n"; return; }
        if (f < minF || f > maxF) { cout << "ошибка: этаж вне диапазона\n"; return; }
        cout << "едем: " << currF << " -> " << f << "\n";
        currF = f;
    }
};

struct Roll {
    string name; double w, l, price;
    double area() const { return w * l; }
};

struct Room {
    string name; double w, l, h; bool ceil;
    double area() const { return (2 * h * (w + l)) + (ceil ? w * l : 0); }
};

struct Student {
    string name;
    vector<int> grades;
};

double inputDouble() {
    double x;
    while (!(cin >> x)) {
        cout << "ошибка! введите число: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return x;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;
    while (true) {
        cout << "\nглавное меню\n";
        cout << "1. тест лифта\n";
        cout << "2. расчет обоев\n";
        cout << "3. группа студентов\n";
        cout << "0. выход\n";
        cout << "выберите пункт: ";
        choice = (int)inputDouble();

        if (choice == 0) break;

        switch (choice) {
        case 1: {
            int min, max, f;
            cout << "нижний этаж: "; min = (int)inputDouble();
            cout << "верхний этаж: "; max = (int)inputDouble();
            Elevator e(min, max);
            e.power(true);
            cout << "на какой этаж едем? "; f = (int)inputDouble();
            e.call(f);
            break;
        }
        case 2: {
            string rName; double w, l, h, p; int c;
            cout << "название рулона: "; cin >> rName;
            cout << "ширина рулона: "; w = inputDouble();
            cout << "длина рулона: "; l = inputDouble();
            cout << "цена рулона: "; p = inputDouble();
            Roll roll = { rName, w, l, p };

            cout << "сколько комнат? "; int count = (int)inputDouble();
            double total = 0;
            for (int i = 0; i < count; i++) {
                cout << "название комнаты " << i + 1 << ": "; cin >> rName;
                cout << "ширина, длина, высота: "; w = inputDouble(); l = inputDouble(); h = inputDouble();
                cout << "клеим потолок? (1-да, 0-нет): "; c = (int)inputDouble();
                Room room = { rName, w, l, h, (bool)c };

                double neededReal = room.area() / roll.area();
                int needed = (int)neededReal;
                if (neededReal > (double)needed) needed++; // ручной расчет количества рулонов

                cout << "необходимо " << needed << " рулонов\n";
                total += needed * roll.price;
            }
            cout << "общая стоимость закупки: " << total << " руб.\n";
            break;
        }
        case 3: {
            string gName;
            cout << "название группы: "; cin >> gName;
            cout << "сколько предметов? "; int subCount = (int)inputDouble();
            vector<string> subs(subCount);
            for (int i = 0; i < subCount; i++) { cout << "предмет " << i + 1 << ": "; cin >> subs[i]; }

            cout << "сколько студентов? "; int stCount = (int)inputDouble();
            vector<Student> students;
            for (int i = 0; i < stCount; i++) {
                Student s;
                cout << "имя студента " << i + 1 << ": "; cin >> s.name;
                for (int j = 0; j < subCount; j++) {
                    cout << "оценка по " << subs[j] << ": ";
                    s.grades.push_back((int)inputDouble());
                }
                students.push_back(s);
            }

            cout << "\nстатистика по группе " << gName << "\n";
            for (int i = 0; i < subCount; i++) {
                double sum = 0;
                for (auto& s : students) sum += s.grades[i];
                cout << subs[i] << " | средний балл: " << sum / students.size() << "\n";
            }
            break;
        }
        default: cout << "неверный выбор!\n";
        }
    }
    return 0;
}
