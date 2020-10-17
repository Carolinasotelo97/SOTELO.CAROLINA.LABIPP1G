#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Color.h"

#define TAMC 3



void mostrarColor(eColor color)
{
     printf("     %d        %20s\n", color.idColor, color.nombreColor);
}

int mostrarColores(eColor color[], int tamC)
{
    int error = 1;
    if(color != NULL && tamC > 0)
    {
        printf(" **** LISTADO DE COLORES*****\n");
        printf("--------------------------------\n");
        printf("     ID         Descripcion\n");

        for(int i =0; i < tamC; i++)
        {
            mostrarColor(color[i]);
        }
        printf("\n\n");

        error = 0;
    }

    return error;
}


int validarIdColor(eColor color[], int tamC, int id)
{
    int esValido = 0;
    if(color !=NULL && tamC > 0 && id >= 5000)
    {
        for(int i= 0; i < tamC; i++)
        {

            if(color[i].idColor == id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}
int obtenerDescripcionColor(eColor color[], int tamC, int id, char nombreColor[])
{
    int error = 1;

    if(color != NULL && tamC>0 && id >=5000 && nombreColor != NULL)
    {
        for(int i= 0; i< tamC; i++)
        {
            if(color[i].idColor == id)
            {
                strcpy(nombreColor, color[i].nombreColor);
                error= 0;
                break;
            }
        }
    }
    return error;
}


