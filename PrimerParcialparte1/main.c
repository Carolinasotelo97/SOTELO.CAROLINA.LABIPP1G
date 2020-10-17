#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Bicicleta.h"
#define TAM 3


char menuOpciones();


int main()
{
    char seguir ='s';
    char confirma;
    int respuesta;
    eBicicleta bici[TAM];
    eTipo datoTipo [TAMT] = {{1000, "Rutera"},{1001, "Carrera"},{1002, "Mountain"},{1003, "BMX"}};
    eColor datoColor [TAMC] = {{5000, "Gris"},{5001, "Negro"},{5002, "Blanco"},{5003, "Azul"},{5004, "Rojo"}};
    int proximoIdBici = 0001;


   if(inicializarBici(bici, TAM)== 0)
    {
        printf("Bicicleta inicilizada con exito!\n");
    }else
    {
        printf("Problema con la inicilizacion de la bicicleta\n");
    }

    do
    {
      system("cls");

      switch(menuOpciones())
      {
         case 'a':
              if(altaBicicleta(bici, TAM, datoColor, TAMC, datoTipo, TAMT, proximoIdBici)== 0)
            {
                proximoIdBici++;
                printf("Alta exitosa\n");
            }else
            {
                printf("Problemas para realizar el alta\n");
            }
        break;
         case 'b':
             respuesta = modificarBicicleta(bici, TAM, datoColor, TAMC, datoTipo, TAMT);

            if(respuesta == 0)
            {
                printf("Modificacion exitosa!!\n\n");
            }else if(respuesta == 2)
            {
                printf("La modificaciones se ha cancelado\n\n");
            }else
            {
                printf("Se ha producido un error en la modificacion\n\n");
            }
            break;
        case 'c':
             respuesta = bajaBicicleta(bici, TAM, datoColor, TAMC, datoTipo, TAMT);

            if(respuesta == 0)
            {
                printf("Baja exitosa!!\n\n");
            }else if(respuesta == 2)
            {
                printf("La baja se ha cancelado\n\n");
            }else
            {
                printf("Se ha producido un error en la baja\n\n");
            }

        break;
        case 'd':

        break;
         case 'x':
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
                {
                    seguir = 'n';
                }
            break;
        default:
            printf("Opcion invalida!!!\n");
        }
            system("pause");
    }
    while(seguir == 's');

    return 0;
}


char menuOpciones()
{
    char opcion;

    printf("*****BICICLETERIA*****\n\n");
    printf("a.- Alta Bicicleta\n");
    printf("b.- Modificar Bicicleta\n");
    printf("c.- Baja Bicicleta\n");
    printf("d.- Listar Bicicletas\n");
    printf("e.- Listar tipos de bicicletas\n");
    printf("f.- Listar Colores\n");
    printf("g.- Listar servicios\n");
    printf("h.- Alta trabajo\n");
    printf("i.- Listar trabajo\n");
    printf("x.- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}

