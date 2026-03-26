#include "exceptions.h"

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "=== Задание 1: BankAccount ===" << endl;
    try {
        BankAccount acc("Иван", 1000);
        cout << "Счёт открыт. Баланс: " << acc.getBalance() << endl;
        acc.withdraw(200);
        cout << "Снято 200. Баланс: " << acc.getBalance() << endl;
        acc.withdraw(900);
    }
    catch (const NegativeBalanceException& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    catch (const NegativeWithdrawException& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    catch (const InsufficientFundsException& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    try {
        BankAccount badAcc("Пётр", -500);
    }
    catch (const NegativeBalanceException& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    try {
        BankAccount acc2("Сергей", 500);
        acc2.withdraw(-100);
    }
    catch (const NegativeWithdrawException& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    cout << endl;

    cout << "=== Задание 2: SafeDivision ===" << endl;
    try {
        cout << "10 / 2 = " << SafeDivision::divide(10, 2) << endl;
        cout << "5 / 0 = " << SafeDivision::divide(5, 0) << endl;
    }
    catch (const DivisionByZeroException& e) {
        cout << e.what() << endl;
    }
    cout << endl;

    cout << "=== Задание 3: IntArray ===" << endl;
    try {
        IntArray arr(5);
        arr.set(0, 10);
        arr.set(1, 20);
        cout << "arr[0] = " << arr.at(0) << endl;
        cout << "arr[1] = " << arr.at(1) << endl;
        cout << "Попытка доступа к arr[5]: ";
        arr.at(5);  
    }
    catch (const OutOfRangeException& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    try {
        IntArray arr2(3);
        arr2.set(0, 100);
        arr2.set(1, 200);
        arr2.set(2, 300);
        cout << "\nКорректные элементы: ";
        for (size_t i = 0; i < arr2.getSize(); i++)
            cout << arr2.at(i) << " ";
        cout << endl;
    }
    catch (const OutOfRangeException& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}