#include "3_clsCancion.h"
#include "3_archCanciones.h"
#include "2_clsArchivos.h"
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

Cancion::Cancion(){
    cargado=false;
}

void Cancion::setNumero(int x){
    numero = x;
}
void Cancion::sumarReproduccion(){
    reproducciones += 1;
}
void Cancion::setNombre(const char *x){
    strcpy(nombre,x);
}
void Cancion::setAutor(const char *x){
    strcpy(autor,x);
}
void Cancion::setInterprete(const char *x){
    strcpy(interprete,x);
}
void Cancion::setFechaPub(Fecha x) {
        fechaPublicacion = x;
}
void Cancion::setCargado(bool x){
    cargado=x;
}
void Cancion::setBajaLogica(bool x){
    bajaLogica=x;
}

int Cancion::getNumero(){
    return numero;
}
int Cancion::getReproducciones(){
    return reproducciones;
}
const char* Cancion::getNombre(){
    return nombre;
}
const char* Cancion::getAutor(){
    return autor;
}
const char* Cancion::getInterprete(){
    return interprete;
}
Fecha Cancion::getFechaPub(){
    return fechaPublicacion;
}

bool Cancion::getCargado(){
    return cargado;
}
bool Cancion::getBajaLogica(){
    return bajaLogica;
}
void Cancion::cargarCancion(){
    Archivo_Cancion archivo;
    bajaLogica=true;
    numero=archivo.CantidadRegis_canc()+1;
    cout<<"NOMBRE"<<endl;
    cin.ignore();
    cin.getline(nombre,30);
    cout<<"AUTOR"<<endl;
    cin.getline(autor,30);
    cout<<"INTERPRETE"<<endl;
    cin.getline(interprete,30);
    reproducciones=0;
}
void Cancion::Mostrar(){
    cout<<"cancion: "<<endl<<nombre<<endl;
    cout<<"autor: "<<endl<<autor<<endl;
    cout<<"interprete: "<<endl<<interprete<<endl;
    cout<<"reproducciones: "<<endl<<reproducciones<<endl;
}
