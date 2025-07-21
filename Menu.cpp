#include <iostream>
#include "Menu.h"
#include "1_clsSuscripcion.h"
#include "2_clsArchivos.h"
#include "funciones_main.h"
#include "Fecha.h"
#include "rlutil.h"


using namespace std;

///MENU-1/////////////////////////////////////////////////////
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
///MENU-2/////////////////////////////////////////////////////
void Menu2()
{
    cout<<"======================"<<endl;
    cout<<"1. Mi perfil"<<endl;
    cout<<"2. Modificar Perfil"<<endl;
    cout<<"3. Todas las canciones"<<endl;
    cout<<"4. Historial"<<endl;
    cout<<"5. Cerrar Sesion"<<endl;
    cout<<"0. Salir"<<endl;
    cout<<"======================="<<endl<<endl;
    cout<<" >>> ";
}
///MENU-ADMIN/////////////////////////////////////////////////////
void MenuAdmin() {
    system("cls");
    cout << "      MENU ADMINISTRADOR     " << endl;
    cout << "==============================" << endl;
    cout << "1. Reportes" << endl;
    cout << "2. Agregar nueva cancion" << endl;
    cout << "3. Dar de baja/alta cancion" << endl;
    cout << "4. Dar de baja/alta suscripcion" << endl;
    cout << "5. Modificar cancion" << endl;
    cout << "6. Modificar sucripcion" << endl;
    cout << "7. Lista Canciones"<<endl;
    cout << "8. Lista Suscriptores" << endl;
    cout << "9. Volver al menu principal" << endl;
    cout << "==============================" << endl;
    cout << " >>> ";
}

void MenuReportes() {
    system("cls");
    cout << "==============================" << endl;
    cout << "      MENU REPORTES     " << endl;
    cout << "==============================" << endl;
    cout << "1. Reportes 1" << endl;
    cout << "2. Reportes 2" << endl;
    cout << "3. Reportes 3" << endl;
    cout << "4. Reportes 4" << endl;
    cout << "5. Reportes 5" << endl;
    cout << "==============================" << endl;
    cout << " >>> ";
}
