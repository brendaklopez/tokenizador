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

	// Precondicion: @counter es una instancia valida creada con Create.
	// Postcondicion: Libera todos los recursos asociados de @counter
	void DestroyOcurrenceCounter(OcurrenceCounter* counter);
}

#endif // !_OCURRENCE_COUNTER_H
