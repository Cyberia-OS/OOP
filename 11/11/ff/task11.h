#pragma once

struct Solution {
    int roots;  
    double x1, x2;
};

template <typename T>
double average(const T* arr, int size);

template <typename T>
Solution solveLinear(T a, T b);

template <typename T>
Solution solveQuadratic(T a, T b, T c);

template <typename T>
T maxOfTwo(const T& a, const T& b);

template <typename T>
T minOfTwo(const T& a, const T& b);
