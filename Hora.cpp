#include "Hora.h"
#include <ctime>
#include "rlutil.h"
#include <iostream>

using namespace std;

///bool Hora::operator==(const Hora& horario);

Hora::Hora(int _hora,int _minuto,int _segundo){
    hora=_hora;
    minuto=_minuto;
    segundo=_segundo;
}
Hora::Hora(){

}
void Hora::setHora(int x){
    hora=x;
}
void Hora::setMinuto(int x){
    minuto=x;
}
void Hora::setSegundo(int x){
    segundo = x;
}
int Hora::getHora(){
    return hora;
}
int Hora::getMinuto(){
    return minuto;
}
int Hora::getSegundo(){
    return segundo;
}

void Hora::Cargar(){
    time_t ahora = time(0);
    tm *ltm = localtime(&ahora);

    hora = ltm->tm_hour;
    minuto = ltm->tm_min;
    segundo = ltm->tm_sec;
}


void Hora::Mostrar(){
    cout<<hora<<":"<<minuto<<":"<<segundo;
}
