#include "Tries.h"
#include <cstddef>
using namespace UndavAlphabet;
namespace UndavTrie{
    struct Nodo {
        Nodo** hijos;
        int contador;
    };
    struct Arbol{
        Nodo* raiz;
    };
    struct Trie {
		Arbol* arbol;
		Alphabet* alphabet;
    };
    Nodo* CrearNodo(int radix) {
        Nodo* nodo = new Nodo;
        nodo->contador = 0;
        nodo->hijos = new Nodo*[radix];
        for (int i = 0; i < radix; i++) {
                nodo->hijos[i] = NULL;
        }
        return nodo;
    }
    Trie* CreateTrie(Alphabet* alphabet) {
        Trie* trie = new Trie;
        trie->alphabet = alphabet;
        trie->arbol = new Arbol;
        trie->arbol->raiz = CrearNodo(Radix(alphabet));
        return trie;
    }
    void Add(Trie* trie, char* word){
    Nodo* nodoActual =  trie->arbol->raiz;
    for(int i=0;word[i]!='\0';i++){
        int indice = ToIndex(trie->alphabet,word[i]);
        if(nodoActual->hijos[indice]== NULL){
            nodoActual->hijos[indice]= CrearNodo(Radix(trie->alphabet));
        }
        nodoActual = nodoActual->hijos[indice];
    }
    nodoActual->contador++;

    }
    int CountWord(Trie* trie, char* word) {
		if (word[0] == '\0') {
			return 0;
		}
		Nodo* nodoActual = trie->arbol->raiz;
		for (int i = 0; word[i] != '\0'; i++) {
			int indice = ToIndex(trie->alphabet, word[i]);
			if (indice == -1) {
				return 0;
			}
			if (nodoActual->hijos[indice] == NULL) {
				return 0;
			}
			nodoActual = nodoActual->hijos[indice];
		}
		return nodoActual->contador;
	}
	void DestroyNodo(Nodo* nodo, int radix) {
		if (nodo != NULL) {
			for (int i = 0; i < radix; i++) {
				DestroyNodo(nodo->hijos[i], radix);
			}
			delete[] nodo->hijos;
			delete nodo;
		}
	}
	void DestroyTrie(Trie* trie) {
		if (trie != NULL) {
			DestroyNodo(trie->arbol->raiz, Radix(trie->alphabet));
			delete trie->arbol;
			delete trie;
		}
	}

}

