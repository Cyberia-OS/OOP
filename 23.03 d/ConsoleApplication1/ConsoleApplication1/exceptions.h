#pragma once
#include <iostream>
#include <string>

using namespace std;

class NegativeBalanceException {
public:
    
    const char* what() const { return "Начальный баланс не может быть отрицательным"; }
};

class NegativeWithdrawException {
public:
    const char* what() const { return "Сумма снятия не может быть отрицательной"; }
};

class InsufficientFundsException {
public:
    const char* what() const { return "Недостаточно средств на счете"; }
};

class DivisionByZeroException {
public:
    const char* what() const { return "Ошибка: деление на ноль"; }
};

class OutOfRangeException {
public:
    const char* what() const { return "Индекс выходит за границы массива"; }
};

class BankAccount {
private:
    string owner;
    double balance;

public:
    BankAccount(const string& name, double initialBalance) : owner(name), balance(initialBalance) {
        if (initialBalance < 0) {
            throw NegativeBalanceException();
        }
    }

    void withdraw(double amount) {
        if (amount < 0) {
            throw NegativeWithdrawException();
        }
        if (amount > balance) {
            throw InsufficientFundsException();
        }
        balance -= amount;
    }

    double getBalance() const { return balance; }
    string getOwner() const { return owner; }
};

class SafeDivision {
public:
    static double divide(double a, double b) {
        if (b == 0) {
            throw DivisionByZeroException();
        }
        return a / b;
    }
};

class IntArray {
private:
    int* data;
    size_t size;

public:
    IntArray(size_t n) : size(n) {
        data = new int[n];
    }

    ~IntArray() {
        delete[] data;
    }

    int at(size_t index) const {
        if (index >= size) {
            throw OutOfRangeException();
        }
        return data[index];
    }

    void set(size_t index, int value) {
        if (index >= size) {
            throw OutOfRangeException();
        }
        data[index] = value;
    }

    size_t getSize() const { return size; }
};