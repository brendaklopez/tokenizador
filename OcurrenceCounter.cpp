#include "OcurrenceCounter.h"
#include "Tries.h"
using UndavAlphabet::Alphabet;
namespace UndavOcurrenceCounter {
    struct OcurrenceCounter {
        Alphabet* alphabet;
        int* ocurrencias;
        UndavTrie::Trie* trie;
    };
    OcurrenceCounter* Create(Alphabet* alphabet, char* text) {
        OcurrenceCounter* counter = new OcurrenceCounter;
        counter->alphabet = alphabet;
        int cantidadSimbolos = UndavAlphabet::Radix(alphabet);
        counter->ocurrencias = new int[cantidadSimbolos];
        counter->trie = UndavTrie::CreateTrie(alphabet);
        InsertarSufijos(counter->trie, text);
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
        return UndavTrie::CountText(counter->trie, word);
}
    void DestroyOcurrenceCounter(OcurrenceCounter* counter) {
        delete[] counter->ocurrencias;
        UndavAlphabet::DestroyAlphabet(counter->alphabet);
        delete counter;
    }
}
