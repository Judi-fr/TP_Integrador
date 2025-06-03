#include <iostream>
#include "funciones_main.h"
#include "1_clsSuscripcion.h"
#include "2_clsArchivos.h"

using namespace std;


Suscripcion login(){
    system("cls");
    Suscripcion login, suscriptor;
    Archivos archivo;
    int cant_suscriptores;

    cout<<"INGRESE SU EMAIL Y CONTRASENIA"<<endl<<endl;
    cout<<"Email: ";
    login.cargarEmail();
    cout<<"Contrasenia: ";
    login.cargarContrasenia();
    cout<<endl;

    cant_suscriptores=archivo.CantidadRegis_susc();

    if(cant_suscriptores!=0){

        for(int i=0;i<cant_suscriptores;i++){

            suscriptor=archivo.leerSuscripcion(i);
            if(login.getEmail()== suscriptor.getEmail()&&
               login.getContrasenia()== suscriptor.getContrasenia()){
                cout<<"Iniciando sesion.. \n";
                system("pause");
                login=suscriptor;
                login.setLogeado(true);
                return login;
            }
        }
        cout<<"EMAIL O CONTRASENIA INCORRECTO. \n"<<endl;
        system("pause");
        return Suscripcion();
    }
    else{
        cout<<"EMAIL O CONTRASENIA INCORRECTO. \n"<<endl;
        system("pause");
        return Suscripcion();
    }

}

