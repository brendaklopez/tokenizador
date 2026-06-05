#include "OcurrenceCounterTestSuite.h"
#include "OcurrenceCounter.h"
#include "Alphabet.h"
#include <iostream>

using namespace UndavAlphabet;
using namespace UndavOcurrenceCounter;
using namespace std;

void TestOcurrenceCounterBinaryAlphabet();
void TestOcurrenceCounterDNAAlphabet();
void TestOcurrenceCounterBase64Alphabet();
void TestOcurrenceCounterASCIIAlphabet();
void TestOcurrenceCounterAbracadabra();

void OcurrenceCounterTestSuite::RunOcurrenceCounterTestSuite() {
	cout << "Running OcurrenceCounterTestSuite..." << endl;
	TestOcurrenceCounterBinaryAlphabet();
	TestOcurrenceCounterDNAAlphabet();
	TestOcurrenceCounterBase64Alphabet();
	TestOcurrenceCounterASCIIAlphabet();
	TestOcurrenceCounterAbracadabra();
	cout << "OcurrenceCounterTestSuite completed" << endl;
}


void TestOcurrenceCounterBinaryAlphabet() {
	char expectedTable[] = "01";//Simbolos del sistema binario
	Alphabet* alphabet = CreateAlphabet(expectedTable);
	char texto[] = "01010101010111";
	OcurrenceCounter* ocurrencia =  Create(alphabet, texto);
    int cantCeros = CountOcurrence(ocurrencia, '0');
    int cantUnos = CountOcurrence(ocurrencia, '1');

    DestroyOcurrenceCounter(ocurrencia);
    DestroyAlphabet(alphabet);

	if (cantCeros == 6 && cantUnos == 8) {
		cout << "TestOcurrenceCounterBinaryAlphabet: OK" << endl;
	}
	else {
		cout << "TestOcurrenceCounterBinaryAlphabet: Fail" << endl;
	}
}


void TestOcurrenceCounterDNAAlphabet() {
	char expectedTable[] = "ACGT";//Simbolos del codigo genetico (ADN)
	Alphabet* alphabet = CreateAlphabet(expectedTable);
	char texto[] = "AGTTTTTAAA!";
	OcurrenceCounter* ocurrencia =  Create(alphabet, texto);
    int cantA = CountOcurrence(ocurrencia, 'A');
    int cantG = CountOcurrence(ocurrencia, 'G');
    int cantT = CountOcurrence(ocurrencia, 'T');

    DestroyOcurrenceCounter(ocurrencia);
    DestroyAlphabet(alphabet);

	if (cantA == 4 && cantG == 1 && cantT == 5) {
		cout << "TestOcurrenceCounterDNAAlphabet: OK" << endl;
	}
	else {
		cout << "TestOcurrenceCounterDNAAlphabet: Fail" << endl;
	}
}


void TestOcurrenceCounterBase64Alphabet() {
	char expectedTable[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";//Simbolos del sistema BASE64
	Alphabet* alphabet = CreateAlphabet(expectedTable);
	char texto[] = "como estaaaaaaaaaaaaas?+++";
	OcurrenceCounter* ocurrencia =  Create(alphabet, texto);
    int cantA = CountOcurrence(ocurrencia, 'a');
    int cantMas = CountOcurrence(ocurrencia, '+');
    DestroyOcurrenceCounter(ocurrencia);
    DestroyAlphabet(alphabet);

	if ( cantA == 13 && cantMas == 3) {
		cout << "TestOcurrenceCounterBase64Alphabet: OK" << endl;
	}
	else {
		cout << "TestOcurrenceCounterBase64Alphabet: Fail" << endl;
	}
}

void TestOcurrenceCounterASCIIAlphabet() {
	char printableChars[] =
		" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

	Alphabet* alphabet = CreateAlphabet(printableChars, 32, 1);
	char texto[] = "como estaaaaaaaaaaaaas?+++";
	OcurrenceCounter* ocurrencia =  Create(alphabet, texto);
    int cantA = CountOcurrence(ocurrencia, 'a');
    int cantMas = CountOcurrence(ocurrencia, '+');
    DestroyOcurrenceCounter(ocurrencia);
    DestroyAlphabet(alphabet);

	if (cantA ==13 && cantMas == 3) {
		cout << "TestOcurrenceCounterASCIIAlphabet: OK" << endl;
	}
	else {
		cout << "TestOcurrenceCounterASCIIAlphabet: Fail" << endl;
	}
}

void TestOcurrenceCounterAbracadabra() {
	char inputChars[] = "ABRACADABRA";
	char expectedTable[] = "ABRCD";//Simbolos del sistema binario

	Alphabet* alphabet = CreateAlphabet(expectedTable);
	OcurrenceCounter* ocurrencia =  Create(alphabet, inputChars);
	int cantA = CountOcurrence(ocurrencia, 'A');
    DestroyOcurrenceCounter(ocurrencia);
    DestroyAlphabet(alphabet);

	if (cantA == 5) {
		cout << "TestOcurrenceCounterAbracadabra: OK" << endl;
	}
	else {
		cout << "TestOcurrenceCounterAbracadabra: Fail" << endl;
	}
}


