#include "stdafx.h"
#include "HaffmanCode.h"
#include <string>
#include "HaffmanTree.h"
#include "TransformBits.h"
using namespace std;

HaffmanCode::HaffmanCode()
{	
}

HaffmanCode::~HaffmanCode()
{
}

string HaffmanCode::toShifrHaffman(string s)
{
	string code = "";
	HaffmanTree tree;
	
	for (char simbol : s) {

		//���� ������ � ������
		if (tree.findNode(simbol) == nullptr) { //���� �� �����, ���������
			code += (tree.getPathEsc0() + simbol); //���������� ��� esc0 + ������
			tree.addNode(simbol);	//��������� ������ � ������			
		} 
		//����� ���� �����, �� ��������� � ��������(����) ���� ������� +1
		else {
			code += tree.getPath(simbol); //���������� ���� � ������� �� ������
			tree.recountNode(simbol);	//�������� ������� ������� � ������ +1
		}
		//������������� ���� � ������������� ������ ��� �������������		
		tree.reCountTree(simbol);
	}

	return code;
}

string HaffmanCode::deShifrHaffman(string s)
{
	
	HaffmanTree tree;
	string decode = "";
	string cod = "";

	//������ ������ ��������� � ������ � ��������� �������,
	//�.�. ����� ��� �� ������� ��� esc0
	tree.addNode(s[0]);
	tree.reCountTree(s[0]);
	decode = s[0];
	
	Node *nod;
	char simbol;

	for (int index = 1; index < s.size(); index++) {
		simbol = s[index];
		cod += simbol;	
		if (cod == tree.getPathEsc0()) {//���� ��� ������� esc0		
			simbol = s[index + 1]; //�� ��������� �� ��� ������
			decode += simbol; //��������� � ���������
			tree.addNode(simbol); //� � ������
			tree.reCountTree(simbol); //��������� ������
			index++; //�.�. ������ ��� ��� ������
			cod = ""; //�������� ���, � ������� ��� ����������
		}
		else {	//�����, ���� � ������ ���� ���� � ����� �����		
			if (tree.getNode(cod) != nullptr) { 
				nod = tree.getNode(cod); // � ���� �� �������� ������
				if (nod->getLeft() == nullptr && nod->getRight() == nullptr) {	
					simbol = nod->getSimbol();
					decode += simbol;	// �� ��������� ������ ����� � ���������				
					tree.recountNode(simbol); //� �������� ������� ������� � ������ +1
					tree.reCountTree(simbol); //��������� ������
					cod = ""; //�������� ���, � ������� ��� ����������
				}
			}
		}
		
	}
	return decode;
}

string HaffmanCode::toShifrHaffmanV(string s)
{
	string code = "";
	HaffmanTree tree;

	string simbolCode = "";

	for (char simbol : s) {

		if (tree.findNode(simbol) == nullptr) { 

			//���������� ��� esc0 + ������
			simbolCode = TransformBits::charToBits(simbol);
			code += tree.getPathEsc0() + simbolCode; 		
			
			tree.addNode(simbol);	
									
		}		
		else {
			code += tree.getPath(simbol);
			tree.recountNode(simbol);	
		}		
		tree.reCountTree(simbol);
	}
	
	return code;
}

string HaffmanCode::deShifrHaffmanV(string s)
{
	HaffmanTree tree;
	string decode = "";
	string cod = "";
	string simbolCode = "";
	Node *nod;
	char simbol;

	simbolCode = s.substr(0, 7);
	simbol = TransformBits::bitsToChar(simbolCode);

	tree.addNode(simbol);
	tree.reCountTree(simbol);
	decode = simbol;

	simbolCode = "";
	simbol = 0;

	for (int index = 8; index < s.size(); index++) {		
		simbol = s[index];
		cod += simbol;
		if (cod == tree.getPathEsc0()) {
			simbolCode = s.substr(index + 1, index + 7);			
			simbol = TransformBits::bitsToChar(simbolCode);
			decode += simbol;
			tree.addNode(simbol); 
			tree.reCountTree(simbol); 
			index+=8; 
			cod = ""; 
			simbolCode = "";
		}
		else {	
			if (tree.getNode(cod) != nullptr) {
				nod = tree.getNode(cod); 
				if (nod->getLeft() == nullptr && nod->getRight() == nullptr) {
					simbol = nod->getSimbol();
					decode += simbol;					
					tree.recountNode(simbol); 
					tree.reCountTree(simbol); 
					cod = ""; 
				}
			}
		}

	}
	return decode;
}

