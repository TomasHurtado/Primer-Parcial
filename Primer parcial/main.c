#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musico.h"
#include "instrumento.h"
#include "orquesta.h"
#include "informes.h"
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
    char buscar[50];

    Orquesta arrayOrquesta[CANTORQUEST];
    Musico arrayMusico[CANTMUSIC];
    Instrumento arrayInstrumento[CANTINSTRUM];

    orquesta_Inicializar(arrayOrquesta,CANTORQUEST);
    musico_Inicializar(arrayMusico,CANTMUSIC);
    instrumento_Inicializar(arrayInstrumento,CANTINSTRUM);


    //Instrumentos
    arrayInstrumento[0].idUnico = 1;
    arrayInstrumento[0].isEmpty = 0;
    strcpy(arrayInstrumento[0].nombre,"Inst1");
    arrayInstrumento[0].tipo = 1;

    arrayInstrumento[1].idUnico = 2;
    arrayInstrumento[1].isEmpty = 0;
    strcpy(arrayInstrumento[1].nombre,"Inst2");
    arrayInstrumento[1].tipo = 2;

    arrayInstrumento[2].idUnico = 3;
    arrayInstrumento[2].isEmpty = 0;
    strcpy(arrayInstrumento[2].nombre,"Inst3");
    arrayInstrumento[2].tipo = 2;

    arrayInstrumento[3].idUnico = 4;
    arrayInstrumento[3].isEmpty = 0;
    strcpy(arrayInstrumento[3].nombre,"Inst4");
    arrayInstrumento[3].tipo = 3;

    arrayInstrumento[4].idUnico = 5;
    arrayInstrumento[4].isEmpty = 0;
    strcpy(arrayInstrumento[4].nombre,"Inst5");
    arrayInstrumento[4].tipo = 4;



    //Hardcode Orquesta
    arrayOrquesta[0].idUnico = 1;
    arrayOrquesta[0].isEmpty = 0;
    strcpy(arrayOrquesta[0].nombre,"Orquesta1");
    strcpy(arrayOrquesta[0].lugar,"Lugar1");
    arrayOrquesta[0].tipo = 1;

    arrayOrquesta[1].idUnico = 2;
    arrayOrquesta[1].isEmpty = 0;
    strcpy(arrayOrquesta[1].nombre,"Orquesta2");
    strcpy(arrayOrquesta[1].lugar,"Lugar2");
    arrayOrquesta[1].tipo = 2;

    arrayOrquesta[2].idUnico = 3;
    arrayOrquesta[2].isEmpty = 0;
    strcpy(arrayOrquesta[2].nombre,"Orquesta3");
    strcpy(arrayOrquesta[2].lugar,"Lugar3");
    arrayOrquesta[2].tipo = 3;

    arrayOrquesta[3].idUnico = 4;
    arrayOrquesta[3].isEmpty = 0;
    strcpy(arrayOrquesta[3].nombre,"Orquesta4");
    strcpy(arrayOrquesta[3].lugar,"Lugar4");
    arrayOrquesta[3].tipo = 3;

    //Hardcode Musico
    arrayMusico[0].idUnico = 1;
    arrayMusico[0].idOrquesta = 1;
    arrayMusico[0].idInstrumento = 2;
    arrayMusico[0].isEmpty = 0;
    strcpy(arrayMusico[0].nombre,"Mus1");
    strcpy(arrayMusico[0].apellido,"Amus1");
    arrayMusico[0].edad = 30;

    arrayMusico[1].idUnico = 2;
    arrayMusico[1].idOrquesta = 2;
    arrayMusico[1].idInstrumento = 5;
    arrayMusico[1].isEmpty = 0;
    strcpy(arrayMusico[1].nombre,"Mus2");
    strcpy(arrayMusico[1].apellido,"Amus2");
    arrayMusico[1].edad = 20;

    arrayMusico[2].idUnico = 3;
    arrayMusico[2].idOrquesta = 4;
    arrayMusico[2].idInstrumento = 2;
    arrayMusico[2].isEmpty = 0;
    strcpy(arrayMusico[2].nombre,"Mus3");
    strcpy(arrayMusico[2].apellido,"Amus3");
    arrayMusico[2].edad = 25;

    arrayMusico[3].idUnico = 4;
    arrayMusico[3].idOrquesta = 4;
    arrayMusico[3].idInstrumento = 1;
    arrayMusico[3].isEmpty = 0;
    strcpy(arrayMusico[3].nombre,"Mus4");
    strcpy(arrayMusico[3].apellido,"Amus4");
    arrayMusico[3].edad = 27;

    arrayMusico[4].idUnico = 5;
    arrayMusico[4].idOrquesta = 1;
    arrayMusico[4].idInstrumento = 3;
    arrayMusico[4].isEmpty = 0;
    strcpy(arrayMusico[4].nombre,"Mus5");
    strcpy(arrayMusico[4].apellido,"Amus5");
    arrayMusico[4].edad = 22;

    arrayMusico[5].idUnico = 6;
    arrayMusico[5].idOrquesta = 3;
    arrayMusico[5].idInstrumento = 4;
    arrayMusico[5].isEmpty = 0;
    strcpy(arrayMusico[5].nombre,"Mus6");
    strcpy(arrayMusico[5].apellido,"Amus6");
    arrayMusico[5].edad = 35;


    do
    {
        utn_getUnsignedInt("\nOrquestas\n1) Alta orquesta \n2) Eliminar orquesta \n3) Imprimir orquesta \nMusicos\n4)agregar musico \n5)Modificar musicon\n6)Eliminar musico \n7)Imprimir musicos \ninstrumento\n8) Agregar instrumento \n9)Imprimir instrumento \n10)Informes\n11)Salir\n",
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

            case 10://informes

                utn_getUnsignedInt("\n 1)Orquestas con mas de 5\n2)listar menores a 30\n3buscar por lugar\n",
                      "\nError",1,sizeof(int),1,11,1,&opcion);

                switch(opcion)
                    {
                    case 1:
                    informes_listarOrquestasMasDe(arrayOrquesta,arrayMusico,CANTORQUEST,CANTMUSIC);
                    break;
                    case 2:
                    informes_musicosMenoresA(arrayMusico,arrayInstrumento,arrayOrquesta,CANTMUSIC,CANTORQUEST,CANTINSTRUM);
                    break;
                    case 3:
                    utn_getAlfanumerico("ingrese lugar a buscar","EROR",1,10,2,buscar);
                    informes_buscarlugar(arrayOrquesta,CANTORQUEST,buscar);
                    break;
                    case 4:
                    break;
                    case 5:
                    break;



                    default:
                      printf("\nOpcion no valida");
                    }
            break;

            case 11:
            break;

            default:
            printf("\nOpcion no valida");

        }
    }
    while(opcion!=11);
    return 0;
}
