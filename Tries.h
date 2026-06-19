#ifndef _UNDAVTRIE_H_
#define _UNDAVTRIE_H_
#include "Alphabet.h"
using UndavAlphabet::Alphabet;
namespace UndavTrie {
	struct Trie;
    // Precondicion: @alphabet es una instancia valida
    //Postcondicion: Devuelve un Trie.
    Trie* CreateTrie(Alphabet* alphabet);
    // Precondicion: @Trie es una instancia valida. @text es una cadena de caracteres
    //Postcondicion: Agrega @word al @trie
	void Add(Trie* trie, char* word);
    // Precondicion: @trie es una instancia valida. @Text es una cadena de caracteres
	// Postcondicion: Devuelve la cantidad de veces que @Textfue agregada a @trie
	int CountText(Trie* trie, char* word);
    // Precondicion: @trie es una instancia valida
	// Postcondicion: Libera todos los recursos asociados de @trie
	void DestroyTrie(Trie* trie);
}
#endif
