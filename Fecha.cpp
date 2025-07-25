#include <iostream>
#include <windows.h>
#include "Fecha.h"
#include <ctime>

using namespace std;

bool Fecha::operator==(const Fecha& otra) {
    if(dia == otra.dia &&
    mes == otra.mes &&
    anio == otra.anio){
    return true;
    }
    return false;
}

Fecha::Fecha(int _dia=0,int _mes=0,int _anio=1900){
    dia=_dia;
    mes=_mes;
    anio=_anio;
}
Fecha::Fecha(){
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

void Fecha::CargarActual(){
    time_t ahora = time(0);
    tm *ltm = localtime(&ahora);

    dia = ltm->tm_mday;
    mes = ltm->tm_mon+1;
    anio = ltm->tm_year+1900;
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
    cout<<endl<<dia<<"/"<<mes<<"/"<<anio<<endl;
    Sleep(700);
}
void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio;
}
