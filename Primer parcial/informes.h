#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


#endif // INFORMES_H_INCLUDED


int informes_listarOrquestasMasDe(Orquesta array[], Musico arrayMusicos[], int size, int sizeMusicos);
int informes_musicosMayoresA(Musico arrayMusicos[], Instrumento arrayInstrumentos[], Orquesta arrayOrquestas[], int sizeArray, int sizeOrquestas, int sizeInstrumentos);
int informes_buscarlugar(Orquesta array[], int size, char* valorBuscado);
int informes_mostrarOrquestaCompleta(Orquesta arrayOrquesta[], int sizeOrquesta,Musico arrayMusicos[], int sizeMusico,Instrumento arrayInstrumento[], int sizeInstrumento);
int informes_mostarMusicoPorUnaOrquesta(Orquesta arrayOrquesta[],int sizeOrquesta,Musico arrayMusico[],int sizeMusico,Instrumento arrayInstrumento[], int sizeInstrumento);
int informes_musicosDeCuerdas(Musico arrayMusico[], int sizeMusico,Instrumento arrayInstrumento[], int sizeInstrumento);
int informes_promedioMusicosPorOrquesta(Orquesta arrayOrquesta[],int sizeOrquesta,Musico arrayMusico[],int sizeMusico);
int informes_orquestaConMasMusicos(Orquesta arrayOrquesta[],int sizeOrquesta,Musico arrayMusico[],int sizeMusico);





