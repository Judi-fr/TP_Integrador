#ifndef ARCHCANCIONES_H_INCLUDED
#define ARCHCANCIONES_H_INCLUDED

#include "3_clsCancion.h"

class Archivo_Cancion{
    private:
        std::string nombreArch;
    public:
        Archivo_Cancion(std::string nombre);
        Archivo_Cancion();

        void bajaLogica(int id);
        void append(Cancion cancion);
        int CantidadRegis_canc();
        Cancion leerCancion(int posicion);
        void Actualizar(int posicion,Cancion nuevaCancion);
        int SaberPocision(Cancion song);
        Cancion BuscarPorId(int idBuscado);
};



#endif // ARCHCANCIONES_H_INCLUDED
