#include "stdafx.h"
#include "HaffmanTree.h"
#include "Node.h"
#include<string>
#include<vector>
#include<queue>
using namespace std;

//public

HaffmanTree::HaffmanTree()
{
	treeSimbols.reserve(256*2+2); 
	tree.reserve(256); 

	root = addNodeHelper();	
	esc0 = addNodeHelper();	

	esc0->setParentLeft(root);	
}


HaffmanTree::~HaffmanTree()
{
}

int HaffmanTree::getCountRoot()
{
	int countRoot = root->getCount();
	return countRoot;
}

void HaffmanTree::swap(Node *nod1, Node *nod2)
{
	Node *parentNod1 = nod1->getParent();
	Node *parentNod2 = nod2->getParent();	
	if (nod1 != parentNod2 && nod2 != parentNod1)
	if (parentNod1 != parentNod2) {
		swapChildrenParentN1(nod1, nod2);
		swapChildrenParentN1(nod2, nod1);

		nod1->setParent(parentNod2);
		nod2->setParent(parentNod1);
	}
	else if (nod1 != nod2){
		swapChildrenParentN1(nod1, nod2);
	}	
}

void HaffmanTree::addNode(char thisSimbol)
{
	Node &newParentEsc0 = *addNodeHelper();

	Node &oldParentEsc0 = *esc0->getParent();
	
	swapChildrenParentN1(esc0, &newParentEsc0);	
	
	newParentEsc0.setParentLeft(&oldParentEsc0);
	esc0->setParentLeft(&newParentEsc0);

	Node &newNod = *addNodeHelper();
	newNod.setSimbol(thisSimbol);
	newNod++;
	newNod.setParentRight(&oldParentEsc0);
	
	addSimbolsTreeHelper(&newNod);	

}

void HaffmanTree::recountNode(char thisSimbol)
{
	Node &nod = *findNode(thisSimbol);
	nod++;
	reBuild();
}

Node* HaffmanTree::findNode(char thisSimbol)
{
	Node* nodPtr = nullptr;
	for (auto nod : treeSimbols) {
		if (nod->getSimbol() == thisSimbol) {
			nodPtr = nod;
			break;
		}
	}
	return nodPtr;
}

string HaffmanTree::getPath(Node *nod)
{
	string path = "";
	Node *parentNode = nod->getParent();	
	while (parentNode != nullptr)
	{
		if (parentNode->getLeft() == nod)
			path = "0" + path;
		else
			path = "1" + path;

		nod = parentNode;
		parentNode = nod->getParent();
	}

	return path;
}

string HaffmanTree::getPath(char thisSimbol) {
	Node *nod =findNode(thisSimbol);
	return getPath(nod);
}

string HaffmanTree::getPathEsc0()
{
	return getPath(esc0->getParent());
}

Node* HaffmanTree::getNode(string path)
{
	Node *nod = root;
	int index = 0;
	char ch = '-';
	for (index = 0; index < path.size() && nod != nullptr; index++) {
		ch = path[index];
		if (ch == '0')
			nod = nod->getLeft();
		else if (ch == '1')
			nod = nod->getRight();
		else { 
			return nullptr;
		}
	}	
	if (nod != nullptr && nod->getLeft() == esc0)
		nod = esc0;		
	return nod;
}

string HaffmanTree::lookTree()
{
	string str = ""; 
	
	queue<Node*> queueLvl;
	queueLvl.push(root);
	
	while (!queueLvl.empty()) {
		Node &nod = *queueLvl.front();
		str += (to_string(nod.getCount()) + "/" + nod.getSimbol() + " ");
		queueLvl.pop();
		if (nod.getRight() != nullptr)
			queueLvl.push(nod.getRight());
		if (nod.getLeft() != nullptr)
			queueLvl.push(nod.getLeft());
		
	}
	return str;
}

void HaffmanTree::reCountTree(char thisSimbol)
{
	Node *nextNod = findNode(thisSimbol)->getParent();
	while (nextNod != nullptr) {
		nextNod->countPlusOne();
		reBuild(); 
		nextNod = nextNod->getParent();
	}
	
}



//private

void HaffmanTree::swapChildrenParentN1(Node *nod1, Node *nod2) {
	Node *parentNod1 = nod1->getParent();	
	Node *left = parentNod1->getLeft();
	if (parentNod1 != nullptr) {
		if (parentNod1 != nod2->getParent()) {			
			if (left == nod1)
				parentNod1->setLeft(nod2);
			else
				parentNod1->setRight(nod2);
		}
		else {
			if (left == nod1) {
				parentNod1->setRight(nod1);
				parentNod1->setLeft(nod2);
			}
			else {
				parentNod1->setRight(nod2);
				parentNod1->setLeft(nod1);
			}
		}		
	}
}

Node* HaffmanTree::addNodeHelper()
{	
	if(tree.size()>=(256*2+2))
		throw invalid_argument("Vector tree in HaffmanTree out size!");
		//если вектор выйдет за пределы зарезервиваного места 
		//- указатели станут недействительными
	Node nod;	
	tree.push_back(nod);
	return &tree.back();
}

void HaffmanTree::addSimbolsTreeHelper(Node* nod)
{
	treeSimbols.push_back(nod);
}

void HaffmanTree::reBuild()
{
	queue<Node*> queueLvl;
	queueLvl.push(root->getRight());
	queueLvl.push(root->getLeft());
	Node *beginLvl = root->getRight(); 
	Node *exBeginLvl = nullptr; 
	
	while (!queueLvl.empty()) {
		Node *nodNext = queueLvl.front();
		if (beginLvl->getCount() > nodNext->getCount()) {
			beginLvl = nodNext;
			exBeginLvl = nullptr;
			if ((beginLvl == esc0->getParent())) {
				return;
			}
		}
		else if (nodNext != beginLvl && exBeginLvl == nullptr && beginLvl->getCount() == nodNext->getCount()) {
			exBeginLvl = nodNext;
		}
		else if (beginLvl->getCount() < nodNext->getCount()) {
			if (nodNext->getParent() != beginLvl) {
				swap(beginLvl, nodNext);
			}
			else if (exBeginLvl != nullptr) {
				swap(exBeginLvl, nodNext);
			}
			return;
		}
		
		queueLvl.pop();
		if (nodNext->getRight() != nullptr)
			queueLvl.push(nodNext->getRight());
		if (nodNext->getLeft() != nullptr)
			queueLvl.push(nodNext->getLeft());
		
	}
}



