#include "pch.h"
#include "CppUnitTest.h"
#include "../FloatPointConverter.h"
#include "../BinaryConverter.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinaryTest
{
	TEST_CLASS(BinaryTest)
	{
	public:
		
        TEST_METHOD(Check_sum)
        {
            BinaryConverter b1(10);
            b1.print();
            cout << "Decimal representation of b1: " << b1.toDecimal() << endl;

            BinaryConverter b2(5);
            b2.print();
            cout << "Decimal representation of b2: " << b2.toDecimal() << endl;

            BinaryConverter sum = b1 + b2;
            sum.print();
            cout << "Decimal representation of the sum: " << sum.toDecimal() << endl;
            Assert::AreEqual(sum.toDecimal(), 15);
        }

        TEST_METHOD(Check_dif)
        {
            BinaryConverter b1(10);
            b1.print();
            cout << "Decimal representation of b1: " << b1.toDecimal() << endl;

            BinaryConverter b2(-5);
            b2.print();
            cout << "Decimal representation of b2: " << b2.toDecimal() << endl;

            BinaryConverter dif = b1 - b2;
            dif.print();
            cout << "Decimal representation of the dif: " << dif.toDecimal() << endl;
            Assert::AreEqual(dif.toDecimal(), 15);
        }

        TEST_METHOD(Check_mult)
        {
            BinaryConverter b1(10);
            b1.print();
            cout << "Decimal representation of b1: " << b1.toDecimal() << endl;

            BinaryConverter b2(-5);
            b2.print();
            cout << "Decimal representation of b2: " << b2.toDecimal() << endl;

            BinaryConverter mult = b1 * b2;
            mult.print();
            cout << "Decimal representation of the mult: " << mult.toDecimal() << endl;
            Assert::AreEqual(mult.toDecimal(), -50);
        }

        TEST_METHOD(Check_division)
        {
            BinaryConverter b1(-10);
            b1.print();
            cout << "Decimal representation of b1: " << b1.toDecimal() << endl;

            BinaryConverter b2(5);
            b2.print();
            cout << "Decimal representation of b2: " << b2.toDecimal() << endl;

            BinaryConverter division = b1 / b2;
            division.print();
            cout << "Decimal representation of the division: " << division.toDecimal() << endl;
            Assert::AreEqual(division.toDecimal(), -2);
        }

        TEST_METHOD(Check_float_sum)
        {
            FloatingPointConverter f1(11.1);
            f1.print();
            cout << "Float representation of the f1: " << f1.toFloat() << endl;

            FloatingPointConverter f2(6.67);
            f2.print();
            cout << "Float representation of the f2: " << f2.toFloat() << endl;

            FloatingPointConverter sum2 = f1 + f2;
            sum2.print();
            cout << "Float representation of the sum: " << sum2.toFloat() << endl;
            float num = 17.77;
            Assert::AreEqual(sum2.toFloat(), num);
        }
	};
}
