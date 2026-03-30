#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class BankAccount {
private:
    string accountName;
    double currentBalance;
public:
    BankAccount(const string& name, double initialBalance);
    void withdraw(double amount);
    double getBalance() const;
    string getOwner() const;
};

class DivisionByZeroException : public exception {
public:
    const char* what() const noexcept override;
};

class SafeDivision {
public:
    static double divide(double a, double b);
};

class IntArray {
private:
    int* arrayData;
    int arraySize;
public:
    IntArray(int n);
    ~IntArray();
    int at(int index) const;
    void setAt(int index, int value);
    int getSize() const;
};