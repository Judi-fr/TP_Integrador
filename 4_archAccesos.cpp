#include <iostream>
#include "4_archAccesos.h"

using namespace std;

Archivo_Acceso::Archivo_Acceso(std::string nombre){
    nombreArch=nombre;
}
Archivo_Acceso::Archivo_Acceso(){

}

///APPEND///////////////////////////////////////////////////////////////
void Archivo_Acceso::append(Accesos acceso){
    FILE *pArchivo = fopen("Accesos.dat","ab");
    if(pArchivo==NULL){
        return;
    }
    fwrite(&acceso,sizeof(Accesos),1,pArchivo);
    fclose(pArchivo);
    return;
}

///LEER/////////////////////////////////////////////////////////////////
Accesos Archivo_Acceso::leerAcceso(int pocision){
    FILE *pArchivo = fopen("Accesos.dat","rb");
    Accesos Axes;
    if(pArchivo==NULL){
        return Axes;
    }
    fseek(pArchivo,sizeof(Accesos)*pocision,0);
    fread(&Axes,sizeof(Accesos),1,pArchivo);
    fclose(pArchivo);
    return Axes;
}

///CANTIDAD-REGISTROS//////////////////////////////////////////////////
int Archivo_Acceso::CantidadRegis_acces(){
    int bytes;
    FILE *pArchivo = fopen("Accesos.dat","rb");

    if (pArchivo == nullptr){
        return 0;
    }
    fseek(pArchivo,0,2);
    bytes=ftell(pArchivo);
    fclose(pArchivo);
    if(bytes!=0){
        return bytes / sizeof(Accesos);
    }
    else{
        return 0;
    }
}
