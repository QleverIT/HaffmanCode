// IntriKCODE.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "HaffmanCode.h"
#include "TransformBits.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	string text = " Всего лишь неделя кодирования с последующей неделей отладки\n могут сэкономить целый час, потраченный на планирование программы";
	string cod = HaffmanCode::toShifrHaffmanV(text);

	string ss = "";
	for (char h : cod)
		ss += TransformBits::charToBits(h);

	cout <<"-------------------------------------------------------------"<< endl;
	cout << " Исходный код сообщения в битах: " << ss.size() << endl;
	cout << "\n Код:\n" << endl;
	cout << ss << endl;
	cout << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << " Сжатый код сообщения в битах:   " << cod.size() << endl;
	cout << "\n Код:\n" << endl;
	cout << cod << endl;
	cout << endl;

	string decod2 = HaffmanCode::deShifrHaffmanV(cod);
	cout << "-------------------------------------------------------------" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << " Исходное сообщение: " << endl;
	cout << text << endl;
	cout << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << " Распакованное сообщение: " << endl;
	cout << decod2 << endl;
	cout << "-------------------------------------------------------------" << endl;
	

	
	return 0;
};
	
	
	//system("pause");
    

/*
TFileStream *fs = new TFileStream("твой файл", fmOpenRead);
unsigned char buffer;

fs->Position = 0;
fs->Read(&buffer, 1);

delete fs;

ShowMessage(buffer);
*/