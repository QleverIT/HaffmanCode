#pragma once
#include <string>
#include<vector>
using namespace std;

class HaffmanCode
{

public:	
	HaffmanCode();
	~HaffmanCode();

	//�������� ������� ����������
	static string toShifrHaffman(string s);
	static string deShifrHaffman(string s);

	//������� �������� �����
	static string toShifrHaffmanV(string s);
	static string deShifrHaffmanV(string s);
};

