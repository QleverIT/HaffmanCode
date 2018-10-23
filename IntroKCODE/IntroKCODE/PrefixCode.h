#pragma once
#include<string>
#include<vector>
#include <map>
using namespace std;

class PrefixCode
{

private:
	vector<vector<bool>> code;
	string alf;

	void fillCode();

public:
	PrefixCode();
	~PrefixCode();

	PrefixCode(string alfCustom, int alfLen[], int size);

	vector<bool> toShifr(string s);//шифрование слова s 
	map<string,char> getCode();//получить зашифрованный алфавит

	static bool ifValidate(int alfLen[], int size);
	string toString();//получить строку [символ - код \n]
};

