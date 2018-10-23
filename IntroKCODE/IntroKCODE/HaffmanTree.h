#pragma once
#include<string>
#include<vector>
#include "Node.h"
#include<iostream>//*
using namespace std;

class HaffmanTree
{
private:	
	Node *esc0;
	Node *root;
	vector <Node> tree; // ��� ������������� ������ ����������
	vector <Node*> treeSimbols; 

	// � �������� nod1 �������� ������ nod1 �� ������ nod2
	void swapChildrenParentN1(Node *nod1, Node *nod2);

	//���������� ������� ���� � ������ (�������) tree 
	Node* addNodeHelper();
	void addSimbolsTreeHelper(Node* nod);

	// ��������� ������ �� ���� ��� � ��������������  
	void reBuild();

public:
	HaffmanTree();
	~HaffmanTree();
	
	int getCountRoot(); //+���-�� �������� � ������

	void swap(Node *nod1, Node *nod2);
		
	//��������� ����� ����(����) � ������
	void addNode(char thisSimbol);
	
	//����������� ������� ��� ������������� ����(�����)
	void recountNode(char thisSimbol);

	//���������� ���� � ��������� �������� ��� nullptr
	Node* findNode(char thisSimbol);

	//��� ������� �������� esc0 = esc0.getParent()
	//���������� ���� �� ����� �� ����
	string getPath(Node* nod);
	string getPath(char thisSimbol);
	string getPathEsc0(); //�����������

	//��� ������� �������� esc0 = esc0.getParent()
	//���������� ���� �� ���� �� �����
	Node* getNode(string path);

	//���������� ���� ������ **�������
	string lookTree();
	
	//������������� ����, ��������� ���� nod
	void reCountTree(char thisSimbol);

	
	
};

