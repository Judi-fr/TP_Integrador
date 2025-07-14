#ifndef FUNCIONES_MAIN_H_INCLUDED
#define FUNCIONES_MAIN_H_INCLUDED
#include "1_clsSuscripcion.h"
#include "4_clsAccesos.h"

Suscripcion login();
void crearNuevoUsuario();
void mi_perfil(Suscripcion );
void listaCanciones(Suscripcion , Fecha );
void historial(Suscripcion );
void dibujar_acceso(int ,int ,Accesos );
void reporte1();
void reporte2();
void reporte3();
void reporte4();
void reporte5();
void AnimacionCarga(std::string );

#endif // FUNCIONES_MAIN_H_INCLUDED
