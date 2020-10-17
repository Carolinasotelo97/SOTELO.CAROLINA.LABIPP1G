#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Bicicleta.h"



int inicializarBicicletas(eBicicleta bici[], int tam)
{
    int error = 1;

    if(bici!= NULL && tam > 0)
    {
        for(int i=0; i< tam; i++)
        {
            bici[i].isEmpty= 1;
        }
        error=0;
    }

    return error;
}

void mostrarBici(eBicicleta unaBici, eTipo tipe[], int tam)
{
    char descTipe[20];

    if(obtenerDescripcionTipo(tipe, tam, unaBici.idTipo, descTipe) == 0)
    {
             printf(" %4d     %c    %.2f      %s\n", unaBici.idBici, unaBici.marca, unaBici.rodado, unaBici.nombColor, descTipe);
    }else
    {
        printf("Problema al obtener descripcion de la bicicleta\n\n");
    }
}

int mostrarBicicletas(eBicicleta bici[], int tam, eTipo tipe[], int tamT, eColor color[], int tamC)
{
    int error = 1;
    int flag = 0;
    if(bici!= NULL && tam > 0)
    {

        // system("cls");
        printf(" ID   MARCA   TIPO    COLOR   RODADO\n");
        printf("-----------------------------------------\n");

        for(int i=0; i < tam; i++)
        {
            if(bici[i].isEmpty == 0)
            {
                mostrarBici(bici[i], tipe, tamT);
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("No hay bicicletas en la lista.");
        }
        printf("\n\n");
    }

    return error;
}


int buscarLibre(eBicicleta bici[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i ++)
    {
        if(bici[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int altaBicicleta(eBicicleta bici[], int tam, eTipo tipe[], int tamT, eColor color[], int tamC, int id)
{
    int error = 1;
    int indice;
    int auxIdColor;
    int auxIdTipo;
    eBicicleta nuevaBici;

    if(bici != NULL && tam > 0 && id > 0 )
    {
        system("cls");
        printf(" ****ALTA DE BICICLETAS****\n\n");

        indice = buscarLibre(bici, tam);

        if(indice == -1)
        {
            printf("El sistema esta completo.\n");
        }
        else
        {
            nuevaBici.idBici = id;
            nuevaBici.isEmpty = 0;

            printf("Ingrese Marca: ");
            fflush(stdin);
            gets(nuevaBici.marca);

            mostrarTipos(tipe, tamT);

            printf("Ingrese ID del Tipo: ");
            scanf("%d", &auxIdTipo);

            mostrarColores(color, tamC);

            printf("Ingrese ID del Color: ");
            scanf("%d", &auxIdColor);

            printf("Ingrese numero de rodado: ");
            scanf("%f", &nuevaBici.rodado);

            while( validarIdTipo(tipe, tamT, auxIdTipo)== 0)
            {
                printf("Id invalido. Reingrese id: ");
                scanf("%d", &auxIdTipo);
            }if(validarIdColor(color, tamC, auxIdColor) == 0)
            {
                printf("Id invalido. Reingrese id: ");
                scanf("%d", &auxIdColor);
            }
            nuevaBici.idTipo = auxIdTipo;
            bici[indice] = nuevaBici;

            nuevaBici.nombColor = auxIdColor;
            bici[indice] = nuevaBici;

            error = 0;
        }
    }

    return error;
}



int buscarBici(eBicicleta bici[], int tam, int id)
{
    int indice = -1;

    for(int i=0; i < tam; i ++)
    {
        if(bici[i].idBici == id && bici[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


int bajaBicicleta(eBicicleta bici[], int tam, eTipo tipe[], int tamT, eColor color[], int tamC)
{
    int error = 1;
    int id;
    int indice;
    char confirma;

    if(bici != NULL && tam > 0)
    {
        system("cls");
        printf("   *** BAJA DE BICICLETAS *** \n\n");

        mostrarBicletas(bici, tam, tipe, tamT, color, tamC);
        printf("Ingrese el id: ");
        scanf("%d", &id);

        indice = buscarBici(bici, tam, id);

        if(indice == -1)
        {
            printf("No existe una bicicleta con ese id\n\n");
        }
        else
        {
            mostrarBicicletas(bici[indice], tipe, tamT, color, tamC);
            printf("Confirma baja: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                bici[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                printf("La baja se ha cancelado por el usuario\n\n");
            }
        }
    }

    return error;
}

int modificarBicicleta(eBicicleta bici[], int tam, eTipo tipe[], int tamT, eColor color[], int tamC)
{
    int error = 1;
    int id;
    int indice;
    char opcionMod;
    char confirma;
    eTipo nuevoTipo;
    eBicicleta nuevoRodado;


    if(bici != NULL && tam > 0)
    {
        system("cls");
        printf("   *** MODIFICAR BICICLETAS *** \n\n");

        mostrarBicletas(bici, tam, tipe, tamT, color, tamC);
        printf("Ingrese el id: ");
        scanf("%d", &id);

        indice = buscarBici(bici, tam, id);

        if(indice == -1)
        {
            printf("No existe una bicicletas con ese id\n\n");
        }
        else
        {
            system("cls");
            printf("*****ELIJA UNA OPCION*****");
            printf("a.- Modificar Tipo\n");
            printf("b.- Modificar Rodado\n");
            printf("Ingrese opcion: ");
            flush(stdin);
            scanf("%c", &opcionMod);


            if(opcionMod == 'a')
            {
                mostrarBici(bici[indice], tipe, tamT, color, tamC);
                printf("\n Ingrese nuevo tipo: ");
                gets(nuevoTipo.descripcion);

            }else if(opcionMod == 'b')
            {
                mostrarBici(bici[indice], tipe, tamT, color, tamC);
                printf("\n Ingrese nuevo rodado: ");
                gets(nuevoRodado.rodado);

            }

            printf("\nConfirma modificacion?: ");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma == 's')
            {

                error = 0;
            }
            else
            {
                error = 2;
            }
        }
    }

    return error;

}

int ordernarBiciRodado(eBicicleta bici[], int tam, int criterioR)
{
    int error = 1;
    eBicicleta auxBici;

    if(bici != NULL && tam > 0 && criterioR >= 0 && criterioR <= 1)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i +1; j < tam; j++)
            {
                if(bici[i].rodado > bici[j].rodado && criterioR)
                {
                    auxBici = bici[i];
                    bici[i] = bici[j];
                    bici[j] = auxBici;
                }
                else if(bici[i].rodado > bici[j].rodado && !criterioR)
                {
                    auxBici = bici[i];
                    bici[i] = bici[j];
                    bici[j] = auxBici;
                }
            }

        }
        error =0;
    }
    return error;
}

int obtenerDescripcionTipo(eTipo tipe[], int tamT, int id, char descripcion[])
{
    int error = 1;

    if(tipe != NULL && tamT>0 && id >=1000 && descripcion != NULL)
    {
        for(int i= 0; i< tamT; i++)
        {
            if(tipe[i].idTipo == id)
            {
                strcpy(descripcion, tipe[i].descripcion);
                error= 0;
                break;
            }
        }
    }
    return error;
}


int ordenarBiciIdTipo(eBicicleta bici[], int tam, eTipo tipe[], int tamT, int criterio)
{
    int error = 1;
    eBicicleta auxBici;
    char tipeA[20];
    char tipeZ[20];

    if(bici != NULL && tam > 0 && criterio >= 0 && criterio <= 1)
    {
        for(int i=0; a < tam -1; a++)
        {
            for(int z= a +1; z < tam; z++)
            {
                obtenerDescripcionTipo(tipe, tamT, bici[a].idTipo, tipeA);
                obtenerDescripcionTipo(tipe, tamT, bici[z].idTipo, tipeZ);
                if( ((strcmp(tipeA, tipeZ) > 0) && criterio)
                    || ((strcmp(tipeZ, tipeA) <0) && !criterio))
                {

                    auxBici = bici[a];
                    bici[a] = bici[z];
                    bici[z] = auxBici;
                }
            }
        }
        error =0;
    }
        return error;
}



int obtenerDescripcionTipo(eTipo tipe[], int tamT, int id, char descripcion[])
{
    int error = 1;

    if(tipe != NULL && tamT>0 && id >=1000 && descripcion != NULL)
    {
        for(int i= 0; i< tamT; i++)
        {
            if(tipe[i].idTipo == id)
            {
                strcpy(descripcion, tipe[i].descripcion);
                error= 0;
                break;
            }
        }
    }
    return error;
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




