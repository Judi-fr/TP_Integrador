#include <iostream>
#include "funciones_main.h"
#include "1_clsSuscripcion.h"


using namespace std;

void Menu(){
    cout<<"======================"<<endl;
    cout<<"1. Log in"<<endl;
    cout<<"2. Suscribirse"<<endl;
    cout<<"3. Mi perfil"<<endl;
    cout<<"4. Lista de canciones"<<endl;
    cout<<"5. Historial"<<endl;
    cout<<"======================="<<endl<<endl;
    cout<<" >>> ";
}

int main()
{
    while(true){
        int opcion;
        Menu();
        cin>>opcion;
        switch(opcion){
            case 1:
                login();
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
