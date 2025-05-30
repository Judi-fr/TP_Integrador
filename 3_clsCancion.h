#ifndef CLSCANCION_H_INCLUDED
#define CLSCANCION_H_INCLUDED
#include <cstring>
#include <string>
#include "Fecha.h"

class Cancion{

    private:
        int numero;
        std::string nombre;
        std::string autor;
        std::string interprete;
        Fecha fechaPublicacion;

    public:
        void setNumero(int );
        void setNombre(const char );
        void setAutor(const char);
        void setInterprete(const char );

        int getNumero();
        const char* getNombre();
        const char* getAutor();
        const char* getInterprete();

        void cargarCancion();
        void mostrarCancion();
};


#endif // CLSARCHIVOS_H_INCLUDED
