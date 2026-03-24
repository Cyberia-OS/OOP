#pragma once
#include <iostream>
#include <vector>

class Set {
private:
    std::vector<int> data;
    bool contains(int elem) const;
public:
    Set();
    Set(const std::vector<int>& vec);
    Set(std::initializer_list<int> list);
    Set operator+(int elem) const;
    Set operator+(const Set& other) const;
    Set operator-(int elem) const;
    Set operator-(const Set& other) const;
    bool operator==(const Set& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Set& s);
};
