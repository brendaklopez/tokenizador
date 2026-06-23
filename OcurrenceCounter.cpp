#include "OcurrenceCounter.h"
#include "Tries.h"
using UndavAlphabet::Alphabet;
namespace UndavOcurrenceCounter {
    struct OcurrenceCounter {
        Alphabet* alphabet;
        int* ocurrencias;
        UndavTrie::Trie* trie;
    };
	bool EsSeparador(char caracter) {
		return caracter == ' ' || caracter == '\t' || caracter == '\n';
	}
	int Longitud(char* text) {
		int longitud = 0;
		while (text[longitud] != '\0') {
			longitud++;
		}
		return longitud;
	}
	void AgregarPalabra(UndavTrie::Trie* trie, char* palabra, int longitudPalabra) {
		if (longitudPalabra > 0) {
			palabra[longitudPalabra] = '\0';
			UndavTrie::Add(trie, palabra);
		}
	}
	void CargarPalabras(UndavTrie::Trie* trie, char* text) {
		int longitudTexto = Longitud(text);
		char* palabra = new char[longitudTexto + 1];
		int longitudPalabra = 0;
		for (int i = 0; text[i] != '\0'; i++) {
			if (EsSeparador(text[i])) {
				AgregarPalabra(trie, palabra, longitudPalabra);
				longitudPalabra = 0;
			} else {
				palabra[longitudPalabra] = text[i];
				longitudPalabra++;
			}
		}
		AgregarPalabra(trie, palabra, longitudPalabra);
		delete[] palabra;
	}
    OcurrenceCounter* Create(Alphabet* alphabet, char* text) {
        OcurrenceCounter* counter = new OcurrenceCounter;
        counter->alphabet = alphabet;
        int cantidadSimbolos = UndavAlphabet::Radix(alphabet);
        counter->ocurrencias = new int[cantidadSimbolos];
        counter->trie = UndavTrie::CreateTrie(alphabet);
        // Inicializar el vector en 0
        for(int i = 0; i < cantidadSimbolos; i++){
            counter->ocurrencias[i] = 0;
        }
        // Contar ocurrencias
        for(int i = 0; text[i] != '\0'; i++){
            int indice = UndavAlphabet::ToIndex(
                alphabet,
                text[i]
            );
            if(indice != -1){
                counter->ocurrencias[indice]++;
            }
        }
        CargarPalabras(counter->trie, text);
        return counter;
    }
    int CountOcurrence(OcurrenceCounter* counter, char symbol) {
        int indice = UndavAlphabet::ToIndex(
            counter->alphabet,
            symbol
        );
        if(indice == -1){
            return 0;
        }
        return counter->ocurrencias[indice];
    }
    int CountOcurrence(OcurrenceCounter* counter, char* word) {
        return UndavTrie::CountWord(counter->trie, word);
}
    void DestroyOcurrenceCounter(OcurrenceCounter* counter) {
        delete[] counter->ocurrencias;
        UndavAlphabet::DestroyAlphabet(counter->alphabet);
        UndavTrie::DestroyTrie(counter->trie);
        delete counter;
    }
}
