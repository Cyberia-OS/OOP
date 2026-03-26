#include "task11.h"
#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

template <typename T>
double average(const T* arr, int size) {
    if (size <= 0) 
        return 0;
    T sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return static_cast<double>(sum) / size;
}

template <typename T>
Solution solveLinear(T a, T b) {
    Solution sol;
    if (a == 0) {
        if (b == 0) sol.roots = -1;
        else sol.roots = 0;
    }
    else {
        sol.roots = 1;
        sol.x1 = -static_cast<double>(b) / a;
    }
    return sol;
}

template <typename T>
Solution solveQuadratic(T a, T b, T c) {
    if (a == 0) 
        return solveLinear(b, c);
    double disc = static_cast<double>(b) * b - 4.0 * a * c;
    Solution sol;
    if (disc < 0) sol.roots = 0;
    else if (disc == 0) {
        sol.roots = 1;
        sol.x1 = -static_cast<double>(b) / (2.0 * a);
    }
    else {
        sol.roots = 2;
        double sqrtD = sqrt(disc);
        sol.x1 = (-static_cast<double>(b) - sqrtD) / (2.0 * a);
        sol.x2 = (-static_cast<double>(b) + sqrtD) / (2.0 * a);
    }
    return sol;
}

template <typename T>
T maxOfTwo(const T& a, const T& b) {
    return (a > b) ? a : b;
}

template <typename T>
T minOfTwo(const T& a, const T& b) {
    return (a < b) ? a : b;
}

void demoAverage() {
    int n;
    cout << "\nсреднее арифметическое\n";
    cout << "Введите количество элементов: ";
    cin >> n;
    if (n <= 0) {
        cout << "Некорректный размер.\n";
        return;
    }

    double* arr = new double[n];
    cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    cout << "Среднее арифметическое: " << average(arr, n) << endl;
    delete[] arr;
}

void eqt() {
    cout << "\nРешение уравнений\n";
    cout << "Выберите тип:\n1 - линейное a*x + b = 0\n2 - квадратное a*x^2 + b*x + c = 0\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        double a, b;
        cout << "Введите a и b: ";
        cin >> a >> b;
        Solution s = solveLinear(a, b);
        if (s.roots == -1) cout << "Бесконечно много решений.\n";
        else if (s.roots == 0) cout << "Нет решений.\n";
        else cout << "Корень: x = " << s.x1 << endl;
    }
    else if (choice == 2) {
        double a, b, c;
        cout << "Введите a, b, c: ";
        cin >> a >> b >> c;
        Solution s = solveQuadratic(a, b, c);
        if (s.roots == -1) cout << "Бесконечно много решений\n";
        else if (s.roots == 0) cout << "Нет действительных корней\n";
        else if (s.roots == 1) cout << "Один корень: x = " << s.x1 << endl;
        else cout << "Два корня: x1 = " << s.x1 << ", x2 = " << s.x2 << endl;
    }
    else {
        cout << "Неверный выбор" << endl;
    }
}

void demoMinMax() {
    cout << "Минимум и максимум" << endl;
    cout << "Введите два числа: ";
    double a, b;
    cin >> a >> b;
    cout << "Максимум: " << maxOfTwo(a, b) << endl;
    cout << "Минимум: " << minOfTwo(a, b) << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");  

    int option;
    do {
        cout << "1 - Среднее арифметическое" << endl;
        cout << "2 - Решение уравнений" << endl;
        cout << "3 - Максимум и минимум из двух" << endl;
        cout << "0 - Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> option;

        switch (option) {
        case 1: demoAverage(); 
            break;
        case 2: eqt();
            break;
        case 3: demoMinMax();
            break;
        case 0: cout << "До свидания" << endl;
            break;
        default: cout << "Неверный пункт" << endl;
        }
    } while (option != 0);
    return 0;
}