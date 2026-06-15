#include "Dictionary.h"
#include <iostream>
namespace UndavDictionary{
	struct DictionaryItem{
	Key key;
	Value value;
	DictionaryItem* siguiente;
	};
	struct Dictionary{
	    DictionaryItem* primero;
	    int cantidadItems;
	};
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
	Value Get(const Dictionary* dictionary, Key key){
	    DictionaryItem* encontrado = BuscarItem(dictionary, key);
	    return encontrado->value;
	};
	bool Contains(const Dictionary* dictionary, Key key){
	    bool contiene = false;
        DictionaryItem* encontrado = BuscarItem(dictionary, key);
	    if(encontrado != NULL ){
            contiene = true;
            }
	    return contiene;
	};
	int Size(const Dictionary* dictionary){
	    return dictionary->cantidadItems;
	};
	namespace UndavIterator {
		struct DictionaryIterator{
		    DictionaryItem* itemActual;
		};
		DictionaryIterator* CreateIterator(Dictionary* dictionary){
		    DictionaryIterator* iterator = new DictionaryIterator;
            iterator->itemActual = dictionary->primero;
            return iterator;
		};
		bool IsEnd(DictionaryIterator* iterator){
		    return iterator->itemActual == NULL;

		};
		void Next(DictionaryIterator* iterator){
		    if (!IsEnd(iterator)) {
                    iterator->itemActual = iterator->itemActual->siguiente;
            }
		};
		Key GetKey(DictionaryIterator* iterator){
		    return iterator->itemActual->key;
		};
		Value GetValue(DictionaryIterator* iterator){
		    return iterator->itemActual->value;
		};
		void Destroy(DictionaryIterator* iterator){
		    delete iterator;
		};
	}
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


