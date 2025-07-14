#include <iostream>
#include "1_archSuscripcion.h"

using namespace std;

Archivo_Suscripcion::Archivo_Suscripcion(std::string nombre){
    nombreArch=nombre;
}
Archivo_Suscripcion::Archivo_Suscripcion(){

}

///LEER/////////////////////////////////////////////////////////////////
Suscripcion Archivo_Suscripcion::leerSuscripcion(int posicion){
    FILE *pArchivo = fopen("Suscripciones.dat","rb");
    Suscripcion suscripcion;
    if(pArchivo==NULL){
        return suscripcion;
    }
    fseek(pArchivo,sizeof(Suscripcion)* posicion,0);
    fread(&suscripcion,sizeof(Suscripcion),1,pArchivo);
    fclose(pArchivo);
    return suscripcion;
}

///APPEND///////////////////////////////////////////////////////////////
void Archivo_Suscripcion::append(Suscripcion suscripcion){
    FILE *pArchivo = fopen("Suscripciones.dat","ab");
    if(pArchivo==NULL){
        return;
    }
    fwrite(&suscripcion,sizeof(Suscripcion),1,pArchivo);
    fclose(pArchivo);
    return;
}

///CANTIDAD-REGISTROS//////////////////////////////////////////////////
int Archivo_Suscripcion::CantidadRegis_susc(){
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
        return bytes / sizeof(Suscripcion);
    }
    else{
        return 0;
    }
}

///BUSCAR-POR-ID//////////////////////////////////////////
Suscripcion Archivo_Suscripcion::BuscarPorId(int idBuscado){
    Suscripcion noEncontrado;
    FILE* archivo = fopen("Suscripciones.dat", "rb");
    if(archivo == nullptr){
        cout<<"No se pudo abrir el archivo: "<<endl;
        return noEncontrado;
    }
    Suscripcion suscripcion;
    while(fread(&suscripcion, sizeof(Suscripcion), 1, archivo) == 1){
        if(suscripcion.getIdentificador() == idBuscado){
            fclose(archivo);
            return suscripcion;
        }
    }

    fclose(archivo);
    return noEncontrado;
}
