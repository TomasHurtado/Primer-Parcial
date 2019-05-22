#include "orquesta.h"
#include "instrumento.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


#endif // INFORMES_H_INCLUDED


int informes_listarOrquestasMasDe(Orquesta array[], Musico arrayMusicos[], int size, int sizeMusicos);

int informes_musicosMenoresA(Musico arrayMusicos[], Instrumento arrayInstrumentos[], Orquesta arrayOrquestas[], int sizeArray, int sizeOrquestas, int sizeInstrumentos);

int informes_buscarlugar(Orquesta array[], int size, char* valorBuscado);
int fantasma_buscarInt(Musico array[], int size, int valorBuscado, int* posicion);




