#include <iostream>
#include "4_clsAccesos.h"
#include "1_clsSuscripcion.h"
///METODOS ACCESOS
using namespace std;

Accesos::Accesos(Cancion cancion_, Suscripcion suscripcion_, Fecha fecha_){
    cancion=cancion_;
    suscriptor=suscripcion_;
    diaEscuchado=fecha_;
}

Accesos::Accesos(){

}

Suscripcion Accesos::getSuscripcion(){
    return suscriptor;
}

Suscripcion Accesos::getSus(){
    return suscriptor;
}

Fecha Accesos::getFecha(){
    return diaEscuchado;
}

Cancion Accesos::getCanciones(){
    return cancion;
}
void Accesos::Mostrar(){
    cout<<suscriptor.getNombre()<<" "<<suscriptor.getApellido()<<endl;
    cout<<"Cancion: "<<cancion.getNombre()<<endl;
    diaEscuchado.Mostrar();
}
