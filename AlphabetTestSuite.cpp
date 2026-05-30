#include "AlphabetTestSuite.h"
#include "Alphabet.h"
#include <iostream>

using namespace UndavAlphabet;
using namespace std;

void TestCreateBinaryAlphabet();
void TestCreateDNAAlphabet();
void TestCreateDecimalAlphabet();
void TestCreateHexadecimalAlphabet();
void TestCreateBase64Alphabet();
void TestCreateASCIIAlphabet();
void TestCreateAlphabetFromAbracadabra();

void AlphabetTestSuite::RunAlphabetTestSuite() {
	cout << "Running AlphabetTestSuite..." << endl;
	TestCreateBinaryAlphabet();
	TestCreateDNAAlphabet();
	TestCreateDecimalAlphabet();
	TestCreateHexadecimalAlphabet();
	TestCreateBase64Alphabet();
	TestCreateASCIIAlphabet();
	TestCreateAlphabetFromAbracadabra();
	cout << "AlphabetTestSuite completed" << endl;
}

void TestCreateBinaryAlphabet() {
	char expectedTable[] = "01";//Simbolos del sistema binario
	int expectedRadix = 2;//Cantidad de elementos del sistema binario
	bool allIndicesOk = true;
	bool allSymbolsOk = true;
	bool radixOk = true;

	Alphabet* alphabet = CreateAlphabet(expectedTable);

	radixOk = (Radix(alphabet) == expectedRadix);
	for (int i = 0; expectedTable[i] != '\0' && allIndicesOk && allSymbolsOk;++i) {
		allIndicesOk = i == ToIndex(alphabet, expectedTable[i]);
		allSymbolsOk = expectedTable[i] == ToChar(alphabet, i);
	}

	if (radixOk && allIndicesOk && allSymbolsOk) {
		cout << "TestCreateBinaryAlphabet: OK" << endl;
	}
	else {
		cout << "TestCreateBinaryAlphabet: Fail" << endl;
	}
}

void TestCreateDNAAlphabet() {
	char expectedTable[] = "ACGT";//Simbolos del codigo genetico (ADN)
	int expectedRadix = 4;//Cantidad de elementos del sistema genetico
	bool allIndicesOk = true;
	bool allSymbolsOk = true;
	bool radixOk = true;

	Alphabet* alphabet = CreateAlphabet(expectedTable);

	radixOk = (Radix(alphabet) == expectedRadix);
	for (int i = 0; expectedTable[i] != '\0' && allIndicesOk && allSymbolsOk;++i) {
		allIndicesOk = i == ToIndex(alphabet, expectedTable[i]);
		allSymbolsOk = expectedTable[i] == ToChar(alphabet, i);
	}

	if (radixOk && allIndicesOk && allSymbolsOk) {
		cout << "TestCreateDNAAlphabet: OK" << endl;
	}
	else {
		cout << "TestCreateDNAAlphabet: Fail" << endl;
	}
}

void TestCreateDecimalAlphabet() {
	char expectedTable[] = "0123456789";//Simbolos del sistema decimal
	int expectedRadix = 10;//Cantidad de elementos del sistema decimal
	bool allIndicesOk = true;
	bool allSymbolsOk = true;
	bool radixOk = true;

	Alphabet* alphabet = CreateAlphabet(expectedTable);

	radixOk = (Radix(alphabet) == expectedRadix);
	for (int i = 0; expectedTable[i] != '\0' && allIndicesOk && allSymbolsOk;++i) {
		allIndicesOk = i == ToIndex(alphabet, expectedTable[i]);
		allSymbolsOk = expectedTable[i] == ToChar(alphabet, i);
	}

	if (radixOk && allIndicesOk && allSymbolsOk) {
		cout << "TestCreateDecimalAlphabet: OK" << endl;
	}
	else {
		cout << "TestCreateDecimalAlphabet: Fail" << endl;
	}
}

void TestCreateHexadecimalAlphabet() {
	char expectedTable[] = "0123456789ABCDEF";//Simbolos del sistema hexadecimal
	int expectedRadix = 16;//Cantidad de elementos del sistema hexadecimal
	bool allIndicesOk = true;
	bool allSymbolsOk = true;
	bool radixOk = true;

	Alphabet* alphabet = CreateAlphabet(expectedTable);

	radixOk = (Radix(alphabet) == expectedRadix);
	for (int i = 0; expectedTable[i] != '\0' && allIndicesOk && allSymbolsOk;++i) {
		allIndicesOk = i == ToIndex(alphabet, expectedTable[i]);
		allSymbolsOk = expectedTable[i] == ToChar(alphabet, i);
	}

	if (radixOk && allIndicesOk && allSymbolsOk) {
		cout << "TestCreateHexadecimalAlphabet: OK" << endl;
	}
	else {
		cout << "TestCreateHexadecimalAlphabet: Fail" << endl;
	}
}

void TestCreateBase64Alphabet() {
	char expectedTable[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";//Simbolos del sistema BASE64
	int expectedRadix = 64;//Cantidad de elementos del sistema BASE64
	bool allIndicesOk = true;
	bool allSymbolsOk = true;
	bool radixOk = true;

	Alphabet* alphabet = CreateAlphabet(expectedTable);

	radixOk = (Radix(alphabet) == expectedRadix);
	for (int i = 0; expectedTable[i] != '\0' && allIndicesOk && allSymbolsOk;++i) {
		allIndicesOk = i == ToIndex(alphabet, expectedTable[i]);
		allSymbolsOk = expectedTable[i] == ToChar(alphabet, i);
	}

	if (radixOk && allIndicesOk && allSymbolsOk) {
		cout << "TestCreateBase64Alphabet: OK" << endl;
	}
	else {
		cout << "TestCreateBase64Alphabet: Fail" << endl;
	}
}

void TestCreateASCIIAlphabet() {
	const char printableChars[] =
		" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	int expectedRadix = 128;
	bool allIndicesOk = true;
	bool allSymbolsOk = true;
	int startOffset = 32;
	bool radixOk = true;

	Alphabet* alphabet = CreateAlphabet(printableChars, startOffset, 1);

	radixOk = (Radix(alphabet) == expectedRadix);
	int i;
	for (i = 0; printableChars[i]!='\0' && allIndicesOk && allSymbolsOk; ++i) {
		allIndicesOk = i + startOffset == ToIndex(alphabet, printableChars[i]);
		allSymbolsOk = printableChars[i] == ToChar(alphabet, i + startOffset);
	}

	if (radixOk && allIndicesOk && allSymbolsOk) {
		cout << "TestCreateASCIIAlphabet: OK" << endl;
	}
	else {
		cout << "TestCreateASCIIAlphabet: Fail" << endl;
	}
}

void TestCreateAlphabetFromAbracadabra() {
	char inputChars[] = "ABRACADABRA";
	char expectedTable[] = "ABRCD";//Simbolos del sistema binario
	int expectedRadix = 5;//Cantidad de elementos del sistema binario
	bool allIndicesOk = true;
	bool allSymbolsOk = true;
	bool radixOk = true;

	Alphabet* alphabet = CreateAlphabet(inputChars);

	radixOk = (Radix(alphabet) == expectedRadix);
	for (int i = 0; expectedTable[i] != '\0' && allIndicesOk && allSymbolsOk;++i) {
		allIndicesOk = i == ToIndex(alphabet, expectedTable[i]);
		allSymbolsOk = expectedTable[i] == ToChar(alphabet, i);
	}

	if (radixOk && allIndicesOk && allSymbolsOk) {
		cout << "TestCreateAlphabetFromAbracadabra: OK" << endl;
	}
	else {
		cout << "TestCreateAlphabetFromAbracadabra: Fail" << endl;
	}
}
