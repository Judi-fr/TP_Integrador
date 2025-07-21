#ifndef MENULISTARCANCIONES_H_INCLUDED
#define MENULISTARCANCIONES_H_INCLUDED

#include "3_clsCancion.h"

///LISTA-CANCIONES/////////////////////
int menu_canciones();
Cancion devuelveCancion(int posicion);
Cancion interaccion_de_menu(int );
void dibujar_cajas(int ,int );
void pintarCaja(int , int );
void dibujar_canciones(int ,int ,Cancion );


#endif // MENULISTARCANCIONES_H_INCLUDED
