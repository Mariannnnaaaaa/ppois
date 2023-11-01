#include "BigInt.h"
using namespace std;

    // конструкторы
   BigInt::BigInt(string s) {
        if (s == "0") {
            digits_.push_back(0);
            sign_ = true;
            return;
        }

        int start = 0;
        if (s[0] == '-') {
            start = 1;
            sign_ = false;
        }
        else sign_ = true;

        for (int i = s.length() - 1; i >= start; i--) {
            digits_.push_back(s[i] - '0');   //преобразует символ в соответствующее ему целое число
        }
    }

    //оператор присваивания
    BigInt& BigInt::operator=(const BigInt& other) {
        digits_ = other.digits_;
        sign_ = other.sign_;
        return *this;
    }

    //оператор преобразования длинного целого к целому
   BigInt::operator int() {
        int result = 0;
        int ten = 1;
        for (int i = 0; i <= digits_.size() - 1; i++) {
            result += digits_[i] * ten;
            ten *= 10;
        }
        if (!sign_) result *= -1;
        return result;
    }

    //СРАВНЕНИЕ

    //если размер одинаковый и положительный, но отличаются цифрами
    bool BigInt::Comparison1(const BigInt& other) {
        for (int i = digits_.size() - 1; i >= 0; i--) {
            if (digits_[i] > other.digits_[i]) return true;
        }
        return false;
    }

    //если размер одинаковый и отрицательный, но отличаются цифрами
    bool BigInt::Comparison2(const BigInt& other) {
        for (int i = digits_.size() - 1; i >= 0; i--) {
            if (digits_[i] > other.digits_[i]) return false;
        }
        return false;
    }

    bool BigInt::operator>(const BigInt& other) {
        if ((sign_) && (sign_ != other.sign_)) return true;

        if ((other.sign_) && (other.sign_ != sign_)) return false;

        //если размер одинаковый и знак одинаковый, но отличаются цифрами
        if ((sign_ == other.sign_) && (digits_ == other.digits_)) {
            bool sign;
            if (sign_) return Comparison1(other); 
            if (!sign_) return Comparison2(other);
        }

        if ((digits_.size() > other.digits_.size()) && (sign_ == other.sign_)) {
            if (sign_) return true;
            if (!sign_) return false;
        }

        if ((digits_.size() < other.digits_.size()) && (sign_ == other.sign_)) {
            if (sign_) return false;
            if (!sign_) return true;
        }
    }

    bool BigInt::Comparison3(const BigInt& other) {
        for (int i = digits_.size() - 1; i >= 0; i--) {
            if (digits_[i] > other.digits_[i]) return true;
        }
        return true;
    }

    bool BigInt::Comparison4(const BigInt& other) {
        for (int i = digits_.size() - 1; i >= 0; i--) {
            if (digits_[i] > other.digits_[i]) return false;
        }
        return true;
    }

    bool BigInt::operator>=(const BigInt& other) {
        if ((sign_) && (sign_ != other.sign_)) return true;

        if ((other.sign_) && (other.sign_ != sign_)) return false;

        //если размер одинаковый и знак одинаковый, но отличаются цифрами
        if ((sign_ == other.sign_) && (digits_ == other.digits_)) {
            bool sign;
            if (sign_) return Comparison3(other);
            if (!sign_) return Comparison4(other);
        }

        if ((digits_.size() > other.digits_.size()) && (sign_ == other.sign_)) {
            if (sign_) return true;
            if (!sign_) return false;
        }

        if ((digits_.size() < other.digits_.size()) && (sign_ == other.sign_)) {
            if (sign_) return false;
            if (!sign_) return true;
        }
    }

    bool BigInt::operator<(const BigInt& other) {
        if ((!sign_) && (sign_ != other.sign_)) return true;

        if ((!other.sign_) && (other.sign_ != sign_)) return false;

        //если размер одинаковый и знак одинаковый, но отличаются цифрами
        if ((sign_ == other.sign_) && (digits_ == other.digits_)) {
            bool sign;
            if (other.sign_) return Comparison2(other);
            if (!other.sign_) return Comparison1(other);
        }

        if ((digits_.size() > other.digits_.size()) && (sign_ == other.sign_)) {
            if (sign_) return false;
            if (!sign_) return true;
        }

        if ((digits_.size() < other.digits_.size()) && (sign_ == other.sign_)) {
            if (sign_) return true;
            if (!sign_) return false;
        }
    }

    bool BigInt::operator<=(const BigInt& other) {
        if ((!sign_) && (sign_ != other.sign_)) return true;

        if ((!other.sign_) && (other.sign_ != sign_)) return false;

        //если размер одинаковый и знак одинаковый, но отличаются цифрами
        if ((sign_ == other.sign_) && (digits_ == other.digits_)) {
            if (other.sign_) return Comparison4(other);
            if (!other.sign_) return Comparison3(other);
        }

        if ((digits_.size() > other.digits_.size()) && (sign_ == other.sign_)) {
            if (sign_) return false;
            if (!sign_) return true;
        }

        if ((digits_.size() < other.digits_.size()) && (sign_ == other.sign_)) {
            if (sign_) return true;
            if (!sign_) return false;
        }
    }

    //СЛОЖЕНИЕ

    //если оба числа положительные или оба числа отрицательные
    vector <int> BigInt::Summ1(const BigInt& other, vector<int>summ, int shift) {
        for (int i = 0; i < max(digits_.size(), other.digits_.size()); i++) {
            int sum = shift;
            if (i < digits_.size()) sum += digits_[i];
            if (i < other.digits_.size()) sum += other.digits_[i];
            if (sum > 9) {
                sum -= 10;
                shift = 1;
            }
            else {
                shift = 0;
            }
            summ.push_back(sum);
        }
        if (shift) summ.push_back(shift);
        return summ;
    }

    //если первое число положительное, а второе отрицательное, и размер первого больше
    vector <int> BigInt::Summ2(const BigInt& other, vector<int>summ, int shift) {
        if (digits_.size() > other.digits_.size()) {
            for (int i = 0; i < digits_.size(); i++) {
                int sum = shift;
                if (i < digits_.size()) sum = digits_[i] + sum;
                if (i < other.digits_.size()) sum = sum - other.digits_[i];
                if (sum < 0) {
                    sum += 10;
                    shift = -1;
                }
                else {
                    shift = 0;
                }
                summ.push_back(sum);
            }
        }
        return summ;
    }

    //если первое число положительное, а второе отрицательное, и размер первого меньше или равен
    vector <int> BigInt::Summ3(const BigInt& other, vector<int>summ, int shift) {
        for (int i = 0; i < other.digits_.size(); i++) {
            int sum = shift;
            if (i < digits_.size()) sum += digits_[i];
            if (i < other.digits_.size()) sum = other.digits_[i] - sum;
            if (sum < 0) {
                sum += 10;
                shift = 1;
            }
            else {
                shift = 0;
            }
            summ.push_back(sum);
        }
        return summ;
    }

    // если первое число отрицательное, а второе положительное, и размер первого больше
    vector <int> BigInt::Summ4(const BigInt& other, vector<int>summ, int shift) {
        for (int i = 0; i < digits_.size(); i++) {
            int sum = shift;
            if (i < digits_.size()) sum = digits_[i] + sum;
            if (i < other.digits_.size()) sum -= other.digits_[i];
            if (sum < 0) {
                sum += 10;
                shift = -1;
            }
            else {
                shift = 0;
            }
            summ.push_back(sum);
        }
        return summ;
    }

    // если первое число отрицательное, а второе положительное, и размер первого меньше
    vector <int> BigInt::Summ5(const BigInt& other, vector<int>summ, int shift) {
        for (int i = 0; i < other.digits_.size(); i++) {
            int sum = shift;
            if (i < other.digits_.size()) sum += other.digits_[i];
            if (i < digits_.size()) sum -= digits_[i];
            if (sum < 0) {
                sum += 10;
                shift = -1;
            }
            else {
                shift = 0;
            }
            summ.push_back(sum);
        }
        return summ;
    }

    // если первое число отрицательное, а второе положительное, и размер первого равен второму
    vector <int> BigInt::Summ6(const BigInt& other, vector<int>summ, int shift) {
        for (int i = 0; i < other.digits_.size(); i++) {
            int sum = shift;
            if (i < other.digits_.size()) sum += other.digits_[i];
            if (i < digits_.size()) {
                if (sum < digits_[i]) {
                    sum += 10;
                    shift = -1;
                }
                sum = digits_[i] - sum;
            }
            if (sum < 0) {
                sum += 10;
                shift = -1;
            }
            else {
                shift = 0;
            }
            summ.push_back(sum);
        }
        return summ;
    }


    BigInt BigInt::operator+(const BigInt& other) {
        vector<int> summ;
        int shift = 0;

        //если оба числа положительные или оба числа отрицательные
        if (sign_ == other.sign_) summ = Summ1(other, summ, shift);

        // если первое число положительное, а второе отрицательное
        if (sign_ && !other.sign_) {
            if (digits_.size() > other.digits_.size()) summ = Summ2(other, summ, shift);
            else summ = Summ3(other, summ, shift);
        }

        // если первое число отрицательное, а второе положительное
        if (!sign_ && other.sign_) {
            if (digits_.size() > other.digits_.size()) summ = Summ4(other, summ, shift);
            else if (digits_.size() < other.digits_.size()) summ = Summ5(other, summ, shift);
            else if (digits_.size() == other.digits_.size()) summ = Summ6(other, summ, shift);
        }

        string str;
        while (summ.size() > 1 && summ.back() == 0) summ.pop_back();
        if ((!sign_ && !other.sign_) || ((!sign_) && (digits_ > other.digits_)) || ((!other.sign_) && (digits_ < other.digits_))) str.push_back('-');
        for (int i = summ.size() - 1; i >= 0; i--)  str.push_back(summ[i] + '0');

        return BigInt(str);
    }

    BigInt& BigInt::operator+=(const BigInt& other) {
        *this = *this + other;
        return *this;
    }

    //ВЫЧИТАНИЕ

    //если оба положительны и размер первого больше
    vector <int> BigInt::Diff1(const BigInt& other, vector<int>diff, int shift) {
        for (int i = 0; i < digits_.size(); i++) {
            int dif = shift + digits_[i];
            if (i < other.digits_.size()) dif -= other.digits_[i];
            if (dif < 0) {
                dif += 10;
                shift = -1;
            }
            else shift = 0;
            diff.push_back(dif);
        }
        return diff;
    }

    //если оба положительны и размер первого меньше или равен
    vector <int> BigInt::Diff2(const BigInt& other, vector<int>diff, int shift) {
        for (int i = 0; i < other.digits_.size(); i++) {
            int dif = shift;
            if (i < digits_.size()) dif += digits_[i];
            if (i < other.digits_.size()) dif = other.digits_[i] - dif;
            if (dif < 0) {
                dif += 10;
                shift = 1;
            }
            else {
                shift = 0;
            }
            diff.push_back(dif);
        }
        return diff;
    }

    //если первое число положительно, второе отрицательно или если первое число отрицательно, а второе положительно
    vector <int> BigInt::Diff3(const BigInt& other, vector<int>diff, int shift) {
        for (int i = 0; i < max(digits_.size(), other.digits_.size()); i++) {
            int dif = shift;
            if (i < digits_.size()) dif += digits_[i];
            if (i < other.digits_.size()) dif += other.digits_[i];
            if (dif > 9) {
                dif -= 10;
                shift = 1;
            }
            else {
                shift = 0;
            }
            diff.push_back(dif);
        }
        if (shift) diff.push_back(shift);
        return diff;
    }

    BigInt BigInt::operator-(const BigInt& other) {
        vector<int> diff;
        int shift = 0;

        //если оба положительны
        if (sign_ && other.sign_) {
            if (digits_.size() > other.digits_.size()) diff = Diff1(other, diff, shift);
            else diff = Diff2(other, diff, shift);
        }

        //если оба отрицательны
        if (!sign_ && !other.sign_) {
            BigInt otherCopy = other;
            sign_ = !sign_;
            otherCopy.sign_ = !otherCopy.sign_;
            return otherCopy - *this;
        }

        //если первое число положительно, второе отрицательно или если первое число отрицательно, а второе положительно
        if ((sign_ && !other.sign_) || (!sign_ && other.sign_)) diff = Diff3(other, diff, shift);

        while (diff.size() > 1 && diff.back() == 0) diff.pop_back();
        string str;
        if (sign_ && other.sign_ && (digits_ < other.digits_)) str.push_back('-');
        for (int i = diff.size() - 1; i >= 0; i--) str.push_back(diff[i] + '0');
        return BigInt(str);
    }

    BigInt& BigInt::operator-=(const BigInt& other) {
        *this = *this - other;
        return *this;
    }

    //преинкремент 
    BigInt& BigInt::operator++() {
        string str = "1";
        *this = *this + str;
        return *this;
    }

    //постинкремент
    BigInt BigInt::operator++(int) {
        BigInt temp(*this);
        string str = "1";
        *this = *this + str;
        return temp;
    }

    //предекремент
    BigInt& BigInt::operator--() {
        string str = "-1";
        *this = *this + str;
        return *this;
    }

    //постдекремент
    BigInt BigInt::operator--(int) {
        BigInt temp(*this);
        string str = "-1";
        *this = *this + str;
        return temp;
    }

    string BigInt::Record(const BigInt& other, vector <int> vector) {
        string str;
        if ((!sign_ && other.sign_) || (sign_ && !other.sign_)) str.push_back('-');
        for (int i = vector.size() - 1; i >= 0; i--) str.push_back(vector[i] + '0');
        return str;
    }

    //произведение
    BigInt BigInt::operator* (const BigInt& other) {
        int totalDigits = digits_.size() + other.digits_.size();
        vector<int> composition(totalDigits, 0);
        int shift = 0;
        int remains = 0;

        for (int i = 0; i < digits_.size(); i++) {
            for (int j = 0; j < other.digits_.size(); j++) {
                int comp = digits_[i] * other.digits_[j];
                shift = comp / 10;
                remains = comp % 10;
                composition[i + j] += remains;
                composition[i + j + 1] += shift;
            }
        }

        // обработка переносов
        for (int i = 0; i < totalDigits - 1; i++) {
            shift = composition[i] / 10;
            remains = composition[i] % 10;

            composition[i] = remains;
            composition[i + 1] += shift;
        }

        while (composition.size() > 1 && composition.back() == 0) composition.pop_back();
        string str = Record(other, composition);
        return BigInt(str);
    }

    BigInt& BigInt::operator*= (const BigInt& other) {
        *this = *this * other;
        return *this;
    }

    //деление
    BigInt BigInt::operator/ (const BigInt& other) {
        vector<int> division(digits_.size(), 0);
        int remains = 0;
        if (other.digits_.empty() || (other.digits_[0] == 0)) return BigInt("Error! Divisor is zero.");
        for (int i = digits_.size() - 1; i >= 0; i--) {
            remains = remains * 10 + digits_[i];
            division[i] = remains / other.digits_[0];
            remains %= other.digits_[0];
        }

        while (division.size() > 1 && division.back() == 0) division.pop_back();
        string str = Record(other, division);
        return BigInt(str);
    }

    BigInt& BigInt::operator/= (const BigInt& other) {
        *this = *this / other;
        return *this;
    }

    string BigInt::GetString() {
        string str;
        if (!sign_) str.push_back('-');
        for (int i = digits_.size() - 1; i >= 0; i--) str.push_back(digits_[i] + '0');
        return str;
    }