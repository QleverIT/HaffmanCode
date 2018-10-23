// IntriKCODE.cpp: ���������� ����� ����� ��� ����������� ����������.
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

	string text = " ����� ���� ������ ����������� � ����������� ������� �������\n ����� ���������� ����� ���, ����������� �� ������������ ���������";
	string cod = HaffmanCode::toShifrHaffmanV(text);

	string ss = "";
	for (char h : cod)
		ss += TransformBits::charToBits(h);

	cout <<"-------------------------------------------------------------"<< endl;
	cout << " �������� ��� ��������� � �����: " << ss.size() << endl;
	cout << "\n ���:\n" << endl;
	cout << ss << endl;
	cout << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << " ������ ��� ��������� � �����:   " << cod.size() << endl;
	cout << "\n ���:\n" << endl;
	cout << cod << endl;
	cout << endl;

	string decod2 = HaffmanCode::deShifrHaffmanV(cod);
	cout << "-------------------------------------------------------------" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << " �������� ���������: " << endl;
	cout << text << endl;
	cout << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << " ������������� ���������: " << endl;
	cout << decod2 << endl;
	cout << "-------------------------------------------------------------" << endl;
	

	
	return 0;
};
	
	
	//system("pause");
    

/*
TFileStream *fs = new TFileStream("���� ����", fmOpenRead);
unsigned char buffer;

fs->Position = 0;
fs->Read(&buffer, 1);

delete fs;

ShowMessage(buffer);
*/