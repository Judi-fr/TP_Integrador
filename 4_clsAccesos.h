#ifndef CLSACCESOS_H_INCLUDED
#define CLSACCESOS_H_INCLUDED
#include <cstring>
#include "Fecha.h"
#include "3_clsCancion.h"
#include "1_clsSuscripcion.h"

class Accesos{
    private:
        Cancion cancion;
        Suscripcion suscriptor;
        Fecha diaEscuchado;

    public:
        Accesos(Cancion , Suscripcion , Fecha );
        Accesos();
        Suscripcion getSuscripcion();
        Suscripcion getSus();
        Cancion getCanciones();
        Fecha getFecha();
        void Mostrar();

};



#endif // 4_CLSACCESOS_H_INCLUDED
