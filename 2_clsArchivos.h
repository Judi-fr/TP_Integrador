#ifndef CLSARCHIVOS_H_INCLUDED
#define CLSARCHIVOS_H_INCLUDED
#include <string>
#include "1_clsSuscripcion.h"
#include "3_clsCancion.h"
#include "4_clsAccesos.h"

class Archivos{

    private:
        std::string _nombreArchivo;
    public:
        Archivos(std::string );
        Archivos();
        void append(Suscripcion );
        void append(Cancion );
        void append(Accesos );

        Suscripcion leerSuscripcion(int pocision);
        Cancion leerCancion(int pocision);
        Accesos leerAcceso(int pocision);

        int CantidadRegis_susc();
        int CantidadRegis_acces();
        int CantidadRegis_canc();

        void Actualizar_reproducciones(int posicion, Cancion song);

        int SaberPocision(Cancion );

};


#endif // CLSARCHIVOS_H_INCLUDED
