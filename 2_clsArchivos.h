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
    void append(Suscripcion );
    void append(Cancion );
    void append(Accesos );
};


#endif // CLSARCHIVOS_H_INCLUDED
