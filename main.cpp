#include <iostream>
#include "funciones_main.h"
#include "Menu.h"
#include "1_clsSuscripcion.h"
#include "rlutil.h"


using namespace std;




int main()
{
    Fecha fechaHoy;
    Suscripcion sus;

    while(true){
        int opcion;
        if(sus.getLogeado()== false){ ///SI NO ESTA LOGEADO SE MUESTRA EL MENU 1
            Menu1();
            sus=switch1(sus);
        }
        if(sus.getLogeado()){
            if (fechaHoy.getBool()==false){
                cout<<"Ingrese la fecha de hoy"<<endl;
                system("pause");
                system("cls");
                fechaHoy.Cargar();
                if(fechaHoy.getAnio()!=2025){
                    system("cls");
                    cout<<"ERROR: El anio debe ser el actual, 2025. Volve a intentarlo."<<endl;
                    rlutil::anykey();
                    system("cls");
                    fechaHoy.Cargar();
                }
            }
            system("cls");
            Menu2();
            sus=switch2(sus,fechaHoy);
        }
    }
}

///SWITCH-1/////////////////////////////////////////////////////
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
///SWITCH-2/////////////////////////////////////////////////////
Suscripcion switch2(Suscripcion sus, Fecha fechaHoy){
    Suscripcion vacia;
    int opcion;
    cin>>opcion;

    switch(opcion){
        case 0:
            exit(1);
            break;
        case 1:
            mi_perfil(sus);
            break;
        case 2:
            listaCanciones(sus,fechaHoy);
            system("cls");
            break;
        case 3:
            historial(sus);
            rlutil::hidecursor();
            rlutil::anykey();
            rlutil::showcursor();
            system("cls");
            break;
        case 4:
            sus=vacia;
            system("cls");
            break;
        default:
            cout<<endl<<"INGRESO INVALIDO, VUELVA A INTENTARLO."<<endl;
            system("pause");
            system("cls");
            break;
    }return sus;
}


