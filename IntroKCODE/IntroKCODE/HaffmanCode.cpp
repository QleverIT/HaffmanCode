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

		//ищем символ в дереве
		if (tree.findNode(simbol) == nullptr) { //если не нашли, добавляем
			code += (tree.getPathEsc0() + simbol); //записываем код esc0 + символ
			tree.addNode(simbol);	//добавляем символ в дерево			
		} 
		//иначе если нашли, то добавляем к счетчику(весу) узла символа +1
		else {
			code += tree.getPath(simbol); //записываем путь к символу по дереву
			tree.recountNode(simbol);	//изменяем счетчик символа в дереве +1
		}
		//пересчитываем веса и перестраиваем дерево при необходимости		
		tree.reCountTree(simbol);
	}

	return code;
}

string HaffmanCode::deShifrHaffman(string s)
{
	
	HaffmanTree tree;
	string decode = "";
	string cod = "";

	//первый символ добавляем в дерево и результат заранее,
	//т.к. перед ним не пишется код esc0
	tree.addNode(s[0]);
	tree.reCountTree(s[0]);
	decode = s[0];
	
	Node *nod;
	char simbol;

	for (int index = 1; index < s.size(); index++) {
		simbol = s[index];
		cod += simbol;	
		if (cod == tree.getPathEsc0()) {//если код символа esc0		
			simbol = s[index + 1]; //то следующий за ним символ
			decode += simbol; //добавляем в результат
			tree.addNode(simbol); //и в дерево
			tree.reCountTree(simbol); //обновляем дерево
			index++; //т.к. символ уже был считан
			cod = ""; //обнуляем код, с которым уже поработали
		}
		else {	//иначе, если в дереве есть узел с таким кодом		
			if (tree.getNode(cod) != nullptr) { 
				nod = tree.getNode(cod); // и если он является листом
				if (nod->getLeft() == nullptr && nod->getRight() == nullptr) {	
					simbol = nod->getSimbol();
					decode += simbol;	// то добавляем символ листа в результат				
					tree.recountNode(simbol); //и изменяем счетчик символа в дереве +1
					tree.reCountTree(simbol); //обновляем дерево
					cod = ""; //обнуляем код, с которым уже поработали
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

			//записываем код esc0 + символ
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

