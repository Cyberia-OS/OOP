#include "Time.h"

int main() {
    setlocale(LC_ALL, "RU");

    Time t1(10, 30, 45), t2, t3(23, 59, 59);

    cout << "t1 = " << t1 << endl;
    cout << "t2 = " << t2 << endl;

    ++t1;
    cout << "После ++t1: " << t1 << endl;
    t1--;
    cout << "После t1--: " << t1 << endl;

    t2 += 90;
    cout << "t2 += 90: " << t2 << endl;

    cout << "t1() = " << t1() << " секунд" << endl;

    cout << "t1 == t2? " << (t1 == t2 ? "да" : "нет") << endl;
    cout << "t1 < t2? " << (t1 < t2 ? "да" : "нет") << endl;

    cout << "Введите часы минуты секунды: ";
    cin >> t2;
    cout << "Вы ввели: " << t2 << endl;

    t3.addOneSecond();
    cout << "23:59:59 + 1 сек = " << t3 << endl;

    return 0;
}
