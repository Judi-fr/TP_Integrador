#ifndef CLSCANCION_H_INCLUDED
#define CLSCANCION_H_INCLUDED
#include <cstring>
#include <string>
#include "Fecha.h"

class Cancion{

    private:
        int numero;
        int reproducciones;
        char nombre[50];
        char autor[50];
        char interprete[50];
        Fecha fechaPublicacion;

    public:
        void setNumero(int );
        void setReproducciones(int );
        void setNombre(const char* );
        void setAutor(const char* );
        void setInterprete(const char* );

        int getNumero();
        int getReproducciones();
        const char* getNombre();
        const char* getAutor();
        const char* getInterprete();

        void cargarCancion();
        void mostrarCancion();
};


#endif // CLSARCHIVOS_H_INCLUDED
