#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\..\IntroKCODE\IntroKCODE\HaffmanTree.h" 
#include "..\..\IntroKCODE\IntroKCODE\HaffmanTree.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestIntroKCODE
{
	TEST_CLASS(TestHaffmanTree)
	{
	public:

		TEST_METHOD(TestGetCountRoot)
		{
			HaffmanTree tree;

			int result = 0;
			int test = tree.getCountRoot();

			Assert::AreEqual(test, result);
		}

		TEST_METHOD(TestSwap_Parent)
		{
			HaffmanTree tree;

			Node nod1;
			Node nod2;

			Node parentNod1;
			nod1.setParentLeft(&parentNod1);

			Node parentNod2;
			nod2.setParentLeft(&parentNod2);

			tree.swap(&nod1, &nod2);

			bool test1 = (&parentNod1 == nod2.getParent());
			bool test2 = (&parentNod2 == nod1.getParent());

			Assert::IsTrue(test1 && test2);
		}

		TEST_METHOD(TestSwap_Children)
		{
			HaffmanTree tree;

			Node nod1;
			Node nod2;

			Node parentNod1;
			nod1.setParentLeft(&parentNod1);

			Node parentNod2;
			nod2.setParentLeft(&parentNod2);

			tree.swap(&nod1, &nod2);

			bool test1 = (parentNod1.getLeft() == &nod2);
			bool test2 = (parentNod2.getLeft() == &nod1);

			Assert::IsTrue(test1 && test2);
		}

		TEST_METHOD(TestSwap_LR)
		{
			HaffmanTree tree;

			Node nod1;
			Node nod2;

			Node parentNod;
			nod1.setParentLeft(&parentNod);
			nod2.setParentRight(&parentNod);


			tree.swap(&nod1, &nod2);

			bool test1 = (parentNod.getRight() == &nod1);
			bool test2 = (parentNod.getLeft() == &nod2);
			Assert::IsTrue(test1 && test2);
		}

		TEST_METHOD(TestAddNode_TestGetPath) {
			HaffmanTree tree;
			char simbol = 'f';
			tree.addNode(simbol);

			string result = "1";
			string test = tree.getPath(simbol);


			Assert::AreEqual(test, result);
		}

		TEST_METHOD(TestGetPath_esc0) {
			HaffmanTree tree;
			char simbol = 'f';
			tree.addNode(simbol);
			
			//исключение для esc0 и его родителя
			Node& test1 = *tree.getNode("0");
			Node& test2 = *tree.getNode("00");
			
			bool test = test1.equals(&test2);

			Assert::IsTrue(test);			
		}

		TEST_METHOD(TestFindNode_TestGetNode) {
			HaffmanTree tree;
			char simbol = 'f';
			tree.addNode(simbol);

			Node &test1 = *tree.findNode(simbol);
			Node &test2 = *tree.getNode("1");

			bool test = test1.equals(&test2);

			Assert::IsTrue(test);
		}

		TEST_METHOD(TestFindNode_TestRecountNode) {
			HaffmanTree tree;
			char simbol = 'f';
			tree.addNode(simbol);

			tree.recountNode(simbol);
			Node &nod = *tree.findNode(simbol);

			int result = 2;
			int test = nod.getCount();

			Assert::AreEqual(test, result);
		}

		TEST_METHOD(TestLookTree) {
			HaffmanTree tree;
			char simbol = 'f';
			tree.addNode(simbol);

			string nullnod = "0/0";
			nullnod[2] = 1;

			string result = nullnod + " 1/f " + nullnod + " " + nullnod;
			string test = tree.lookTree();

			Assert::IsTrue(test.compare(result));
		}

		TEST_METHOD(TestReCountTree) {
			
			HaffmanTree tree;
			char simbol = 'f';
			tree.addNode(simbol);
			tree.reCountTree('f');

			char simbol2 = 'm';
			tree.addNode(simbol2);
			tree.reCountTree('m');

			char simbol3 = 'r';
			tree.addNode(simbol3);
			tree.reCountTree('r');

			string nullnod = "/0";
			nullnod[1] = 1;

			string result = "3" + nullnod + " 2" + nullnod
				+ " 1/f 1/m 1" + nullnod + " 1/r 0" + nullnod 
				+ " 0" + nullnod + " ";
			string test = tree.lookTree();

			Assert::IsTrue(test == result); 

		}
	};
}