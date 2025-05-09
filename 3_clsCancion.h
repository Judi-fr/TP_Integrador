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
    void setNombre(std::string );
    void setAutor(std::string );
    void setInterprete(std::string );

    int getNumero();
    std::string getNombre();
    std::string getAutor();
    std::string getInterprete();

    void cargarCancion();
    void mostrarCancion();
};


#endif // CLSARCHIVOS_H_INCLUDED
