#pragma once

#include <iostream>
#include <string>
using namespace std;

class MyString {
    string s;
public:
    MyString(const char* str = "");
    MyString operator*(const MyString& other) const;
    friend ostream& operator<<(ostream& os, const MyString& ms);
    friend istream& operator>>(istream& is, MyString& ms);
};
