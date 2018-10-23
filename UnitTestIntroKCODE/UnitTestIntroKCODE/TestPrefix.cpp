#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\..\IntroKCODE\IntroKCODE\PrefixCode.h" 
#include "..\..\IntroKCODE\IntroKCODE\PrefixCode.cpp" 
#include "..\..\IntroKCODE\IntroKCODE\Deshifrator.h" 
#include "..\..\IntroKCODE\IntroKCODE\Deshifrator.cpp" 
#include <string>
#include <vector>
#include <map>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestIntroKCODE
{		
	TEST_CLASS(TestPrefixCode)
	{
	public:
		
		TEST_METHOD(TestIfValidate)
		{
			int alen[] = { 1, 2, 3, 4 }; // Длина кода одного символа			
			int size = 4; // Размер алфавита

			// Получится ли закодировать алваит?
			// Проверяемое условие:  сумма 2^alen[i] <= 1
			bool test = PrefixCode::ifValidate(alen, size);

			Assert::IsTrue(test);
		}

		TEST_METHOD(TestToString)
		{
			int alen[] = { 1, 2, 3, 4 }; // Длина кода одного символа
			string a = "abcd"; // Алфавит
			int size = 4; // Размер алфавита

			// Cоздание объекта PrefixCode			
			PrefixCode pr(a, alen, size);

			// Проверка информации об объекте
			string result = "a || 0\nb || 10\nc || 110\nd || 1110\n";
			string test = pr.toString();

			Assert::AreEqual(test, result);
		}
		
		TEST_METHOD(TestGetCode)
		{
			int alen[] = { 1, 2, 3, 4 }; // Длина кода одного символа
			string a = "abcd"; // Алфавит
			int size = 4; // Размер алфавита

			// Cоздание объекта PrefixCode			
			PrefixCode pr(a, alen, size);
			
			// Функция возвращает вектор пар: символ и его код			
			map<string, char> alfCode = pr.getCode();
			string s = "";
			for (auto elem : alfCode) {
				s += elem.second;
				s += elem.first;
			}

			// Проверяем возвращаемое значение
			string result = "a0b10c110d1110";
			string test = s;

			Assert::AreEqual(test, result);
		}
		
		TEST_METHOD(TestToShifr)
		{
			int alen[] = { 1, 2, 3, 4 }; // Длина кода одного символа
			string a = "abcd"; // Алфавит
			int size = 4; // Размер алфавита

			// Cоздание объекта PrefixCode			
			PrefixCode pr(a, alen, size);

			// Кодируемое слово
			string word = "aabadac";

			
			// Шифрование			
			vector<bool> shifr = pr.toShifr(word);
			string s = "";
			for (auto b : shifr)
				if (b)
					s += "1";
				else
					s += "0";

			// Проверяем возвращаемое значение
			string result = "0010011100110";			
			string test = s;
			
			/*
			vector<bool> result = {0,0,1,0,0,1,1,1,0,0,1,1,0};
			vector<bool> test = pr.toShifr(word); 
			// ^ ошибка литерал определен пользователем (Assert error)
			*/

			Assert::AreEqual(test, result);
		}

	};

	TEST_CLASS(TestDeshifrator)
	{
	public:

		TEST_METHOD(TestDeCode)
		{
			// Зашифрованное слово
			vector<bool> shifr = { 0,0,1,0,0,1,1,1,0,0,1,1,0 };
			
			// Вектор пар: символ алфавита и его код
			map<string, char> code = { {"0",'a'},
									  {"10",'b'},
									 {"110",'c'},
									{"1110",'d'} };

			// Проверяем возвращаемое значение
			string result = "aabadac";
			string test = Deshifrator::DeCode(code, shifr);

			Assert::AreEqual(test, result);
		}		
	};

	TEST_CLASS(TestPrefixCode_TestDeshifrator)
	{
	public:

		TEST_METHOD(TestDeCode)
		{
			int alen[] = { 1, 2, 3, 4 }; // Длина кода одного символа
			string a = "abcd"; // Алфавит
			int size = 4; // Размер алфавита

			// Cоздание объекта PrefixCode			
			PrefixCode pr(a, alen, size);

			// Кодируемое слово
			string word = "aabadac";

			// Шифрование			
			vector<bool> shifr = pr.toShifr(word);

			// Вектор пар: символ алфавита и его код
			map<string, char> code = pr.getCode();

			// Проверяем процсс ширования-дешифрования
			string result = word;
			string test = Deshifrator::DeCode(code, shifr);

			Assert::AreEqual(test, result);
		}
	};
}