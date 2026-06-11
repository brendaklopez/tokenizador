#include "Alphabet.h"
#include <iostream>
#include "Dictionary.h"
struct UndavAlphabet::Alphabet{
    char* caracteres;
    int cantCaracteres;
    UndavDictionary::Dictionary* indices;
};
<<<<<<< HEAD
// Funcion auxiliar para calcular longitud de un texto
=======
>>>>>>> de8404f18877e2ce58efe18d148bbeab679c643e
int Longitud(const char* texto){
    int i = 0;
    while(texto[i] != '\0'){
        i++;
    }
    return i;
}
UndavAlphabet::Alphabet* UndavAlphabet::CreateAlphabet(const char* printableChars){
    return CreateAlphabet(printableChars, 0, 0);
}
UndavAlphabet::Alphabet* UndavAlphabet::CreateAlphabet(const char* printableChars, int startOffset, int endOffset){
    UndavAlphabet::Alphabet* alfabeto = new UndavAlphabet::Alphabet;
    alfabeto->caracteres = new char[128];
    alfabeto->cantCaracteres = 0;
    alfabeto->indices = UndavDictionary::CreateDictionary();
<<<<<<< HEAD
    return alfabeto;
}
UndavAlphabet::Alphabet* UndavAlphabet::CreateAlphabet(const char* printableChars){
    Alphabet* alfabeto = CrearAlphabetVacio();
    for(int i = 0; printableChars[i] != '\0'; i++){
        char c = printableChars[i];
        // Evita duplicados
        if(!UndavDictionary::Contains(alfabeto->indices, c)){
            alfabeto->caracteres[alfabeto->cantCaracteres] = c;
            UndavDictionary::Add(
                alfabeto->indices,
                c,
                alfabeto->cantCaracteres
            );
            alfabeto->cantCaracteres++;
        }
    }
    return alfabeto;
}
UndavAlphabet::Alphabet* UndavAlphabet::CreateAlphabet(
    const char* printableChars,
    int startOffset,
    int endOffset
){
    Alphabet* alfabeto = CrearAlphabetVacio();
=======
>>>>>>> de8404f18877e2ce58efe18d148bbeab679c643e
    // Espacios reservados al inicio
    for(int i = 0; i < startOffset; i++){
        alfabeto->caracteres[alfabeto->cantCaracteres] = '\0';
        alfabeto->cantCaracteres++;
    }
<<<<<<< HEAD
    // Agregar caracteres unicos
=======
    // Agregar caracteres únicos
>>>>>>> de8404f18877e2ce58efe18d148bbeab679c643e
    for(int i = 0; printableChars[i] != '\0'; i++){
        char c = printableChars[i];
        if(!UndavDictionary::Contains(alfabeto->indices, c)){
            alfabeto->caracteres[alfabeto->cantCaracteres] = c;
            UndavDictionary::Add(
                alfabeto->indices,
                c,
                alfabeto->cantCaracteres
            );
            alfabeto->cantCaracteres++;
        }
    }
    // Espacios reservados al final
    for(int i = 0; i < endOffset; i++){
        alfabeto->caracteres[alfabeto->cantCaracteres] = '\0';
        alfabeto->cantCaracteres++;
    }
    return alfabeto;
}
char UndavAlphabet::ToChar(const Alphabet* alphabet, int index){
    if(index < 0 || index >= alphabet->cantCaracteres){
        return '\0';
    }
    return alphabet->caracteres[index];
}
int UndavAlphabet::ToIndex(const Alphabet* alphabet, char c){
    if(UndavDictionary::Contains(alphabet->indices, c)){
        return UndavDictionary::Get(alphabet->indices, c);
    }
    return -1;
}
bool UndavAlphabet::Contains(const Alphabet* alphabet, char c){
    return UndavDictionary::Contains(alphabet->indices, c);
}
int UndavAlphabet::Radix(const Alphabet* alphabet){
    return alphabet->cantCaracteres;
}
int* UndavAlphabet::ToIndices(
    const Alphabet* alphabet,
    const char* text
){
    int longitud = Longitud(text);
    int* indices = new int[longitud];
    for(int i = 0; i < longitud; i++){
        indices[i] = ToIndex(alphabet, text[i]);
    }
    return indices;
}
char* UndavAlphabet::ToText(
    const Alphabet* alphabet,
    const int* indices,
    int cantidadIndices
){
    char* texto = new char[cantidadIndices + 1];
    for(int i = 0; i < cantidadIndices; i++){
        texto[i] = ToChar(alphabet, indices[i]);
    }
    texto[cantidadIndices] = '\0';
    return texto;
}

void UndavAlphabet::DestroyAlphabet(Alphabet* alphabet){
    delete[] alphabet->caracteres;
    UndavDictionary::DestroyDictionary(alphabet->indices);
    delete alphabet;
}
