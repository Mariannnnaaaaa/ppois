#include "FloatingPointConverter.h"
using namespace std;

    void FloatingPointConverter::setSign(float& value) {
        if (value < 0) {
            sign = 1;
            value = -value;
        }
        else sign = 0;
    }

    void FloatingPointConverter::convertIntegerPart(int intValue) {
        while (intValue) {
            exponent.insert(exponent.begin(), intValue % 2);
            intValue /= 2;
        }
        while (exponent.size() < 8) exponent.insert(exponent.begin(), 0);
    }

    void FloatingPointConverter::convertFractionalPart(float fracValue) {
        while (fracValue > 0) {
            fracValue *= 2;
            int bit = fracValue >= 1.0 ? 1 : 0;
            mantissa.push_back(bit);
            if (bit == 1) fracValue -= 1.0;
        }
    }

    FloatingPointConverter::FloatingPointConverter (float value) {
        setSign(value);
        int intValue = (int)value;
        float fracValue = value - intValue;
        convertIntegerPart(intValue);
        convertFractionalPart(fracValue);
    }

    void FloatingPointConverter::print() {
        cout << "Sign: " << sign << "\n";
        cout << "Exponent: ";
        for (int bit : exponent) cout << bit;
        cout << "\n";
        cout << "Mantissa: ";
        for (int bit : mantissa) cout << bit;
        cout << "\n";
    }

    float FloatingPointConverter::toFloat() {
        float value = 0.0;
        for (int i = 0; i < exponent.size(); ++i) {
            value += exponent[i] * pow(2, exponent.size() - 1 - i);
        }
        for (int i = 0; i < mantissa.size(); ++i) {
            value += mantissa[i] * pow(2, -1 - i);
        }
        return sign == 1 ? -value : value;
    }

    vector<int> FloatingPointConverter::subtractMantissas(const FloatingPointConverter& greater, const FloatingPointConverter& lesser) const {
        vector<int> result;
        int borrow = 0;
        for (int i = greater.mantissa.size() - 1; i >= 0; --i) {
            int sub = greater.mantissa[i] - (i < lesser.mantissa.size() ? lesser.mantissa[i] : 0) - borrow;
            if (sub < 0) {
                sub += 2;
                borrow = 1;
            }
            else borrow = 0;
            result.insert(result.begin(), sub);
        }
        return result;
    }

    vector<int> FloatingPointConverter::addMantissas(const vector<int>& mantissa1, const vector<int>& mantissa2, int& carry) const {
        vector<int> result;
        int size = max(mantissa1.size(), mantissa2.size());
        for (int i = size - 1; i >= 0; --i) {
            int sum = mantissa1[i] + mantissa2[i] + carry;
            result.push_back(sum % 2);
            carry = sum / 2;
        }
        return result;
    }

    vector<int> FloatingPointConverter::addExponents(const vector<int>& exponent1, const vector<int>& exponent2, int& carry) const {
        vector<int> result;
        for (int i = 7; i >= 0; --i) {
            int sum = exponent1[i] + exponent2[i] + carry;
            result.insert(result.begin(), sum % 2);
            carry = sum / 2;
        }
        return result;
    }

    FloatingPointConverter FloatingPointConverter::operator+(const FloatingPointConverter& other) const {
        vector<int> result;
        if (this->sign != other.sign) {
            bool thisIsGreater = this->exponent.size() > other.exponent.size() || (this->exponent.size() == other.exponent.size() && this->mantissa > other.mantissa);
            const FloatingPointConverter& greater = thisIsGreater ? *this : other;
            const FloatingPointConverter& lesser = thisIsGreater ? other : *this;
            result = subtractMantissas(greater, lesser);
            FloatingPointConverter diff(0);
            diff.sign = thisIsGreater ? this->sign : other.sign;
            diff.exponent = greater.exponent;
            diff.mantissa = result;
            return diff;
        }

        int carry = 0;
        int size = max(this->mantissa.size(), other.mantissa.size());
        vector<int> mantissa1 = this->mantissa;
        vector<int> mantissa2 = other.mantissa;
        while (mantissa1.size() < size) mantissa1.push_back(0);
        while (mantissa2.size() < size) mantissa2.push_back(0);

        result = addMantissas(mantissa1, mantissa2, carry);

        vector<int> exponent1 = this->exponent;
        vector<int> exponent2 = other.exponent;
        if (carry) exponent1.push_back(carry);
        vector<int> exponentResult = addExponents(exponent1, exponent2, carry);

        FloatingPointConverter sum(0);
        sum.sign = this->sign;
        sum.exponent = exponentResult;
        sum.mantissa = vector<int>(result.rbegin(), result.rend());

        return sum;
    }