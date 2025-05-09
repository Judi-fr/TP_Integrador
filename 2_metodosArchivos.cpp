#include <iostream>
#include "2_clsArchivos.h"

Archivos::Archivos(std::string nombre){
    _nombreArchivo=nombre;
}

///APPEND///////////////////////////////////////
void Archivos::append(Suscripcion suscripcion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(),"ab");
    if(pArchivo==NULL){
        return;
    }
}
void Archivos::append(Cancion cancion){

}
void Archivos::append(Accesos acceso){

}

/////////////////////////////////////////////////
