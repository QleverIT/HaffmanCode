#pragma once
#include <string>
#include<vector>
using namespace std;

class HaffmanCode
{

public:	
	HaffmanCode();
	~HaffmanCode();

	//частично записан симвволами
	static string toShifrHaffman(string s);
	static string deShifrHaffman(string s);

	//записан двоичным кодом
	static string toShifrHaffmanV(string s);
	static string deShifrHaffmanV(string s);
};

