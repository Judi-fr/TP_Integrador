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
    cout<<"cancion: cancion mas larga que la mierda";
    cout<<"interprete: 111111111111111111111111111111";/// +44 esquina (14,1) +44 esquina (58,1) otra esquina(59.1) esquina (103,1)
}                                                      ///             (15,2)nombre:                         (60,2)nombre:


Suscripcion switch1(Suscripcion sus){
    int opcion;
    cin>>opcion;
    Fecha fechahoy;
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
        case 9:
            system("cls");
            listaCanciones(sus,fechahoy);
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
            listaCanciones(sus,fechaHoy);
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


void dibujar_cajas(int axisX,int axisY){
    rlutil::locate(14+axisX,1+axisY);
    cout<<char(201);
    rlutil::locate(58+axisX,1+axisY);
    cout<<char(187);
    rlutil::locate(14+axisX,6+axisY);
    cout<<char(200);
    rlutil::locate(58+axisX,6+axisY);
    cout<<char(188);
}
