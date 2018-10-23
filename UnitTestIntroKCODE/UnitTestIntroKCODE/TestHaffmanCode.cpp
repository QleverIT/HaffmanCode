#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\..\IntroKCODE\IntroKCODE\HaffmanCode.h" 
#include "..\..\IntroKCODE\IntroKCODE\HaffmanCode.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestIntroKCODE
{
	TEST_CLASS(TestHaffmanCode)
	{
	public:

		TEST_METHOD(Test_mfff)
		{
			string s = "mfff";
			string cod = HaffmanCode::toShifrHaffman(s);

			string result = s;
			string test = HaffmanCode::deShifrHaffman(cod);

			Assert::IsTrue(test == result);
		}
		
		TEST_METHOD(Test_mfa)
		{
			string s = "mfa";
			string cod = HaffmanCode::toShifrHaffman(s);

			string result = s;
			string test = HaffmanCode::deShifrHaffman(cod);

			Assert::IsTrue(test == result);
		}

		TEST_METHOD(Test_accbcaaabc)
		{
			string s = "accbcaaabc";
			string cod = HaffmanCode::toShifrHaffman(s);

			string result = s;
			string test = HaffmanCode::deShifrHaffman(cod);

			Assert::IsTrue(test == result);
		}

		TEST_METHOD(Test_xfzfxzaxff)
		{
			string s = "xfzfxzaxff";
			string cod = HaffmanCode::toShifrHaffman(s);

			string result = s;
			string test = HaffmanCode::deShifrHaffman(cod);

			Assert::IsTrue(test == result);
		}
		
		TEST_METHOD(Test_V_mfff)
		{
			string s = "mfff";
			string cod = HaffmanCode::toShifrHaffmanV(s);

			string result = s;
			string test = HaffmanCode::deShifrHaffmanV(cod);

			Assert::IsTrue(test == result);
		}

		TEST_METHOD(Test_V_mfa)
		{
			string s = "mfa";
			string cod = HaffmanCode::toShifrHaffmanV(s);

			string result = s;
			string test = HaffmanCode::deShifrHaffmanV(cod);

			Assert::IsTrue(test == result);
		}

		TEST_METHOD(Test_V_accbcaaabc)
		{
			string s = "accbcaaabc";
			string cod = HaffmanCode::toShifrHaffmanV(s);

			string result = s;
			string test = HaffmanCode::deShifrHaffmanV(cod);

			Assert::IsTrue(test == result);
		}

		TEST_METHOD(Test_V_xfzfxzaxff)
		{
			string s = "xfzfxzaxff";
			string cod = HaffmanCode::toShifrHaffmanV(s);

			string result = s;
			string test = HaffmanCode::deShifrHaffmanV(cod);

			Assert::IsTrue(test == result);
		}
	};
}