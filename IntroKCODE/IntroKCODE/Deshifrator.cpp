#include "stdafx.h"
#include "Deshifrator.h"


Deshifrator::Deshifrator()
{
}


Deshifrator::~Deshifrator()
{
}

string Deshifrator::DeCode(map<string, char> code, vector<bool> shifr)
{
	string deshifr = "";
	string decod = "";
	for (auto b : shifr) {
		if (b)
			decod += "1";
		else
			decod += "0";
		auto it = code.find(decod); //map<string,char>::iterator it
		if (it != code.end()) {
			deshifr += it->second;
			decod = "";
		}
	}
	return deshifr;
}

