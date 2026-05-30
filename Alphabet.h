#ifndef _ALPHABET_H_
#define _ALPHABET_H_

namespace UndavAlphabet {
	struct Alphabet;

	// Precondicion: @printableChars es una cadena de caracteres
	// Postcondicion: @printableChars son los simbolos (caracteres imprimibles). Los procesa como conjunto y le asigna a cada simbolo un unico numero entero comenzando de 0
	Alphabet* CreateAlphabet(const char* printableChars);

	// Precondicion: @printableChars es una cadena de caracteres
	// Postcondicion: @printableChars son los simbolos (caracteres imprimibles). Los procesa como conjunto y le asigna a cada simbolo un unico numero entero comenzando de @startOffset quedando el rango [0, @starOffser] como reservados (puede simbolizarlo con '\0'). Al final agrega una cantidad de simbolos reservados igual a @endOffset
	Alphabet* CreateAlphabet(const char* printableChars, int startOffset, int endOffset);

	// Precondicion: @alphabet es una instancia valida creada con CreateAlphabet
	// Postcondicion: Si @index esta dentro de la tabla, devuelve el caracter asociado. Si index esta fuera devuelve el caracter '\0'
	char ToChar(const Alphabet* alphabet, int index);

	// Precondicion: @alphabet es una instancia valida creada con CreateAlphabet
	// Postcondicion: Devuelve el indice que le corresponde al caracter @c en @Alphabet. Si @c no pertenece a @Alphabet devuelve -1
	int ToIndex(const Alphabet* alphabet, char c);

	// Precondicion: @alphabet es una instancia valida creada con CreateAlphabet
	// Postcondicion: Devuelve true si @alphabet contiene a @c. Caso contrario devuelve false
	bool Contains(const Alphabet* alphabet, char c);

	// Precondicion: @alphabet es una instancia valida creada con CreateAlphabet
	// Postcondicion: Devuelve la cantidad de elementos de @alphabet, es decir la cardinalidad del conjunto de caracteres de @alphabet
	int Radix(const Alphabet* alphabet);

	// Precondicion: @alphabet es una instancia valida creada con CreateAlphabet. @text es una cadena de caracteres
	// Postcondicion: Devuelve un vector de de igual tama o que text y que en cada posicion tiene el indice de @alphabet correspondiente al caracter de @text
	int* ToIndices(const Alphabet* alphabet, const char* text);

	// Precondicion: @alphabet es una instancia valida creada con CreateAlphabet. @indices tiene una cantidad de elementos igual a @cantidadIndices y cada elemento es un valor entre [0, radix)
	// Postcondicion: Convierte @indices en texto utilizando @alphabet
	char* ToText(const Alphabet* alphabet, const int* indices, int cantidadIndices);

	// Precondicion: @alphabet es una instancia valida creada con CreateAlphabet
	// Postcondicion: Liberar todos los recursos asociados a @alphabet
	void DestroyAlphabet(Alphabet* alphabet);
}

#endif // !_ALPHABET_H_
