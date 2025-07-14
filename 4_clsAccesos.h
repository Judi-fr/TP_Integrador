#ifndef CLSACCESOS_H_INCLUDED
#define CLSACCESOS_H_INCLUDED
#include <cstring>
#include "Fecha.h"
#include "3_clsCancion.h"
#include "1_clsSuscripcion.h"

class Accesos{
    private:
        int idCancion;
        int idSuscripcion;
        Fecha diaEscuchado;

    public:
        Accesos(int , int , Fecha );
        Accesos();
        void setCancion(int song);
        void setSuscriptor(int sus);
        void setFecha(Fecha fecha);
        int getSuscripcion();
        int getCanciones();
        Fecha getFecha();
        void Mostrar();

};




#endif // 4_CLSACCESOS_H_INCLUDED
