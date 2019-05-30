#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "instrumento.h"
#include "orquesta.h"
#include "musico.h"
#define TEXT_SIZE 20




/** \brief lista las orquestas con mas de 5 musicos
 *
 * \param array[] Orquesta array de Orquesta
 * \param array Musicos[] Musico array de Musico
 * \param size int tamaño del array de Orquesta
 * \param sizeMusicos int tamaño del array de Musico
 * \return int retorno -1 si da error o no encontro mas q 5 y 0 si salio bien
 *
 */
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



/** \brief lista los musicos mayores a 30 años
 *
 * \param arrayMusicos[] Musico array de Musico
 * \param arrayInstrumentos[] Instrumento  array de Instrumentos
 * \param arrayOrquestas[] Orquesta array de Orquestas
 * \param sizeArray int tamaño del array de Musico
 * \param sizeOrquestas int tamaño del array de Orquesta
 * \param sizeInstrumentos int tamaño del array de Instrumento
 * \return int retorno -1 si da error o no hay mayores a 30 0 si sale todo bien
 *
 */
int informes_musicosMayoresA(Musico arrayMusicos[], Instrumento arrayInstrumentos[], Orquesta arrayOrquestas[], int sizeArray, int sizeOrquestas, int sizeInstrumentos)
{
    int i;
    int j;
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
            if(arrayMusicos[i].edad > 30)
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
* \param array Orquesta Array de Orquesta
* \param size int Tamaño del array
* \param valorbuscado es el string a buscar
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


            if(!array[i].isEmpty && strcmp(array[i].lugar,valorBuscado)==0)
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

            }
        }



    }
    return retorno;
}


/** \brief muestra orquestas completas mediante 3 parametros
 *
 * \param arrayOrquesta[] Orquesta array de Orquesta
 * \param sizeOrquesta int tamaño del array de Orquesta
 * \param arrayMusicos[] Musico array de Musico
 * \param sizeMusico int tamaño del array de Musico
 * \param arrayInstrumento[] Instrumento array de Intrumentos
 * \param sizeInstrumento int tamaño del array de Intrumentos
 * \return int retorno -1 si es error o no cumplen los parametros y 0 si salio todo bien
 *
 */
int informes_mostrarOrquestaCompleta(Orquesta arrayOrquesta[], int sizeOrquesta,Musico arrayMusicos[], int sizeMusico,Instrumento arrayInstrumento[], int sizeInstrumento)
{
    int retorno =-1;
    int i;
    int j;
    int cantCuerdas;
    int cantViento;
    int cantPercusion;
    if (arrayOrquesta!=NULL && arrayMusicos!=NULL && sizeMusico>0 && sizeOrquesta>0 && sizeInstrumento>0 && arrayInstrumento!=NULL)
    {
        printf("\n");
        for (i=0;i<sizeOrquesta;i++)
        {
            if(!arrayOrquesta[i].isEmpty)
            {
                cantCuerdas=0;
                cantViento=0;
                cantPercusion=0;
                for(j=0;j<sizeMusico;j++)
                {
                    if (arrayMusicos[j].isEmpty && arrayOrquesta[i].idUnico==arrayMusicos[j].idOrquesta)
                    {
                        switch(arrayInstrumento[arrayMusicos[j].idInstrumento].tipo)
                        {
                            case 1:
                                cantCuerdas++;
                                break;
                            case 2:
                                cantViento++;
                                break;
                            case 3:
                                cantViento++;
                                break;
                            case 4:
                                cantPercusion++;
                                break;
                        }
                    }
                }
                if (cantCuerdas>=5 && cantViento>=3 && cantPercusion>=2)
                {
                    printf("\n ID orquesta completa: %d",arrayOrquesta[i].idUnico);
                }
            }
        }
        retorno =0;
    }
    return retorno;
}


/** \brief muestra los musicos que tiene una orquestas
 *
 * \param arrayOrquesta[] Orquesta arrat de Orquestas
 * \param sizeOrquesta int tamaño del array de Orquestas
 * \param arrayMusico[] Musico array de Musico
 * \param sizeMusico int tamaño del array de Musicos
 * \param arrayInstrumento[] Instrumento array de Intrumentos
 * \param sizeInstrumento int tamaño del array de Intrumentos
 * \return int retorno -1 si da error o no existe la orquesta o 0 si salio todo bien
 *
 */
int informes_mostarMusicoPorUnaOrquesta(Orquesta arrayOrquesta[],int sizeOrquesta,Musico arrayMusico[],int sizeMusico,Instrumento arrayInstrumento[], int sizeInstrumento)
{
    int retorno=-1;
    int i;
    int bufferOrqId;
    int posOrquest;
    int bufferInstID;
    if (arrayOrquesta!=NULL && arrayMusico!=NULL && sizeMusico>0 && sizeOrquesta>0 && sizeInstrumento>0 && arrayInstrumento!=NULL)
    {
        orquesta_listar(arrayOrquesta,sizeOrquesta);
        utn_getUnsignedInt("\nID a buscar ","error",1,sizeof(int),0,1000,1,&bufferOrqId);
        if(orquesta_buscarID(arrayOrquesta,sizeOrquesta,bufferOrqId,&posOrquest)==0)
        {
            for (i=0;i<sizeMusico;i++)
            {
                if (!arrayMusico[i].isEmpty && arrayMusico[i].idOrquesta==bufferOrqId)
                {
                instrumento_buscarID(arrayInstrumento,sizeInstrumento,arrayMusico[i].idInstrumento,&bufferInstID);

                printf("\n Nombre : %s\n Apellido: %s\n Edad: %d",arrayMusico[i].nombre,arrayMusico[i].apellido,arrayMusico[i].edad);
                printf("\n Instrumento: %s\n Tipo: %d ",arrayInstrumento[bufferInstID].nombre,arrayInstrumento[bufferInstID].tipo);
                       switch(arrayInstrumento[bufferInstID].tipo)
                       {
                        case 1:
                        printf("cuerdas");
                        break;
                        case 2:
                        printf("Viento-madera");
                        break;
                        case 3:
                        printf("Viento-metal");
                        break;
                        case 4:
                        printf("Percucion");
                        break;
                       }
                }
            }
        }
        else
        {
            printf("\n No existe");
        }
        retorno=0;
    }

    return retorno;
}


/** \brief lista los musicos que tocan instrumentos de cuerdas
 *
 * \param arrayMusico[] Musico array de Musicos
 * \param sizeMusico int tamaño del array de musicos
 * \param arrayInstrumento[] Instrumento array de Instrumentos
 * \param sizeInstrumento int tamaño del array de Instrumentos
 * \return int retorno -1 si da error o no existen musicos que toquen instrumentos de cuerda o 0 si sale todo bien
 *
 */
int informes_musicosDeCuerdas(Musico arrayMusico[], int sizeMusico,Instrumento arrayInstrumento[], int sizeInstrumento)
{
    int retorno=-1;
    int i;
    int bufferInstID;
    if (arrayMusico!=NULL && sizeMusico>0 && sizeInstrumento>0 && arrayInstrumento!=NULL)
    {
        printf("\n");
        musico_ordenarPorApellido(arrayMusico,sizeMusico);
        for (i=0;i<sizeMusico;i++)
        {
            if(!arrayMusico[i].isEmpty)
            {
                instrumento_buscarID(arrayInstrumento,sizeInstrumento,arrayMusico[i].idInstrumento,&bufferInstID);
                if (arrayInstrumento[bufferInstID].tipo==1)
                {
                    printf("\n");
                    printf("\nToca cuerdas :");
                    printf("\n Nombre: %s",arrayMusico[i].nombre);
                    printf("\n Apellido: %s",arrayMusico[i].apellido);
                    printf("\n Edad: %d",arrayMusico[i].edad);
                    printf("\n Nombre instrumento: %s",arrayInstrumento[bufferInstID].nombre);
                }
            }
        }
        retorno=0;
    }
    return retorno;
}


/** \brief saca el promedio de musicos por orquestas
 *
 * \param arrayOrquesta[] Orquesta array de Orquestas
 * \param sizeOrquesta int tamaño del array de Orquesta
 * \param arrayMusico[] Musico array de Musicos
 * \param sizeMusico int tamaño del array de Musicos
 * \return int retorno -1 si da error o no hay con que promediar o 0 si sale todo bien
 *
 */
int informes_promedioMusicosPorOrquesta(Orquesta arrayOrquesta[],int sizeOrquesta,Musico arrayMusico[],int sizeMusico)
{
    int retorno=-1;
    int cantidadDeMusicos;
    int cantidadDeOrquestas;
    if (arrayOrquesta!=NULL && arrayMusico!=NULL && sizeMusico>0 && sizeOrquesta>0)
    {

        cantidadDeMusicos=musico_cantidadDeMusicos(arrayMusico,sizeMusico);
        cantidadDeOrquestas=orquesta_cantidadDeOrquestas(arrayOrquesta,sizeOrquesta);
        if (cantidadDeOrquestas==0)
        {
            printf("\nNo hay orquestas.");
            retorno=-1;
        }
        else
        {
           printf("\n El promedio de musicos por orquesta es %.2f", (float)cantidadDeMusicos/cantidadDeOrquestas);
           retorno=0;
        }

    }
    return retorno;
}


/** \brief lista la o las orquestas con mas musicos
 *
 * \param arrayOrquesta[] Orquesta array de Orquestas
 * \param sizeOrquesta int tamaño del array de Orquestas
 * \param arrayMusico[] Musico array de Musicos
 * \param sizeMusico int tamaño del array de Musicos
 * \return int ret -1 si es error o no hay musicos o 0 si sale todo bien
 *
 */
int informes_orquestaConMasMusicos(Orquesta arrayOrquesta[],int sizeOrquesta,Musico arrayMusico[],int sizeMusico)
{
    int ret= -1;
    int contMusico;
    int MaxMusicos=-1;
    int maxMusicoIgual=0;
    int idOrquestaIgual;
    int idOrquestaMax;
    int bufferOrqId=0;
    int bufferMusicID=0;
    if(arrayMusico!=NULL && arrayOrquesta!=NULL && sizeMusico>=0 && sizeOrquesta>=0)
    {
        for(bufferOrqId=0;bufferOrqId<sizeOrquesta;bufferOrqId++)
        {
            if(arrayOrquesta[bufferOrqId].isEmpty==0)
            {
                contMusico=0;
                for(bufferMusicID=0;bufferMusicID<sizeMusico;bufferMusicID++)
                {
                    if(arrayMusico[bufferMusicID].idOrquesta==arrayOrquesta[bufferOrqId].idUnico)
                    {
                        contMusico++;
                    }
                }

                if(contMusico>MaxMusicos)
                {
                    MaxMusicos=contMusico;
                    idOrquestaMax=bufferOrqId;
                }
                if(contMusico==MaxMusicos)
                {
                    maxMusicoIgual=contMusico;
                    idOrquestaIgual=bufferOrqId;
                }
            }
        }
        printf("\nId: %d\nNombre: %s\nLugar: %s\nTipo: %d\n",arrayOrquesta[idOrquestaMax].idUnico,arrayOrquesta[idOrquestaMax].nombre,arrayOrquesta[idOrquestaMax].lugar,arrayOrquesta[idOrquestaMax].tipo);
                        switch(arrayOrquesta[idOrquestaMax].tipo)
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
        if(maxMusicoIgual==MaxMusicos)
        {
            printf("\nId: %d\nNombre: %s\nLugar: %s\nTipo: %d\n",arrayOrquesta[idOrquestaIgual].idUnico,arrayOrquesta[idOrquestaIgual].nombre,arrayOrquesta[idOrquestaIgual].lugar,arrayOrquesta[idOrquestaIgual].tipo);
                        switch(arrayOrquesta[idOrquestaMax].tipo)
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
        }
        printf("\n\nCantidad de musicos %d\n",MaxMusicos);

        ret=0;

        }
     return ret;
}









