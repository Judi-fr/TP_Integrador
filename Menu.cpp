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
    ///cout<<fecha y nombre
    cout<<"======================"<<endl;
    cout<<"1. Mi perfil"<<endl;
    cout<<"2. Lista de canciones"<<endl;
    cout<<"3. Historial"<<endl;
    cout<<"4. Cerrar Sesion"<<endl;
    cout<<"0. Salir"<<endl;
    cout<<"======================="<<endl<<endl;
    cout<<" >>> ";
}
///MENU-ADMIN/////////////////////////////////////////////////////
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
            historial(sus);
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



void menu_canciones(){
    Archivos archivo;
    int x=0, y=0;
    for(int i=1;i<10;i++){
        Cancion song=archivo.leerCancion(i);
        dibujar_cajas(x,y);
        dibujar_canciones(x,y,song);
        if(x==0){
            x+=45;
        }else{
            x=0;
            y+=6;}
    }
}
Cancion interaccion_de_menu(){
    Archivos archivo;
    Cancion cancion;

    int pocision = 1, pocisionAux, key, x=0, y=0, auxX, auxY;
    int Cantidad_canciones = archivo.CantidadRegis_canc();
    rlutil::hidecursor();
    rlutil::locate(1,1);

    while(true){
        auxX=x, auxY=y, pocisionAux=pocision;
        rlutil::setColor(rlutil::BLUE);
        dibujar_cajas(x,y);
        rlutil::setColor(rlutil::WHITE);
        key=rlutil::getkey();
        switch(key){
            case 16:
                ///IZQUIERDA
                if(x==45){
                    x-=45;
                    pocision--;
                }
                break;
            case 17:
                ///DERECHA
                if(x==0){
                    x+=45;
                    pocision++;
                }
                break;
            case 14:
                ///ARRIBA
                if(y!=0){
                    y-=6;
                    pocision-=2;
                }else{rlutil::locate(1,1);}
                break;
            case 15:
                ///ABAJO
                y+=6;
                pocision+=2;
                break;
            case 10||1:
                ///enter
                cancion=archivo.leerCancion(pocision-1);
                return cancion;
        }
        if(pocision<10){
            rlutil::setColor(rlutil::WHITE);
            dibujar_cajas(auxX,auxY);
            rlutil::setColor(rlutil::BLUE);
            dibujar_cajas(x,y);
        }else{
            pocision=pocisionAux;
            x=auxX;
            y=auxY;
        }
    }rlutil::showcursor();
}

void dibujar_cajas(int axisX,int axisY){
    rlutil::locate(14+axisX,2+axisY);
    cout<<char(201);
    rlutil::locate(58+axisX,2+axisY);
    cout<<char(187);
    rlutil::locate(14+axisX,7+axisY);
    cout<<char(200);
    rlutil::locate(58+axisX,7+axisY);
    cout<<char(188);

    for(int i=15;i<58;i++){
        rlutil::locate(i+axisX,2+axisY);
        cout<<char(196);
        rlutil::locate(i+axisX,7+axisY);
        cout<<char(196);
    }
    for(int x=3;x<7;x++){
        rlutil::locate(14+axisX,x+axisY);
        cout<<char(195);
        rlutil::locate(58+axisX,x+axisY);
        cout<<char(180);
    }
}

void dibujar_canciones(int axisX, int axisY,Cancion song){
    rlutil::locate(15+axisX,3+axisY);
    cout<<"Cancion: "<<song.getNombre();
    rlutil::locate(15+axisX,4+axisY);
    cout<<"Autor: "<<song.getAutor();
    rlutil::locate(15+axisX,5+axisY);
    cout<<"Interprete: "<<song.getInterprete();
    rlutil::locate(15+axisX,6+axisY);
    cout<<"Reproducciones: "<<song.getReproducciones();
}
