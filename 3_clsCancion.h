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
        bool bajaLogica;

    public:
        Cancion();

        void setNumero(int );
        void sumarReproduccion();
        void setNombre(const char* );
        void setAutor(const char* );
        void setInterprete(const char* );
        void setFechaPub(Fecha );
        void setCargado(bool );
        void setBajaLogica(bool );

        int getNumero();
        int getReproducciones();
        const char* getNombre();
        const char* getAutor();
        const char* getInterprete();
        Fecha getFechaPub();
        bool getCargado();
        bool getBajaLogica();

        void cargarCancion();
        void Mostrar();
};


#endif // CLSARCHIVOS_H_INCLUDED
