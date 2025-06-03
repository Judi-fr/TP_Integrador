#include <iostream>
#include "funciones_main.h"
#include "1_clsSuscripcion.h"


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
    cout<<"3. Mi perfil"<<endl;
    cout<<"4. Lista de canciones"<<endl;
    cout<<"5. Historial"<<endl;
    cout<<"6. Cerrar Sesion"<<endl;
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
int main()
{
    Fecha fechaHoy;
    Suscripcion sus;

    while(true){
        int opcion;
        if(sus.getLogeado()== false){ ///SI NO ESTA LOGEADO SE MUESTRA EL MENU 1
            Menu1();
        cin>>opcion;

        switch(opcion){
            case 0:
                exit(1);
                break;
            case 1:
                sus=login();
                if(sus.getLogeado()==true){
                    cout<<"Ingrese la fecha de hoy"<<endl;
                    fechaHoy.Cargar();
                }
                system("cls");
                break;
            case 2:
                system("cls");
                break;
            case 3:
                system("cls");
                break;
            case 4:
                system("cls");
                break;
            case 5:
                system("cls");
                break;
            default:
                cout<<endl<<"INGRESO INVALIDO, VUELVA A INTENTARLO."<<endl;
                system("pause");
                system("cls");
                break;
            }
        }
    }
}
