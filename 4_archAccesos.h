#ifndef ARCHACCESOS_H_INCLUDED
#define ARCHACCESOS_H_INCLUDED

#include "4_clsAccesos.h"

class Archivo_Acceso{
    private:
        std::string nombreArch;
    public:
        Archivo_Acceso(std::string nombre);
        Archivo_Acceso();

        void append(Accesos acceso);
        Accesos leerAcceso(int pocision);
        int CantidadRegis_acces();
};



#endif // 4_ARCHACCESOS_H_INCLUDED
