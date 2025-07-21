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

///BAJA-LOGICA//////////////////////////////////////////////////////////
void Archivo_Suscripcion::bajaLogica(int id){
    Archivo_Suscripcion archivoSus;
    Suscripcion sus;
    bool encontrado = false;
    int cantidad = archivoSus.CantidadRegis_susc();

    for(int i = 0; i < cantidad; i++){
        sus = archivoSus.leerSuscripcion(i);

        if(sus.getIdentificador() == id && sus.getBajaLogica()){
            sus.setBajaLogica(false);
            encontrado = true;
            cout << "La suscripcion ha sido dada de Baja" << endl;
            break;
        }
        if(sus.getIdentificador() == id && sus.getBajaLogica() == false){
            sus.setBajaLogica(true);
            encontrado = true;
            cout << "La suscripcion ha sido dada de Alta" << endl;
            break;
        }
    }
    if(encontrado){
        int posicion = archivoSus.SaberPocision(sus);
        archivoSus.Actualizar(posicion, sus);
    }
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
///MODIFICAR-REGISTRO/////////////////////////////////////////////////////
void Archivo_Suscripcion::Actualizar(int posicion,Suscripcion nuevaSuscripcion){
    FILE *pFile = fopen("Suscripciones.dat","rb+");
    if (pFile == nullptr) {
        cout<<"Error al abrir el archivo."<<endl;
        return;
    }

    fseek(pFile, sizeof(Suscripcion) * posicion, SEEK_SET);
    fwrite(&nuevaSuscripcion, sizeof(Suscripcion), 1, pFile);

    fclose(pFile);
}

///SABER-POCISION///////////////////////////////////////////////////////

int Archivo_Suscripcion::SaberPocision(Suscripcion sus){
    Archivo_Suscripcion archivo;
    Suscripcion suscripcionAux;
    int cantidadRegistros = archivo.CantidadRegis_susc();
    for(int i=0;i<cantidadRegistros;i++){
        suscripcionAux = archivo.leerSuscripcion(i);
        if(sus.getIdentificador()== suscripcionAux.getIdentificador()){
            return i;
        }
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
    cout<<"No se encontro la suscripcion.";
    noEncontrado.setIdentificador(-1);
    return noEncontrado;
}
