#include "3_clsCancion.h"
#include "2_clsArchivos.h"
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

void Cancion::setNumero(int x){
    numero = x;
}
void Cancion::setReproducciones(int x){
    reproducciones = x;
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
void Cancion::cargarCancion(){
    Archivos archivo;
    numero=archivo.CantidadRegis_canc()+1;
    cout<<"NUMERO"<<numero<<endl;
    cout<<"NOMBRE"<<endl;
    cin.ignore();
    cin.getline(nombre,50);
    cout<<"AUTOR"<<endl;
    cin.ignore();
    cin.getline(autor,50);
    cout<<"INTERPRETE"<<endl;
    cin.ignore();
    cin.getline(interprete,50);
    reproducciones=0;
}
void Cancion::mostrarCancion(){
    cout<<numero<<endl;
    cout<<"cancion: "<<endl<<nombre<<endl;
    cout<<"autor: "<<endl<<autor<<endl;
    cout<<"interprete: "<<endl<<interprete<<endl;
    cout<<"reproducciones: "<<endl<<reproducciones<<endl;
}
