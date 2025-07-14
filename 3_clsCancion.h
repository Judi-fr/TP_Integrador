#ifndef CLSCANCION_H_INCLUDED
#define CLSCANCION_H_INCLUDED
#include <cstring>
#include <string>
#include "Fecha.h"

class Cancion{

    private:
        int numero;
        int reproducciones;
        char nombre[30];
        char autor[30];
        char interprete[30];
        Fecha fechaPublicacion;
        bool cargado;

    public:
        Cancion();

        void setNumero(int );
        void sumarReproduccion();
        void setNombre(const char* );
        void setAutor(const char* );
        void setInterprete(const char* );
        void setCargado(bool );
        bool getCargado();

        int getNumero();
        int getReproducciones();
        const char* getNombre();
        const char* getAutor();
        const char* getInterprete();

        void cargarCancion();
        void Mostrar();
};


#endif // CLSARCHIVOS_H_INCLUDED
