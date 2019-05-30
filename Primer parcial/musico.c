#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"
#define CANTORQUEST 50
#define CANTINSTRUM 20
#define CANTMUSIC 1000


/** \brief  Incializa el isEmpty en 1 para que indique que este vacio
* \param array musico Array of musico
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musico_Inicializar(Musico array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}


/** \brief Busca el primer lugar vacio en un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musico_buscarEmpty(Musico array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}





/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musico_alta(Musico array[],Orquesta arrayOrquesta[], Instrumento arrayInstrumento[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    int aux;
    int buffer;

    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {


            if(utn_getUnsignedInt("Ingrese ID de la orquesta","\nError",1,sizeof(int),1,10000,1,&buffer))
            {
                printf("\nID de Orquesta invalida.\n");
                return retorno;
            }
            else
            {
                 if(!orquesta_buscarID(arrayOrquesta, 50, buffer, &aux))
                {
                    array[posicion].idOrquesta = buffer;
                }else
                {
                    return retorno;
                }
            }
            if(utn_getUnsignedInt("\nIngrese el ID del Instrumento :\n","\nID Invalida.\n",1,sizeof(int),1,10,1,&buffer))
            {
                printf("\nID de Instrumento invalido.\n");
                return retorno;
            }
            else
            {
                if(!instrumento_buscarID(arrayInstrumento, 20, buffer, &aux))
                {
                    array[posicion].idInstrumento = buffer;
                }else
                {
                    printf("\nID de Instrumento no encontrado.\n");
                    return retorno;
                }

            utn_getName("Nombre\n: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getTexto("Apellido\n: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);
            utn_getUnsignedInt("Edad: ","\nError",1,sizeof(int),1,1000,1,&array[posicion].edad);


            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;



            printf("\n Posicion: %d\n ID: %d\n  nombre: %s\n apellido: %s\n edad: %d\n ID orquesta: %d\n ID instrumento: %d",
                       posicion, array[posicion].idUnico,array[posicion].nombre,array[posicion].apellido,array[posicion].edad,array[posicion].idOrquesta,array[posicion].idInstrumento);
                retorno=0;
            }
        }
        return retorno;
    }
     return retorno;
}

/** \brief Borra un elemento del array por ID
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_baja(Musico array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;
            array[posicion].edad=0;
            strcpy(array[posicion].nombre,"");
            strcpy(array[posicion].apellido,"");
            retorno=0;
        }
    }
    return retorno;
}





/** \brief Busca un elemento por ID y modifica sus campos
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_modificar(Musico array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                 printf("\n Posicion: %d\n ID: %d\n  nombre: %s\n apellido: %s\n edad: %d\n ID orquesta: %d\n ID instrumento: %d",
                   posicion, array[posicion].idUnico,array[posicion].nombre,array[posicion].apellido,array[posicion].edad,array[posicion].idOrquesta,array[posicion].idInstrumento);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",1,6,1,&opcion);
                switch(opcion)
                {
                    case 3:
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].edad);
                        break;
                    case 1:
                        break;
                    case 2:
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
                        break;
                    case 4:
                       utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idOrquesta);
                        break;
                    case 5:
                       utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idInstrumento);
                        break;
                    case 6:
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!=6);
            retorno=0;
        }
        return retorno;

    }


/** \brief Lista los elementos de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si da Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musico_listar(Musico array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n nombre: %s\n apellido: %s\n edad: %d\n idorquesta: %d\n idinstrumento: %d",
                       array[i].idUnico,array[i].nombre,array[i].apellido,array[i].edad,array[i].idOrquesta,array[i].idInstrumento);
        }
        retorno=0;
    }
    return retorno;
}


/** \brief borra musico cuando se da de baja una orquesta
 *
 * \param array[] Musico array de Musicos
 * \param sizeArray int tamaño de array de Musicos
 * \param idAEliminar int id del musico a eliminar
 * \return int retorno -1 si da error o no existe el id o 0 si sale todo bien
 *
 */
int musico_bajaPorOrquesta(Musico array[], int sizeArray, int idAEliminar)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idOrquesta == idAEliminar)
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;
                array[i].edad=0;
                strcpy(array[i].nombre,"");
                strcpy(array[i].apellido,"");
                array[i].idOrquesta = 0;
                array[i].idInstrumento = 0;
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief cuenta cuantos musicos hay cargados
 *
 * \param array[] Musico array de Musicos
 * \param size int tamaño del array de Musicos
 * \return cantidad de musicos
 *
 */
int musico_cantidadDeMusicos(Musico array[], int size)
{
    int i;
    int cantidadDeMusicos=0;
    for (i=0;i<size;i++)
    {
        if (!array[i].isEmpty)
        {
            cantidadDeMusicos++;
        }
    }
    return cantidadDeMusicos;
}



/** \brief ordena alfabeticamente a los musicos por apellido
 *
 * \param array[] Musico array de Musicos
 * \param size int tamaño del array de Musicos
 * \return int -1 si no se pudo ordenar o da error y 0 si se ordeno correctamente
 *
 */
int musico_ordenarPorApellido(Musico array[],int size)
{
    int retorno=-1;
    int i;
    int j;
    char bufferApellido[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;

    int bufferEdad;
    int bufferidInstrumento;
    int bufferidOrquesta;
    char bufferNombre[TEXT_SIZE];

    if(array!=NULL && size>=0)
    {
        for (i=1;i<size;i++)
        {
            strncpy(bufferApellido,array[i].apellido,sizeof(array[i].apellido));
            bufferId=array[i].idUnico;
            bufferIsEmpty=array[i].isEmpty;

            bufferEdad=array[i].edad;
            bufferidInstrumento=array[i].idInstrumento;
            bufferidOrquesta=array[i].idOrquesta;
            strcpy(bufferNombre,array[i].nombre);


            j = i - 1;
            while ((j >= 0) && strcmp(bufferApellido,array[j].apellido)<0)
            {
                strncpy(array[j + 1].apellido,array[j].apellido,sizeof(array[j + 1].apellido));
                array[j + 1].idUnico=array[j].idUnico;
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].edad=array[j].edad;
                array[j + 1].idInstrumento=array[j].idInstrumento;
                array[j + 1].idOrquesta=array[j].idOrquesta;
                strncpy(array[j + 1].nombre,array[j].nombre,sizeof(array[j + 1].nombre));

                j--;
            }
            strncpy(array[j + 1].apellido,bufferApellido,sizeof(array[j + 1].apellido));
            array[j + 1].idUnico=bufferId;
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].edad=bufferEdad;
            array[j + 1].idInstrumento=bufferidInstrumento;
            array[j + 1].idOrquesta=bufferidOrquesta;
            strncpy(array[j + 1].nombre,bufferNombre,sizeof(array[j + 1].nombre));
        }
        retorno=0;
    }
    return retorno;
}
