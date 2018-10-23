#include "stdafx.h"
#include "Node.h"


Node::Node() :count(0), parent(nullptr), right(nullptr), left(nullptr), simbol(1)
{

}

//так же надо назначить данный узел левым или правым соседом своего родителя
Node::Node(Node *parentNew):parent(parentNew),count(0),right(nullptr), left(nullptr), simbol(1)
{
	
}


Node::~Node()
{
}


Node* Node::getRight()
{
	return Node::right;
}

void Node::setRight(Node* newRight) {
	Node::right = newRight;
}

Node* Node::getLeft() {
	return Node::left;
}

void Node::setLeft(Node* newLeft) {
	Node::left = newLeft;
}


Node* Node::getParent() {
	return Node::parent; 
}

//так же надо назначить данный узел 
//левым или правым соседом своего родителя
void Node::setParent(Node* newParent) {
	Node::parent = newParent;
}

void Node::setParentLeft(Node * newParent)
{
	setParent(newParent);
	newParent->setLeft(this);
}

void Node::setParentRight(Node * newParent)
{
	setParent(newParent);
	newParent->setRight(this);
}

int Node::getCount() {
	return Node::count;
}

void Node::operator++(int)
{
	Node::count++;
}

void Node::countPlusOne()
{
	count++;
}

char Node::getSimbol() {
	return Node::simbol;
}
void Node::setSimbol(char newSimbol) {
	Node::simbol = newSimbol;
}

bool Node::equals(Node* nod)
{	
	Node *nod1 = this;
	Node *nod2 = nod;
	return nod1 == nod2;
}



