#include <iostream>
#include "Menu.h"
#include "1_clsSuscripcion.h"
#include "funciones_main.h"
#include "Fecha.h"
#include "rlutil.h"


using namespace std;

void Menu1(){
    cout<<"======================"<<endl;
    cout<<"1. Log in"<<endl;
    cout<<"2. Suscribirse"<<endl;
    cout<<"3. Mi perfil"<<endl;
    cout<<"4. Lista de canciones"<<endl;
    cout<<"5. Historial"<<endl;
    cout<<"0. Salir"<<endl;
    cout<<"======================="<<endl<<endl;
    cout<<" >>> ";
}
void Menu2()
{
    cout<<"======================"<<endl;
    cout<<"1. Mi perfil"<<endl;
    cout<<"2. Lista de canciones"<<endl;
    cout<<"3. Historial"<<endl;
    cout<<"4. Cerrar Sesion"<<endl;
    cout<<"0. Salir"<<endl;
    cout<<"======================="<<endl<<endl;
    cout<<" >>> ";
}

void MenuAdmin()
{
    cout<<"======================"<<endl;
    cout<<"1. "<<endl;
    cout<<"4. Lista de canciones"<<endl;
    cout<<"5. Historial"<<endl;
    cout<<"6. Cerrar Sesion"<<endl;
    cout<<"0. Salir"<<endl;
    cout<<"======================="<<endl<<endl;
    cout<<" >>> ";
}


Suscripcion switch1(Suscripcion sus){
    int opcion;
    cin>>opcion;

    switch(opcion){
        case 0:
            exit(1);
            break;
        case 1:
            sus=login();
            system("cls");
            break;
        case 2:
            crearNuevoUsuario();
            system("cls");
            break;
        case 3:
            cout<<"Tenes que logearte primero."<<endl;
            system("pause");
            system("cls");
            break;
        case 4:
            cout<<"Tenes que logearte primero."<<endl;
            system("pause");
            system("cls");
            break;
        case 5:
            cout<<"Tenes que logearte primero."<<endl;
            system("pause");
            system("cls");
            break;
        default:
            cout<<endl<<"INGRESO INVALIDO, VUELVA A INTENTARLO."<<endl;
            system("pause");
            system("cls");
            break;
    }
    return sus;
}

Suscripcion switch2(Suscripcion sus, Fecha fechaHoy){
    Suscripcion vacia;
    int opcion;
    cin>>opcion;

    switch(opcion){
        case 0:
            exit(1);
            break;
        case 1:
            system("cls");
            sus.Mostrar();
            system("pause");
            system("cls");
            break;
        case 2:
            crearNuevoUsuario();
            system("cls");
            break;
        case 3:
            cout<<"Tenes que logearte primero."<<endl;
            system("pause");
            system("cls");
            break;
        case 4:
            sus=vacia;
            system("cls");
            break;
        case 5:
            cout<<"Tenes que logearte primero."<<endl;
            system("pause");
            system("cls");
            break;
        default:
            cout<<endl<<"INGRESO INVALIDO, VUELVA A INTENTARLO."<<endl;
            system("pause");
            system("cls");
            break;
    }return sus;
}
