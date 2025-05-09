#include <iostream>
#include "2_clsArchivos.h"

Archivos::Archivos(std::string nombre){
    _nombreArchivo=nombre;
}

///APPEND///////////////////////////////////////
void Archivos::append(Suscripcion suscripcion){
    FILE *pArchivo = fopen("Suscripciones.dat","ab");
    if(pArchivo==NULL){
        return;
    }
    fwrite(&suscripcion,sizeof(Suscripcion),1,pArchivo);
    fclose(pArchivo);
    return;
}
void Archivos::append(Cancion cancion){
    FILE *pArchivo = fopen("Canciones.dat","ab");
    if(pArchivo==NULL){
        return;
    }
    fwrite(&cancion,sizeof(Cancion),1,pArchivo);
    fclose(pArchivo);
    return;
}
void Archivos::append(Accesos acceso){
    FILE *pArchivo = fopen("Accesos.dat","ab");
    if(pArchivo==NULL){
        return;
    }
    fwrite(&acceso,sizeof(Accesos),1,pArchivo);
    fclose(pArchivo);
    return;
}

/////////////////////////////////////////////////
