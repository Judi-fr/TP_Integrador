#ifndef CLSACCESOS_H_INCLUDED
#define CLSACCESOS_H_INCLUDED
#include <cstring>
#include "Fecha.h"
#include "3_clsCancion.h"
#include "Hora.h"
#include "1_clsSuscripcion.h"

class Accesos{
    private:
        int idCancion;
        int idSuscripcion;
        Fecha diaEscuchado;
        Hora horaEscuchada;
    public:
        Accesos(int , int , Fecha ,Hora );
        Accesos();
        void setCancion(int song);
        void setSuscriptor(int sus);
        void setFecha(Fecha fecha);
        int getSuscripcion();
        int getCanciones();
        Fecha getFecha();
        Hora getHora();
        void Mostrar();

};




#endif // 4_CLSACCESOS_H_INCLUDED
