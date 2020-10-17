#include "Color.h"

#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED
typedef struct
{
    int idTipo;
    char descripcion[20];

}eTipo;


#endif // TIPO_H_INCLUDED
void mostrarTipo(eTipo tipe);
int mostrarTipos(eTipo tipe[], int tamT);
int validarIdTipo(eTipo tipe[], int tamT, int id);
