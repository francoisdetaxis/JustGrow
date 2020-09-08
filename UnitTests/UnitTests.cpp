#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../JustGrow/BigNumber.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		TEST_METHOD(BigNumberInit1)
		{
			int a = 10, b = 10;
			BigNumber actual(a, b);
			std::string expected = "1.00E11";
			Assert::AreEqual(actual.asString(), expected);
		}

		TEST_METHOD(BigNumberInit2)
		{
			int b = 10;
			double a = 10;
			BigNumber actual(a, b);
			std::string expected = "1.00E11";
			Assert::AreEqual(actual.asString(), expected);
		}

		TEST_METHOD(BigNumberInit3)
		{
			int b = 10;
			float a = 10;
			BigNumber actual(a, b);
			std::string expected = "1.00E11";
			Assert::AreEqual(actual.asString(), expected);
		}

		TEST_METHOD(BigNumberInit4)
		{
			int b = 10;
			long a = 10;
			BigNumber actual(a, b);
			std::string expected = "1.00E11";
			Assert::AreEqual(actual.asString(), expected);
		}

		//LT = <
		TEST_METHOD(BigNumberLT1)
		{
			BigNumber a(1, 0);
			BigNumber b(1, 10);
			Assert::IsTrue(a < b);
		}

		TEST_METHOD(BigNumberLT2)
		{
			BigNumber a(1.0, 10);
			BigNumber b(100.0, 10);
			Assert::IsTrue(a < b);
		}

		TEST_METHOD(BigNumberLT3)
		{
			BigNumber a(1.0, 2);
			int b = 1000;
			Assert::IsTrue(a < b);
		}

		TEST_METHOD(BigNumberLT4)
		{
			BigNumber a(1.0, 2);
			float b = 1000.0;
			Assert::IsTrue(a < b);
		}

		TEST_METHOD(BigNumberLT5)
		{
			BigNumber a(1.0, 3);
			float b = 1000.0;
			Assert::IsFalse(a < b);
		}

		TEST_METHOD(BigNumberLT6)
		{
			BigNumber a(1.0, 3);
			int b = 1000;
			Assert::IsFalse(a < b);
		}

		TEST_METHOD(BigNumberLT7)
		{
			BigNumber a(1.0, 3);
			double b = 1000;
			Assert::IsFalse(a < b);
		}
		//LE = <=
		TEST_METHOD(BigNumberLE1)
		{
			BigNumber a(1, 0);
			BigNumber b(1, 10);
			Assert::IsTrue(a <= b);
		}

		TEST_METHOD(BigNumberLE2)
		{
			BigNumber a(1.0, 10);
			BigNumber b(100.0, 10);
			Assert::IsTrue(a <= b);
		}

		TEST_METHOD(BigNumberLE3)
		{
			BigNumber a(1.0, 2);
			int b = 1000;
			Assert::IsTrue(a <= b);
		}

		TEST_METHOD(BigNumberLE4)
		{
			BigNumber a(1.0, 2);
			float b = 1000.0;
			Assert::IsTrue(a <= b);
		}

		TEST_METHOD(BigNumberLE5)
		{
			BigNumber a(1.0, 3);
			float b = 1000.0;
			Assert::IsTrue(a <= b);
		}

		TEST_METHOD(BigNumberLE6)
		{
			BigNumber a(1.0, 3);
			int b = 1000;
			Assert::IsTrue(a <= b);
		}

		TEST_METHOD(BigNumberLE7)
		{
			BigNumber a(1.0, 3);
			double b = 1000;
			Assert::IsTrue(a <= b);
		}

		//GT = >
		TEST_METHOD(BigNumberGT1)
		{
			BigNumber a(1, 10);
			BigNumber b(1, 0);
			Assert::IsTrue(a > b);
		}

		TEST_METHOD(BigNumberGT2)
		{
			BigNumber a(100.0, 10);
			BigNumber b(1.0, 10);
			Assert::IsTrue(a > b);
		}

		TEST_METHOD(BigNumberGT3)
		{
			BigNumber a(1.0, 2);
			int b = 1000;
			Assert::IsFalse(a > b);
		}

		TEST_METHOD(BigNumberGT4)
		{
			BigNumber a(1.0, 2);
			float b = 1000.0;
			Assert::IsFalse(a > b);
		}

		TEST_METHOD(BigNumberGT5)
		{
			BigNumber a(1.0, 3);
			float b = 1000.0;
			Assert::IsFalse(a > b);
		}

		TEST_METHOD(BigNumberGT6)
		{
			BigNumber a(1.0, 3);
			int b = 1000;
			Assert::IsFalse(a > b);
		}

		TEST_METHOD(BigNumberGT7)
		{
			BigNumber a(1.0, 3);
			double b = 1000;
			Assert::IsFalse(a > b);
		}

		//GE = >=
		TEST_METHOD(BigNumberGE1)
		{
			BigNumber a(1, 10);
			BigNumber b(1, 0);
			Assert::IsTrue(a >= b);
		}

		TEST_METHOD(BigNumberGE2)
		{
			BigNumber a(100.0, 10);
			BigNumber b(1.0, 10);
			Assert::IsTrue(a >= b);
		}

		TEST_METHOD(BigNumberGE3)
		{
			BigNumber a(1.0, 2);
			int b = 1000;
			Assert::IsFalse(a >= b);
		}

		TEST_METHOD(BigNumberGE4)
		{
			BigNumber a(1.0, 2);
			float b = 1000.0;
			Assert::IsFalse(a >= b);
		}

		TEST_METHOD(BigNumberGE5)
		{
			BigNumber a(1.0, 3);
			float b = 1000.0;
			Assert::IsTrue(a >= b);
		}

		TEST_METHOD(BigNumberGE6)
		{
			BigNumber a(1.0, 3);
			int b = 1000;
			Assert::IsTrue(a >= b);
		}

		TEST_METHOD(BigNumberGE7)
		{
			BigNumber a(1.0, 3);
			double b = 1000;
			Assert::IsTrue(a >= b);
		}

		TEST_METHOD(BigNumberEQ1)
		{
			BigNumber a(1.0, 3);
			BigNumber b(1.0, 3);
			Assert::IsTrue(a == b);
		}

		TEST_METHOD(BigNumberEQ2)
		{
			BigNumber a(1.0, 3);
			int b = 1000;
			Assert::IsTrue(a == b);
		}

		TEST_METHOD(BigNumberEQ3)
		{
			BigNumber a(1.0, 3);
			float b = 1000;
			Assert::IsTrue(a == b);
		}

		TEST_METHOD(BigNumberEQ4)
		{
			BigNumber a(1.0, 3);
			double b = 1000;
			Assert::IsTrue(a == b);
		}

		TEST_METHOD(BigNumberEQ5)
		{
			BigNumber a(1.0, 0);
			double b = 1;
			Assert::IsTrue(a == b);
		}

		TEST_METHOD(BigNumberEQ6)
		{
			BigNumber a(1.0, 0);
			float b = 1.21;
			Assert::IsFalse(a == b);
		}

		TEST_METHOD(BigNumberNEQ1)
		{
			BigNumber a(1.0, 3);
			BigNumber b(1.2, 3);
			Assert::IsTrue(a != b);
		}

		TEST_METHOD(BigNumberNEQ2)
		{
			BigNumber a(1.0, 6);
			int b = 1000001;
			Assert::IsTrue(a != b);
		}

		TEST_METHOD(BigNumberNEQ3)
		{
			BigNumber a(1.0, 4);
			float b = 1000;
			Assert::IsTrue(a != b);
		}

		TEST_METHOD(BigNumberNEQ4)
		{
			BigNumber a(1.0, 3);
			double b = 10;
			Assert::IsTrue(a != b);
		}

		TEST_METHOD(BigNumberNEQ5)
		{
			BigNumber a(1.0, 0);
			double b = 1.01;
			Assert::IsTrue(a != b);
		}

		TEST_METHOD(BigNumberNEQ6)
		{
			BigNumber a(1.0, 0);
			float b = 1.21;
			Assert::IsTrue(a != b);
		}

		TEST_METHOD(BigNumberMult1)
		{
			BigNumber a(1.0, 0);
			BigNumber b(2, 0);
			BigNumber result;
			BigNumber expected(2, 0);
			result = a * b;
			Assert::IsTrue(result == expected);
		}

		TEST_METHOD(BigNumberMult2)
		{
			BigNumber a(1.0, 0);
			int b = 2000;
			BigNumber result;
			BigNumber expected(2, 3);
			result = a * b;
			Assert::IsTrue(result == expected);
		}

		TEST_METHOD(BigNumberMult3)
		{
			BigNumber a(1.8, 0);
			float b = 2245.17;
			BigNumber result;
			BigNumber expected(4.041306, 3);
			result = a * b;
			Assert::IsTrue(result == expected);
		}
	};
}