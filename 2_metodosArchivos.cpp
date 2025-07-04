#include <iostream>
#include "2_clsArchivos.h"
using namespace std;

Archivos::Archivos(std::string nombre){
    _nombreArchivo=nombre;
}
Archivos::Archivos(){

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

///LEER/////////////////////////////////////////////////////////////////
Suscripcion Archivos::leerSuscripcion(int pocision){
    FILE *pArchivo = fopen("Suscripciones.dat","rb");
    Suscripcion suscripcion;
    if(pArchivo==NULL){
        return suscripcion;
    }
    fseek(pArchivo,sizeof(Suscripcion)*pocision,0);
    fread(&suscripcion,sizeof(Suscripcion),1,pArchivo);
    fclose(pArchivo);
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
    fclose(pArchivo);
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
    fclose(pArchivo);
    return Axes;
}

///CANTIDAD-REGISTROS//////////////////////////////////////////////////
int Archivos::CantidadRegis_susc(){
    Suscripcion suscripcion;
    int bytes;

    FILE *pArchivo = fopen("Suscripciones.dat","rb");
    if (pArchivo == nullptr){
        return 0;
    }
    fseek(pArchivo,0,2);
    bytes=ftell(pArchivo);
    fclose(pArchivo);
    if(bytes!=0){
        return bytes / sizeof(Cancion);
    }
    else{
        return 0;
    }
}
int Archivos::CantidadRegis_acces(){
    int bytes;
    FILE *pArchivo = fopen("Accesos.dat","rb");

    if (pArchivo == nullptr){
        return 0;
    }
    fseek(pArchivo,0,2);
    bytes=ftell(pArchivo);
    fclose(pArchivo);
    if(bytes!=0){
        return bytes / sizeof(Cancion);
    }
    else{
        return 0;
    }
}
int Archivos::CantidadRegis_canc(){
    int bytes;
    FILE *pArchivo = fopen("Canciones.dat","rb");

    if (pArchivo == nullptr){
        return 0;
    }
    fseek(pArchivo,0,2);
    bytes=ftell(pArchivo);
    fclose(pArchivo);
    if(bytes!=0){
        return bytes / sizeof(Cancion);
    }
    else{
        return 0;
    }
}
//////////////////////////////////////////////////////////////////////////

///MODIFICAR-REGISTRO/////////////////////////////////////////////////////
void Archivos::Actualizar_reproducciones(int posicion,Cancion nuevaCancion){
    FILE *pFile = fopen("Canciones.dat","rb+");
    if (pFile == nullptr) {
        cout<<"Error al abrir el archivo."<<endl;
        return;
    }

    fseek(pFile, sizeof(Cancion) * posicion, SEEK_SET);  // Posiciona el puntero en el registro a modificar
    fwrite(&nuevaCancion, sizeof(Cancion), 1, pFile); // Escribe el nuevo objeto en la posici�n indicada

    fclose(pFile);
}

///SABER-POCISION///////////////////////////////////////////////////////

int Archivos::SaberPocision(Cancion song){
    Archivos archivo;
    Cancion cancionAux;
    int cantidadRegistros = archivo.CantidadRegis_canc();
    for(int i=0;i<cantidadRegistros;i++){
        cancionAux = archivo.leerCancion(i);
        if(song.getNumero()== cancionAux.getNumero()){
            return i;
        }
    }

}
