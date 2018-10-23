#include "stdafx.h"
#include "TransformBits.h"

TransformBits::TransformBits()
{
}


TransformBits::~TransformBits()
{
}

string TransformBits::charToBits(char simbol)
{
	string bits = "00000000";
	for(int n = 0; n < 8; n++) {
		if (simbol & (1 << n)) { bits[n] = '1'; }
	}
	return bits;
}

char TransformBits::bitsToChar(string bits)
{
	char simbol = 0;
	for (int n = 0; n < 8; n++) {
		if (bits[n] == '1') { simbol |= (1 << n); }
		else { simbol &= ~(1 << n); }
	}
	return simbol;
}

