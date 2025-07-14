#include <iostream>
#include "4_clsAccesos.h"
#include "1_clsSuscripcion.h"
#include "1_archSuscripcion.h"
#include "3_archCanciones.h"
///METODOS ACCESOS
using namespace std;

Accesos::Accesos(int cancion_, int Suscripcion_, Fecha fecha_){
    idCancion=cancion_;
    idSuscripcion=Suscripcion_;
    diaEscuchado=fecha_;
}

Accesos::Accesos(){
}
void Accesos::setCancion(int song){
    idCancion = song;
}
void Accesos::setSuscriptor(int sus){
    idSuscripcion = sus;
}
void Accesos::setFecha(Fecha fecha){
    diaEscuchado = fecha;
}
int Accesos::getSuscripcion(){
    return idSuscripcion;
}

Fecha Accesos::getFecha(){
    return diaEscuchado;
}

int Accesos::getCanciones(){
    return idCancion;
}
void Accesos::Mostrar(){
    Archivo_Cancion archivoCan;
    Archivo_Suscripcion archivoSus;

    Suscripcion suscriptor;
    Cancion cancion;
    suscriptor=archivoSus.BuscarPorId(idSuscripcion);
    cancion=archivoCan.BuscarPorId(idCancion);

    cout<<endl<<suscriptor.getNombre()<<" "<<suscriptor.getApellido()<<endl;
    cout<<"Cancion: "<<cancion.getNombre()<<endl;
    diaEscuchado.Mostrar();
}

///void Accesos::MostrarHistorial(){

///}
