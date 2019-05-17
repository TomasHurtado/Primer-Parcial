#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musico.h"
#include "instrumento.h"
#include "orquesta.h"
#define CANTORQUEST 50
#define CANTINSTRUM 20
#define CANTMUSIC 1000
int main()
{
    int opcion;
    int flag=-1;
    int flad=-1;
    int contadorIdOrquesta=0;
    int contadorIdMusico=0;
    int contadorIdInstrumento=0;

    Orquesta arrayOrquesta[CANTORQUEST];
    Musico arrayMusico[CANTMUSIC];
    Instrumento arrayInstrumento[CANTINSTRUM];

    orquesta_Inicializar(arrayOrquesta,CANTORQUEST);
    musico_Inicializar(arrayMusico,CANTMUSIC);
    instrumento_Inicializar(arrayInstrumento,CANTINSTRUM);

    do
    {
        utn_getUnsignedInt("\nOrquestas\n1) Alta orquesta \n2) Eliminar orquesta \n3) Imprimir orquesta \nMusicos\n4)agregar musico \n5)Modificar musicon6)Eliminar musico \n7)Imprimir musicos \ninstrumento\n8) Agregar instrumento \n9)Imprimir instrumento \n10)Salir\n",
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta orquest
                orquesta_alta(arrayOrquesta,CANTORQUEST,&contadorIdOrquesta);
                flag=1;
                break;

            case 2: //eliminar
                orquesta_baja(arrayOrquesta,CANTORQUEST);
                break;

            case 3: //imprimir
            orquesta_listar(arrayOrquesta,CANTORQUEST);
                break;

            case 4://alta musico
              if(flad==1 && flag==1)
              {
                musico_alta(arrayMusico,CANTMUSIC,&contadorIdMusico);
              }
              else
              {
                printf("Se nesesita dar de alta al menos una orquesta y un instrumento\n");
              }
                break;

            case 5://modificar musico
                musico_modificar(arrayMusico,CANTMUSIC);
                break;

            case 6: //eliminar musico
                musico_baja(arrayMusico,CANTMUSIC);
                break;

            case 7: //imprimir musico
                musico_listar(arrayMusico,CANTMUSIC);
                break;

            case 8: //agregar instrumento
                instrumento_alta(arrayInstrumento,CANTINSTRUM,&contadorIdInstrumento);
                flad=1;
                break;

            case 9://imprimir
               instrumento_listar(arrayInstrumento,CANTINSTRUM);
                break;

            case 10://salir

                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=10);
    return 0;
}
