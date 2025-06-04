#include <iostream>
#include <windows.h>
#include "Fecha.h"

using namespace std;

Fecha::Fecha(int d, int m, int a){
    dia = d;
    mes = m;
    anio = a;
}

void Fecha::setDia(int d){
    dia = d;
}
void Fecha::setMes(int m){
    mes = m;
}
void Fecha::setAnio(int a){
    anio = a;
}
int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getAnio(){
    return anio;
}
bool Fecha::getBool(){
    return cargada;
}
void Fecha::Cargar(){
    cargada=true;
    cout<<"Dia: ";
    cin>>dia;
    if(dia<0||dia>31){
        cout<<"ERROR: Dia invalido"<<endl<<"Dia: ";
        cin>>dia;
    }
    cout<<"Mes: ";
    cin>>mes;
    if(mes<0||mes>12){
        cout<<"ERROR: Mes invalido"<<endl<<"Mes: ";
        cin>>mes;
    }
    cout<<"Anio: ";
    cin>>anio;
    if(anio<1900||anio>2025){
        cout<<"ERROR: Anio invalido"<<endl<<"Anio: ";
        cin>>anio;
    }
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    Sleep(700);
}
void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio;
}
