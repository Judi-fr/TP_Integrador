#ifndef FUNCIONES_MAIN_H_INCLUDED
#define FUNCIONES_MAIN_H_INCLUDED
#include "1_clsSuscripcion.h"
#include "4_clsAccesos.h"

Suscripcion login();
void crearNuevoUsuario();
void mi_perfil(Suscripcion );
void listaCanciones(Suscripcion , Fecha );
int historial(Suscripcion );
void dibujar_acceso(int ,int ,Accesos );
void dibujar_grilla(int contador);
void switchHistorial();
void reporte1();
void reporte2();
void reporte3();
void reporte4();
void reporte5();
void Modif_susc(Suscripcion );
void Modif_canc();
void listar_canc();
int mostrarTodasLasCanciones();
void dibujar_cancion(int x, int y, Cancion );
void listar_sus();
int mostrarTodosLosSuscriptores();
void dibujar_suscriptor(int x, int y, Suscripcion );
void AnimacionCarga(std::string );

#endif // FUNCIONES_MAIN_H_INCLUDED
