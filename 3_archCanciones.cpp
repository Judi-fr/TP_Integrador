#include <iostream>
#include "3_archCanciones.h"

using namespace std;

Archivo_Cancion::Archivo_Cancion(std::string nombre){
    nombreArch=nombre;
}
Archivo_Cancion::Archivo_Cancion(){

}

///BAJA-LOGICA//////////////////////////////////////////////////////////
void Archivo_Cancion::bajaLogica(int id){
    Archivo_Cancion archivoCanc;
    Cancion canc;
    bool encontrado=false;
    int cantidad=CantidadRegis_canc();

    for(int i=0;i<cantidad;i++){
        canc=leerCancion(i);
        if(canc.getNumero()==id && canc.getBajaLogica()){
            canc.setBajaLogica(false);
            encontrado=true;
            cout<<"La cancion a sido dada de Baja"<<endl;
            break;
        }
        if(canc.getNumero()==id && canc.getBajaLogica()==false){
            canc.setBajaLogica(true);
            encontrado=true;
            cout<<"La cancion a sido dada de Alta"<<endl;
            break;
        }
    }
    if(encontrado==true){
        int pocision=archivoCanc.SaberPocision(canc);
        archivoCanc.Actualizar(pocision, canc);
    }else{cout<<"El id ingresado no Pertenece a ninguna cancion";}
}

///APPEND///////////////////////////////////////////////////////////////
void Archivo_Cancion::append(Cancion cancion){
    FILE *pArchivo = fopen("Canciones.dat","ab");
    if(pArchivo==NULL){
        return;
    }
    fwrite(&cancion,sizeof(Cancion),1,pArchivo);
    fclose(pArchivo);
    return;
}

///LEER/////////////////////////////////////////////////////////////////
Cancion Archivo_Cancion::leerCancion(int pocision){
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

///CANTIDAD-REGISTROS//////////////////////////////////////////////////
int Archivo_Cancion::CantidadRegis_canc(){
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

///MODIFICAR-REGISTRO/////////////////////////////////////////////////////
void Archivo_Cancion::Actualizar(int posicion,Cancion nuevaCancion){
    FILE *pFile = fopen("Canciones.dat","rb+");
    if (pFile == nullptr) {
        cout<<"Error al abrir el archivo."<<endl;
        return;
    }

    fseek(pFile, sizeof(Cancion) * posicion, SEEK_SET);
    fwrite(&nuevaCancion, sizeof(Cancion), 1, pFile);

    fclose(pFile);
}

///SABER-POCISION///////////////////////////////////////////////////////

int Archivo_Cancion::SaberPocision(Cancion song){
    Archivo_Cancion archivo;
    Cancion cancionAux;
    int cantidadRegistros = archivo.CantidadRegis_canc();
    for(int i=0;i<cantidadRegistros;i++){
        cancionAux = archivo.leerCancion(i);
        if(song.getNumero()== cancionAux.getNumero()){
            return i;
        }
    }
}

///BUSCARPORID/////////////////////////////////////////////////////////////
Cancion Archivo_Cancion::BuscarPorId(int idBuscado){
    Cancion noEncontrado;
    FILE* archivo = fopen("Canciones.dat", "rb");
    if(archivo == nullptr){
        cout<<"No se pudo abrir el archivo: "<<endl;
        return noEncontrado;
    }
    Cancion cancion;
    while(fread(&cancion, sizeof(Cancion), 1, archivo) == 1){
        if(cancion.getNumero() == idBuscado){
            fclose(archivo);
            return cancion;
        }
    }
    fclose(archivo);
    cout<<"No se encontro la cancion.";
    noEncontrado.setNumero(-1);
    return noEncontrado;
}
