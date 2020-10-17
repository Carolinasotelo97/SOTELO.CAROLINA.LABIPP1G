#include "Tipo.h"


#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{
    int idBici;
    char marca[20];
    int  idTipo;
    eColor nombColor;
    float rodado;
    int isEmpty;
}eBicicleta;

#endif // BICICLETA_H_INCLUDED
int inicializarBicicletas(eBicicleta bici[], int tam);
void mostrarBici(eBicicleta unaBici, eTipo tipe[], int tam);
int mostrarBicletas(eBicicleta bici[], int tam, eTipo tipe[], int tamT, eColor color[], int tamC);
int buscarLibre(eBicicleta bici[], int tam);
int altaBicicleta(eBicicleta bici[], int tam, eTipo tipe[], int tamT, eColor color[], int tamC, int id);
int buscarBici(eBicicleta bici[], int tam, int id);
int bajaBicicleta(eBicicleta bici[], int tam, eTipo tipe[], int tamT, eColor color[], int tamC);
int modificarBicicleta(eBicicleta bici[], int tam, eTipo tipe[], int tamT, eColor color[], int tamC);
int ordernarBiciRodado(eBicicleta bici[], int tam, int criterioR);
int obtenerDescripcionTipo(eTipo tipe[], int tamT, int id, char descripcion[]);
int ordenarBiciIdTipo(eBicicleta bici[], int tam, eTipo tipe[], int tamT, int criterio);

