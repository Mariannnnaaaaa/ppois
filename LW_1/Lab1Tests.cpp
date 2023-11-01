#include "pch.h"
#include "CppUnitTest.h"
#include "../lab1/BigInt.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab1Tests
{
	TEST_CLASS(Lab1Tests)
	{
	public:
		TEST_METHOD(Check_comparison1) {
			BigInt a("577578");
			BigInt b("-4774");
			bool res = a > b;
			bool result = true;
			Assert::AreEqual(result, res);
		}
		TEST_METHOD(Check_comparison2) {
			BigInt a("577");
			BigInt b("-477");
			bool res = a < b;
			bool result = false;
			Assert::AreEqual(result, res);
		}
		TEST_METHOD(Check_comparison3) {
			BigInt a("4775453");
			BigInt b("4774");
			bool res = a >= b;
			bool result = true;
			Assert::AreEqual(result, res);
		}
		TEST_METHOD(Check_comparison4) {
			BigInt a("577578");
			BigInt b("-4774");
			bool res = a <= b;
			bool result = false;
			Assert::AreEqual(result, res);
		}
		TEST_METHOD(Check_comparison5) {
			BigInt a("577");
			BigInt b("577");
			bool res = a <= b;
			bool result = true;
			Assert::AreEqual(result, res);
		}
		TEST_METHOD(Check_summ1)
		{
			BigInt a("577578");
			BigInt b("-4774");
			BigInt res = a + b;
			string result("572804");
			Assert::AreEqual(result, res.GetString());
		}
		TEST_METHOD(Check_summ2)
		{
			BigInt a("55");
			BigInt b("-65");
			BigInt res = a + b;
			string result = "-10";
			Assert::AreEqual(result, res.GetString());
		}
		TEST_METHOD(Check_summ3)
		{
			BigInt a("-65");
			BigInt b("55");
			BigInt res = a + b;
			string result = "-10";
			Assert::AreEqual(result, res.GetString());
		}
		TEST_METHOD(Check_summ4) {
			BigInt a("-6557884");
			BigInt b("553");
			BigInt res = a + b;
			string result = "-6557331";
			Assert::AreEqual(result, res.GetString());
		}
		TEST_METHOD(Check_summ5) {
			BigInt a("-6557884");
			BigInt b("553854989348");
			BigInt res = a + b;
			string result = "553848431464";
			Assert::AreEqual(result, res.GetString());
		}
		TEST_METHOD(Check_diff1) {
			BigInt a("6557884");
			BigInt b("553854989348");
			BigInt res = a - b;
			string result = "-553848431464";
			Assert::AreEqual(result, res.GetString());
		}
		TEST_METHOD(Check_diff2) {
			BigInt a("6557884");
			BigInt b("-5538");
			BigInt res = a - b;
			string result = "6563422";
			Assert::AreEqual(result, res.GetString());
		}
		TEST_METHOD(Check_composition) {
			BigInt a("-5787448");
			BigInt b("45436");
			BigInt res = a * b;
			string result = "-262958487328";
			Assert::AreEqual(result, res.GetString());
		}
		TEST_METHOD(Check_division) {
			BigInt a("-24648955");
			BigInt b("5");
			BigInt res = a / b;
			string result = "-4929791";
			Assert::AreEqual(result, res.GetString());
		}
		TEST_METHOD(Check_summ_and_appropriation) {
			BigInt a("214");
			BigInt b("23");
			a += b;
			string res = a.GetString();
			string result = "237";
			Assert::AreEqual(result, res);
		}
		TEST_METHOD(Check_diff_and_appropriation) {
			BigInt a("214");
			BigInt b("23");
			a -= b;
			string res = a.GetString();
			string result = "191";
			Assert::AreEqual(result, res);
		}
		TEST_METHOD(Check_composition_and_appropriation) {
			BigInt a("214");
			BigInt b("23");
			a *= b;
			string res = a.GetString();
			string result = "4922";
			Assert::AreEqual(result, res);
		}
		TEST_METHOD(Check_division_and_appropriation) {
			BigInt a("11633862");
			BigInt b("3");
			a /= b;
			string res = a.GetString();
			string result = "3877954";
			Assert::AreEqual(result, res);
		}
		TEST_METHOD(Check_pre_increment) {
			BigInt a("11633862");
			++a;
			string res = a.GetString();
			string result = "11633863";
			Assert::AreEqual(result, res);
		}
		TEST_METHOD(Check_pre_decrement) {
			BigInt a("11633862");
			--a;
			string res = a.GetString();
			string result = "11633861";
			Assert::AreEqual(result, res);
		}
	};
}
