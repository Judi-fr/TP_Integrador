#include "3_clsCancion.h"
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

void Cancion::setNumero(int x){
    numero = x;
}
void Cancion::setNombre(const char *x){
    strcpy(nombre,x);
}
void Cancion::setAutor(const charx){
    strcpy(autor,x);
}
void Cancion::setInterprete(const char x){
    strcpy(interprete,x);
}

int Cancion::getNumero(){
    return numero;
}
const char Cancion::getNombre(){
    return nombre;
}
const char* Cancion::getAutor(){
    return autor;
}
const char* Cancion::getInterprete(){
    return interprete;
}
void Cancion::cargarCancion(){
    cout<<"NUMERO"<<endl;
        cin>>numero;
    cout<<"NOMBRE"<<endl;
        cargarCadena(nombre,30);
    cout<<"AUTOR"<<endl;
        cargarCadena(autor,30);
    cout<<"INTERPRETE"<<endl;
        cargarCadena(interprete,30);
}
void Cancion::mostrarCancion(){
    cout<<numero<<endl;
    cout<<"el nombre de la cancion es: "<<nombre<<endl;
    cout<<"el autor es: "<<autor<<endl;
    cout<<"el interprete es: "<<interprete<<endl;
}
