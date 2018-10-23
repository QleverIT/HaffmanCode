#include "stdafx.h"
#include "PrefixCode.h"
#include <string>
#include <vector>
using namespace std;

void PrefixCode::fillCode()
{
	int sizeVec = code.size();
	int pos = -1;

	for (int i = 1; i < sizeVec; i++) {
		for (int j = code[i - 1].size() - 1; j >= 0; j--) {
			if (code[i - 1][j] == 0) {
				code[i][j] = 1; //+1 к предыдущему вектору || записываем в текущий
				pos = j;
				j = -1;
			}
			else
				code[i][j] = 0;
		}
		for (int j = 0; j < pos; j++) {
			code[i][j] = code[i-1][j];//записываем нетронутую часть предыдущего вектора
		}
	}

}

PrefixCode::PrefixCode()
{
}


PrefixCode::~PrefixCode()
{
}

PrefixCode::PrefixCode(string alfCustom, int alfLen[], int size):alf(alfCustom)
{
	for (int i = 0; i < size; i++)
		code.push_back(vector<bool>(alfLen[i]));

	PrefixCode::fillCode();

	

}

vector<bool> PrefixCode::toShifr(string s)
{
	vector<bool> shifr;
	int index = -1;
	for (auto i : s) {
		index = alf.find(i);
		shifr.insert(end(shifr),begin(code[index]), end(code[index]));//copy vctor
		index = -1;
	}
	return shifr;
}

map<string, char> PrefixCode::getCode()
{
	map<string, char> getcod;
	int sizeVec = code.size();
	char simbol;
	string cod;
	int i = 0;
	for (const auto& b1 : code) {
		simbol = alf[i];		
		for (const auto& b2 : b1) {
			if (b2)
				cod += "1";
			else
				cod += "0";
		} 

		getcod.emplace(pair<string, char>(cod, simbol));//современный аналог insert

		i++;
		cod = "";
	}
	return getcod;
}



bool PrefixCode::ifValidate(int alfLen[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += pow(2, -alfLen[i]); 
	}
	if (sum <= 1) return true;
	else return false;
}

string PrefixCode::toString()
{
	string str = "";
	int i = 0;
	for (const auto& b1 : code) {
		str += alf[i];
		str += " || ";
		for (const auto& b2 : b1) {
			if(b2)
				str += "1";
			else 
				str += "0";
		} str+="\n";
		i++;
	}
	return str;
}
