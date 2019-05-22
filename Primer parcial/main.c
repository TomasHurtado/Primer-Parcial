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
    int aux;

    Orquesta arrayOrquesta[CANTORQUEST];
    Musico arrayMusico[CANTMUSIC];
    Instrumento arrayInstrumento[CANTINSTRUM];

    orquesta_Inicializar(arrayOrquesta,CANTORQUEST);
    musico_Inicializar(arrayMusico,CANTMUSIC);
    instrumento_Inicializar(arrayInstrumento,CANTINSTRUM);


    //Instrumentos
    arrayInstrumento[0].idUnico = 1;
    arrayInstrumento[0].isEmpty = 0;
    strcpy(arrayInstrumento[0].nombre,"Flauta");
    arrayInstrumento[0].tipo = 1;

    arrayInstrumento[1].idUnico = 2;
    arrayInstrumento[1].isEmpty = 0;
    strcpy(arrayInstrumento[1].nombre,"xilofono");
    arrayInstrumento[1].tipo = 2;

    arrayInstrumento[2].idUnico = 3;
    arrayInstrumento[2].isEmpty = 0;
    strcpy(arrayInstrumento[2].nombre,"piano");
    arrayInstrumento[2].tipo = 3;


    //Hardcode Orquesta
    arrayOrquesta[0].idUnico = 1;
    arrayOrquesta[0].isEmpty = 0;
    strcpy(arrayOrquesta[0].nombre,"Betoven");
    strcpy(arrayOrquesta[0].lugar,"en casa");
    arrayOrquesta[0].tipo = 1;

    arrayOrquesta[1].idUnico = 2;
    arrayOrquesta[1].isEmpty = 0;
    strcpy(arrayOrquesta[1].nombre,"Mozart");
    strcpy(arrayOrquesta[1].lugar,"en la playa");
    arrayOrquesta[1].tipo = 2;

    arrayOrquesta[2].idUnico = 3;
    arrayOrquesta[2].isEmpty = 0;
    strcpy(arrayOrquesta[2].nombre,"Pablitolescano");
    strcpy(arrayOrquesta[2].lugar,"en la calle");
    arrayOrquesta[2].tipo = 3;

    //Hardcode Musico
    arrayMusico[0].idUnico = 1;
    arrayMusico[0].idOrquesta = 1;
    arrayMusico[0].idInstrumento = 1;
    arrayMusico[0].isEmpty = 0;
    strcpy(arrayMusico[0].nombre,"pepe");
    strcpy(arrayMusico[0].apellido,"guapo");
    arrayMusico[0].edad = 50;

    arrayMusico[1].idUnico = 2;
    arrayMusico[1].idOrquesta = 2;
    arrayMusico[1].idInstrumento = 3;
    arrayMusico[1].isEmpty = 0;
    strcpy(arrayMusico[1].nombre,"julian");
    strcpy(arrayMusico[1].apellido,"soliz");
    arrayMusico[1].edad = 30;

    arrayMusico[2].idUnico = 3;
    arrayMusico[2].idOrquesta = 3;
    arrayMusico[2].idInstrumento = 2;
    arrayMusico[2].isEmpty = 0;
    strcpy(arrayMusico[2].nombre,"ricardo");
    strcpy(arrayMusico[2].apellido,"milos");
    arrayMusico[2].edad = 75;

    do
    {
        utn_getUnsignedInt("\nOrquestas\n1) Alta orquesta \n2) Eliminar orquesta \n3) Imprimir orquesta \nMusicos\n4)agregar musico \n5)Modificar musicon\n6)Eliminar musico \n7)Imprimir musicos \ninstrumento\n8) Agregar instrumento \n9)Imprimir instrumento \n10)Salir\n",
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta orquest
                orquesta_alta(arrayOrquesta,CANTORQUEST,&contadorIdOrquesta);
                flag=1;
                break;

            case 2: //eliminar
                if(!orquesta_baja(arrayOrquesta,CANTORQUEST,&aux))
                {
                    musico_bajaPorOrquesta(arrayMusico, CANTMUSIC, aux);
                }
                break;

            case 3: //imprimir
            orquesta_listar(arrayOrquesta,CANTORQUEST);
                break;

            case 4://alta musico
              if(flad==1 && flag==1)
              {
                musico_alta(arrayMusico,arrayOrquesta,arrayInstrumento,CANTMUSIC,&contadorIdMusico);
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
