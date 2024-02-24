#pragma once
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class FloatingPointConverter {
private:
    int sign;
    vector<int> exponent;
    vector<int> mantissa;
public:
    void setSign(float& value);

    void convertIntegerPart(int intValue);

    void convertFractionalPart(float fracValue);

    FloatingPointConverter(float value);

    void print();

    float toFloat();

    vector<int> subtractMantissas(const FloatingPointConverter& greater, const FloatingPointConverter& lesser) const;

    vector<int> addMantissas(const vector<int>& mantissa1, const vector<int>& mantissa2, int& carry) const;

    vector<int> addExponents(const vector<int>& exponent1, const vector<int>& exponent2, int& carry) const;

    FloatingPointConverter operator+(const FloatingPointConverter& other) const;
};

