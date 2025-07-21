#include <iostream>
#include "2_clsArchivos.h"
#include "3_archCanciones.h"

#include "rlutil.h"
#include "MenuListarCanciones.h"


using namespace std;

int menu_canciones(){
    Archivo_Cancion archivo;
    int cantidad_canciones=archivo.CantidadRegis_canc();
    int x=0, y=0,countBajaLogica=0;
    for(int i=0;i<cantidad_canciones;i++){
        Cancion song=archivo.leerCancion(i);
        if(song.getBajaLogica()==true){
            dibujar_cajas(x,y);
            dibujar_canciones(x,y,song);
            if(x==0){
                x+=45;
            }else{
                x=0;
                y+=6;}
        }else{countBajaLogica+=1;}
    }
    return countBajaLogica;
}
Cancion devuelveCancion(int posicion){
    Archivo_Cancion archivo;
    int cantidad_canciones=archivo.CantidadRegis_canc(), x=1;
    for(int i=0;i<cantidad_canciones;i++){
        Cancion song=archivo.leerCancion(i);
        if(song.getBajaLogica()==true){
            if(posicion==x){
                return song;
            }
            x++;
        }
    }
}

Cancion interaccion_de_menu(int contador){
    Archivo_Cancion archivo;
    Cancion cancion;

    int pocision = 1, pocisionAux, key, x=0, y=0, auxX, auxY;
    int Cantidad_canciones = (archivo.CantidadRegis_canc())-contador;
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
                cancion=devuelveCancion(pocision);
                cancion.setCargado(true);
                pintarCaja(x,y);
                return cancion;
            case 0:
                cancion.setCargado(false);
                return cancion;

        }
        if(pocision<=Cantidad_canciones){
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

void pintarCaja(int x, int y){
    rlutil::setColor(rlutil::YELLOW);
    dibujar_cajas(x,y);
    rlutil::msleep(50);
    rlutil::setColor(rlutil::RED);
    dibujar_cajas(x,y);
    rlutil::msleep(50);
    rlutil::setColor(rlutil::GREEN);
    dibujar_cajas(x,y);
    rlutil::msleep(50);
    rlutil::setColor(rlutil::CYAN);
    dibujar_cajas(x,y);
    rlutil::msleep(50);
    rlutil::setColor(rlutil::MAGENTA);
    dibujar_cajas(x,y);
    rlutil::msleep(50);
    rlutil::setColor(rlutil::WHITE);
    dibujar_cajas(x,y);
    rlutil::msleep(50);
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
