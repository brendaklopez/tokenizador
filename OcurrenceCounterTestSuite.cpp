#include "OcurrenceCounterTestSuite.h"
#include "OcurrenceCounter.h"
#include "Alphabet.h"
#include <iostream>
using namespace UndavAlphabet;
using namespace UndavOcurrenceCounter;
using namespace std;
// Funciones creacionales de alfabetos
Alphabet* CrearAlfabetoBinario();
Alphabet* CrearAlfabetoADN();
Alphabet* CrearAlfabetoBase64();
Alphabet* CrearAlfabetoASCII();
Alphabet* CrearAlfabetoAbracadabra();
// Tests separados
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
Alphabet* CrearAlfabetoBinario() {
	char simbolos[] = "01";
	return CreateAlphabet(simbolos);
}
Alphabet* CrearAlfabetoADN() {
    char simbolos[] = "ACGT";
	return CreateAlphabet(simbolos);
}
Alphabet* CrearAlfabetoBase64() {
	char simbolos[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	return CreateAlphabet(simbolos);
}
Alphabet* CrearAlfabetoASCII() {
	char printableChars[] =
		" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	return CreateAlphabet(printableChars, 32, 1);
}
Alphabet* CrearAlfabetoAbracadabra() {
	char simbolos[] = "ABRCD";
	return CreateAlphabet(simbolos);
}
void TestOcurrenceCounterBinaryAlphabet() {
	Alphabet* alphabet = CrearAlfabetoBinario();
	char texto[] = "01010101010111";
	OcurrenceCounter* ocurrencia = Create(alphabet, texto);
	int cantCeros = CountOcurrence(ocurrencia, '0');
	int cantUnos = CountOcurrence(ocurrencia, '1');
	DestroyOcurrenceCounter(ocurrencia);
	if (cantCeros == 6 && cantUnos == 8) {
        cout << "TestOcurrenceCounterBinaryAlphabet: OK" << endl;
	}else{
        cout << "TestOcurrenceCounterBinaryAlphabet: Fail" << endl;
	}
}

void TestOcurrenceCounterDNAAlphabet() {
	Alphabet* alphabet = CrearAlfabetoADN();
	char texto[] = "AGTTTTTAAA!";
	OcurrenceCounter* ocurrencia = Create(alphabet, texto);
	int cantA = CountOcurrence(ocurrencia, 'A');
	int cantG = CountOcurrence(ocurrencia, 'G');
	int cantT = CountOcurrence(ocurrencia, 'T');
	DestroyOcurrenceCounter(ocurrencia);
	if (cantA == 4 && cantG == 1 && cantT == 5) {
		cout << "TestOcurrenceCounterDNAAlphabet: OK" << endl;
	}
	else {
		cout << "TestOcurrenceCounterDNAAlphabet: Fail" << endl;
	}
}
void TestOcurrenceCounterBase64Alphabet() {
	Alphabet* alphabet = CrearAlfabetoBase64();
	char texto[] = "como estaaaaaaaaaaaaas?+++";
	OcurrenceCounter* ocurrencia = Create(alphabet, texto);
	int cantA = CountOcurrence(ocurrencia, 'a');
	int cantMas = CountOcurrence(ocurrencia, '+');
	DestroyOcurrenceCounter(ocurrencia);
	if (cantA == 13 && cantMas == 3) {
		cout << "TestOcurrenceCounterBase64Alphabet: OK" << endl;
	}
	else {
		cout << "TestOcurrenceCounterBase64Alphabet: Fail" << endl;
	}
}
void TestOcurrenceCounterASCIIAlphabet() {
	Alphabet* alphabet = CrearAlfabetoASCII();
	char texto[] = "como estaaaaaaaaaaaaas?+++";
	OcurrenceCounter* ocurrencia = Create(alphabet, texto);
	int cantA = CountOcurrence(ocurrencia, 'a');
	int cantMas = CountOcurrence(ocurrencia, '+');
	DestroyOcurrenceCounter(ocurrencia);
	if (cantA == 13 && cantMas == 3) {
		cout << "TestOcurrenceCounterASCIIAlphabet: OK" << endl;
	}
	else {
		cout << "TestOcurrenceCounterASCIIAlphabet: Fail" << endl;
	}
}
void TestOcurrenceCounterAbracadabra() {
	Alphabet* alphabet = CrearAlfabetoAbracadabra();
	char texto[] = "ABRACADABRA";
	OcurrenceCounter* ocurrencia = Create(alphabet, texto);
	int cantA = CountOcurrence(ocurrencia, 'A');
	DestroyOcurrenceCounter(ocurrencia);
	if (cantA == 5) {
		cout << "TestOcurrenceCounterAbracadabra: OK" << endl;
	}
	else {
		cout << "TestOcurrenceCounterAbracadabra: Fail" << endl;
	}
}
