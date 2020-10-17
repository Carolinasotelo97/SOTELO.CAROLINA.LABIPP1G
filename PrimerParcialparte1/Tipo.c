#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Tipo.h"


#define TAMT 3



void mostrarTipo(eTipo tipe)
{
     printf("     %d        %20s\n", tipe.idTipo, tipe.descripcion);
}

int mostrarTipos(eTipo tipe[], int tamT)
{
    int error = 1;
    if(tipe != NULL && tamT > 0)
    {
        printf(" **** LISTADO DE TIPOS*****\n");
        printf("--------------------------------\n");
        printf("     ID         Descripcion\n");

        for(int i =0; i < tamT; i++)
        {
            mostrarTipo(tipe[i]);
        }
        printf("\n\n");

        error = 0;
    }

    return error;
}


int validarIdTipo(eTipo tipe[], int tamT, int id)
{
    int esValido = 0;
    if(tipe !=NULL && tamT > 0 && id >= 1000)
    {
        for(int i= 0; i < tamT; i++)
        {

            if(tipe[i].idTipo == id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}



