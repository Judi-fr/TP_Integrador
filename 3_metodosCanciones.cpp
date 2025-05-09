#include "3_clsCancion.h"
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

void Cancion::setNumero(int x){
    numero = x;
}
void Cancion::setNombre(string x){
    nombre=x;
}
void Cancion::setAutor(string x){
    autor=x;
}
void Cancion::setInterprete(string x){
    interprete=x;
}

int Cancion::getNumero(){
    return numero;
}
string Cancion::getNombre(){
    return nombre;
}
string Cancion::getAutor(){
    return autor;
}
string Cancion::getInterprete(){
    return interprete;
}
void Cancion::cargarCancion(){
    cout<<"NUMERO"<<endl;
        cin>>numero;
    cout<<"NOMBRE"<<endl;
        cin.ignore();
        getline(cin,nombre);
    cout<<"AUTOR"<<endl;
        cin.ignore();
        getline(cin,autor);
    cout<<"INTERPRETE"<<endl;
        cin.ignore();
        getline(cin,interprete);
}
void Cancion::mostrarCancion(){
    cout<<numero<<endl;
    cout<<"el nombre de la cancion es: "<<nombre<<endl;
    cout<<"el autor es: "<<autor<<endl;
    cout<<"el interprete es: "<<interprete<<endl;
}
