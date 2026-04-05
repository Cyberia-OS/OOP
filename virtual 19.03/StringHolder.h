#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class StringHolder {
protected:
    char* data;          
public:
    StringHolder(const char* src) {
        data = new char[strlen(src) + 1];
        strcpy_s(data, strlen(src) + 1, src);
        cout << "Конструктор StringHolder для \"" << src << "\"" << endl;
    }

    virtual ~StringHolder() {
        cout << "Деструктор StringHolder для \"" << data << "\"" << endl;
        delete[] data;
    }

    virtual void print() const {
        cout << data << endl;
    }
};

class ReverseString : public StringHolder {
private:
    char* reversed;    
    void buildReverse() {
        int len = strlen(data);
        reversed = new char[len + 1];
        for (int i = 0; i < len; ++i)
            reversed[i] = data[len - 1 - i];
        reversed[len] = '\0';
    }
public:
    ReverseString(const char* src) : StringHolder(src), reversed(nullptr) {
        cout << "Конструктор ReverseString" << endl;
        buildReverse();
    }

    ~ReverseString() override {
        cout << "Деструктор ReverseString" << endl;
        delete[] reversed;
    }

    void print() const override {
        cout << reversed << endl;
    }
};
