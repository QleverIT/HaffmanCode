#pragma once
class Node
{
private:
	Node *right;
	Node *left;
	Node *parent;
	int count;
	char simbol;
	
public:
	Node();
	Node(Node *parentNew);
	~Node();

	Node *getRight();	
	void setRight(Node* newRight);
	
	Node *getLeft();
	void setLeft(Node* newLeft);

	Node *getParent();
	void setParent(Node* newParent);

	//�������� ��������, �������� ����� �������
	void setParentLeft(Node* newParent);

	//�������� ��������, �������� ������ �������
	void setParentRight(Node* newParent);


	int getCount();

	//count + 1
	void operator++(int);
	void countPlusOne();

	char getSimbol();
	void setSimbol(char newSimbol);

	bool equals(Node* nod);

};

