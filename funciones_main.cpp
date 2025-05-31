#include <iostream>
#include "funciones_main.h"
#include "1_clsSuscripcion.h"
#include "2_clsArchivos.h"

using namespace std;

Suscripcion login(){
    Suscripcion login, suscriptor;
    Archivos archivo;
    int cant_suscriptores;

    cout<<"Email: ";
    login.setEmail();
    cout<<endl<<"Contrasenia: ";
    login.setContrasenia();
    cout<<endl;

    cant_suscriptores=archivo.CantidadRegis_susc();

    if(cant_suscriptores!=0){
        for(int i=0;i<cant_suscriptores;i++){
            suscriptor=archivo.leerSuscripcion(i);
            if(login.getEmail()== suscriptor.getEmail()&&
               login.getContrasenia()== suscriptor.getContrasenia()){
                cout<<"Iniciando sesion..";
                return login=suscriptor;
            }
        }
    }
    else{
        cout<<"email o contrasenia incorrecto. "<<endl;
        return Suscripcion();
    }

}
