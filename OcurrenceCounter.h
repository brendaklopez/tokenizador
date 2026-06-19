#ifndef _OCURRENCE_COUNTER_H_
#define _OCURRENCE_COUNTER_H_

#include "Alphabet.h"
using UndavAlphabet::Alphabet;

namespace UndavOcurrenceCounter {

	struct OcurrenceCounter;

	// Precondicion: @alphabet es una instancia valida. @text es una cadena de caracteres
	// Postcondicion: Devuelve una instancia valida de OcurrenceCounter que contiene un indice de busqueda por caracter (simbolo) que permite obtener las ocurrencias de
	// de un caracter en @text con una complejidad temporal O(1) en lugar de O(N)
	OcurrenceCounter* Create(Alphabet* alphabet, char* text);

	// Precondicion: @counter es una instancia valida creada con Create.
	// Postcondicion: Devuelve la cantidad de veces que aparece el caracter @symbol en el texto que contiene @counter
	int CountOcurrence(OcurrenceCounter* counter, char symbol);
    // Precondicion: @alphabet es una instancia valida. @word es una cadena de caracteres que es solo una palabra
	// Postcondicion: Devuelve la cantidad de veces que @text contiene a la palabra @word
	int CountOcurrence(OcurrenceCounter* counter, char* word);
	// Precondicion: @alphabet es una instancia valida. @subText es una cadena de caracteres
	// Postcondicion: Devuelve true si @text contiene a @subText
	bool Contains(OcurrenceCounter* counter, char* subText);

	// Precondicion: @counter es una instancia valida creada con Create.
	// Postcondicion: Libera todos los recursos asociados de @counter
	void DestroyOcurrenceCounter(OcurrenceCounter* counter);
}

#endif // !_OCURRENCE_COUNTER_H
