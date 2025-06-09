#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "1_clsSuscripcion.h"
#include "3_clsCancion.h"

///MENUS///////////////////////////////
void Menu1();
void Menu2();
void MenuAdmin();

///SWITCHS/////////////////////////////
Suscripcion switch1(Suscripcion );
Suscripcion switch2(Suscripcion ,Fecha );
void switchAdm();
///////////////////////////////////////

///LISTA-CANCIONES/////////////////////
void menu_canciones();
Cancion interaccion_de_menu();
void dibujar_cajas(int ,int );
void pintarCaja(int , int );
void dibujar_canciones(int ,int ,Cancion );


#endif // MENU_H_INCLUDED
