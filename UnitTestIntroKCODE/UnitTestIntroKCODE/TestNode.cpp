#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\..\IntroKCODE\IntroKCODE\Node.h" 
#include "..\..\IntroKCODE\IntroKCODE\Node.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestIntroKCODE
{
	TEST_CLASS(TestNode)
	{
	public:

		TEST_METHOD(TestCreateNode)
		{
			Node nod;

			// проверка значения по умолчанию 
			int result = 0;
			int test = nod.getCount();

			Assert::AreEqual(test, result);
		}

		TEST_METHOD(TestCreateNode2)
		{
			Node nodP;
			Node nod(&nodP);

			// проверка значения по умолчанию 
			int result = 0;
			int test = nod.getCount();

			Assert::AreEqual(test, result);
		}

		TEST_METHOD(TestEquals1)
		{			
			Node test;

			//узел равен самому себе
			Assert::IsTrue(test.equals(&test));
		}
		TEST_METHOD(TestEquals2)
		{
			Node test0;
			Node &test1 = test0;
			
			//узлы считаются равными, только если равны их адреса
			Assert::IsTrue(test0.equals(&test1));
		}
		
		TEST_METHOD(TestEquals3)
		{
			Node test0;
			Node test1;

			//узлы считаются равными, только если равны их адреса
			Assert::IsFalse(test0.equals(&test1));
		}
				
		TEST_METHOD(TestGetCount_TestPP)
		{
			Node nod; //count = 0 по умолчанию					
			nod++;
			nod++;

			// count - множитель элемента, хранимого в узле
			int result = 2;
			int test = nod.getCount();

			Assert::AreEqual(test, result);
		}

		TEST_METHOD(TestGetSimbol_TestSetSimbol)
		{
			Node nod;
			int simbol = 'н';
			nod.setSimbol(simbol);

			// simbol - элемент, хранимый в узле
			int result = simbol;
			int test = nod.getSimbol();

			Assert::AreEqual(test, result);
		}

		TEST_METHOD(TestGetRight_TestSetRight)
		{
			Node nod; 
			Node nodR;

			nod.setRight(&nodR);

			// right - правый сосед узла в дереве
			Node* result = &nodR; 
			Node &test = *nod.getRight();	

			Assert::IsTrue(test.equals(result));
		}

		TEST_METHOD(TestGetLeft_TestSetLeft)
		{
			Node nod;
			Node nodL;

			nod.setLeft(&nodL);

			// left - левый сосед узла в дереве
			Node* result = &nodL;
			Node &test = *nod.getLeft();

			Assert::IsTrue(test.equals(result));
		}

		TEST_METHOD(TestGetParent_TestSetParent)
		{
			Node nod;
			Node nodP;

			nod.setParent(&nodP);

			// parent - родитель узла в дереве
			Node* result = &nodP;
			Node &test = *nod.getParent();

			Assert::IsTrue(test.equals(result));
		}

		TEST_METHOD(TestCreateNodeFromParent1)
		{	
			Node nodP;
			Node nod(&nodP);

			// parent - родитель узла в дереве
			Node* result = &nodP;
			Node &test = *nod.getParent();

			Assert::IsTrue(test.equals(result));
		}	

		

	};

}

