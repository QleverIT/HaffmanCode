#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\..\IntroKCODE\IntroKCODE\TransformBits.h" 
#include "..\..\IntroKCODE\IntroKCODE\TransformBits.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestIntroKCODE
{
	TEST_CLASS(TestTransformBits)
	{
	public:

		TEST_METHOD(Test)
		{
			char x = 'x';
			string bitX = TransformBits::charToBits(x);
			char retX = TransformBits::bitsToChar(bitX);

			char result = x;
			char test = retX;

			Assert::AreEqual(test, result);
		}
	};
}