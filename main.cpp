#include <iostream>
#include "funciones_main.h"
#include "Menu.h"
#include "1_clsSuscripcion.h"


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
            }
            system("cls");
            Menu2();
            sus=switch2(sus,fechaHoy);
        }
    }
}
