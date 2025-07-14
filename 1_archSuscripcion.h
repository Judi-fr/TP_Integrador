#ifndef ARCHSUSCRIPCION_H_INCLUDED
#define ARCHSUSCRIPCION_H_INCLUDED
#include "1_clsSuscripcion.h"

class Archivo_Suscripcion{
    private:
        std::string nombreArch;
    public:
        Archivo_Suscripcion(std::string nombre);
        Archivo_Suscripcion();

        Suscripcion leerSuscripcion(int posicion);
        void append(Suscripcion suscripcion);
        int CantidadRegis_susc();
        Suscripcion BuscarPorId(int idBuscado);

};


#endif // 1_ARCHSUSCRIPCION_H_INCLUDED
