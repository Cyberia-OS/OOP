#include "exceptions_task.h"

BankAccount::BankAccount(const string& name, double initialBalance)
    : accountName(name), currentBalance(initialBalance) {
    if (initialBalance < 0) {
        throw invalid_argument("начальный баланс не может быть отрицательным");
    }
}

void BankAccount::withdraw(double amount) {
    if (amount < 0) {
        throw invalid_argument("сумма снятия не может быть отрицательной");
    }
    if (amount > currentBalance) {
        throw runtime_error("недостаточно средств");
    }
    currentBalance -= amount;
}

double BankAccount::getBalance() const { return currentBalance; }
string BankAccount::getOwner() const { return accountName; }

const char* DivisionByZeroException::what() const noexcept {
    return "деление на ноль";
}

double SafeDivision::divide(double a, double b) {
    if (b == 0) {
        throw DivisionByZeroException();
    }
    return a / b;
}

IntArray::IntArray(int n) : arraySize(n) {
    if (n <= 0) {
        throw invalid_argument("размер массива должен быть положительным");
    }
    arrayData = new int[arraySize];
}

IntArray::~IntArray() {
    delete[] arrayData;
}

int IntArray::at(int index) const {
    if (index < 0 || index >= arraySize) {
        throw out_of_range("индекс выходит за границы");
    }
    return arrayData[index];
}

void IntArray::setAt(int index, int value) {
    if (index < 0 || index >= arraySize) {
        throw out_of_range("индекс выходит за границы");
    }
    arrayData[index] = value;
}

int IntArray::getSize() const { return arraySize; }

void testBankAccount() {
    try {
        BankAccount acc("Иванов", -100);
    }
    catch (const invalid_argument& e) {
        cout << "Исключение: " << e.what() << endl;
    }

    BankAccount acc("Петров", 1000);
    try {
        acc.withdraw(-50);
    }
    catch (const invalid_argument& e) {
        cout << "Исключение: " << e.what() << endl;
    }
    try {
        acc.withdraw(2000);
    }
    catch (const runtime_error& e) {
        cout << "Исключение: " << e.what() << endl;
    }
    acc.withdraw(300);
    cout << "Конечный баланс: " << acc.getBalance() << endl;
}

void testSafeDivision() {
    cout << "\nSafeDivision\n";
    try {
        cout << "10 / 2 = " << SafeDivision::divide(10, 2) << endl;
    }
    catch (const DivisionByZeroException& e) {
        cout << e.what() << endl;
    }
    try {
        cout << "10 / 0 = " << SafeDivision::divide(10, 0) << endl;
    }
    catch (const DivisionByZeroException& e) {
        cout << "Исключение: " << e.what() << endl;
    }
    try {
        cout << "7 / 3 = " << SafeDivision::divide(7, 3) << endl;
    }
    catch (const DivisionByZeroException& e) {
        cout << e.what() << endl;
    }
}

void testIntArray() {
    cout << "\nIntArray\n";
    try {
        IntArray arr(-5);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    IntArray arr(5);
    for (int i = 0; i < arr.getSize(); ++i) {
        arr.setAt(i, (i + 1) * 10);
    }
    try {
        cout << "arr[2] = " << arr.at(2) << endl;
        cout << "arr[4] = " << arr.at(4) << endl;
        cout << "arr[5] = " << arr.at(5) << endl;
    }
    catch (const out_of_range& e) {
        cout << "Исключение: " << e.what() << endl;
    }
    try {
        arr.setAt(5, 100);
    }
    catch (const out_of_range& e) {
        cout << "Исключение: " << e.what() << endl;
    }
    cout << "Все элементы: ";
    for (int i = 0; i < arr.getSize(); ++i) {
        cout << arr.at(i) << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    int choice;
    do {
        cout << "\nВыберите задание (1-3, 0 выход): ";
        cin >> choice;
        switch (choice) {
        case 1: testBankAccount();
            break;
        case 2: testSafeDivision(); 
            break;
        case 3: testIntArray();
            break;
        case 0: cout << "До свидания.\n"; 
            break;
        default: cout << "Неверный выбор.\n";
        }
    } while (choice != 0);
    return 0;
}