#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "instrumento.h"
#include "orquesta.h"
#include "musico.h"
#define TEXT_SIZE 20
int informes_listarOrquestasMasDe(Orquesta array[], Musico arrayMusicos[], int size, int sizeMusicos)
{
    int retorno=-1;
    char bufferTipo[TEXT_SIZE];
    int i,j;
    int contadorOrquestas = 0;
    if(array!=NULL && arrayMusicos != NULL && size>=0 && sizeMusicos >=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            {
                for(j=0;j<sizeMusicos;j++)
                {
                    if(arrayMusicos[j].isEmpty)
                    {
                        continue;
                    }
                    if(array[i].idUnico == arrayMusicos[j].idOrquesta)
                    {
                        contadorOrquestas++;
                    }
                }
                if(contadorOrquestas > 5)
                {
                    switch(array[i].tipo)
                    {
                        case 1:
                            strcpy(bufferTipo, "Sinfonica");
                            break;
                        case 2:
                            strcpy(bufferTipo, "Filarmonica");
                            break;
                        case 3:
                            strcpy(bufferTipo, "Camara");
                            break;
                    }
                    printf("\n ID: %d\n Tipo: %s\n Nombre: %s\n Lugar: %s\n",
                           array[i].idUnico,bufferTipo,array[i].nombre,array[i].lugar);
                }
                contadorOrquestas = 0;
            }
        }
        retorno=0;
    }

    printf("\nno se encontro ninguna con mas de 5");
    return retorno;
}



int informes_musicosMenoresA(Musico arrayMusicos[], Instrumento arrayInstrumentos[], Orquesta arrayOrquestas[], int sizeArray, int sizeOrquestas, int sizeInstrumentos)
{
    int i,j;
    int retorno = -1;
    char bufferOrquesta[TEXT_SIZE];
    char bufferInstrumento[TEXT_SIZE];
    if(arrayMusicos != NULL && arrayInstrumentos != NULL && arrayOrquestas != NULL && sizeArray >= 0 && sizeInstrumentos >= 0 && sizeOrquestas >= 0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(arrayMusicos[i].isEmpty)
            {
                continue;
            }
            if(arrayMusicos[i].edad < 30)
            {
                for(j=0;j<sizeOrquestas;j++)
                {
                    if(arrayMusicos[i].idOrquesta == arrayOrquestas[j].idUnico)
                    {
                        strcpy(bufferOrquesta, arrayOrquestas[j].nombre);
                        break;
                    }
                }
                for(j=0;j<sizeInstrumentos;j++)
                {
                    if(arrayMusicos[i].idInstrumento == arrayInstrumentos[j].idUnico)
                    {
                        strcpy(bufferInstrumento, arrayInstrumentos[j].nombre);
                        break;
                    }
                }
                printf("\nID: %d\nNombre: %s\nApellido: %s\nEdad: %d\nInstrumento: %s\nOrquesta: %s\n",
                        arrayMusicos[i].idUnico, arrayMusicos[i].nombre, arrayMusicos[i].apellido, arrayMusicos[i].edad, bufferInstrumento, bufferOrquesta);
                retorno = 0;
            }
        }
        if(retorno)
        {
            printf("No se ha encontrado ningun musico menor de 30.");
        }
    }
    return retorno;
}


/** \brief Busca un string en un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int informes_buscarlugar(Orquesta array[], int size, char* valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].lugar,valorBuscado)==0)
            {
                 printf("\n ID: %d\n  nombre: %s\n lugar: %s\n tipo: %d",
                       array[i].idUnico,array[i].nombre,array[i].lugar,array[i].tipo);
                        switch(array[i].tipo)
                       {
                        case 1:
                        printf("Sinfonica");
                        break;
                        case 2:
                        printf("Filarmonica");
                        break;
                        case 3:
                        printf("Camara");
                        break;
                       }


                retorno=0;
                break;
            }
        }



    }
    return retorno;
}


/*int fantasma_buscarInt(Instrumento array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].tipo==valorBuscado)
            {

                printf("los musicos que tocan cuerdas son:
")
                retorno=0;

                break;
            }
        }
    }
    return retorno;
}
*/
