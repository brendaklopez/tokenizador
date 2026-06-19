#include "Tries.h"
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
        int indice = ToIndex(trie->alphabet;word[i])
        if(nodoActual->hijos[indice]== NULL){
            nodoActual->hijos[indice]= CrearNodo(Radix(trie->alphabet));
        }
        nodoActual = nodoActual->hijos[indice];

    }
    nodoActual->contador++;

    }

    }

    }
}

