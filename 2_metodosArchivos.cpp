#include <iostream>
#include "2_clsArchivos.h"

Archivos::Archivos(std::string nombre){
    _nombreArchivo=nombre;
}

///APPEND///////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////

///LEER/////////////////////////////////////////////////////////////////
Suscripcion Archivos::leerSuscripcion(int pocision){
    FILE *pArchivo = fopen("Suscripciones.dat","rb");
    Suscripcion suscripcion;
    if(pArchivo==NULL){
        return suscripcion;
    }
    fseek(pArchivo,sizeof(Suscripcion)*pocision,0);
    fread(&suscripcion,sizeof(Suscripcion),1,pArchivo);
    return suscripcion;
}
Cancion Archivos::leerCancion(int pocision){
    FILE *pArchivo = fopen("Canciones.dat","rb");
    Cancion knCion;
    if(pArchivo==NULL){
        return knCion;
    }
    fseek(pArchivo,sizeof(Cancion)*pocision,0);
    fread(&knCion,sizeof(Cancion),1,pArchivo);
    return knCion;
}
Accesos Archivos::leerAcceso(int pocision){
    FILE *pArchivo = fopen("Accesos.dat","rb");
    Accesos Axes;
    if(pArchivo==NULL){
        return Axes;
    }
    fseek(pArchivo,sizeof(Accesos)*pocision,0);
    fread(&Axes,sizeof(Accesos),1,pArchivo);
    return Axes;
}
///////////////////////////////////////////////////////////////////////////

///CANTIDAD-REGISTROS//////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
