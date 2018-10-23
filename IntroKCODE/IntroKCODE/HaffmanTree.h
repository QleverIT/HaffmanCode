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
	vector <Node> tree; // при переполнениее ссылки потеряются
	vector <Node*> treeSimbols; 

	// у родителя nod1 заменить соседа nod1 на соседа nod2
	void swapChildrenParentN1(Node *nod1, Node *nod2);

	//добавление пустого узла к дереву (вектору) tree 
	Node* addNodeHelper();
	void addSimbolsTreeHelper(Node* nod);

	// проверяет дерево до узла нод и перестравивает  
	void reBuild();

public:
	HaffmanTree();
	~HaffmanTree();
	
	int getCountRoot(); //+кол-во символов в дереве

	void swap(Node *nod1, Node *nod2);
		
	//добавляет новый узел(лист) к дереву
	void addNode(char thisSimbol);
	
	//увеличивает счетчик уже существующего узла(листа)
	void recountNode(char thisSimbol);

	//Возвращает узел с указанным символом или nullptr
	Node* findNode(char thisSimbol);

	//при расчете временно esc0 = esc0.getParent()
	//возвращает путь от корня до узла
	string getPath(Node* nod);
	string getPath(char thisSimbol);
	string getPathEsc0(); //тестировать

	//при расчете временно esc0 = esc0.getParent()
	//возвращает узел по пути от корня
	Node* getNode(string path);

	//показывает узлы дерева **отлпдка
	string lookTree();
	
	//пересчитывает веса, невключая узел nod
	void reCountTree(char thisSimbol);

	
	
};

