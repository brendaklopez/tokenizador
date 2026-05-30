#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#define Key char
#define Value int

namespace UndavDictionary {
	struct Dictionary;

	// Precondicion: Ninguna
	// Postcondicion: Devuelve un diccionario vacio listo para ser utilizado
	Dictionary* CreateDictionary();

	// Precondicion: @ditionary es una instancia valida creada con CreateDictionary
	// Postcondicion: Si @key no existe agrega el par de elementos @key @value (@value asociado a @key)
	// Si ya existe @key, actualiza el valor a asociado con @value
	void Add(Dictionary* dictionary, Key key, Value value);

	// Precondicion: @dictionary es una instancia valida y @key esta en el @dictionary
	// Postcondicion: Devuelve el valor asociado a @key
	Value Get(const Dictionary* dictionary, Key key);

	// Precondicion: @dictionary es una instancia valida
	// Postcondicion: Devuelve true si @key se encuentra en @diccionary
	bool Contains(const Dictionary* dictionary, Key key);

	// Precondicion: @dictionary es una instancia valida
	// Postcondicion: Devuelve la cantidad de entradas (Keys) del @dictionary
	int Size(const Dictionary* dictionary);

	namespace UndavIterator {
		struct DictionaryIterator;
		// Precondicion: @diccionary es una intancia valida
		// Postcondicion: Devuelve un iterador nuevo apuntando a la primera entrada
		DictionaryIterator* CreateIterator(Dictionary* dictionary);

		// Precondicion: @iterador es una instancia valida creada con CreateIterator
		// Postcondicion: Devuelve true si @iterador ya no apunta a ninguna entrada. Caso contrario devuelve false
		bool IsEnd(DictionaryIterator* iterator);

		// Precondicion: @iterador es una instancia valida creada con CreateIterator
		// Postcondicion: Avanza @iterador al siguiente elemento si no llego a fin. Si llego a fin no realiza ninguna accion
		void Next(DictionaryIterator* iterator);

		// Precondicion: @iterador es una instancia valida creada con CreateIterator. Iterador no esta en el fin
		// Postcondicion: Devuelve la clave del diccionario a la que apunta @iterador
		Key GetKey(DictionaryIterator* iterator);

		// Precondicion: @iterador es una instancia valida creada con CreateIterator. Iterador no esta en el fin
		// Postcondicion: Devuelve el valor del diccionario al que apunta @iterador
		Value GetValue(DictionaryIterator* iterator);

		// Precondicion: @iterador es una instancia valida creada con CreateIterator.
		// Postcondicion: Libera todos los recursos asociados de @iterador
		void Destroy(DictionaryIterator* iterator);
	}

	// Precondicion: @dictionary es una instancia valida
	// Postcondicion: Libera todos los recursos asociados de @dictionary
	void DestroyDictionary(Dictionary* dictionary);
}

#endif

