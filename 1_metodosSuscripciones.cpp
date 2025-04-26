
///METODOS
#include <iostream>
#include <cstring>
#include "1_clsSuscripcion.h"
#include "cargar_cadena.h"
#include "Fecha.h"

using namespace std;

void Suscripcion::setIdentificador(int x){
    identificador = x;
}
void Suscripcion::setDni(int x){
    dni = x;
}
void Suscripcion::setNombre(const char *x){
    strcpy(nombre,x);
}
void Suscripcion::setApellido(const char *x){
    strcpy(apellido, x);
}
void Suscripcion::setTelefono(int x){
    telefono = x;
}
void Suscripcion::setEmail(const char *x){
    strcpy(email, x);
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
const char* Suscripcion::getNombre(){
    return nombre;
}
const char* Suscripcion::getApellido(){
    return apellido;
}
int Suscripcion::getTelefono(){
    return telefono;
}
const char* Suscripcion::getEmail(){
    return email;
}
Fecha Suscripcion::getFecha(){
    return fechaNacimiento;
}

void Suscripcion::Cargar(){
    cout<<"INGRESA TU DNI: ";
    cin>>dni;
    cout<<"INGRESA TU NOMBRE: ";
    cargarCadena(nombre,30);
    cout<<"INGRESA TU APELLIDO: ";
    cargarCadena(apellido,30);
    cout<<"INGRESA TU TELEFONO: ";
    cin>>telefono;
    cout<<"INGRESA TU EMAIL: ";
    cargarCadena(email,30);
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
