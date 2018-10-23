#pragma once
#include<string>
#include<vector>
#include<map>
using namespace std;

class Deshifrator
{
public:
	Deshifrator();
	~Deshifrator();

	static string DeCode(map<string, char> code, vector<bool> shifr);
};

