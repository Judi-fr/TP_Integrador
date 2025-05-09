
///METODOS
#include <iostream>
#include <cstring>
#include "1_clsSuscripcion.h"
#include "Fecha.h"

using namespace std;

void Suscripcion::setIdentificador(int x){
    identificador = x;
}
void Suscripcion::setDni(int x){
    dni = x;
}
void Suscripcion::setNombre(string x){
    nombre=x;
}
void Suscripcion::setApellido(string x){
    apellido=x;
}
void Suscripcion::setTelefono(int x){
    telefono = x;
}
void Suscripcion::setEmail(string x){
    email=x;
}
void Suscripcion::setFechaNac(Fecha x){
    fechaNacimiento = x;
}
int Suscripcion::getIdentificador(){
    return identificador;
}
int Suscripcion::getDni(){
    return dni;
}
string Suscripcion::getNombre(){
    return nombre;
}
string Suscripcion::getApellido(){
    return apellido;
}
int Suscripcion::getTelefono(){
    return telefono;
}
string Suscripcion::getEmail(){
    return email;
}
Fecha Suscripcion::getFecha(){
    return fechaNacimiento;
}

void Suscripcion::Cargar(){
    cout<<"INGRESA TU DNI: ";
    cin>>dni;
    cout<<"INGRESA TU NOMBRE: ";
    cin.ignore();
    getline(cin,nombre);
    cout<<"INGRESA TU APELLIDO: ";
    cin.ignore();
    getline(cin,apellido);
    cout<<"INGRESA TU TELEFONO: ";
    cin>>telefono;
    cout<<"INGRESA TU EMAIL: ";
    cin.ignore();
    getline(cin,email);
    cout<<"INGRESA TU FECHA DE NACIMIENTO: ";
    fechaNacimiento.Cargar();
}
void Suscripcion::Mostrar(){
    cout<<nombre<<" "<<apellido<<endl;
    cout<<"Dni: "<<dni<<endl;

    cout<<"Fecha de nacimiento: "
    <<fechaNacimiento.getDia()<<"/"
    <<fechaNacimiento.getMes()<<"/"
    <<fechaNacimiento.getAnio()<<endl;

    cout<<"Telefono "<<telefono<<endl;
    cout<<email<<endl;
    cout<<"Suscriptor n."<<identificador<<endl;
}
