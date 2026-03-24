#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Complex {
private:
    double re;  
    double im; 

public:
    Complex();              
    Complex(double r);     
    Complex(double r, double i);

    friend istream& operator>>(istream& in, Complex& c);
    friend ostream& operator<<(ostream& out, const Complex& c);

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    double operator()() const;  
};

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize();  

public:
    Time();                       
    Time(int h, int m, int s);

    void addSecond();             

    friend istream& operator>>(istream& in, Time& t);
    friend ostream& operator<<(ostream& out, const Time& t);

    Time& operator++();          
    Time operator++(int);           
    Time& operator--();            
    Time operator--(int);        

    bool operator==(const Time& other) const;
    bool operator!=(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator<(const Time& other) const;

    Time& operator=(const Time& other);
    Time& operator+=(int sec);
    Time& operator-=(int sec);

    int operator()() const;        
};