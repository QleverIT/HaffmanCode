#pragma once
#include<string>
using namespace std;

class TransformBits
{
public:
	TransformBits();
	~TransformBits();

	static string charToBits(char simbol);
	static char bitsToChar(string bits);
};

