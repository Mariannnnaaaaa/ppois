#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;


class BigInt
{
private:
    bool sign_;
    vector <int> digits_;

public:

    // конструкторы
    BigInt();

    BigInt(string s);

    //оператор присваивания
    BigInt& operator=(const BigInt& other);

    //оператор преобразования длинного целого к целому
    operator int();

    //СРАВНЕНИЕ

    //если размер одинаковый и положительный, но отличаются цифрами
    bool Comparison1(const BigInt& other);

    //если размер одинаковый и отрицательный, но отличаются цифрами
    bool Comparison2(const BigInt& other);

    bool operator>(const BigInt& other);

    bool Comparison3(const BigInt& other);

    bool Comparison4(const BigInt& other);

    bool operator>=(const BigInt& other);

    bool operator<(const BigInt& other);

    bool operator<=(const BigInt& other);

    //СЛОЖЕНИЕ

    //если оба числа положительные или оба числа отрицательные
    vector <int> Summ1(const BigInt& other, vector<int>summ, int shift);

    //если первое число положительное, а второе отрицательное, и размер первого больше
    vector <int> Summ2(const BigInt& other, vector<int>summ, int shift);

    //если первое число положительное, а второе отрицательное, и размер первого меньше или равен
    vector <int> Summ3(const BigInt& other, vector<int>summ, int shift);

    // если первое число отрицательное, а второе положительное, и размер первого больше
    vector <int> Summ4(const BigInt& other, vector<int>summ, int shift);

    // если первое число отрицательное, а второе положительное, и размер первого меньше
    vector <int> Summ5(const BigInt& other, vector<int>summ, int shift); 

    // если первое число отрицательное, а второе положительное, и размер первого равен второму
    vector <int> Summ6(const BigInt& other, vector<int>summ, int shift);


    BigInt operator+(const BigInt& other);

    BigInt& operator+=(const BigInt& other);

    //ВЫЧИТАНИЕ

    //если оба положительны и размер первого больше
    vector <int> Diff1(const BigInt& other, vector<int>diff, int shift);

    //если оба положительны и размер первого меньше или равен
    vector <int> Diff2(const BigInt& other, vector<int>diff, int shift);

    //если первое число положительно, второе отрицательно или если первое число отрицательно, а второе положительно
    vector <int> Diff3(const BigInt& other, vector<int>diff, int shift);

    BigInt operator-(const BigInt& other);

    BigInt& operator-=(const BigInt& other);

    //преинкремент 
    BigInt& operator++();

    //постинкремент
    BigInt operator++(int);

    //предекремент
    BigInt& operator--();

    //постдекремент
    BigInt operator--(int);

    string Record(const BigInt& other, vector <int> vector);

    //произведение
    BigInt operator* (const BigInt& other);

    BigInt& operator*= (const BigInt& other);

    //деление
    BigInt operator/ (const BigInt& other);

    BigInt& operator/= (const BigInt& other);

    string GetString();
};
