#include <iostream>
#include <ctime>
#include "funciones_main.h"
#include "Menu.h"
#include "1_clsSuscripcion.h"
#include "3_archCanciones.h"
#include "2_clsArchivos.h"
#include "rlutil.h"


using namespace std;

void switchReportes();
Suscripcion switchAdm(Suscripcion );

/**
ABML para todos los archivos.
ALTA
BAJA
MODIFICACION
LISTADO
*/

int main()
{
    Fecha fechaHoy;
    Suscripcion sus;
    char admin[6]="admin";

    while(true){
        int opcion;
        if(sus.getLogeado()== false){ ///SI NO ESTA LOGEADO SE MUESTRA EL MENU 1
            Menu1();
            sus=switch1(sus);
        }
        if(sus.getLogeado()){
            if(strcmp(sus.getEmail(),admin)==0){
                MenuAdmin();Fecha&
                sus=switchAdm(sus);

            }else{
                if (fechaHoy.getBool()== false){
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
                rlutil::showcursor();
                Menu2();
                sus=switch2(sus,fechaHoy);
            }

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
            crearNuevoUsuario();                             ///SWITCH 1
            system("cls");
            break;
        case 3:
            rlutil::locate(6,10);
            cout<<"Tenes que logearte primero."<<endl;
            rlutil::hidecursor();
            rlutil::anykey();
            rlutil::showcursor();
            system("cls");
            break;
        case 4:
            rlutil::locate(6,10);
            cout<<"Tenes que logearte primero."<<endl;
            rlutil::hidecursor();
            rlutil::anykey();
            system("cls");                                     ///SWITCH 1
            rlutil::showcursor();
            break;
        case 5:
            rlutil::locate(6,10);
            cout<<"Tenes que logearte primero."<<endl;
            rlutil::hidecursor();
            rlutil::anykey();
            rlutil::showcursor();
            system("cls");
            break;
        case 9:
            system("cls");
            listaCanciones(sus,fechahoy);                       ///SWITCH 1
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
            mi_perfil(sus);                    ///SWITCH 2
            break;
        case 2:
            listaCanciones(sus,fechaHoy);
            system("cls");
            break;
        case 3:
            historial(sus);
            rlutil::hidecursor();
            rlutil::anykey();                  ///SWITCH 2
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
    }return sus;                               ///SWITCH 2
}

///SWITCH-ADMIN/////////////////////////////////////////////////
Suscripcion switchAdm(Suscripcion sus){

    int opcion;
    Suscripcion vacia;
    cin>>opcion;
    system("cls");

    switch(opcion){
        case 1:
            system("cls");
            MenuReportes();
            switchReportes();
            break;
        case 2:{
            Cancion nuevaCancion;
            nuevaCancion.cargarCancion();
            Archivo_Cancion archivo;
            archivo.append(nuevaCancion);
            cout<<"Canción agregada exitosamente."<<endl;
            system("pause");
            break;
        }
        case 3:
            sus=vacia;
            return sus;
            break;
        default:
            cout<<"Opción no válida. Intente nuevamente."<<endl;
            system("pause");
            break;
    }
}
///SWITCH-REPORTES//////////////////////////////////////////////
void switchReportes(){
    int opcion;
    MenuReportes();
    cin>>opcion;
    system("cls");

    switch (opcion) {
        case 1:
            reporte1();
            system("cls");
            MenuReportes();
            switchReportes();
            break;
        case 2:
            reporte2();
            system("cls");
            MenuReportes();
            switchReportes();
            break;
        case 3:
            reporte3();
            system("cls");
            MenuReportes();
            switchReportes();
            break;
        case 4:
            reporte4();
            system("cls");
            MenuReportes();
            switchReportes();
            break;
        case 5:
            reporte5();
            system("cls");
            MenuReportes();
            switchReportes();
            break;
        case 6:
            break;
        default:
            cout << "Opción no válida. Intente nuevamente." << endl;
            system("pause");
    }
}


