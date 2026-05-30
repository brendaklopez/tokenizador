#include "Dictionary.h"
#include <iostream>


namespace UndavDictionary {

	struct DictionaryItem{
	Key key;
	Value value;
	DictionaryItem* siguiente;
	};

	struct Dictionary{
	    DictionaryItem* primero;
	    int cantidadItems;
	};;

	// Precondicion: Ninguna
	// Postcondicion: Devuelve un diccionario vacio listo para ser utilizado
	Dictionary* CreateDictionary(){
	    Dictionary* diccionario = new Dictionary;
	    diccionario->primero = NULL;
	    diccionario->cantidadItems = 0;
        return diccionario;
	};

	DictionaryItem* BuscarItem(const Dictionary* diccionario, Key key){
	DictionaryItem* actual = diccionario->primero; //porque empieza a busacr desde el primero
	DictionaryItem* encontrado = NULL;

	while(encontrado == NULL && actual != NULL){
	    if (actual->key == key){
            encontrado = actual;
	    }
	    actual = actual->siguiente;
	}
	return encontrado;
	}

	// Precondicion: @ditionary es una instancia valida creada con CreateDictionary
	// Postcondicion: Si @key no existe agrega el par de elementos @key @value (@value asociado a @key)
	// Si ya existe @key, actualiza el valor a asociado con @value
	void Add(Dictionary* dictionary, Key key, Value value){
	    DictionaryItem* item = BuscarItem(dictionary, key);
	    if (item != NULL) {
            item->value = value;
        } else {
            DictionaryItem* nuevoItem = new DictionaryItem;

            nuevoItem->key = key;
            nuevoItem->value = value;
            nuevoItem->siguiente = dictionary->primero;

            dictionary->primero = nuevoItem;
            dictionary->cantidadItems++;
        }
	};

	// Precondicion: @dictionary es una instancia valida y @key esta en el @dictionary
	// Postcondicion: Devuelve el valor asociado a @key
	Value Get(const Dictionary* dictionary, Key key){
	    DictionaryItem* encontrado = BuscarItem(dictionary, key);
	    return encontrado->value;
	};

	// Precondicion: @dictionary es una instancia valida
	// Postcondicion: Devuelve true si @key se encuentra en @diccionary
	bool Contains(const Dictionary* dictionary, Key key){
	    bool contiene = false;
        DictionaryItem* encontrado = BuscarItem(dictionary, key);
	    if(encontrado != NULL ){
            contiene = true;
            }
	    return contiene;
	};

	// Precondicion: @dictionary es una instancia valida
	// Postcondicion: Devuelve la cantidad de entradas (Keys) del @dictionary
	int Size(const Dictionary* dictionary){
	    return dictionary->cantidadItems;
	};

	namespace UndavIterator {
		struct DictionaryIterator{
		    DictionaryItem* itemActual;
		};
		// Precondicion: @diccionary es una intancia valida
		// Postcondicion: Devuelve un iterador nuevo apuntando a la primera entrada
		DictionaryIterator* CreateIterator(Dictionary* dictionary){
		     DictionaryIterator* iterator = new DictionaryIterator;

            iterator->itemActual = dictionary->primero;

            return iterator;
		};

		// Precondicion: @iterador es una instancia valida creada con CreateIterator
		// Postcondicion: Devuelve true si @iterador ya no apunta a ninguna entrada. Caso contrario devuelve false
		bool IsEnd(DictionaryIterator* iterator){
		    return iterator->itemActual == NULL;

		};

		// Precondicion: @iterador es una instancia valida creada con CreateIterator
		// Postcondicion: Avanza @iterador al siguiente elemento si no llego a fin. Si llego a fin no realiza ninguna accion
		void Next(DictionaryIterator* iterator){
		    if (!IsEnd(iterator)) {
                    iterator->itemActual = iterator->itemActual->siguiente;
            }
		};

		// Precondicion: @iterador es una instancia valida creada con CreateIterator. Iterador no esta en el fin
		// Postcondicion: Devuelve la clave del diccionario a la que apunta @iterador
		Key GetKey(DictionaryIterator* iterator){
		    return iterator->itemActual->key;
		};

		// Precondicion: @iterador es una instancia valida creada con CreateIterator. Iterador no esta en el fin
		// Postcondicion: Devuelve el valor del diccionario al que apunta @iterador
		Value GetValue(DictionaryIterator* iterator){
		    return iterator->itemActual->value;
		};

		// Precondicion: @iterador es una instancia valida creada con CreateIterator.
		// Postcondicion: Libera todos los recursos asociados de @iterador
		void Destroy(DictionaryIterator* iterator){
		    delete iterator;
		};
	}

	// Precondicion: @dictionary es una instancia valida
	// Postcondicion: Libera todos los recursos asociados de @dictionary
	void DestroyDictionary(Dictionary* dictionary){
	    DictionaryItem* actual = dictionary->primero;

        while (actual != NULL) {
            DictionaryItem* itemAEliminar = actual;
            actual = actual->siguiente;
            delete itemAEliminar;
        }

        delete dictionary;
    }
	};


